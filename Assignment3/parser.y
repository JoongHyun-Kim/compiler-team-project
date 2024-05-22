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

int type_init = 0;
int type_void = 0;

void line(int);
extern printError();
extern yylex();
extern yyerror(s);
%}

%token TIDEN TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE TINC TDEC
%token TPLUS TMINUS TMULTIPLY TDIVIDE TMOD TNOT TASSIGN TLPAREN TRPAREN TCOMMA TSEMICOLON 
%token TLBRACKET TRBRACKET TLBRACE TRBRACE
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c		        : translation_unit
                    ;
                    
translation_unit	: external_dcl		
		            | translation_unit external_dcl
		            ;
		            
external_dcl	    : function_def	
		            | declaration	
		            | TIDEN TSEMICOLON
		            | TIDEN error
		            {
		                yyerrork;
		                printError(wrong_st);  /* error - wrong statement */
		            }
		            ;
		            
function_def	    : function_header compound_st
                    | function_header TSEMICOLON
                    | function_header error   /* 비정상적인 함수 정의 */
                    {
                        /* 에러 발생시 type 수정을 위해 default값 '0' 세팅 */
                        /* identifier about parse error */
                        look_tmp->tpye = 0;
                        yyerrork;
                        /* error - wrong function definition */
                        printError(wrong_funcdef);
                    }
                    ;
                    
function_header	    : dcl_spec function_name formal_param
                    ;
                    
dcl_spec		    : dcl_specifiers	
                    ;
                    
dcl_specifiers	    : dcl_specifier	
		            | dcl_specifiers dcl_specifier
		            ;
		            
dcl_specifier	    : type_qualifier
		            | type_specifier
		            ;
		            
type_qualifier	    : TCONST
                    ;
                    
type_specifier	    : TINT {type_int=1;}  /* type : integer */
                    | TVOID {type_void=1;}  /* type : void */
                    ;
                    
function_name	    : TIDEN
                    {
                        /* identifier about parse error or not defined indentifier/function */
                            if(look_id->type == 0 || look_id->type == 5) 
                                {
                                    look_id->type = 4;      /* function name */
                                    type_int = 0;           /* not integer */
                                    type_void = 0;          /* not void */
                                    look_tmp = look_id;
                                }
                    }
                    ;
                    
formal_param	    : TLPAREN opt_formal_param TRPAREN
                    ;
                    
opt_formal_param	: formal_param_list
                    |
                    ;

formal_param_list	: param_dcl	
		            | formal_param_list TCOMMA param_dcl
		            
// 여기 아래부터는 참조 사진에 없는 부분
param_del	: del_spec declarator		{ semantic(22); };
compound_st	: '{' opt_del_list opt_stat_list '}'	{ semantic(23); };
opt_del_list	: declaration_list			{ semantic(24); }
		|				{ semantic(25); };
declaration_list	: declaration			{ semantic(26); }
		| declaration_list declaration		{ semantic(27); };
declaration	: del_spec init_del_list ';'		{ semantic(28); };
init_del_list	: init_declarator			{ semantic(29); }
		| init_del_list ',' init_declarator 	{ semantic(30); };
init_declarator	: declarator			{ semantic(31); }
		| declarator '=' tnumber		{ semantic(32); };
declarator	: tident				{ semantic(33); }
		| tident '[' opt_number ']'		{ semantic(34); };
opt_number	: tnumber			{ semantic(35); }
		| 				{ semantic(36); };
opt_stat_list	: statement_list			{ semantic(37); }
		|				{ semantic(38); };
statement_list	: statement			{ semantic(39); }
		| statement_list statement		{ semantic(40); };
statement	: compound_st			{ semantic(41); }
		| expression_st			{ semantic(42); }
		| if_st				{ semantic(43); }
		| while_st				{ semantic(44); }
		| return_st			{ semantic(45); }
		;
expression_st	: opt_expression ';'			{ semantic(46); };
opt_expression	: expression			{ semantic(47); }
		|				{ semantic(48); };
if_st		: tif '(' expression ')' statement %prec LOWER_THAN_ELSE	{ semantic(49); }
		| tif '(' expression ')' statement
		  telse statement			{ semantic(50); };
while_st		: twhile '(' expression ')' statement	{ semantic(51); };
return_st		: treturn opt_expression ';'		{ semantic(52); };
expression	: assignment_exp			{ semantic(53); };
assignment_exp	: logical_or_exp			{ semantic(54); }
		| unary_exp '=' assignment_exp	{ semantic(55); }
		| unary_exp taddAssign assignment_exp	{ semantic(56); }
		| unary_exp tsubAssign assignment_exp	{ semantic(57); }
		| unary_exp tmulAssign assignment_exp	{ semantic(58); }
		| unary_exp tdivAssign assignment_exp		{ semantic(59); }
		| unary_exp tmodAssign assignment_exp	{ semantic(60); }
		;
logical_or_exp	: logical_and_exp			{ semantic(61); }
		| logical_or_exp tor logical_and_exp	{ semantic(62); };
logical_and_exp	: equality_exp			{ semantic(63); }
		| logical_and_exp tand equality_exp	{ semantic(64); };
equality_exp	: relational_exp			{ semantic(65); }
		| equality_exp tequal relational_exp	{ semantic(66); }
		| equality_exp tnotequ relational_exp	{ semantic(67); };
relational_exp	: additive_exp			{ semantic(68); }
		| relational_exp '>' additive_exp	{ semantic(69); }
		| relational_exp '<' additive_exp	{ semantic(70); }
		| relational_exp tgreate additive_exp	{ semantic(71); }
		| relational_exp tlesse additive_exp	{ semantic(72); };
additive_exp	: multiplicative_exp			{ semantic(73); }
		| additive_exp '+' multiplicative_exp	{ semantic(74); }
		| additive_exp '-' multiplicative_exp	{ semantic(75); };
multiplicative_exp	: unary_exp			{ semantic(76); }
		| multiplicative_exp '*' unary_exp	{ semantic(77); }	
		| multiplicative_exp '/' unary_exp	{ semantic(78); }
		| multiplicative_exp '%' unary_exp	{ semantic(79); };
unary_exp	: postfix_exp			{ semantic(80); }
		| '-' unary_exp			{ semantic(81); }
		| '!' unary_exp			{ semantic(82); }
		| tinc unary_exp			{ semantic(83); }
		| tdec unary_exp			{ semantic(84); };
postfix_exp	: primary_exp			{ semantic(85); }
		| postfix_exp '[' expression ']'		{ semantic(86); }
		| postfix_exp '(' opt_actual_param ')'	{ semantic(87); }
		| postfix_exp tinc			{ semantic(88); }
		| postfix_exp tdec			{ semantic(89); };
opt_actual_param	: actual_param			{ semantic(90); }
		|				{ semantic(91); };
actual_param	: actual_param_list			{ semantic(92); };
actual_param_list	: assignment_exp			{ semantic(93); }
		| actual_param_list ',' assignment_exp	{ semantic(94); };
primary_exp	: tident				{ semantic(95); }
		| tnumber			{ semantic(96); }
		| '(' expression ')'			{ semantic(97); };
%%
void semantic(int n)
{
	printf("reduced rule number = %d\n", n);
}
