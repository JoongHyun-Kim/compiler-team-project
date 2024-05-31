
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
int type_param = 0;

extern yylex();
extern ReportError();
extern yyerror(s);
extern char *yytext;

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



#define	YYFINAL		216
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 93)

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
    77,    81,    84,    86,    90,    95,   100,   102,   103,   105,
   108,   112,   116,   118,   122,   126,   128,   132,   136,   142,
   148,   150,   154,   156,   161,   165,   170,   172,   174,   175,
   177,   178,   180,   183,   185,   187,   189,   191,   193,   196,
   199,   201,   202,   208,   216,   221,   227,   232,   236,   240,
   243,   245,   247,   251,   255,   259,   263,   267,   271,   275,
   279,   283,   287,   291,   295,   297,   301,   305,   307,   311,
   315,   317,   321,   325,   329,   333,   335,   339,   343,   347,
   351,   355,   359,   363,   367,   369,   373,   377,   381,   385,
   387,   391,   395,   399,   403,   407,   411,   413,   416,   419,
   422,   425,   427,   432,   437,   442,   447,   450,   453,   455,
   456,   458,   460,   464,   466,   468,   470,   474,   478
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    65,     0,
     4,    38,     0,     4,     1,     0,     3,     0,    50,    62,
     0,    50,    38,     0,    50,     1,     0,    51,    56,    57,
     0,     4,    56,    57,     1,     0,    52,     0,    53,     0,
    52,    53,     0,    54,     0,    55,     0,     8,     0,    11,
     0,    13,     0,     7,     0,     4,     0,     3,     0,    39,
    58,    40,     0,    39,    58,     1,     0,    59,     0,     0,
    60,     0,    59,    37,    60,     0,    59,    60,     1,     0,
    51,    61,     0,     4,     0,     4,    41,    42,     0,    43,
    63,    71,    44,     0,    43,    63,    71,     1,     0,    64,
     0,     0,    65,     0,    64,    65,     0,    51,    66,    38,
     0,    51,    66,     1,     0,    67,     0,    66,    37,    67,
     0,    66,    67,     1,     0,    69,     0,    69,    36,     5,
     0,    69,    36,     6,     0,    69,    36,    43,    68,    44,
     0,    69,    36,    43,    68,     1,     0,     5,     0,    68,
    37,     5,     0,     4,     0,     4,    41,    70,    42,     0,
     4,    41,    42,     0,     4,    41,    70,     1,     0,     3,
     0,     5,     0,     0,    72,     0,     0,    73,     0,    72,
    73,     0,    62,     0,    74,     0,    76,     0,    77,     0,
    78,     0,    75,    38,     0,    75,     1,     0,    79,     0,
     0,    10,    39,    79,    40,    73,     0,    10,    39,    79,
    40,    73,     9,    73,     0,    10,    39,    79,     1,     0,
    14,    39,    79,    40,    73,     0,    14,    39,    79,     1,
     0,    12,    75,    38,     0,    12,    75,     1,     0,    12,
     1,     0,    80,     0,    81,     0,    87,    36,    80,     0,
    87,    36,     1,     0,    87,    15,    80,     0,    87,    15,
     1,     0,    87,    16,    80,     0,    87,    16,     1,     0,
    87,    17,    80,     0,    87,    17,     1,     0,    87,    18,
    80,     0,    87,    18,     1,     0,    87,    19,    80,     0,
    87,    19,     1,     0,    82,     0,    81,    20,    82,     0,
    81,    20,     1,     0,    83,     0,    82,    21,    83,     0,
    82,    21,     1,     0,    84,     0,    83,    22,    84,     0,
    83,    22,     1,     0,    83,    23,    84,     0,    83,    23,
     1,     0,    85,     0,    84,    24,    85,     0,    84,    24,
     1,     0,    84,    25,    85,     0,    84,    25,     1,     0,
    84,    26,    85,     0,    84,    26,     1,     0,    84,    27,
    85,     0,    84,    27,     1,     0,    86,     0,    85,    30,
    86,     0,    85,    30,     1,     0,    85,    31,    86,     0,
    85,    31,     1,     0,    87,     0,    86,    32,    87,     0,
    86,    32,     1,     0,    86,    33,    87,     0,    86,    33,
     1,     0,    86,    34,    87,     0,    86,    34,     1,     0,
    88,     0,    31,    87,     0,    35,    87,     0,    28,    87,
     0,    29,    87,     0,    92,     0,    88,    41,    79,    42,
     0,    88,    41,    79,     1,     0,    88,    39,    89,    40,
     0,    88,    39,    89,     1,     0,    88,    28,     0,    88,
    29,     0,    90,     0,     0,    91,     0,    80,     0,    91,
    37,    80,     0,     4,     0,     5,     0,     6,     0,    39,
    79,    40,     0,    39,    79,     1,     0,     3,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    38,    41,    42,    45,    46,    47,    48,    53,    56,    57,
    58,    65,    66,    73,    76,    77,    80,    81,    84,    90,
    96,   102,   110,   130,   133,   134,   141,   142,   145,   146,
   147,   154,   157,   168,   181,   182,   189,   190,   193,   194,
   197,   205,   218,   219,   220,   227,   228,   229,   230,   231,
   238,   239,   242,   263,   282,   301,   306,   310,   311,   314,
   315,   318,   319,   322,   323,   324,   325,   326,   329,   330,
   337,   338,   341,   342,   343,   350,   351,   358,   359,   364,
   371,   374,   375,   376,   381,   382,   387,   388,   393,   394,
   399,   400,   405,   406,   413,   414,   415,   422,   423,   424,
   431,   432,   433,   438,   439,   446,   447,   448,   453,   454,
   459,   460,   465,   466,   473,   474,   475,   480,   481,   488,
   489,   490,   495,   496,   501,   502,   509,   510,   511,   512,
   513,   516,   517,   518,   523,   524,   529,   530,   533,   534,
   537,   540,   541,   544,   551,   552,   553,   554,   559
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
"param_dcl","param_declarator","compound_st","opt_dcl_list","declaration_list",
"declaration","init_dcl_list","init_declarator","init_list","declarator","opt_number",
"opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    48,    48,    48,    49,    49,
    49,    50,    50,    51,    52,    52,    53,    53,    54,    55,
    55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
    59,    60,    61,    61,    62,    62,    63,    63,    64,    64,
    65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
    68,    68,    69,    69,    69,    69,    69,    70,    70,    71,
    71,    72,    72,    73,    73,    73,    73,    73,    74,    74,
    75,    75,    76,    76,    76,    77,    77,    78,    78,    78,
    79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    80,    80,    81,    81,    81,    82,    82,    82,
    83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
    84,    84,    84,    84,    85,    85,    85,    85,    85,    86,
    86,    86,    86,    86,    86,    86,    87,    87,    87,    87,
    87,    88,    88,    88,    88,    88,    88,    88,    89,    89,
    90,    91,    91,    92,    92,    92,    92,    92,    92
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     1,     2,     2,
     2,     3,     4,     1,     1,     2,     1,     1,     1,     1,
     1,     1,     1,     1,     3,     3,     1,     0,     1,     3,
     3,     2,     1,     3,     4,     4,     1,     0,     1,     2,
     3,     3,     1,     3,     3,     1,     3,     3,     5,     5,
     1,     3,     1,     4,     3,     4,     1,     1,     0,     1,
     0,     1,     2,     1,     1,     1,     1,     1,     2,     2,
     1,     0,     5,     7,     4,     5,     4,     3,     3,     2,
     1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     1,     2,     2,     2,
     2,     1,     4,     4,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     1,     3,     3,     1
};

