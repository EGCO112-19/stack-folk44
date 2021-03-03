
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);
#endif

void push(StackPtr s, char value){
  Node *new_node=(Node *)malloc(sizeof(Node));
  if(new_node){
    new_node->data=value;
    new_node->nextPtr=s->top;
    s->top=new_node;
    (s->size)++;
  }
}

char pop(StackPtr s){
  char value;
  NodePtr t = s->top;
  if(t!=NULL){
    value=t->data;
    s->top = t->nextPtr;
    free(t);
    (s->size)--;}
  else value=0;
  return value;
}

void pop_all(StackPtr s){ //clear stack
  char value;
  NodePtr t = NULL;
  s->size=0;
  while(s->top){
    t=s->top;
    value=t->data;
    s->top = t->nextPtr;
    free(t);
    printf("Popping %c \n",value);
  };
}