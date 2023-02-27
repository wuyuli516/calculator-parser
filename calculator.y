%{
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
%}
 
%union { data num; bool boo; symrec* po;  }

%token <boo> SIGN
%token <num> INUM DNUM TRUE FALSE
%token <po> VAR  /* Symbol table pointer: variable */
%type  <num> expression orExpr andExpr eqExpr cmpExpr addExpr mulExpr uniExpr single
%right UMI
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%%
    line_list: line {output=1;}
             | line_list line {output=1;}
             ;
 
         line: expression '\n' {if(output) { printf(">>%g\n", $1.dnum); if(outputType){ printType($1.type,$1.dnum);}  if(outputSymbols){ printSymbols();}  }  }
             | error '\n' { printf(">>no matched rules\n"); output=1; yyerrok; }
             | SIGN '\n' {  yyerrok;}
             ;
 
   expression: orExpr {if(outputInduction&&output) printf("expression -> orExpr \n");}
             | VAR '=' expression %prec UMI  { if(outputInduction&&output) printf("expression -> VAR = expression \n"); ($$).dnum = ($3).dnum; ($$).type=($3).type; if(output) { $1->value = ($3).dnum; $1->type = ($3).type; $1->def=1;} }
             ;
    
	   orExpr: andExpr {if(outputInduction&&output) printf("orExpr -> andExpr \n");}
             | orExpr '|' '|' andExpr  {$$.dnum = $1.dnum || $4.dnum; $$.type=0; if(outputInduction&&output) printf("orExpr -> orExpr || andExpr \n");}
             ; 
             
      andExpr: eqExpr {if(outputInduction&&output) printf("andExpr -> eqExpr \n");}
             | andExpr '&' '&' eqExpr  {$$.dnum = $1.dnum && $4.dnum; $$.type=0; if(outputInduction&&output) printf("andExpr -> andExpr && eqExpr \n");}
             ;
			       
       eqExpr: cmpExpr {if(outputInduction&&output) printf("eqExpr -> cmpExpr \n");}
             | eqExpr '=''=' cmpExpr  {if($1.dnum==$4.dnum){$$.dnum=1; $$.type=0;} else{$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("eqExpr -> eqExpr == cmpExpr \n");}
             | eqExpr '!''=' cmpExpr  {if($1.dnum!=$4.dnum) {$$.dnum=1; $$.type=0;} else {$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("eqExpr -> eqExpr != cmpExpr \n"); }
             ;
             
      cmpExpr: addExpr {if(outputInduction&&output) printf("cmpExpr -> addExpr \n");}
             | cmpExpr '<' addExpr  {if($1.dnum<$3.dnum) {$$.dnum=1; $$.type=0;} else {$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr < addExpr \n");}
             | cmpExpr '<' '=' addExpr  {if($1.dnum<=$4.dnum) {$$.dnum=1; $$.type=0;} else {$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr <= addExpr \n");}
             | cmpExpr '>' addExpr  {if($1.dnum>$3.dnum) {$$.dnum=1; $$.type=0;} else {$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr > addExpr \n");}
             | cmpExpr '>' '=' addExpr  {if($1.dnum>=$4.dnum) {$$.dnum=1; $$.type=0;} else {$$.dnum=0; $$.type=0;} if(outputInduction&&output) printf("cmpExpr -> cmpExpr >= addExpr \n");}
             ;
             
      addExpr: mulExpr {if(outputInduction&&output) printf("addExpr -> mulExpr \n");}
             | addExpr '+' mulExpr  {$$.dnum = ($1).dnum + ($3).dnum; if($1.type==2 || $3.type ==2) $$.type=2; else $$.type=1; if(outputInduction&&output) printf("addExpr -> addExpr + mulExpr \n"); }
             | addExpr '-' mulExpr  {$$.dnum = ($1).dnum - ($3).dnum; if($1.type==2 || $3.type ==2) $$.type=2; else $$.type=1; if(outputInduction&&output) printf("addExpr -> addExpr - mulExpr \n");}
             ;
 
      mulExpr: uniExpr {if(outputInduction&&output) printf("mulExpr -> uniExpr \n");}
             | mulExpr '*' uniExpr       {$$.dnum = $1.dnum * $3.dnum; if($1.type==2 || $3.type ==2) $$.type=2; else $$.type=1;if(outputInduction&&output) printf("mulExpr -> mulExpr * uniExpr \n");}
             | mulExpr '/' uniExpr       {if($3.dnum!=0) {$$.dnum = (double)$1.dnum / $3.dnum;  if( !isInt($$.dnum)) $$.type=2; else $$.type=1; } else { $$.dnum=0; printf("error:division by zero\n"); output=0;} if(outputInduction&&output) printf("mulExpr -> mulExpr / uniExpr \n"); }
             | mulExpr '%' uniExpr       {if (isInt($1.dnum) && isInt($3.dnum) ) {$$.dnum = (int)$1.dnum % (int)$3.dnum; $$.type=1;} else {output=0; $$.dnum=0; printf("error:type error\n");  } if(outputInduction&&output) printf("mulExpr -> mulExpr % uniExpr \n"); }
             ;
 
      uniExpr: single {if(outputInduction&&output) printf("uniExpr -> single \n");}
             | '+' uniExpr %prec UMINUS       {$$.dnum = $2.dnum; $$.type=$2.type; if(outputInduction&&output) printf("uniExpr -> + uniExpr \n");}
             | '-' uniExpr %prec UMINUS       {$$.dnum = -$2.dnum; $$.type=$2.type; if(outputInduction&&output) printf("uniExpr -> - uniExpr \n");}
             | '!' uniExpr %prec UMINUS       {$$.dnum = !$2.dnum; $$.type=0; if(outputInduction&&output) printf("uniExpr -> ! uniExpr \n");} //require check
             | '(' expression ')' {$$.dnum = $2.dnum; $$.type=$2.type;}
             ;
       
	   single: DNUM  {$$.dnum = ($1).dnum; $$.type=($1).type; if(outputInduction&&output) printf("single -> DNUM \n");}
	         | INUM                 {$$.dnum = ($1).dnum; $$.type=($1).type; if(outputInduction&&output) printf("single -> INUM \n");}
             | VAR                  {if($1->def==0) { ($$).dnum=0; printf("error:undefined identifier %s \n",$1->name); output=0; }  else {$$.dnum = $1->value; $$.type=$1->type; } if(outputInduction&&output) printf("single -> VAR \n"); }
             | TRUE                 {$$.dnum = $1.dnum; $$.type=0; if(outputInduction&&output) printf("single -> TRUE \n");}
             | FALSE                {$$.dnum = $1.dnum; $$.type=0; if(outputInduction&&output) printf("single -> FALSE \n");}
             ;
%%
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

    if (c == EOF) return YYEOF; //读取结束 

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