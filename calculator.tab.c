
/*  A Bison parser, made from calculator.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	SIGN	257
#define	INUM	258
#define	DNUM	259
#define	TRUE	260
#define	FALSE	261
#define	VAR	262
#define	UMI	263
#define	UMINUS	264

#line 1 "calculator.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h> /* malloc, realloc. */
    int yylex(void);
    void yyerror(char *);
    void welcome(void);
    void outputHelp(void);
    void printType(int type, double value);
    void printSymbols(void);
    struct symrec
    {
	  	char *name;  /* name of symbol */
	  	double value;
	  	int type;
	 	struct symrec *next;  /* link field */
	 	bool def;
    };
    struct data{
    	double dnum;
    	int type; //0 bool 1 int 2 double
	}; 
	typedef struct data data;
    typedef struct symrec symrec;
    symrec *sym_table;
    symrec *putsym (char const *name);
    symrec *getsym (char const *name);
    bool isInt(double a);
    char tru[]="true";
    char fal[]="false";
    double tmp;
    bool output=1; //whether to output the result
    bool defaul=1;
	bool outputSymbols=0; //whether to output the symbols table
	bool outputType =0;  //whether to output the data type
	bool outputInduction = 0; //whether to output the induction process

#line 40 "calculator.y"
typedef union { data num; bool boo; symrec* po;  } YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		66
#define	YYFLAG		-32768
#define	YYNTBASE	25

#define YYTRANSLATE(x) ((unsigned)(x) <= 264 ? yytranslate[x] : 36)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    20,     2,     2,     2,    14,    19,     2,    23,
    24,    12,    10,     2,    11,     2,    13,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
    17,    22,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    18,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    15
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     8,    11,    14,    16,    20,    22,    27,
    29,    34,    36,    41,    46,    48,    52,    57,    61,    66,
    68,    72,    76,    78,    82,    86,    90,    92,    95,    98,
   101,   105,   107,   109,   111,   113
};

static const short yyrhs[] = {    26,
     0,    25,    26,     0,    27,    16,     0,     1,    16,     0,
     3,    16,     0,    28,     0,     8,    17,    27,     0,    29,
     0,    28,    18,    18,    29,     0,    30,     0,    29,    19,
    19,    30,     0,    31,     0,    30,    17,    17,    31,     0,
    30,    20,    17,    31,     0,    32,     0,    31,    21,    32,
     0,    31,    21,    17,    32,     0,    31,    22,    32,     0,
    31,    22,    17,    32,     0,    33,     0,    32,    10,    33,
     0,    32,    11,    33,     0,    34,     0,    33,    12,    34,
     0,    33,    13,    34,     0,    33,    14,    34,     0,    35,
     0,    10,    34,     0,    11,    34,     0,    20,    34,     0,
    23,    27,    24,     0,     5,     0,     4,     0,     8,     0,
     6,     0,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    51,    52,    55,    56,    57,    60,    61,    64,    65,    68,
    69,    72,    73,    74,    77,    78,    79,    80,    81,    84,
    85,    86,    89,    90,    91,    92,    95,    96,    97,    98,
    99,   102,   103,   104,   105,   106
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","SIGN","INUM",
"DNUM","TRUE","FALSE","VAR","UMI","'+'","'-'","'*'","'/'","'%'","UMINUS","'\\n'",
"'='","'|'","'&'","'!'","'<'","'>'","'('","')'","line_list","line","expression",
"orExpr","andExpr","eqExpr","cmpExpr","addExpr","mulExpr","uniExpr","single", NULL
};
#endif

static const short yyr1[] = {     0,
    25,    25,    26,    26,    26,    27,    27,    28,    28,    29,
    29,    30,    30,    30,    31,    31,    31,    31,    31,    32,
    32,    32,    33,    33,    33,    33,    34,    34,    34,    34,
    34,    35,    35,    35,    35,    35
};

static const short yyr2[] = {     0,
     1,     2,     2,     2,     2,     1,     3,     1,     4,     1,
     4,     1,     4,     4,     1,     3,     4,     3,     4,     1,
     3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
     3,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    33,    32,    35,    36,    34,     0,     0,     0,
     0,     0,     1,     0,     6,     8,    10,    12,    15,    20,
    23,    27,     4,     5,     0,    34,    28,    29,    30,     0,
     2,     3,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     7,    31,     0,     0,     0,     0,     0,
    16,     0,    18,    21,    22,    24,    25,    26,     9,    11,
    13,    14,    17,    19,     0,     0
};

