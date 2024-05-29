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

int type_int = 0;
int type_void = 0;

HTpointer look_id;
HTpointer look_tmp;

extern yylex();
extern printError();
extern yyerror(s);
%}

%token TERROR TIDENT TNUMBER TFLOAT TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE TINC TDEC
%token TADD TSUB TMUL TDIV TMOD TNOT TASSIGN TCOMMA TSEMICOLON 
%token TLEFTPARENTHESIS TRIGHTPARENTHESIS TLEFTBRACKET TRIGHTBRACKET TLEFTBRACE TRIGHTBRACE
%nonassoc LOWER_THAN_ELSE TELSE

%%
mini_c			: translation_unit
			;
                    
translation_unit		: external_dcl		
			| translation_unit external_dcl
			;
		            
external_dcl		: function_def	
			| declaration	
			| TIDENT TSEMICOLON
			| TIDENT error
			{
				yyerrok;
				printError(wrong_st);  /* error - wrong statement */
			}
			;
		            
function_def		: function_header compound_st
			| function_header TSEMICOLON
			| function_header error   /* 비정상적인 함수 정의 */
			{
				/* 에러 발생시 type 수정을 위해 default값 '0' 세팅 */
				/* identifier about parse error */
				look_tmp->type = 0;
				yyerrok;
				/* error - wrong function definition */
				printError(wrong_funcdef);
			}
			;
                    
function_header	    	: dcl_spec function_name formal_param
			;
                    
dcl_spec			: dcl_specifiers
			{printf("spce");
			}
			;
                    
dcl_specifiers		: dcl_specifier	
			| dcl_specifiers dcl_specifier
			;
		            
dcl_specifier		: type_qualifier
			| type_specifier
			;
		            
type_qualifier		: TCONST
			;
                    
type_specifier		: TINT {type_int=1;}  /* type : integer */
			| TVOID {type_void=1;}  /* type : void */
			;
                    
function_name		: TIDENT
			{
				printf("func name");
				/* identifier about parse error or not defined identifier/function */
				if(look_id->type == 0 || look_id->type == 5) {
					look_id->type = 4;      /* function name */
					type_int = 0;           /* not integer */
					type_void = 0;          /* not void */
					look_tmp = look_id;
				}
			}
			;
                    
formal_param		: TLEFTPARENTHESIS opt_formal_param TRIGHTPARENTHESIS
			;
                    
opt_formal_param		: formal_param_list
			|
			;

formal_param_list		: param_dcl	
			| formal_param_list TCOMMA param_dcl

param_dcl		: dcl_spec declarator
			{
				printf("param_dcl");
				look_id -> type = type_int ? 1 : type_void ? 2 : 0;
				type_int = 0;
				type_void = 0;
			}

compound_st		: '{' opt_dcl_list opt_stat_list '}'

opt_dcl_list		: declaration_list
			|

declaration_list		: declaration
			| declaration_list declaration

declaration		: dcl_spec init_dcl_list ';'

init_dcl_list		: init_declarator
			| init_dcl_list ',' init_declarator

init_declarator		: declarator
			| declarator '=' TNUMBER

declarator		: TIDENT
			{
				printf("dcl");
				if(look_id->type == 0) {
					look_id->type = type_int == 1 ? 1 : type_void == 1 ? 2 : 0;
				}
				look_tmp = look_id;
			}
			| TIDENT '[' opt_number ']'
			{
				if(look_id->type == 0) {
					look_id->type = type_int == 1 ? 3 : 0;
				}
				look_tmp = look_id;
			}

opt_number		: TNUMBER
			|

opt_stat_list		: statement_list
			|

statement_list		: statement
			| statement_list statement

statement		: compound_st
			| expression_st
			| if_st
			| while_st
			| return_st
			;

expression_st		: opt_expression ';'

opt_expression		: expression
			|

if_st			: TIF '(' expression ')' statement %prec LOWER_THAN_ELSE
			| TIF '(' expression ')' statement
			  TELSE statement

while_st			: TWHILE '(' expression ')' statement

return_st			: TRETURN opt_expression ';'

expression		: assignment_exp

assignment_exp		: logical_or_exp
			| unary_exp '=' assignment_exp
			| unary_exp TADDASSIGN assignment_exp
			| unary_exp TSUBASSIGN assignment_exp
			| unary_exp TMULASSIGN assignment_exp
			| unary_exp TDIVASSIGN assignment_exp	
			| unary_exp TMODASSIGN assignment_exp
			;

logical_or_exp		: logical_and_exp
			| logical_or_exp TOR logical_and_exp

logical_and_exp		: equality_exp
			| logical_and_exp TAND equality_exp

equality_exp		: relational_exp
			| equality_exp TEQUAL relational_exp
			| equality_exp TNOTEQU relational_exp

relational_exp		: additive_exp
			| relational_exp '>' additive_exp
			| relational_exp '<' additive_exp
			| relational_exp TGREATE additive_exp
			| relational_exp TLESSE additive_exp

additive_exp		: multiplicative_exp
			| additive_exp '+' multiplicative_exp
			| additive_exp '-' multiplicative_exp

multiplicative_exp		: unary_exp
			| multiplicative_exp '*' unary_exp
			| multiplicative_exp '/' unary_exp
			| multiplicative_exp '%' unary_exp

unary_exp		: postfix_exp
			| '-' unary_exp
			| '!' unary_exp
			| TINC unary_exp
			| TDEC unary_exp

postfix_exp		: primary_exp
			| postfix_exp '[' expression ']'	
			| postfix_exp '(' opt_actual_param ')'
			| postfix_exp TINC
			| postfix_exp TDEC

opt_actual_param		: actual_param
			|

actual_param		: actual_param_list

actual_param_list		: assignment_exp
			| actual_param_list ',' assignment_exp

primary_exp		: TIDENT
			{
				printf("primaryexp");
				if(look_id -> type == 0) look_id -> type = 4; // 임시로. 아직 타입 지정 안 됨.
			}
			| TNUMBER
			| '(' expression ')'
			;
%%