%{
#include <fcntl.h> 
#include "tpl.h"
#include <stdio.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char yystring;
void yyerror(const char *s);

// konfiguracija dac-a
//struct dac_config {
//    int channel;
//    int addr;
//    int ledaddr;
//    int vref;
//    int init_val;
//};

struct dac_config dac = {-1, -1, -1, 2500, 0};
%}

%union {
    int ival;
}

%token MOD AO DI DO AI TYPE CHANNEL ADDR LEDADDR VREF INIT_VAL EQ COMMA CR
%token <ival> NUM
%token <sval> STRING

%%

cfg_file: dac_block
        ;

dac_block: MOD AO header O_BRACE body C_BRACE
         ;
		 
		 
		 
%%		 
cmdlist: cmd
  | cmdlist cmd
  ;

cmd :cmodcmd
    |impmodcmd
    |impfmodcmd
    |CR
    ;

cmodcmd:cmodhdr '{' coutlist '}'
    {
      struct mrcldiinfo *pinfo;
      pinfo=cfg->infos_di;

      
      *pinfo=minfo_di;
    }
    ;

coutlist: cout
    | coutlist cout
    ;

cout:
    CR
    |
    ;

cmodhdr: MOD DI constarglist CR
    ;

constarglist: constarg
    | constarglist ',' constarg
    ;
	
constarg: 
    SAMPLE EQ NUM
    {
      minfo_di.sample=$3;
    }
    | ADDR EQ NUM
    {
      minfo_di.addr=$3;
    }
    | DPI_ADDR EQ NUM
    {
      minfo_di.dpi_addr=$3;
    }
    | ERR_ADR EQ NUM
    {
      minfo_di.err_adr=$3;
    }
    | ERR_P_ADDR EQ NUM
    {
      minfo_di.err_p_addr=$3;
    }
    | LEDADDR EQ NUM
    {
      minfo_di.led_addr=$3;
    }
    | LEDADDRSTAT EQ NUM
    {
      minfo_di.led_addr_stat=$3;
    }
    | STATUSADDR EQ NUM
    {
      minfo_di.statusaddr=$3;
    }
    ;
	
	
	
	

%%

int yyerror(char *s)
{
  fprintf(stderr,"tplload ln %d: %s\n",yylineno,s);
  return 0;
}


int mrclparse(struct mrclcfg* p)
{
  int res;
  //
  cfg=p;
  memset((void*)cfg,0,sizeof(struct mrclcfg));

  yyout=fopen("/dev/null","w");

  res=yyparse();

  fclose(yyout);

  return res;
}
