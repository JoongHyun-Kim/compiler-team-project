
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TERROR	258
#define	TIDENT	259
#define	TNUMBER	260
#define	TRNUMBER	261
#define	TFLOAT	262
#define	TCONST	263
#define	TELSE	264
#define	TIF	265
#define	TINT	266
#define	TRETURN	267
#define	TVOID	268
#define	TWHILE	269
#define	TADDASSIGN	270
#define	TSUBASSIGN	271
#define	TMULASSIGN	272
#define	TDIVASSIGN	273
#define	TMODASSIGN	274
#define	TOR	275
#define	TAND	276
#define	TEQUAL	277
#define	TNOTEQU	278
#define	TGREAT	279
#define	TLESS	280
#define	TGREATE	281
#define	TLESSE	282
#define	TINC	283
#define	TDEC	284
#define	TADD	285
#define	TSUB	286
#define	TMUL	287
#define	TDIV	288
#define	TMOD	289
#define	TNOT	290
#define	TASSIGN	291
#define	TCOMMA	292
#define	TSEMICOLON	293
#define	TLEFTPARENTHESIS	294
#define	TRIGHTPARENTHESIS	295
#define	TLEFTBRACKET	296
#define	TRIGHTBRACKET	297
#define	TLEFTBRACE	298
#define	TRIGHTBRACE	299
#define	LOWER_THAN_ELSE	300

#line 1 "parser.y"

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

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		175
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 91)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    55,    59,    61,    62,    64,    68,    71,    76,
    81,    83,    84,    86,    89,    93,    97,    99,   103,   106,
   108,   112,   114,   119,   124,   126,   127,   129,   130,   132,
   135,   137,   139,   141,   143,   145,   148,   151,   153,   154,
   160,   168,   173,   179,   184,   188,   192,   195,   197,   199,
   203,   207,   211,   215,   219,   223,   226,   229,   232,   235,
   238,   241,   243,   247,   251,   253,   257,   261,   263,   267,
   271,   275,   279,   281,   285,   289,   293,   297,   299,   303,
   307,   309,   313,   317,   321,   323,   326,   329,   332,   335,
   337,   342,   347,   350,   353,   355,   356,   358,   360,   364,
   366,   368,   370,   374
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    64,     0,
     4,    38,     0,     4,     1,     0,    50,    61,     0,    50,
    38,     0,    50,     1,     0,    51,    56,    57,     0,    52,
     0,    53,     0,    52,    53,     0,    54,     0,    55,     0,
     8,     0,    11,     0,    13,     0,     7,     0,     4,     0,
    39,    58,    40,     0,    39,    58,     1,     0,    59,     0,
     0,    60,     0,    59,    37,    60,     0,    51,    67,     0,
    43,    62,    69,    44,     0,    43,    62,    69,     1,     0,
    63,     0,     0,    64,     0,    63,    64,     0,    51,    65,
    38,     0,    51,    65,     1,     0,    66,     0,    65,    37,
    66,     0,    65,    66,     0,    67,     0,    67,    36,     5,
     0,     4,     0,     4,    41,    68,    42,     0,     4,    41,
    68,     1,     0,     5,     0,     0,    70,     0,     0,    71,
     0,    70,    71,     0,    61,     0,    72,     0,    74,     0,
    75,     0,    76,     0,    73,    38,     0,    73,     1,     0,
    77,     0,     0,    10,    39,    77,    40,    71,     0,    10,
    39,    77,    40,    71,     9,    71,     0,    10,    39,    77,
     1,     0,    14,    39,    77,    40,    71,     0,    14,    39,
    77,     1,     0,    12,    73,    38,     0,    12,    73,     1,
     0,    12,     1,     0,    78,     0,    79,     0,    85,    36,
    78,     0,    85,    15,    78,     0,    85,    16,    78,     0,
    85,    17,    78,     0,    85,    18,    78,     0,    85,    19,
    78,     0,    85,    36,     0,    85,    15,     0,    85,    16,
     0,    85,    17,     0,    85,    18,     0,    85,    19,     0,
    80,     0,    79,    20,    80,     0,    79,    20,     1,     0,
    81,     0,    80,    21,    81,     0,    80,    21,     1,     0,
    82,     0,    81,    22,    82,     0,    81,    23,    82,     0,
    81,    22,     1,     0,    81,    23,     1,     0,    83,     0,
    82,    24,    83,     0,    82,    25,    83,     0,    82,    26,
    83,     0,    82,    27,    83,     0,    84,     0,    83,    30,
    84,     0,    83,    31,    84,     0,    85,     0,    84,    32,
    85,     0,    84,    33,    85,     0,    84,    34,    85,     0,
    86,     0,    31,    85,     0,    35,    85,     0,    28,    85,
     0,    29,    85,     0,    90,     0,    86,    41,    77,    42,
     0,    86,    39,    87,    40,     0,    86,    28,     0,    86,
    29,     0,    88,     0,     0,    89,     0,    78,     0,    89,
    37,    78,     0,     4,     0,     5,     0,     6,     0,    39,
    77,    40,     0,    39,    77,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    36,    39,    40,    43,    44,    45,    46,    53,    54,    55,
    65,    68,    71,    72,    75,    76,    79,    85,    89,    93,
    99,   118,   119,   126,   127,   130,   131,   134,   152,   153,
   160,   161,   164,   165,   168,   174,   186,   187,   188,   195,
   196,   199,   212,   223,   231,   232,   235,   236,   239,   240,
   243,   244,   245,   246,   247,   250,   251,   258,   259,   262,
   263,   264,   271,   272,   279,   280,   285,   292,   295,   296,
   297,   298,   299,   300,   301,   302,   307,   312,   317,   322,
   327,   334,   335,   336,   343,   344,   345,   352,   353,   354,
   355,   360,   367,   368,   369,   370,   371,   374,   375,   376,
   379,   380,   381,   382,   385,   386,   387,   388,   389,   392,
   393,   394,   395,   396,   399,   400,   403,   406,   407,   410,
   416,   417,   418,   419
};

