#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peep(struct stack *);


int main(){
    int val, choice;
    printf("\n *****MAIN MENU*****");
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. PEEK");
    printf("\n 4. DISPLAY");
    printf("\n 5. EXIT");
    do
    {
        printf("\n Enter your option: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d",&val);
            top=push(top,val);
            break;
           
            case 2:
            top=pop(top);
            break;
           
            case 3:
            val=peep(top);
            if (val!=-1){
                printf("\n The value at the top of stack is: %d", val);
            }
            else{
                printf("\n STACK IS EMPTY");
            }
            break;
           
            case 4:
            top=display(top);
            break;
           
        }
       
    }while(choice!=5);
   
    return 0;
}


struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL)          ///no element present
    {
        ptr->next=NULL;
        top=ptr;
       
    }
    else                //element already present
    {
        ptr->next=top;
        top=ptr;
       
    }
    return top;
}


struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if(top == NULL){
        printf("\n stack is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n %d", ptr -> data);
            ptr=ptr->next;
        }
    }
    return top;
}


struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL){
        printf("\n underflow");
    }
    else
    {
        top = top -> next;
        printf("\n The value being deleted is: %d", ptr -> data);
        free(ptr);
    }
    return top;
}


int peep(struct stack *top)
{
    if(top==NULL){
        return -1;
    }
    else{
        return top->data;        
    }
}
