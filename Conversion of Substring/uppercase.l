#Conversion of abc to ABC
%{
#include <stdio.h>
#include <string.h>

char s[1000] = "";  
%}

%%

abc     { strcat(s, "ABC"); }        
.       { strncat(s, yytext, 1); }    

%%

int main()
{
    printf("Enter the String: ");
    yylex();  // Scan the input
    printf("The converted text: %s\n", s);
    return 0;
}

int yywrap() { return 1; }
