%{
/*
    parser.y - yacc source for the mini_c
    Programmer - JoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292)
    date - 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_const = 0;
int type_int = 0;
int type_void = 0;
int type_float = 0;
int param_int = 0;
int param_float = 0;

extern yylex();
extern ReportError();
extern yyerror(s);
%}

%token TERROR TIDENT TNUMBER TRNUMBER TFLOAT TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE TINC TDEC
%token TADD TSUB TMUL TDIV TMOD TNOT TASSIGN TCOMMA TSEMICOLON 
%token TLEFTPARENTHESIS TRIGHTPARENTHESIS TLEFTBRACKET TRIGHTBRACKET TLEFTBRACE TRIGHTBRACE
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c			: translation_unit
			;
                    
translation_unit	: external_dcl		
			| translation_unit external_dcl
			;
		            
external_dcl		: function_def	
			| declaration	
			| TIDENT TSEMICOLON
			| TIDENT error
			{
				yyerrok;
				ReportError(wrong_st);  /* error - wrong statement */
			}
			;
		            
function_def		: function_header compound_st
			| function_header TSEMICOLON
			| function_header error   /* 비정상적인 함수 정의 */
			{				
				yyerrok;
				ReportError(wrong_funcdef);	/* error - wrong function definition */
			}
			;
                    
function_header	    	: dcl_spec function_name formal_param
			;
                    
dcl_spec		: dcl_specifiers
			;
                    
dcl_specifiers		: dcl_specifier	
			| dcl_specifiers dcl_specifier
			;
		            
dcl_specifier		: type_qualifier
			| type_specifier
			;
		            
type_qualifier		: TCONST
			{
				type_const = 1;
			}
			;
                    
type_specifier		: TINT
			{ 
				type_int = 1;	/* type : integer */
				type_void = 0;
				type_float = 0;
			}
			| TVOID 
			{
				type_void = 1;	/* type : void */
				type_int = 0;
				type_float = 0;
			}
			| TFLOAT
			{
				type_float = 1;	/* type : float */
				type_void = 0;
				type_int = 0;
			}
			;
                    
function_name		: TIDENT
			{
				/* identifier about parse error or not defined identifier/function */
				if(look_id->type == 0 || look_id->type == 10) {
					if(type_void == 1) {
                              			look_id->type = 6; /* func, void */
                       			} else if(type_int == 1) {
                              			look_id->type = 7; /* func, int */
                        		} else if(type_float == 1) {
						look_id->type = 8; /* func, float */
					}
                        		type_int = 0;
                        		type_void = 0;
					type_float = 0;
                        		look_tmp = look_id;
                  		}
			}
			;
                    
formal_param		: TLEFTPARENTHESIS opt_formal_param TRIGHTPARENTHESIS
			| TLEFTPARENTHESIS opt_formal_param error
			{
				yyerrok;
				ReportError(noparen);
			}
			;
                    
opt_formal_param	: formal_param_list
			|
			;

formal_param_list	: param_dcl	
			| formal_param_list TCOMMA param_dcl
			;

param_dcl		: dcl_spec declarator
			{
				if(type_int == 1) {
					param_int = 1;
					look_id->type = 11; /* integer scalar parameter */
				}
				else if(type_float == 1) {
					param_float = 1;
					look_id->type = 12; /* float scalar parameter */
				}
				type_int=0;
                  		type_void=0;
                  		type_float=0;
                  		param_int=0;
                  		param_float=0;
			}
			;

compound_st		: TLEFTBRACE opt_dcl_list opt_stat_list TRIGHTBRACE
			| TLEFTBRACE opt_dcl_list opt_stat_list error
			{
				yyerrok;
				ReportError(nobrace);
			}
			;

opt_dcl_list		: declaration_list
			|
			;

declaration_list	: declaration
			| declaration_list declaration
			;

declaration		: dcl_spec init_dcl_list TSEMICOLON
			{
				type_int = 0;
				type_void = 0;
				type_float = 0;
			}
			| dcl_spec init_dcl_list error
			{
				look_tmp->type = 0;
				type_int = 0;
				type_void = 0;
				type_float = 0;
				yyerrok;
				ReportError(nosemi);
			}
			;
				

init_dcl_list		: init_declarator
			| init_dcl_list TCOMMA init_declarator
			| init_dcl_list init_declarator
			{
				yyerrok;
				ReportError(nocomma);
			}
			;

init_declarator		: declarator
			| declarator TASSIGN TNUMBER
			;

