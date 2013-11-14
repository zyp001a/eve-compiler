  /* This scanner prints "//" comments. */
     
%option reentrant stack noyywrap

     
%%
     
$[a-zA-Z_][0-9a-zA-Z_]* {fprintf(yyout, "%s\n", yytest);}
     
%%
     
         int main ( int argc, char * argv[] )
         {
             yyscan_t scanner;
     
             yylex_init ( &scanner );
             yylex ( scanner );
             yylex_destroy ( scanner );
         return 0;
        }