static const char * const yytname[] = {   "$","error","$undefined.","TERROR",
"TIDENT","TNUMBER","TRNUMBER","TFLOAT","TCONST","TELSE","TIF","TINT","TRETURN",
"TVOID","TWHILE","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN",
"TOR","TAND","TEQUAL","TNOTEQU","TGREAT","TLESS","TGREATE","TLESSE","TINC","TDEC",
"TADD","TSUB","TMUL","TDIV","TMOD","TNOT","TASSIGN","TCOMMA","TSEMICOLON","TLEFTPARENTHESIS",
"TRIGHTPARENTHESIS","TLEFTBRACKET","TRIGHTBRACKET","TLEFTBRACE","TRIGHTBRACE",
"LOWER_THAN_ELSE","mini_c","translation_unit","external_dcl","function_def",
"function_header","dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier",
"type_specifier","function_name","formal_param","opt_formal_param","formal_param_list",
"param_dcl","compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
    50,    51,    52,    52,    53,    53,    54,    55,    55,    55,
    56,    57,    57,    58,    58,    59,    59,    60,    61,    61,
    62,    62,    63,    63,    64,    64,    65,    65,    65,    66,
    66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
    71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
    74,    74,    75,    75,    76,    76,    76,    77,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
    78,    79,    79,    79,    80,    80,    80,    81,    81,    81,
    81,    81,    82,    82,    82,    82,    82,    83,    83,    83,
    84,    84,    84,    84,    85,    85,    85,    85,    85,    86,
    86,    86,    86,    86,    87,    87,    88,    89,    89,    90,
    90,    90,    90,    90
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     0,     1,     3,     2,     4,     4,
     1,     0,     1,     2,     3,     3,     1,     3,     2,     1,
     3,     1,     4,     4,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     2,     2,     1,     0,     5,
     7,     4,     5,     4,     3,     3,     2,     1,     1,     3,
     3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
     2,     1,     3,     3,     1,     3,     3,     1,     3,     3,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
     4,     4,     2,     2,     1,     0,     1,     1,     3,     1,
     1,     1,     3,     3
};

static const short yydefact[] = {     0,
     0,    20,    17,    18,    19,     1,     2,     4,     0,     0,
    12,    13,    15,    16,     5,     7,     6,     3,    10,     9,
    32,     8,    42,     0,     0,    37,    40,    14,     0,    48,
    31,    33,    46,    25,    11,    36,    42,     0,    35,    39,
     0,   120,   121,   122,     0,     0,     0,     0,     0,     0,
     0,     0,    51,     0,    47,    49,    52,     0,    53,    54,
    55,    58,    68,    69,    82,    85,    88,    93,    98,   101,
   105,   110,    34,    45,     0,     0,     0,    24,    26,    38,
    41,     0,    67,     0,     0,   108,   109,   106,   107,     0,
    30,    29,    50,    57,    56,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
    79,    80,    81,    76,   113,   114,   116,     0,    44,    43,
    28,    23,    22,     0,     0,    66,    65,     0,   124,   123,
    84,    83,   101,    87,    86,    91,    89,    92,    90,    94,
    95,    96,    97,    99,   100,   102,   103,   104,    71,    72,
    73,    74,    75,    70,   118,     0,   115,   117,     0,    27,
    62,    59,    64,    59,   112,     0,   111,    60,    63,   119,
    59,    61,     0,     0,     0
};

