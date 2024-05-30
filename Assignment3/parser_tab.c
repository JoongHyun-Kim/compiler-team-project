
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



#define	YYFINAL		204
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 92)

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
     0,     2,     4,     7,     9,    11,    14,    17,    19,    22,
    25,    28,    32,    37,    39,    41,    44,    46,    48,    50,
    52,    54,    56,    58,    60,    64,    68,    70,    71,    73,
    77,    81,    84,    89,    94,    96,    97,    99,   102,   106,
   110,   112,   116,   120,   122,   126,   130,   136,   142,   144,
   148,   150,   155,   160,   162,   164,   165,   167,   168,   170,
   173,   175,   177,   179,   181,   183,   186,   189,   191,   192,
   198,   206,   211,   217,   222,   226,   230,   233,   235,   237,
   241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
   281,   285,   287,   291,   295,   297,   301,   305,   307,   311,
   315,   319,   323,   325,   329,   333,   337,   341,   343,   347,
   351,   353,   357,   361,   365,   367,   370,   373,   376,   379,
   381,   386,   391,   396,   401,   404,   407,   409,   410,   412,
   414,   418,   420,   422,   424,   428,   432
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    64,     0,
     4,    38,     0,     4,     1,     0,     3,     0,    50,    61,
     0,    50,    38,     0,    50,     1,     0,    51,    56,    57,
     0,     4,    56,    57,     1,     0,    52,     0,    53,     0,
    52,    53,     0,    54,     0,    55,     0,     8,     0,    11,
     0,    13,     0,     7,     0,     4,     0,     3,     0,    39,
    58,    40,     0,    39,    58,     1,     0,    59,     0,     0,
    60,     0,    59,    37,    60,     0,    59,    60,     1,     0,
    51,    68,     0,    43,    62,    70,    44,     0,    43,    62,
    70,     1,     0,    63,     0,     0,    64,     0,    63,    64,
     0,    51,    65,    38,     0,    51,    65,     1,     0,    66,
     0,    65,    37,    66,     0,    65,    66,     1,     0,    68,
     0,    68,    36,     5,     0,    68,    36,     6,     0,    68,
    36,    43,    67,    44,     0,    68,    36,    43,    67,     1,
     0,     5,     0,    67,    37,     5,     0,     4,     0,     4,
    41,    69,    42,     0,     4,    41,    69,     1,     0,     3,
     0,     5,     0,     0,    71,     0,     0,    72,     0,    71,
    72,     0,    61,     0,    73,     0,    75,     0,    76,     0,
    77,     0,    74,    38,     0,    74,     1,     0,    78,     0,
     0,    10,    39,    78,    40,    72,     0,    10,    39,    78,
    40,    72,     9,    72,     0,    10,    39,    78,     1,     0,
    14,    39,    78,    40,    72,     0,    14,    39,    78,     1,
     0,    12,    74,    38,     0,    12,    74,     1,     0,    12,
     1,     0,    79,     0,    80,     0,    86,    36,    79,     0,
    86,    15,    79,     0,    86,    16,    79,     0,    86,    17,
    79,     0,    86,    18,    79,     0,    86,    19,    79,     0,
    86,    36,     1,     0,    86,    15,     1,     0,    86,    16,
     1,     0,    86,    17,     1,     0,    86,    18,     1,     0,
    86,    19,     1,     0,    81,     0,    80,    20,    81,     0,
    80,    20,     1,     0,    82,     0,    81,    21,    82,     0,
    81,    21,     1,     0,    83,     0,    82,    22,    83,     0,
    82,    23,    83,     0,    82,    22,     1,     0,    82,    23,
     1,     0,    84,     0,    83,    24,    84,     0,    83,    25,
    84,     0,    83,    26,    84,     0,    83,    27,    84,     0,
    85,     0,    84,    30,    85,     0,    84,    31,    85,     0,
    86,     0,    85,    32,    86,     0,    85,    33,    86,     0,
    85,    34,    86,     0,    87,     0,    31,    86,     0,    35,
    86,     0,    28,    86,     0,    29,    86,     0,    91,     0,
    87,    41,    78,    42,     0,    87,    41,    78,     1,     0,
    87,    39,    88,    40,     0,    87,    39,    78,     1,     0,
    87,    28,     0,    87,    29,     0,    89,     0,     0,    90,
     0,    79,     0,    90,    37,    79,     0,     4,     0,     5,
     0,     6,     0,    39,    78,    40,     0,    39,    78,     1,
     0,     3,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    36,    39,    40,    43,    44,    45,    46,    51,    54,    55,
    56,    63,    64,    71,    74,    75,    78,    79,    82,    88,
    94,   100,   108,   125,   128,   129,   136,   137,   140,   141,
   142,   149,   167,   168,   175,   176,   179,   180,   183,   190,
   202,   203,   204,   211,   212,   213,   214,   215,   222,   223,
   226,   239,   250,   255,   259,   260,   263,   264,   267,   268,
   271,   272,   273,   274,   275,   278,   279,   286,   287,   290,
   291,   292,   299,   300,   307,   308,   313,   320,   323,   324,
   325,   326,   327,   328,   329,   330,   335,   340,   345,   350,
   355,   362,   363,   364,   371,   372,   373,   380,   381,   382,
   383,   388,   395,   396,   397,   398,   399,   402,   403,   404,
   407,   408,   409,   410,   413,   414,   415,   416,   417,   420,
   421,   422,   427,   428,   433,   434,   437,   438,   441,   444,
   445,   448,   454,   455,   456,   457,   462
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
"init_declarator","init_list","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    48,    48,    48,    49,    49,
    49,    50,    50,    51,    52,    52,    53,    53,    54,    55,
    55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
    59,    60,    61,    61,    62,    62,    63,    63,    64,    64,
    65,    65,    65,    66,    66,    66,    66,    66,    67,    67,
    68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
    72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
    75,    75,    76,    76,    77,    77,    77,    78,    79,    79,
    79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
    79,    80,    80,    80,    81,    81,    81,    82,    82,    82,
    82,    82,    83,    83,    83,    83,    83,    84,    84,    84,
    85,    85,    85,    85,    86,    86,    86,    86,    86,    87,
    87,    87,    87,    87,    87,    87,    88,    88,    89,    90,
    90,    91,    91,    91,    91,    91,    91
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     1,     2,     2,
     2,     3,     4,     1,     1,     2,     1,     1,     1,     1,
     1,     1,     1,     1,     3,     3,     1,     0,     1,     3,
     3,     2,     4,     4,     1,     0,     1,     2,     3,     3,
     1,     3,     3,     1,     3,     3,     5,     5,     1,     3,
     1,     4,     4,     1,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     2,     2,     1,     0,     5,
     7,     4,     5,     4,     3,     3,     2,     1,     1,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
     4,     4,     4,     4,     2,     2,     1,     0,     1,     1,
     3,     1,     1,     1,     3,     3,     1
};

