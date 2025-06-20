#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node * next;
};

void linklisttrav(struct node *ptr)
{  while(ptr != NULL){
   printf("elemnt:%d\t", ptr->data);
   ptr = ptr->next; 
}
}

int main(){
struct node * head = ( struct node *)malloc(sizeof( struct node));
struct node * second = ( struct node *)malloc(sizeof( struct node));
struct node * third = ( struct node *)malloc(sizeof( struct node));

head->data = 7;
head->next = second;

second->data = 8;
second->next = third;

third->data = 9;
third->next = NULL;

linklisttrav(head);

return 0;
}