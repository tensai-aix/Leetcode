#include <string.h>
#include <malloc.h>

typedef struct{
    char c[30010];
    int top;
}Stack;
void push(Stack* stack,char c){
    stack->c[stack->top++] = c;
}
char top(Stack stack){
    return stack.c[stack.top - 1];
}
void pop(Stack* stack){
    stack->top--;
}
char* decodeString(char* s) {
    Stack stack = {.top = 0};
    char to_insert[30000];
    int s_length = strlen(s);
    for(int i=0;i<s_length;i++){
        if(s[i] == ']'){
            char to_inseert_length = 0;
            while(top(stack)!='['){
                to_insert[to_inseert_length++] = top(stack);
                pop(&stack);
            }
            pop(&stack);
            int loop_time = 0;
            int grade = 1;
            while(top(stack) <= '9' && top(stack) >= '0'){
                loop_time += grade * (top(stack) - '0');
                grade *= 10;
                pop(&stack);
                if(!stack.top) break;
            }
            for(int j=0;j<loop_time;j++){
                for(int k=to_inseert_length - 1;k>=0;k--){
                    push(&stack,to_insert[k]);
                }
            }
        }
        else push(&stack,s[i]);
    }
    char* to_return = (char*) malloc ((stack.top + 1) * sizeof(char));
    memcpy(to_return,stack.c,(stack.top) * sizeof(char));
    to_return[stack.top] = '\0';
    return to_return;
}