static const short yydefact[] = {     0,
     8,     0,    22,    19,    20,    21,     1,     2,     4,     0,
     0,    14,    15,    17,    18,     5,     7,    24,    23,     6,
     0,     3,    11,    10,    36,     9,    54,    51,     0,     0,
    41,    44,    16,    28,     0,     0,    58,    35,    37,    56,
    12,    40,    54,    51,     0,    39,     0,     0,     0,     0,
    27,    29,    13,   137,   132,   133,   134,     0,     0,     0,
     0,     0,     0,     0,     0,    61,     0,    57,    59,    62,
     0,    63,    64,    65,    68,    78,    79,    92,    95,    98,
   103,   108,   111,   115,   120,    38,    55,     0,    42,    43,
    45,    46,     0,    32,    26,    25,     0,     0,     0,    77,
     0,     0,   118,   119,   116,   117,     0,    34,    33,    60,
    67,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   125,   126,   128,     0,    53,    52,    49,     0,    30,
    31,     0,    76,    75,     0,   136,   135,    94,    93,   111,
    97,    96,   101,    99,   102,   100,   104,   105,   106,   107,
   109,   110,   112,   113,   114,    87,    81,    88,    82,    89,
    83,    90,    84,    91,    85,    86,    80,     0,   130,     0,
   127,   129,     0,    48,     0,    47,    72,    69,    74,    69,
   124,   123,     0,   122,   121,    50,    70,    73,   131,    69,
    71,     0,     0,     0
};

static const short yydefgoto[] = {   202,
     7,     8,     9,    10,    49,    12,    13,    14,    15,    21,
    35,    50,    51,    52,    66,    37,    38,    16,    30,    31,
   139,    32,    88,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,   180,   181,   182,    85
};

static const short yypact[] = {    33,
-32768,   132,-32768,-32768,-32768,-32768,    33,-32768,-32768,    10,
    39,   217,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   -22,-32768,-32768,-32768,   217,-32768,    -5,   -12,   -22,    29,
-32768,     3,-32768,   217,    46,    90,    86,   217,-32768,    54,
-32768,-32768,-32768,    21,    90,-32768,    84,    44,    90,    18,
   327,-32768,-32768,-32768,-32768,-32768,-32768,    49,   140,    56,
   322,   322,   322,   322,   322,-32768,    11,    86,-32768,-32768,
    13,-32768,-32768,-32768,-32768,-32768,    81,    89,    96,   305,
   117,    74,   350,   111,-32768,-32768,-32768,    14,-32768,-32768,
-32768,-32768,   107,-32768,-32768,-32768,   217,   115,   322,-32768,
    59,   322,-32768,-32768,-32768,-32768,    23,-32768,-32768,-32768,
-32768,-32768,   152,   161,   198,   207,   322,   322,   322,   322,
   322,   322,   322,   322,   322,   216,   253,   262,   271,   308,
   317,-32768,-32768,   322,   322,-32768,-32768,-32768,     8,-32768,
-32768,    24,-32768,-32768,    25,-32768,-32768,-32768,    89,-32768,
-32768,    96,-32768,   305,-32768,   305,   117,   117,   117,   117,
    74,    74,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   122,   125,    91,
-32768,   100,    15,-32768,   144,-32768,-32768,    99,-32768,    99,
-32768,-32768,   322,-32768,-32768,-32768,   142,-32768,-32768,    99,
-32768,   154,   159,-32768
};