static const short yydefgoto[] = {    12,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    22
};

static const short yypact[] = {    35,
    -4,     2,-32768,-32768,-32768,-32768,    12,    71,    71,    71,
    91,     3,-32768,    21,     9,    25,     0,    10,    11,    75,
-32768,-32768,-32768,-32768,    91,-32768,-32768,-32768,-32768,    28,
-32768,-32768,    41,    42,    45,    47,    43,    63,    71,    71,
    71,    71,    71,-32768,-32768,    71,    71,    71,    71,    71,
    11,    71,    11,    75,    75,-32768,-32768,-32768,    25,     0,
    10,    10,    11,    11,    65,-32768
};

static const short yypgoto[] = {-32768,
    60,    -6,-32768,    38,    46,   -24,   -22,    17,    -8,-32768
};


#define	YYLAST		114


static const short yytable[] = {    27,
    28,    29,    65,     1,    30,     2,     3,     4,     5,     6,
     7,    23,     8,     9,    51,    53,    35,    24,    44,    36,
    39,    40,    10,    61,    62,    11,    33,    63,    25,    64,
    37,    38,    56,    57,    58,     1,    32,     2,     3,     4,
     5,     6,     7,    34,     8,     9,     3,     4,     5,     6,
    26,    45,     8,     9,    10,    54,    55,    11,    46,    50,
    47,    48,    10,    49,    66,    11,     3,     4,     5,     6,
    26,    31,     8,     9,     3,     4,     5,     6,    26,    52,
     8,     9,    10,    59,     0,    11,    41,    42,    43,     0,
    10,     0,    60,    11,     3,     4,     5,     6,     7,     0,
     8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
    10,     0,     0,    11
};

