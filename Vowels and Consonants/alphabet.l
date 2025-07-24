%{
#include <stdio.h>
#include <ctype.h>

int vow = 0;
int cons = 0;
%}

%%

[aeiouAEIOU] {
	vow++;
}

[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {
	cons++;
}

. {
}

\n {
	return 0;
}

%%

int main() {
	printf("Enter the String : ");
	yylex();
	printf("No of vowels : %d\n", vow);
	printf("No of consonants : %d\n", cons);
	return 0;
}

int yywrap() {
	return 1;
}
