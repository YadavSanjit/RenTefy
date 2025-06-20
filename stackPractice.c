#include <stdio.h>
int max = 5;
int stack[max];
int top = -1;

int empty(){
    if(top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
int full(){
    if(top == max)
 {   
    return 1;
}else {
    return 0;
 }
}
int pop(){
    int data;
    if(!empty)
    {
        data = stack[top];
        top--;
        return data;

    }else{
        printf("Stack is empty\n");
    }
    
}
int push(int data)
{
    if(!full){
        top++;
        stack[top] = data;
    } else{
        printf("Stack is full\n");
    }
}

int main(){
    
}