static const short yydefact[] = {     0,
     8,     0,    22,    19,    20,    21,     1,     2,     4,     0,
     0,    14,    15,    17,    18,     5,     7,    24,    23,     6,
     0,     3,    11,    10,    38,     9,    57,    53,     0,     0,
    43,    46,    16,    28,     0,     0,    61,    37,    39,    59,
    12,    42,    57,    53,     0,    41,     0,     0,     0,     0,
    27,    29,    13,   149,   144,   145,   146,     0,     0,     0,
     0,     0,     0,     0,     0,    64,     0,    60,    62,    65,
     0,    66,    67,    68,    71,    81,    82,    95,    98,   101,
   106,   115,   120,   127,   132,    40,    58,    55,     0,    44,
    45,    47,    48,     0,    33,    32,    26,    25,     0,     0,
     0,    80,     0,     0,   130,   131,   128,   129,     0,    36,
    35,    63,    70,    69,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   137,   138,   140,     0,    56,    54,    51,
     0,     0,    30,    31,     0,    79,    78,     0,   148,   147,
    97,    96,   120,   100,    99,   103,   102,   105,   104,   108,
   107,   110,   109,   112,   111,   114,   113,   117,   116,   119,
   118,   122,   121,   124,   123,   126,   125,    86,    85,    88,
    87,    90,    89,    92,    91,    94,    93,    84,    83,   142,
     0,   139,   141,     0,    50,     0,    49,    34,    75,    72,
    77,    72,   136,   135,     0,   134,   133,    52,    73,    76,
   143,    72,    74,     0,     0,     0
};