static const short yydefgoto[] = {   173,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    24,
    35,    77,    78,    79,    53,    30,    31,    15,    25,    26,
    27,    75,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
   156,   157,   158,    72
};

static const short yypact[] = {    95,
    28,-32768,-32768,-32768,-32768,    95,-32768,-32768,    26,    17,
    31,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    31,-32768,   -17,    -2,     9,-32768,    -6,-32768,    75,    82,
    31,-32768,    40,    31,-32768,-32768,    64,    75,-32768,-32768,
   107,-32768,-32768,-32768,    76,   134,    79,   210,   210,   210,
   210,   210,-32768,     6,    82,-32768,-32768,    33,-32768,-32768,
-32768,-32768,-32768,    94,    98,    18,    58,    67,   126,    59,
    52,-32768,-32768,-32768,     7,    75,     8,    89,-32768,-32768,
-32768,   210,-32768,    35,   210,-32768,-32768,-32768,-32768,    25,
-32768,-32768,-32768,-32768,-32768,   150,   170,   182,   191,   210,
   210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
   210,   210,   210,   210,-32768,-32768,   210,   210,-32768,-32768,
-32768,-32768,-32768,    31,    27,-32768,-32768,    30,-32768,-32768,
-32768,    98,-32768,-32768,    18,-32768,    58,-32768,    58,    67,
    67,    67,    67,   126,   126,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    87,-32768,    92,    91,-32768,
-32768,   118,-32768,   118,-32768,   210,-32768,   122,-32768,-32768,
   118,-32768,   136,   137,-32768
};

static const short yypgoto[] = {-32768,
-32768,   128,-32768,-32768,   -20,-32768,   139,-32768,-32768,-32768,
-32768,-32768,-32768,    21,   143,-32768,-32768,    12,-32768,   -13,
    72,-32768,-32768,-32768,   -55,-32768,   120,-32768,-32768,-32768,
   -50,   -94,-32768,    68,    70,    -9,    41,    -4,   -45,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		249


static const short yytable[] = {    93,
    29,    90,    86,    87,    88,    89,    91,   119,   122,    36,
    29,    40,    37,    76,   149,   150,   151,   152,   153,   154,
    23,   -21,   155,    33,    80,   129,    19,   161,    16,    41,
   163,   125,    32,    94,   128,   126,    34,     2,     3,    98,
    99,     4,    73,     5,    74,    38,    39,   123,   120,    92,
   133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
   146,   147,   148,    20,   130,    17,   162,   159,    21,   164,
    95,   170,   127,   109,   110,   111,   112,   113,    37,   115,
   116,   100,   101,   102,   103,    42,    43,    44,   137,   139,
   117,    45,   118,    46,   114,    47,   104,   105,     1,   144,
   145,     2,     3,    76,    33,     4,   168,     5,   169,    48,
    49,    81,    50,    96,    82,   172,    51,    85,    97,   -59,
    52,    42,    43,    44,    21,   124,   165,    45,   166,    46,
   171,    47,   167,    18,    83,   174,   175,    42,    43,    44,
   140,   141,   142,   143,   160,    48,    49,   121,    50,    28,
   131,    22,    51,    42,    43,    44,    52,   106,   107,   108,
    21,    48,    49,   132,    50,    84,   135,     0,    51,     0,
   134,   -59,    52,    42,    43,    44,     0,    48,    49,     0,
    50,     0,   136,     0,    51,    42,    43,    44,    52,     0,
     0,   138,     0,     0,    42,    43,    44,    48,    49,     0,
    50,     0,     0,     0,    51,     0,     0,     0,    52,    48,
    49,     0,    50,    42,    43,    44,    51,     0,    48,    49,
    52,    50,     0,     0,     0,    51,     0,     0,     0,    52,
     0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
    50,     0,     0,     0,    51,     0,     0,     0,    52
};

static const short yycheck[] = {    55,
    21,    52,    48,    49,    50,    51,     1,     1,     1,     1,
    31,    25,     4,    34,   109,   110,   111,   112,   113,   114,
     4,    39,   117,    41,    38,     1,     1,     1,     1,    36,
     1,    82,    21,     1,    85,     1,    39,     7,     8,    22,
    23,    11,    31,    13,     5,    37,    38,    40,    42,    44,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,    38,    40,    38,    40,   118,    43,    40,
    38,   166,    38,    15,    16,    17,    18,    19,     4,    28,
    29,    24,    25,    26,    27,     4,     5,     6,    98,    99,
    39,    10,    41,    12,    36,    14,    30,    31,     4,   104,
   105,     7,     8,   124,    41,    11,   162,    13,   164,    28,
    29,     5,    31,    20,    39,   171,    35,    39,    21,    38,
    39,     4,     5,     6,    43,    37,    40,    10,    37,    12,
     9,    14,    42,     6,     1,     0,     0,     4,     5,     6,
   100,   101,   102,   103,   124,    28,    29,    76,    31,    11,
     1,     9,    35,     4,     5,     6,    39,    32,    33,    34,
    43,    28,    29,    96,    31,    46,    97,    -1,    35,    -1,
     1,    38,    39,     4,     5,     6,    -1,    28,    29,    -1,
    31,    -1,     1,    -1,    35,     4,     5,     6,    39,    -1,
    -1,     1,    -1,    -1,     4,     5,     6,    28,    29,    -1,
    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    28,
    29,    -1,    31,     4,     5,     6,    35,    -1,    28,    29,
    39,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 47 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);  /* error - wrong statement */
			;
    break;}
