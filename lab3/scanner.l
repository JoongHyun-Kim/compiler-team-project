%{
    #include <stdio.h>
    #include <stdlib.h>
    enum tnumber { TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESSE, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN,
    TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
%}

%%

"const" return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"==" return(TEQUAL);
"!=" return(TNOTEQU);
"<=" return(TLESSE);
">=" return(TGREATE);
"&&" return(TAND);
"||" return(TOR);
"++" return(TINC);
"--" return(TDEC);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);

[A-Za-z_][A-Za-z0-9_]* return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? return(TNUMBER);

"/*"([^*]|\*+[^*/])*\**"*/" ;
"\\".* ;
[ \t\n] ;

. return(yytext[0]);

%%

void main() {
    enum tnumber tn;
    while ((tn = yylex()) != TEOF) {
        switch (tn) {
            case TCONST : printf("TCONST\tconst\n"); break;
            case TELSE : printf("TELSE\telse\n"); break;
            case TIF : printf("TIF\tif\n"); break;
            case TINT : printf("TINT\tint\n"); break;
            case TRETURN : printf("TRETURN\treturn\n"); break;
            case TVOID : printf("TVOID\tvoid\n"); break;
            case TWHILE : printf("TWHILE\twhile\n"); break;
            case TEQUAL : printf("TEQUAL\tequal\n"); break;
            case TNOTEQU : printf("TNOTEQU\tnot equal\n"); break;
            case TLESSE : printf("TLESSE\tless than\n"); break;
            case TGREATE : printf("TGREATE\tgreater than\n"); break;
            case TAND : printf("TAND\tand\n"); break;
            case TOR : printf("TOR\tor\n"); break;
            case TINC : printf("TINC\tincrease\n"); break;
            case TDEC : printf("TDEC\tdecrease\n"); break;
            case TADDASSIGN : printf("TADDASSIGN\tadd assign\n"); break;
            case TMULASSIGN : printf("TMULASSIGN\tmul assign\n"); break;
            case TDIVASSIGN : printf("TDIVASSIGN\tdiv assign\n"); break;
            case TMODASSIGN : printf("TMODASSIGN\tmod assign\n"); break;
            case TIDENT : printf("TIDENT\t%s\n", yytext); break;
            case TNUMBER : printf("TNUMBER\t%d\n", atoi(yytext)); break;
        }
    }
}

int yywrap() {
    printf("\nJoongHyun Kim(2076088) SeoJin Kwak(2076016) SeonYeong Kim(2071010) NaHyun Lee(2076292)\n");
    return 1;
}