static const short yydefgoto[] = {   214,
     7,     8,     9,    10,    49,    12,    13,    14,    15,    21,
    35,    50,    51,    52,    96,    66,    37,    38,    16,    30,
    31,   141,    32,    89,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,   191,   192,   193,    85
};

static const short yypact[] = {   514,
-32768,   110,-32768,-32768,-32768,-32768,   514,-32768,-32768,    16,
   127,    28,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   -14,-32768,-32768,-32768,    28,-32768,    -2,     1,   -14,   142,
-32768,    65,-32768,    28,    51,   138,    77,    28,-32768,    46,
-32768,-32768,-32768,    62,   138,-32768,   106,    43,   105,    15,
   486,-32768,-32768,-32768,-32768,-32768,-32768,    78,   134,    83,
   481,   481,   481,   481,   481,-32768,    14,    77,-32768,-32768,
    52,-32768,-32768,-32768,-32768,-32768,   104,   136,    75,   464,
   123,    94,    11,    -7,-32768,-32768,-32768,-32768,    18,-32768,
-32768,-32768,-32768,   150,   135,-32768,-32768,-32768,    28,   163,
   481,-32768,    98,   481,-32768,-32768,-32768,-32768,    22,-32768,
-32768,-32768,-32768,-32768,   146,   155,   192,   201,   210,   247,
   256,   265,   302,   311,   320,   357,   366,   375,   412,   421,
   430,   467,   476,-32768,-32768,   481,   481,-32768,-32768,-32768,
    13,   126,-32768,-32768,    23,-32768,-32768,    37,-32768,-32768,
-32768,   136,-32768,-32768,    75,-32768,   464,-32768,   464,-32768,
   123,-32768,   123,-32768,   123,-32768,   123,-32768,    94,-32768,
    94,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    44,-32768,   141,    19,-32768,   177,-32768,-32768,-32768,    90,
-32768,    90,-32768,-32768,   481,-32768,-32768,-32768,   178,-32768,
-32768,    90,-32768,   188,   189,-32768
};

