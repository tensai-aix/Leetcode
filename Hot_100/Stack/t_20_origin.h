#include <string.h>
#include <malloc.h>

typedef struct{
    char* c;
    int length;
}Stack;
void push(Stack* stack,char c){
    stack->c[stack->length++] = c;
}
char pop(Stack* stack){
    return stack->c[--stack->length];
}
bool isValid(char* s) {
    Stack stack = { .length = 0};
    int s_length = strlen(s);
    stack.c = (char* ) malloc ((s_length + 1) * sizeof(char));
    for(int i=0;i<s_length;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(&stack,s[i]);
        }
        else{
            if(!stack.length) return false;
            switch(pop(&stack)){
                case '(' :{
                    if (s[i] != ')') return false;
                    break;
                }
                case '[' :{
                    if (s[i] != ']') return false;
                    break;
                }
                case '{' :{
                    if (s[i] != '}') return false;
                }
            }
        }
    }
    if(stack.length > 0) return false;
    return true;
}