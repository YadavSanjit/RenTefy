#include <stdio.h>

int  MAX = 5;
int q[5];
int front = -1, rear = -1;
int empty() {
    if (front == -1 || rear == -1)
    {
        return true;
    } else {
        return false;
    }
}
int full(){
    if(front == MAX-1)
    {
        return true;
    } else 
    {
        return false;
    }
}
int inq(int item)
{
    if(!full){      
        rear ++;
        q[0] = item;
    } else {
        printf(" Que is full.\n");
    }
  }
  int Dq(){
    int itm;
    if(!empty)
    {
        front ++;
      itm = q[front];
      return itm;
    } else {
        printf("que is empty\n.");
    }
    }
  int main(){
    printf("select operation:\n 1.add element \n 2. delete \n");

    return;
  }