static const short yypgoto[] = {-32768,
-32768,   156,-32768,-32768,    61,-32768,   162,-32768,-32768,   165,
   148,-32768,-32768,   -43,   172,-32768,-32768,    -7,-32768,   -17,
-32768,   135,-32768,-32768,-32768,   -68,-32768,   126,-32768,-32768,
-32768,   -64,  -124,-32768,    73,    79,    45,   254,    51,   -41,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		386


static const short yytable[] = {   110,
   107,   167,   169,   171,   173,   175,   177,    98,   184,   179,
    23,   108,    47,   111,   136,   194,    34,    39,    95,   103,
   104,   105,   106,   146,   187,   189,   -23,    89,    40,    42,
    86,    43,    44,   -24,   142,     1,     2,   145,    48,     3,
     4,    27,    28,     5,   185,     6,    53,    24,    91,    92,
   112,   186,    25,   140,   109,   137,   195,    96,    87,   143,
    11,    40,   147,   188,   190,    45,    46,    11,   199,   178,
   183,   150,   150,   150,   150,   150,   150,   150,   150,   150,
   150,   163,   164,   165,    90,    36,    93,    99,    54,    55,
    56,    57,    43,    44,   102,    58,   144,    59,    36,    60,
   113,    54,    55,    56,    57,   123,   124,   125,    58,   114,
    59,   138,    60,    61,    62,   141,    63,   115,   116,   197,
    64,   198,   191,   -69,    65,   -78,    61,    62,    25,    63,
   192,   201,    17,    64,    18,    19,   193,    65,   132,   133,
   100,    25,    54,    55,    56,    57,   121,   122,   196,   134,
   200,   135,   148,   203,    54,    55,    56,    57,   204,   154,
   156,   151,    22,    54,    55,    56,    57,    61,    62,    20,
    63,   161,   162,    33,    64,    29,    41,   -69,    65,    61,
    62,    26,    63,    94,   101,   149,    64,     0,    61,    62,
    65,    63,   152,     0,     0,    64,     0,     0,   153,    65,
    54,    55,    56,    57,     0,     0,     0,   155,     0,    54,
    55,    56,    57,     0,     0,     0,   166,     0,    54,    55,
    56,    57,     0,     3,     4,    61,    62,     5,    63,     6,
     0,     0,    64,     0,    61,    62,    65,    63,     0,     0,
     0,    64,     0,    61,    62,    65,    63,     0,     0,     0,
    64,     0,     0,   168,    65,    54,    55,    56,    57,     0,
     0,     0,   170,     0,    54,    55,    56,    57,     0,     0,
     0,   172,     0,    54,    55,    56,    57,     0,     0,     0,
    61,    62,     0,    63,     0,     0,     0,    64,     0,    61,
    62,    65,    63,     0,     0,     0,    64,     0,    61,    62,
    65,    63,     0,     0,     0,    64,     0,     0,   174,    65,
    54,    55,    56,    57,     0,     0,     0,   176,     0,    54,
    55,    56,    57,     0,    54,    55,    56,    57,   117,   118,
   119,   120,     0,     3,     4,    61,    62,     5,    63,     6,
     0,     0,    64,     0,    61,    62,    65,    63,     0,    61,
    62,    64,    63,     0,     0,    65,    64,     0,     0,     0,
    65,     0,     0,    97,   126,   127,   128,   129,   130,     0,
   157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   131
};

static const short yycheck[] = {    68,
    65,   126,   127,   128,   129,   130,   131,    51,     1,   134,
     1,     1,    30,     1,     1,     1,    39,    25,     1,    61,
    62,    63,    64,     1,     1,     1,    39,    45,    41,     1,
    38,     3,     4,    39,    99,     3,     4,   102,    36,     7,
     8,     3,     4,    11,    37,    13,     1,    38,     5,     6,
    38,    44,    43,    97,    44,    42,    42,    40,     5,     1,
     0,    41,    40,    40,    40,    37,    38,     7,   193,   134,
   135,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,     1,    25,    43,    39,     3,     4,
     5,     6,     3,     4,    39,    10,    38,    12,    38,    14,
    20,     3,     4,     5,     6,    32,    33,    34,    10,    21,
    12,     5,    14,    28,    29,     1,    31,    22,    23,   188,
    35,   190,     1,    38,    39,     1,    28,    29,    43,    31,
    40,   200,     1,    35,     3,     4,    37,    39,    28,    29,
     1,    43,     3,     4,     5,     6,    30,    31,     5,    39,
     9,    41,     1,     0,     3,     4,     5,     6,     0,   115,
   116,     1,     7,     3,     4,     5,     6,    28,    29,    38,
    31,   121,   122,    12,    35,    11,    29,    38,    39,    28,
    29,    10,    31,    49,    59,   113,    35,    -1,    28,    29,
    39,    31,   114,    -1,    -1,    35,    -1,    -1,     1,    39,
     3,     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,
     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,
     5,     6,    -1,     7,     8,    28,    29,    11,    31,    13,
    -1,    -1,    35,    -1,    28,    29,    39,    31,    -1,    -1,
    -1,    35,    -1,    28,    29,    39,    31,    -1,    -1,    -1,
    35,    -1,    -1,     1,    39,     3,     4,     5,     6,    -1,
    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
    28,    29,    -1,    31,    -1,    -1,    -1,    35,    -1,    28,
    29,    39,    31,    -1,    -1,    -1,    35,    -1,    28,    29,
    39,    31,    -1,    -1,    -1,    35,    -1,    -1,     1,    39,
     3,     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,
     4,     5,     6,    -1,     3,     4,     5,     6,    24,    25,
    26,    27,    -1,     7,     8,    28,    29,    11,    31,    13,
    -1,    -1,    35,    -1,    28,    29,    39,    31,    -1,    28,
    29,    35,    31,    -1,    -1,    39,    35,    -1,    -1,    -1,
    39,    -1,    -1,    37,    15,    16,    17,    18,    19,    -1,
   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    36
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
				ReportError(wrong_st);
			;
    break;}
case 11:
#line 57 "parser.y"
{
				yyerrok;
				ReportError(wrong_funcdef);	/* error - wrong function definition */
			;
    break;}
case 13:
#line 65 "parser.y"
{
				yyerrok;
				ReportError(wrong_funcdef);
			;
    break;}
case 19:
#line 83 "parser.y"
{
				type_const = 1;
			;
    break;}
case 20:
#line 89 "parser.y"
{ 
				type_int = 1;	/* type : integer */
				type_void = 0;
				type_float = 0;
			;
    break;}
case 21:
#line 95 "parser.y"
{
				type_void = 1;	/* type : void */
				type_int = 0;
				type_float = 0;
			;
    break;}
case 22:
#line 101 "parser.y"
{
				type_float = 1;	/* type : float */
				type_void = 0;
				type_int = 0;
			;
    break;}
case 23:
#line 109 "parser.y"
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
case 26:
#line 130 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 31:
#line 143 "parser.y"
{
				yyerrok;
				ReportError(nocomma);
			;
    break;}
case 32:
#line 150 "parser.y"
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
			;
    break;}
