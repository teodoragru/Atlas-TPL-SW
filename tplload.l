%{
#include "tpl.tab.h"
#include <stdio.h>
#include <string.h>
%}

%option noyywrap
%option yylineno

%%

[\-\+]?[0-9]+  {
          yylval.ival=atoi(yytext);
          return NUM;
        }

0x[0-9abcdefABCDEF]+ {
          sscanf(yytext,"%x",&(yylval.ival));
          //yylval.ival=atoi(yytext);
          return NUM;
        }

[mM][oO][dD]						return MOD;
[aA][oO] 							return AO;
[dD][iI] 							return DI;
[dD][oO] 							return DO;
[aA][iI] 							return AI;
[tT][yY][pP][eE]					return TYPE;
[cC][hH][aA][nN][nN][eE][lL]        return CHANNEL; 
[aA][dD][dD][rR]  					return ADDR;
[lL][eE][dD][aA][dD][dD][rR]  		return LEDADDR;
[vV][rR][eE][fF]					return VREF; 
[iI][nN][iI][tT]['_'][vV][aA][lL]   return INIT_VAL; 
[=]                             	return EQ; 
\n   								{return CR;}
[{]    								return '{';
[}]   								return '}';


\"[^\"\n]+\"   {
                        strncpy(table+tab,yytext+1,yyleng-2);
                        table[tab+yyleng-2]=0;
                        yylval.sval=table+tab;
                        tab+=yyleng-1;
                        //fprintf(stderr,"string %s\n",yylval.sval);
                        return STRING;
                      }

\"
\t
[ ]

[#]   {while(input() != '\n');return CR;}
[,] return ',';

%%