static const short yypgoto[] = {-32768,
-32768,   184,-32768,-32768,    85,-32768,   180,-32768,-32768,   190,
   170,-32768,-32768,   -43,-32768,   193,-32768,-32768,     6,-32768,
   -12,-32768,-32768,-32768,-32768,-32768,   -68,-32768,   149,-32768,
-32768,-32768,   -58,  -127,-32768,    95,    84,    49,   409,    47,
   -51,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		531


static const short yytable[] = {   112,
   179,   181,   183,   185,   187,   189,   109,   100,   190,   105,
   106,   107,   108,   195,   110,    97,    23,    47,   138,   206,
   134,   135,   149,   199,    34,   128,   129,   130,   131,   132,
    39,   136,    90,   137,     3,     4,   -24,   201,     5,   -23,
     6,    40,   145,    86,   203,   148,   133,    92,    93,   196,
    87,    53,   113,    24,    98,   143,   197,   111,    25,   139,
   207,   150,   200,   153,   153,   153,   153,   153,   153,   153,
   153,   153,   153,   173,   175,   177,   202,   211,   194,    54,
    55,    56,    57,   204,    11,    94,    58,    88,    59,   114,
    60,    11,    54,    55,    56,    57,   117,   118,   146,    58,
    48,    59,    40,    60,    61,    62,    91,    63,    95,    36,
    17,    64,    18,    19,   -72,    65,   101,    61,    62,    25,
    63,   104,    36,   115,    64,   125,   126,   127,    65,    27,
    28,   209,    25,   210,   102,   147,    54,    55,    56,    57,
    43,    44,    42,   213,    43,    44,   151,    20,    54,    55,
    56,    57,   123,   124,   140,   154,   116,    54,    55,    56,
    57,    61,    62,   144,    63,   157,   159,   198,    64,   169,
   171,   -72,    65,    61,    62,   142,    63,   205,    45,    46,
    64,   208,    61,    62,    65,    63,   212,   215,   216,    64,
    22,    33,   156,    65,    54,    55,    56,    57,    41,   155,
    29,   158,    26,    54,    55,    56,    57,   103,     0,   152,
   160,     0,    54,    55,    56,    57,     0,     0,     0,    61,
    62,     0,    63,     0,     0,     0,    64,     0,    61,    62,
    65,    63,     0,     0,     0,    64,     0,    61,    62,    65,
    63,     0,     0,     0,    64,     0,     0,   162,    65,    54,
    55,    56,    57,     0,     0,     0,   164,     0,    54,    55,
    56,    57,     0,     0,     0,   166,     0,    54,    55,    56,
    57,     0,     0,     0,    61,    62,     0,    63,     0,     0,
     0,    64,     0,    61,    62,    65,    63,     0,     0,     0,
    64,     0,    61,    62,    65,    63,     0,     0,     0,    64,
     0,     0,   168,    65,    54,    55,    56,    57,     0,     0,
     0,   170,     0,    54,    55,    56,    57,     0,     0,     0,
   172,     0,    54,    55,    56,    57,     0,     0,     0,    61,
    62,     0,    63,     0,     0,     0,    64,     0,    61,    62,
    65,    63,     0,     0,     0,    64,     0,    61,    62,    65,
    63,     0,     0,     0,    64,     0,     0,   174,    65,    54,
    55,    56,    57,     0,     0,     0,   176,     0,    54,    55,
    56,    57,     0,     0,     0,   178,     0,    54,    55,    56,
    57,     0,     0,     0,    61,    62,     0,    63,     0,     0,
     0,    64,     0,    61,    62,    65,    63,     0,     0,     0,
    64,     0,    61,    62,    65,    63,     0,     0,     0,    64,
     0,     0,   180,    65,    54,    55,    56,    57,     0,     0,
     0,   182,     0,    54,    55,    56,    57,     0,     0,     0,
   184,     0,    54,    55,    56,    57,     0,     0,     0,    61,
    62,     0,    63,     0,     0,     0,    64,     0,    61,    62,
    65,    63,     0,     0,     0,    64,     0,    61,    62,    65,
    63,     0,     0,     0,    64,     0,     0,   186,    65,    54,
    55,    56,    57,     0,     0,     0,   188,     0,    54,    55,
    56,    57,     0,    54,    55,    56,    57,   119,   120,   121,
   122,     0,     3,     4,    61,    62,     5,    63,     6,     0,
     0,    64,     0,    61,    62,    65,    63,     0,    61,    62,
    64,    63,     0,     0,    65,    64,     1,     2,     0,    65,
     3,     4,    99,     0,     5,     0,     6,   161,   163,   165,
   167
};

static const short yycheck[] = {    68,
   128,   129,   130,   131,   132,   133,    65,    51,   136,    61,
    62,    63,    64,     1,     1,     1,     1,    30,     1,     1,
    28,    29,     1,     1,    39,    15,    16,    17,    18,    19,
    25,    39,    45,    41,     7,     8,    39,     1,    11,    39,
    13,    41,   101,    38,     1,   104,    36,     5,     6,    37,
     5,     1,     1,    38,    40,    99,    44,    44,    43,    42,
    42,    40,    40,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,    40,   205,   137,     3,
     4,     5,     6,    40,     0,    43,    10,    42,    12,    38,
    14,     7,     3,     4,     5,     6,    22,    23,     1,    10,
    36,    12,    41,    14,    28,    29,     1,    31,     4,    25,
     1,    35,     3,     4,    38,    39,    39,    28,    29,    43,
    31,    39,    38,    20,    35,    32,    33,    34,    39,     3,
     4,   200,    43,   202,     1,    38,     3,     4,     5,     6,
     3,     4,     1,   212,     3,     4,     1,    38,     3,     4,
     5,     6,    30,    31,     5,     1,    21,     3,     4,     5,
     6,    28,    29,     1,    31,   117,   118,    42,    35,   123,
   124,    38,    39,    28,    29,    41,    31,    37,    37,    38,
    35,     5,    28,    29,    39,    31,     9,     0,     0,    35,
     7,    12,     1,    39,     3,     4,     5,     6,    29,   116,
    11,     1,    10,     3,     4,     5,     6,    59,    -1,   115,
     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    28,
    29,    -1,    31,    -1,    -1,    -1,    35,    -1,    28,    29,
    39,    31,    -1,    -1,    -1,    35,    -1,    28,    29,    39,
    31,    -1,    -1,    -1,    35,    -1,    -1,     1,    39,     3,
     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,
     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
     6,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,
    -1,    35,    -1,    28,    29,    39,    31,    -1,    -1,    -1,
    35,    -1,    28,    29,    39,    31,    -1,    -1,    -1,    35,
    -1,    -1,     1,    39,     3,     4,     5,     6,    -1,    -1,
    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    28,
    29,    -1,    31,    -1,    -1,    -1,    35,    -1,    28,    29,
    39,    31,    -1,    -1,    -1,    35,    -1,    28,    29,    39,
    31,    -1,    -1,    -1,    35,    -1,    -1,     1,    39,     3,
     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,
     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
     6,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,
    -1,    35,    -1,    28,    29,    39,    31,    -1,    -1,    -1,
    35,    -1,    28,    29,    39,    31,    -1,    -1,    -1,    35,
    -1,    -1,     1,    39,     3,     4,     5,     6,    -1,    -1,
    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    28,
    29,    -1,    31,    -1,    -1,    -1,    35,    -1,    28,    29,
    39,    31,    -1,    -1,    -1,    35,    -1,    28,    29,    39,
    31,    -1,    -1,    -1,    35,    -1,    -1,     1,    39,     3,
     4,     5,     6,    -1,    -1,    -1,     1,    -1,     3,     4,
     5,     6,    -1,     3,     4,     5,     6,    24,    25,    26,
    27,    -1,     7,     8,    28,    29,    11,    31,    13,    -1,
    -1,    35,    -1,    28,    29,    39,    31,    -1,    28,    29,
    35,    31,    -1,    -1,    39,    35,     3,     4,    -1,    39,
     7,     8,    37,    -1,    11,    -1,    13,   119,   120,   121,
   122
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
#line 49 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 11:
#line 59 "parser.y"
{
				yyerrok;
				ReportError(wrong_funcdef);	/* error - wrong function definition */
			;
    break;}
case 13:
#line 67 "parser.y"
{
				yyerrok;
				ReportError(wrong_funcdef);
			;
    break;}
case 19:
#line 85 "parser.y"
{
				type_const = 1;    /* type : const */
			;
    break;}
case 20:
#line 91 "parser.y"
{ 
				type_int = 1;	/* type : integer */
				type_void = 0;
				type_float = 0;
			;
    break;}
case 21:
#line 97 "parser.y"
{
				type_void = 1;	/* type : void */
				type_int = 0;
				type_float = 0;
			;
    break;}
case 22:
#line 103 "parser.y"
{
				type_float = 1;	/* type : float */
				type_void = 0;
				type_int = 0;
			;
    break;}
case 23:
#line 111 "parser.y"
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
			;
    break;}
case 26:
#line 135 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 31:
#line 148 "parser.y"
{
				yyerrok;
				ReportError(nocomma);
			;
    break;}
case 33:
#line 158 "parser.y"
{
				if(look_id->type == 0){
					if(type_int == 1) {
						look_id->type = 11;	/* integer scalar param */
					} else if(type_float == 1) {
						look_id->type = 12;	/* float scalar param */
					}
				}
				look_tmp = look_id;
			;
    break;}
case 34:
#line 169 "parser.y"
{
				if(look_id->type == 0){
					if(type_int == 1) {
						look_id->type = 13;	/* integer array param */
					} else if(type_float == 1) {
						look_id->type = 14;	/* float array param */
					}
				}
				look_tmp = look_id;
			;
    break;}
case 36:
#line 183 "parser.y"
{
				yyerrok;
				ReportError(nobrace);
			;
    break;}
case 41:
#line 198 "parser.y"
{
				type_int = 0;
				type_void = 0;
				type_float = 0;
				type_const = 0;
				type_param = 0;
			;
    break;}
case 42:
#line 206 "parser.y"
{
				yyerrok;
				type_int = 0;
				type_void = 0;
				type_float = 0;
				type_const = 0;
				type_param = 0;
				ReportError(nosemi);
			;
    break;}
case 45:
#line 221 "parser.y"
{
				yyerrok;
				ReportError(nocomma);
			;
    break;}
case 50:
#line 232 "parser.y"
{
				yyerrok;
				ReportError(nobrace);
			;
    break;}
case 53:
#line 243 "parser.y"
{
				if(look_id->type == 0){
					if(type_const == 0) {
						if(type_int == 1) {
							look_id->type = 1;	/* int scalar var */
						} else if(type_void == 1) {
							look_id->type = 2;	/* void scalar var */
						} else if(type_float == 1) {
							look_id->type = 3;	/* float scalar var */
						}
					} else if(type_const == 1) {
						if(type_int == 1) {
							look_id->type = 17;	/* integer scalar constant */
						} else if(type_float == 1) {
							look_id->type = 18;	/* float scalar constant */
						}
					}
				}
				look_tmp = look_id;
			;
    break;}
case 54:
#line 264 "parser.y"
{
				if(look_id->type == 0){
					if(type_const == 0) {
						if(type_int == 1) {
							look_id->type = 4;	/* integer array var */
						} else if(type_float == 1) {
							look_id->type = 5;	/* float array var*/
						}
					} else if(type_const == 1) {
						if(type_int == 1) {
							look_id->type = 15;	/* integer array constant */
						} else if(type_float == 1) {
							look_id->type = 16;	/* float array constant */
						}
					}
				}
				look_tmp = look_id;
			;
    break;}
case 55:
#line 283 "parser.y"
{
				if(look_id->type == 0){
					if(type_const == 0) {
						if(type_int == 1) {
							look_id->type = 4;	/* integer array var */
						} else if(type_float == 1) {
							look_id->type = 5;	/* float array var*/
						}
					} else if(type_const == 1) {
						if(type_int == 1) {
							look_id->type = 15;	/* integer array constant */
						} else if(type_float == 1) {
							look_id->type = 16;	/* float array constant */
						}
					}
				}
				look_tmp = look_id;
			;
    break;}
case 56:
#line 302 "parser.y"
{
				yyerrok;
				ReportError(nobracket);
			;
    break;}
case 70:
#line 331 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 75:
#line 344 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 77:
#line 352 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 79:
#line 360 "parser.y"
{
				yyerrok;
				ReportError(nosemi);
			;
    break;}
case 80:
#line 365 "parser.y"
{
				yyerrok;
				ReportError(wrong_st);
			;
    break;}
case 84:
#line 377 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 86:
#line 383 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 88:
#line 389 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 90:
#line 395 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 92:
#line 401 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 94:
#line 407 "parser.y"
{
				yyerrok;
				ReportError(wrong_assign);
			;
    break;}
case 97:
#line 416 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 100:
#line 425 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 103:
#line 434 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 105:
#line 440 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 108:
#line 449 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 110:
#line 455 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 112:
#line 461 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 114:
#line 467 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 117:
#line 476 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 119:
#line 482 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 122:
#line 491 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 124:
#line 497 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 126:
#line 503 "parser.y"
{
				yyerrok;
				ReportError(nooperand);
			;
    break;}
case 134:
#line 519 "parser.y"
{
				yyerrok;
				ReportError(nobracket);
			;
    break;}
case 136:
#line 525 "parser.y"
{
				yyerrok;
				ReportError(noparen);
			;
    break;}
case 144:
#line 545 "parser.y"
{
				/* identifeir가 정의되지 않은 경우를 처리 */
				if(look_id->type == 0) {
					look_id->type = 10;	/* not defined */
				}
			;
    break;}
case 148:
#line 555 "parser.y"
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
#line 561 "parser.y"