case 34:
#line 169 "parser.y"
{
				yyerrok;
				ReportError(nobrace);
			;
    break;}
case 39:
#line 184 "parser.y"
{
				type_int = 0;
				type_void = 0;
				type_float = 0;
				type_const = 0;
			;
    break;}
case 40:
#line 191 "parser.y"
{
				yyerrok;
				type_int = 0;
				type_void = 0;
				type_float = 0;
				type_const = 0;
				ReportError(nosemi);
			;
    break;}
case 43:
#line 205 "parser.y"
{
				yyerrok;
				ReportError(nocomma);
			;
    break;}
case 48:
#line 216 "parser.y"
{
				yyerrok;
				ReportError(nobrace);
			;
    break;}
case 51:
#line 227 "parser.y"
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
case 52:
#line 240 "parser.y"
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
case 53:
#line 251 "parser.y"
{
				yyerrok;
				ReportError(nobracket);
			;
    break;}
case 67:
#line 280 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 72:
#line 293 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 74:
#line 301 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 76:
#line 309 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 77:
#line 314 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 86:
#line 331 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 87:
#line 336 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 88:
#line 341 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 89:
#line 346 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 90:
#line 351 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 91:
#line 356 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 94:
#line 365 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 97:
#line 374 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 101:
#line 384 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 102:
#line 389 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 122:
#line 423 "parser.y"
{
				yyerrok;
				ReportError(nobracket);
			;
    break;}
case 124:
#line 429 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 132:
#line 449 "parser.y"
{
				if(look_id->type == 0) {
					look_id->type = 10;	/* not defined */
				}
			;
    break;}
case 136:
#line 458 "parser.y"
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
#line 464 "parser.y"