static const short yycheck[] = {     8,
     9,    10,     0,     1,    11,     3,     4,     5,     6,     7,
     8,    16,    10,    11,    37,    38,    17,    16,    25,    20,
    10,    11,    20,    48,    49,    23,    18,    50,    17,    52,
    21,    22,    41,    42,    43,     1,    16,     3,     4,     5,
     6,     7,     8,    19,    10,    11,     4,     5,     6,     7,
     8,    24,    10,    11,    20,    39,    40,    23,    18,    17,
    19,    17,    20,    17,     0,    23,     4,     5,     6,     7,
     8,    12,    10,    11,     4,     5,     6,     7,     8,    17,
    10,    11,    20,    46,    -1,    23,    12,    13,    14,    -1,
    20,    -1,    47,    23,     4,     5,     6,     7,     8,    -1,
    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    20,    -1,    -1,    23
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
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

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
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
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
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
  int yyfree_stacks = 0;

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
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
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

case 1:
#line 51 "calculator.y"
{output=1;;
    break;}
case 2:
#line 52 "calculator.y"
{output=1;;
    break;}
case 3:
#line 55 "calculator.y"
{if(output) { printf(">>%g\n", yyvsp[-1].num.dnum); if(outputType){ printType(yyvsp[-1].num.type,yyvsp[-1].num.dnum);}  if(outputSymbols){ printSymbols();}  }  ;
    break;}
case 4:
#line 56 "calculator.y"
{ printf(">>no matched rules\n"); output=1; yyerrok; ;
    break;}
case 5:
#line 57 "calculator.y"
{  yyerrok;;
    break;}
case 6:
#line 60 "calculator.y"
{if(outputInduction&&output) printf("expression -> orExpr \n");;
    break;}
case 7:
#line 61 "calculator.y"
{ if(outputInduction&&output) printf("expression -> VAR = expression \n"); (yyval.num).dnum = (yyvsp[0].num).dnum; (yyval.num).type=(yyvsp[0].num).type; if(output) { yyvsp[-2].po->value = (yyvsp[0].num).dnum; yyvsp[-2].po->type = (yyvsp[0].num).type; yyvsp[-2].po->def=1;} ;
    break;}
case 8:
#line 64 "calculator.y"
{if(outputInduction&&output) printf("orExpr -> andExpr \n");;
    break;}
case 9:
#line 65 "calculator.y"
{yyval.num.dnum = yyvsp[-3].num.dnum || yyvsp[0].num.dnum; yyval.num.type=0; if(outputInduction&&output) printf("orExpr -> orExpr || andExpr \n");;
    break;}
case 10:
#line 68 "calculator.y"
{if(outputInduction&&output) printf("andExpr -> eqExpr \n");;
    break;}
case 11:
#line 69 "calculator.y"
{yyval.num.dnum = yyvsp[-3].num.dnum && yyvsp[0].num.dnum; yyval.num.type=0; if(outputInduction&&output) printf("andExpr -> andExpr && eqExpr \n");;
    break;}
case 12:
#line 72 "calculator.y"
{if(outputInduction&&output) printf("eqExpr -> cmpExpr \n");;
    break;}
case 13:
#line 73 "calculator.y"
{if(yyvsp[-3].num.dnum==yyvsp[0].num.dnum){yyval.num.dnum=1; yyval.num.type=0;} else{yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("eqExpr -> eqExpr == cmpExpr \n");;
    break;}
case 14:
#line 74 "calculator.y"
{if(yyvsp[-3].num.dnum!=yyvsp[0].num.dnum) {yyval.num.dnum=1; yyval.num.type=0;} else {yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("eqExpr -> eqExpr != cmpExpr \n"); ;
    break;}
case 15:
#line 77 "calculator.y"
{if(outputInduction&&output) printf("cmpExpr -> addExpr \n");;
    break;}
case 16:
#line 78 "calculator.y"
{if(yyvsp[-2].num.dnum<yyvsp[0].num.dnum) {yyval.num.dnum=1; yyval.num.type=0;} else {yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr < addExpr \n");;
    break;}
case 17:
#line 79 "calculator.y"
{if(yyvsp[-3].num.dnum<=yyvsp[0].num.dnum) {yyval.num.dnum=1; yyval.num.type=0;} else {yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr <= addExpr \n");;
    break;}
case 18:
#line 80 "calculator.y"
{if(yyvsp[-2].num.dnum>yyvsp[0].num.dnum) {yyval.num.dnum=1; yyval.num.type=0;} else {yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr > addExpr \n");;
    break;}
case 19:
#line 81 "calculator.y"
{if(yyvsp[-3].num.dnum>=yyvsp[0].num.dnum) {yyval.num.dnum=1; yyval.num.type=0;} else {yyval.num.dnum=0; yyval.num.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr >= addExpr \n");;
    break;}
case 20:
#line 84 "calculator.y"
{if(outputInduction&&output) printf("addExpr -> mulExpr \n");;
    break;}
case 21:
#line 85 "calculator.y"
{yyval.num.dnum = (yyvsp[-2].num).dnum + (yyvsp[0].num).dnum; if(yyvsp[-2].num.type==2 || yyvsp[0].num.type ==2) yyval.num.type=2; else yyval.num.type=1; if(outputInduction&&output) printf("addExpr -> addExpr + mulExpr \n"); ;
    break;}
case 22:
#line 86 "calculator.y"
{yyval.num.dnum = (yyvsp[-2].num).dnum - (yyvsp[0].num).dnum; if(yyvsp[-2].num.type==2 || yyvsp[0].num.type ==2) yyval.num.type=2; else yyval.num.type=1; if(outputInduction&&output) printf("addExpr -> addExpr - mulExpr \n");;
    break;}
case 23:
#line 89 "calculator.y"
{if(outputInduction&&output) printf("mulExpr -> uniExpr \n");;
    break;}
case 24:
#line 90 "calculator.y"
{yyval.num.dnum = yyvsp[-2].num.dnum * yyvsp[0].num.dnum; if(yyvsp[-2].num.type==2 || yyvsp[0].num.type ==2) yyval.num.type=2; else yyval.num.type=1;if(outputInduction&&output) printf("mulExpr -> mulExpr * uniExpr \n");;
    break;}
case 25:
#line 91 "calculator.y"
{if(yyvsp[0].num.dnum!=0) {yyval.num.dnum = (double)yyvsp[-2].num.dnum / yyvsp[0].num.dnum;  if( !isInt(yyval.num.dnum)) yyval.num.type=2; else yyval.num.type=1; } else { yyval.num.dnum=0; printf("error:division by zero\n"); output=0;} if(outputInduction&&output) printf("mulExpr -> mulExpr / uniExpr \n"); ;
    break;}
case 26:
#line 92 "calculator.y"
{if (isInt(yyvsp[-2].num.dnum) && isInt(yyvsp[0].num.dnum) ) {yyval.num.dnum = (int)yyvsp[-2].num.dnum % (int)yyvsp[0].num.dnum; yyval.num.type=1;} else {output=0; yyval.num.dnum=0; printf("error:type error\n");  } if(outputInduction&&output) printf("mulExpr -> mulExpr % uniExpr \n"); ;
    break;}
case 27:
#line 95 "calculator.y"
{if(outputInduction&&output) printf("uniExpr -> single \n");;
    break;}
case 28:
#line 96 "calculator.y"
{yyval.num.dnum = yyvsp[0].num.dnum; yyval.num.type=yyvsp[0].num.type; if(outputInduction&&output) printf("uniExpr -> + uniExpr \n");;
    break;}
case 29:
#line 97 "calculator.y"
{yyval.num.dnum = -yyvsp[0].num.dnum; yyval.num.type=yyvsp[0].num.type; if(outputInduction&&output) printf("uniExpr -> - uniExpr \n");;
    break;}
case 30:
#line 98 "calculator.y"
{yyval.num.dnum = !yyvsp[0].num.dnum; yyval.num.type=0; if(outputInduction&&output) printf("uniExpr -> ! uniExpr \n");;
    break;}
case 31:
#line 99 "calculator.y"
{yyval.num.dnum = yyvsp[-1].num.dnum; yyval.num.type=yyvsp[-1].num.type;;
    break;}
case 32:
#line 102 "calculator.y"
{yyval.num.dnum = (yyvsp[0].num).dnum; yyval.num.type=(yyvsp[0].num).type; if(outputInduction&&output) printf("single -> DNUM \n");;
    break;}
case 33:
#line 103 "calculator.y"
{yyval.num.dnum = (yyvsp[0].num).dnum; yyval.num.type=(yyvsp[0].num).type; if(outputInduction&&output) printf("single -> INUM \n");;
    break;}
case 34:
#line 104 "calculator.y"
{if(yyvsp[0].po->def==0) { (yyval.num).dnum=0; printf("error:undefined identifier %s \n",yyvsp[0].po->name); output=0; }  else {yyval.num.dnum = yyvsp[0].po->value; yyval.num.type=yyvsp[0].po->type; } if(outputInduction&&output) printf("single -> VAR \n"); ;
    break;}
case 35:
#line 105 "calculator.y"
{yyval.num.dnum = yyvsp[0].num.dnum; yyval.num.type=0; if(outputInduction&&output) printf("single -> TRUE \n");;
    break;}
case 36:
#line 106 "calculator.y"
{yyval.num.dnum = yyvsp[0].num.dnum; yyval.num.type=0; if(outputInduction&&output) printf("single -> FALSE \n");;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

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

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 108 "calculator.y"

void printType(int type, double value){
	if(type==0) {
		printf("[bool, %d]\n",(int)value);
	}
	else if(type==1){
		printf("[int,%d]\n",(int)value);
	}
	else if(type==2) {
		printf("[double,%g]\n",value);
	}
}
void printSymbols(void){
	int cnt=1;
	for (symrec *p = sym_table; p; p = p->next) {
		if(!(p->def)) continue; 
		printf("(%d) ",cnt);
		printf("name: %s |",p->name);  /* name of symbol */
		printf("type: "); // data type
		if(p->type==0) {
			printf("bool |");
			printf("value: %d ",(int)p->value);
		}
	  	else if(p->type==1) {
	  		printf("int |");
			printf("value: %d ",(int)p->value);
		}
	 	else {
	 		printf("double |");
			printf("value: %g ",p->value);
		 }
		 printf("\n");
		 cnt++;
	}
}
void yyerror(char *str) {
    fprintf(stderr, "error:%s\n", str);
}
 
int yywrap() {
    return 1;
}
 
symrec * putsym (char const *name){
  symrec *res = (symrec *) malloc (sizeof (symrec));
  res->name = strdup (name);
  res->value = 0.0;
  res->type = -1;
  res->next = sym_table;
  sym_table = res;
  return res;
}

symrec * getsym (char const *name)
{
  for (symrec *p = sym_table; p; p = p->next)
    if (strcmp (p->name, name) == 0)
      return p;
  return NULL;
}

bool isInt(double a){
	if(a - (int)a == 0) return 1;
	else return 0;
}

int main() {
	welcome();
    yyparse();
}
// division zero error
// mod
// key word
// data type match
// display 
void welcome() {
	printf("You can use '$help' to view how to configure your output format\n");
	printf("Enter your expression.(enter ## to quit.)\n");
}
void outputHelp() {
	printf("How to configure your output format.\n");
	printf("enter '$type' to view the data type and value of each expression.\n");
	printf("enter '$induction' to view the induction process.\n");
	printf("enter 'symbols' to view the symbols table.\n");
	printf("enter 'default' to view the value of each expression.\n");
	printf("enter '##' to quit.\n");
}
int yylex(){
    int c = getchar ();
	char str[15]; 
    /* Ignore white space, get first nonwhite character. */
    while (c == ' ' || c == '\t') c = getchar ();

    if (c == EOF) return YYEOF; //???????????? 

    /* Char starts a number => parse the number. */
    if (c == '.' || isdigit (c)){
      ungetc (c, stdin);
      if (scanf ("%lf", &tmp) != 1){
      	 printf("input error\n");
      	 abort ();
	  }
	  if(isInt(tmp)) {
	  	yylval.num.type=1;
	  	yylval.num.dnum=(int)tmp;
	  	return INUM;
	  }
	  else {
	  	yylval.num.dnum=tmp;
	  	yylval.num.type=2;
     	 return DNUM;
	  }
      
    }
    /* Char starts an identifier => read the name. */
    if (isalpha (c)){
      static ptrdiff_t bufsize = 0;
      static char *symbuf = 0;
      ptrdiff_t i = 0;
      do
        {
          /* If buffer is full, make it bigger. */
          if (bufsize <= i)
            {
              bufsize = 2 * bufsize + 40;
              symbuf = realloc (symbuf, (size_t) bufsize);
            }
          /* Add this character to the buffer. */
          symbuf[i++] = (char) c;
          /* Get another character. */
          c = getchar ();
        }
      while (isalnum (c));
	  
      ungetc (c, stdin);
      symbuf[i] = '\0';
	  if(strcmp(symbuf,tru)==0) {
	  	yylval.num.type=0;
	  	yylval.num.dnum=1;
	  	return TRUE;
	  }
	  if(strcmp(symbuf,fal)==0) {
	  	yylval.num.type=0;
	  	yylval.num.dnum=0;
	  	return FALSE;
	  }
      symrec *s = getsym (symbuf);
      if (!s) s = putsym (symbuf);
      yylval.po = s; 
      return VAR;
    }
	if(c=='$') {
		if(scanf ("%10s", str)!=1) {
			printf("input error\n");
		}
		else {
			if(strcmp(str,"default")==0) {
				outputSymbols=0; 
				outputType=0;  
				outputInduction=0; 
				defaul=1;
			}
			else if(strcmp(str,"symbols")==0) {
				outputSymbols=1;
				defaul=0;
			}
			else if(strcmp(str,"type")==0) {
				outputType=1;
				defaul=0;
			}
			else if(strcmp(str,"induction")==0) {
				outputInduction=1;
				defaul=0;
			}
			else if(strcmp(str,"help")==0) {
				outputHelp();
			}
			else {
				printf("input error\n");
			}
		}
		while(1) {
			c=getchar();
			if(c=='\n') {
				ungetc (c, stdin);
				return SIGN;
			}
		}
	}	
	if(c=='#') {
		c=getchar();
		if(c=='#') {
			printf("quit\n");
			system("pause");
			exit(0);
		}
		else {
			printf("input error\n");
			while(1) {
				if(c=='\n') {
					ungetc (c, stdin);
					return SIGN;
				}
				c=getchar();
			}
		}
	}
  /* Any other character is a token by itself. */
  return c;
}