declarator		: TIDENT
			{
				if(look_id->type == 0) {
					if(type_int == 1) {
						look_id->type = 1;	/* int scalar var */
					} else if (type_void == 1) {
						look_id->type = 2;	/* void scalar var */
					} else if (type_float == 1) {
						look_id->type = 3;	/* float scalar var */
					}
				}
				look_tmp = look_id;
			}
			| TIDENT TLEFTBRACKET opt_number TRIGHTBRACKET
			{
				if(look_id->type == 0) {
					if(type_int == 1) {
						look_id->type = 4;	/* int array var */
					} else if(type_float == 1) {
						look_id->type = 5;	/* float array var */
					}
				}
				look_tmp = look_id;
			}
			| TIDENT TLEFTBRACKET opt_number error
			{
				yyerrok;
				ReportError(nobracket);
			}
			;
				

opt_number		: TNUMBER
			|
			;

opt_stat_list		: statement_list
			|
			;

statement_list		: statement
			| statement_list statement
			;

statement		: compound_st
			| expression_st
			| if_st
			| while_st
			| return_st
			;

expression_st		: opt_expression TSEMICOLON
			| opt_expression error
			{
				yyerrok;
				ReportError(nosemi);
			}
			;

opt_expression		: expression
			|
			;

if_st			: TIF TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement %prec LOWER_THAN_ELSE
			| TIF TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement TELSE statement
			| TIF TLEFTPARENTHESIS expression error
			{
				yyerrok;
				ReportError(noparen);
			}
			;

while_st		: TWHILE TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement
			| TWHILE TLEFTPARENTHESIS expression error
			{
				yyerrok;
				ReportError(noparen);
			}
			;

return_st		: TRETURN opt_expression TSEMICOLON
			| TRETURN opt_expression error
			{
				yyerrok;
				ReportError(nosemi);
			}
			| TRETURN error
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

expression		: assignment_exp
			;

assignment_exp		: logical_or_exp
			| unary_exp TASSIGN assignment_exp
			| unary_exp TADDASSIGN assignment_exp
			| unary_exp TSUBASSIGN assignment_exp
			| unary_exp TMULASSIGN assignment_exp
			| unary_exp TDIVASSIGN assignment_exp	
			| unary_exp TMODASSIGN assignment_exp
			| unary_exp TASSIGN
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TADDASSIGN		
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TSUBASSIGN		
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TMULASSIGN		
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TDIVASSIGN		
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TMODASSIGN		
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			;

logical_or_exp		: logical_and_exp
			| logical_or_exp TOR logical_and_exp
			| logical_or_exp TOR error
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

logical_and_exp		: equality_exp
			| logical_and_exp TAND equality_exp
			| logical_and_exp TAND error
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

equality_exp		: relational_exp
			| equality_exp TEQUAL relational_exp
			| equality_exp TNOTEQU relational_exp
			| equality_exp TEQUAL error
			{
				yyerrok;
				ReportError(wrong_st);
			}
			| equality_exp TNOTEQU error
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

relational_exp		: additive_exp
			| relational_exp TGREAT additive_exp
			| relational_exp TLESS additive_exp
			| relational_exp TGREATE additive_exp
			| relational_exp TLESSE additive_exp
			;

additive_exp		: multiplicative_exp
			| additive_exp TADD multiplicative_exp
			| additive_exp TSUB multiplicative_exp
			;

multiplicative_exp	: unary_exp
			| multiplicative_exp TMUL unary_exp
			| multiplicative_exp TDIV unary_exp
			| multiplicative_exp TMOD unary_exp
			;

unary_exp		: postfix_exp
			| TSUB unary_exp
			| TNOT unary_exp
			| TINC unary_exp
			| TDEC unary_exp
			;

postfix_exp		: primary_exp
			| postfix_exp TLEFTBRACKET expression TRIGHTBRACKET	
			| postfix_exp TLEFTPARENTHESIS opt_actual_param TRIGHTPARENTHESIS
			| postfix_exp TINC
			| postfix_exp TDEC
			;

opt_actual_param	: actual_param
			|
			;

actual_param		: actual_param_list
			;

actual_param_list	: assignment_exp
			| actual_param_list TCOMMA assignment_exp
			;

primary_exp		: TIDENT
			{
				if(look_id->type == 0) {
					look_id->type = 10;	/* not defined */
				}
			}
			| TNUMBER
			| TRNUMBER
			| TLEFTPARENTHESIS expression TRIGHTPARENTHESIS
			| TLEFTPARENTHESIS expression error
			{
				yyerrok;
				ReportError(noparen);
			}
			;
%%