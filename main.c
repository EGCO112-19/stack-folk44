#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  
  Stack s;
  s.size=0;
  s.top=NULL;

  for(i=1;i<argc;i++){ //
    N=0;//use to check conditions
    for(j=0;j<strlen(argv[i]);j++){
      switch (argv[i][j]){
        case '{' :{
          push(&s,'{');
        };break;
         
         case '}' :{
          if(pop(&s)!='{')
            N=1;
        };break;
        
        case '[' :{
          push(&s, '[');
        };break;
         
        case ']' :{
          if(pop(&s)!='[')
            N=1;
        };break;
      }
      if(N==1) break;
    }

    if(N==1||s.size!=0)
      printf("The paratheses do not match for %s \n",argv[i]);
    else
      printf("The paratheses match successfully for %s \n",argv[i]);
    
    pop_all(&s);
  }
  return 0;
}
