#DESIGN AND IMPLEMENT A LEXICAL ANALYZER USING C LANGUAGE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
intisKeyword(char buffer[]){
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
inti, flag = 0;
for(i = 0; i< 32; ++i){
if(strcmp(keywords[i], buffer) == 0){
flag = 1;
break;
}
}
return flag;
}

int main(){
charch, buffer[15], operators[] = "+-*/%=";
FILE *fp;
inti,j=0;
fp = fopen("inp.txt","r");
if(fp == NULL){
printf("error while opening the file\n");
exit(0);
}
while((ch = fgetc(fp)) != EOF){
for(i = 0; i< 6; ++i){
if(ch == operators[i])
printf("%c is operator\n", ch);
   }
if(isalnum(ch)){
buffer[j++] = ch;
   }
else if((ch == ' ' || ch == '\n') && (j != 0)){
buffer[j] = '\0';
   j = 0;
if(isKeyword(buffer) == 1)
printf("%s is keyword\n", buffer);
else
printf("%s is an identifier\n", buffer);
   }  
}
fclose(fp);
return 0;
}