case 10:
#line 56 "parser.y"
{
				/* 에러 발생시 type 수정을 위해 default값 '0' 세팅 */
				/* identifier about parse error */
				
				yyerrok;
				ReportError(wrong_funcdef);	/* error - wrong function definition */
			;
    break;}
case 17:
#line 80 "parser.y"
{
				type_const = 1;
			;
    break;}
case 18:
#line 86 "parser.y"
{ 
				type_int = 1;	/* type : integer */
			;
    break;}
case 19:
#line 90 "parser.y"
{
				type_void = 1;	/* type : void */
			;
    break;}
case 20:
#line 94 "parser.y"
{
				type_float = 1;	/* type : float */
			;
    break;}
case 21:
#line 100 "parser.y"
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
			;
    break;}
case 23:
#line 120 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 28:
#line 135 "parser.y"
{
				if(type_int == 1) {
					param_int = 1;
					look_id->type = 10; /* integer scalar parameter */
				}
				else if(type_float == 1) {
					param_float = 1;
					look_id->type = 11; /* float scalar parameter */
				}
				type_int=0;
                  		type_void=0;
                  		type_float=0;
                  		param_int=0;
                  		param_float=0;
			;
    break;}
case 30:
#line 154 "parser.y"
{
				yyerrok;
				ReportError(nobrace);
			;
    break;}
case 35:
#line 169 "parser.y"
{
				type_int = 0;
				type_void = 0;
				type_float = 0;
			;
    break;}
case 36:
#line 175 "parser.y"
{
				look_tmp->type = 0;
				type_int = 0;
				type_void = 0;
				type_float = 0;
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 39:
#line 189 "parser.y"
{
				yyerrok;
				ReportError(nocomma);
			;
    break;}
case 42:
#line 200 "parser.y"
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
			;
    break;}
case 43:
#line 213 "parser.y"
{
				if(look_id->type == 0) {
					if(type_int == 1) {
						look_id->type = 4;	/* int array var */
					} else if(type_float == 1) {
						look_id->type = 5;	/* float array var */
					}
				}
				look_tmp = look_id;
			;
    break;}
case 44:
#line 224 "parser.y"
{
				yyerrok;
				ReportError(nobracket);
			;
    break;}
case 57:
#line 252 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 62:
#line 265 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 64:
#line 273 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 66:
#line 281 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 67:
#line 286 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 76:
#line 303 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 77:
#line 308 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 78:
#line 313 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 79:
#line 318 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 80:
#line 323 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 81:
#line 328 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 84:
#line 337 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 87:
#line 346 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 91:
#line 356 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 92:
#line 361 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 120:
#line 411 "parser.y"
{
				if(look_id->type == 0) {
					look_id->type = 10;	/* not defined */
				}
			;
    break;}
case 124:
#line 420 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 425 "parser.y"
