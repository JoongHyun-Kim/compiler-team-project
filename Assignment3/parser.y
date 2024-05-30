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

/* 우선순위 정의 */
%nonassoc LOWER_THAN_ELSE /*    'else' 키워드보다 낮은 우선순위를 가지는 'if'를 정의하여 'if' 문과 'else' 문 사이의 모호성을 해결 */
%nonassoc TELSE /* 'else' 키워드를 정의하여 if-else 문에서 'else'의 결합성을 지정 */

%%
mini_c			: translation_unit
			;
                    
translation_unit	: external_dcl		
			| translation_unit external_dcl
			;
		            
external_dcl		: function_def	
			| declaration	
			| TIDENT TSEMICOLON /* identifier와 세미콜론을 처리한다. */
			| TIDENT error /* 식별자와 그 뒤에 오류가 있는 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_st);
			}
			| TERROR /* 일반적인 구문 오류 처리 */
			;
		            
function_def		: function_header compound_st
			| function_header TSEMICOLON /*   함수 헤더와 세미콜론으로 구성된 함수 선언을 처리 */
			| function_header error /*   함수 헤더 뒤에 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_funcdef);	/* error - wrong function definition */
			}
			;
                    
function_header	    	: dcl_spec function_name formal_param
			| TIDENT function_name formal_param error /*  declaration specifier 생략 등 잘못된 형식의 함수 헤더를 처리 */
			{
				yyerrok;
				ReportError(wrong_funcdef);
			}
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
				type_const = 1;    /* type : const */
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
				if(look_id->type == 0 || look_id->type == 10) {
					if(type_void == 1) {
                              			look_id->type = 6; /* func, void */
                       			} else if(type_int == 1) {
                              			look_id->type = 7; /* func, int */
                        		} else if(type_float == 1) {
						look_id->type = 8; /* func, float */
					}

					/* 초기화 */
                        		type_int = 0;
                        		type_void = 0;
					type_float = 0;

					/* look_temp에 현재 identifier 저장 */
                        		look_tmp = look_id;
                  		}
			}
			| TERROR /* 구문 오류 처리 */
			;
                    
formal_param		: TLEFTPARENTHESIS opt_formal_param TRIGHTPARENTHESIS
			| TLEFTPARENTHESIS opt_formal_param error /*  오른쪽 괄호 ')'가 누락된 형식 매개변수 선언을 처리 */
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
			| formal_param_list param_dcl error /*  쉼표를 사용하지 않고 formal parameter declaration을 나열할 때 발생하는 오류를 처리 */
			{
				yyerrok;
				ReportError(nocomma);
			}
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
			| TLEFTBRACE opt_dcl_list opt_stat_list error /*  중괄호 또는 그 안에 있는 변수 선언과 명령문에 오류가 있는 경우 등 올바르지 않은 형식의 compound 명령문 처리 */
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
				type_const = 0;
			}
			| dcl_spec init_dcl_list error /* 올바르지 않은 형식의 선언을 처리. 오류가 있는 경우를 포함하며, 세미콜론으로 끝나지 않는 경우를 다룸 */
			{
				yyerrok;
				type_int = 0;
				type_void = 0;
				type_float = 0;
				type_const = 0;
				ReportError(nosemi);
			}
			;
				

init_dcl_list		: init_declarator
			| init_dcl_list TCOMMA init_declarator
			| init_dcl_list init_declarator error /*  쉼표를 사용하지 않고 초기화된 변수 선언을 나열할 때 발생하는 오류를 처리 */
			{
				yyerrok;
				ReportError(nocomma);
			}
			;

init_declarator		: declarator
			| declarator TASSIGN TNUMBER /* 숫자로 초기화된 변수 선언을 처리 */
			| declarator TASSIGN TRNUMBER /* 실수로 초기화된 변수 선언을 처리 */
			| declarator TASSIGN TLEFTBRACE init_list TRIGHTBRACE /* 중괄호로 둘러싸인 초기화된 변수 선언을 처리 */
			| declarator TASSIGN TLEFTBRACE init_list error /* 중괄호로 둘러싸인 초기화된 변수 선언에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(nobrace);
			}
			;

init_list		: TNUMBER /*  숫자로 초기화된 변수 값을 처리 */
			| init_list TCOMMA TNUMBER  /* 쉼표로 구분된 숫자로 초기화된 변수 값을 처리 */
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
			| TIDENT TLEFTBRACKET opt_number error /* 배열 변수의 선언에서 오류가 발생한 경우를 처리*/
			{
				yyerrok;
				ReportError(nobracket);
			}
			| TERROR /* 문법 오류가 발생하한 경우를 처리 */
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
			| opt_expression error /*  expression_st에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(nosemi);
			}
			;

opt_expression		: expression
			|
			;

if_st			: TIF TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement %prec LOWER_THAN_ELSE /*   올바른 형식의 if 문을 처리. 조건식 뒤에 중괄호로 둘러싸인 명령문이 옴. %prec LOWER_THAN_ELSE는 else보다 우선순위가 낮음을 의미 */
			| TIF TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement TELSE statement
			| TIF TLEFTPARENTHESIS expression error /* if 문에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(noparen);
			}
			;

while_st		: TWHILE TLEFTPARENTHESIS expression TRIGHTPARENTHESIS statement
			| TWHILE TLEFTPARENTHESIS expression error /* while 문에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(noparen);
			}
			;

return_st		: TRETURN opt_expression TSEMICOLON
			| TRETURN opt_expression error /* 반환값이 있는 return 문에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(nosemi);
			}
			| TRETURN error /* 반환값이 없는 return 문에서 오류가 발생한 경우를 처리 */
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
			| unary_exp TASSIGN error /* '='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TADDASSIGN error /* '+='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TSUBASSIGN error /* '-='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TMULASSIGN error  /* '*='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TDIVASSIGN error  /* '/='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			| unary_exp TMODASSIGN error  /* '%='에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_assign);
			}
			;

logical_or_exp		: logical_and_exp
			| logical_or_exp TOR logical_and_exp
			| logical_or_exp TOR error /*  논리 또는 표현식에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

logical_and_exp		: equality_exp
			| logical_and_exp TAND equality_exp
			| logical_and_exp TAND error /* 논리 곱 표현식에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_st);
			}
			;

equality_exp		: relational_exp
			| equality_exp TEQUAL relational_exp
			| equality_exp TNOTEQU relational_exp
			| equality_exp TEQUAL error   /* 동등성 표현식에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(wrong_st);
			}
			| equality_exp TNOTEQU error /* 부등성 표현식에서 오류가 발생한 경우를 처리 */
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
			| postfix_exp TLEFTBRACKET expression error /*  배열 접근 연산에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(nobracket);
			}
			| postfix_exp TLEFTPARENTHESIS opt_actual_param TRIGHTPARENTHESIS
			| postfix_exp TLEFTPARENTHESIS expression error /*   함수 호출에서 오류가 발생한 경우를 처리*/
			{
				yyerrok;
				ReportError(noparen);
			}
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
				/* identifeir가 정의되지 않은 경우를 처리 */
				if(look_id->type == 0) {
					look_id->type = 10;	/* not defined */
				}
			}
			| TNUMBER
			| TRNUMBER
			| TLEFTPARENTHESIS expression TRIGHTPARENTHESIS
			| TLEFTPARENTHESIS expression error /* 괄호로 둘러싸인 표현식에서 오류가 발생한 경우를 처리 */
			{
				yyerrok;
				ReportError(noparen);
			}
			| TERROR /* 일반적인 오류 처리 */
			;
%%