#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct Node{             //create a node
    int data;            //data part
    struct Node *next;   //pointer part
};

void display(struct Node *start){
    struct Node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t %d", ptr->data);
        ptr=ptr->next;
       
    }
}

//insertion at begining
void insertbegin(struct Node *start){
    printf("creating new node at begining\n");
   
    struct Node *new_node;
    int new_data;
    printf("enter value to be entered in the list\n");
    scanf("%d",&new_data);
   
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=start;
    start=new_node;
}

//insertion at end
void insertend(struct Node *start){
    printf("creating new node at end\n");
    struct Node *new_node,*ptr;
    int new_data;
    printf("enter value to be entered in the list\n");
    scanf("%d",&new_data);
   
    new_node = (struct Node*)malloc(sizeof(struct Node));
   
   
    new_node->data = new_data;
    ptr =start;
    if (start == NULL) {     //no node present
        start = new_node;
        return;
       
    }
   
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next = NULL;    //last pointer =null
}

void insertafter(struct Node *start){
    printf("creating new node\n");
    struct Node *new_node,*ptr,*preptr;
    int new_data,val;
    printf("enter value to be entered in the list\n");
    scanf("%d",&new_data);
   
    printf("\n Enter the value after which the data has to be inserted :\n");
    scanf("%d",&val);
    
    new_node = (struct Node*)malloc(sizeof(struct Node));
    ptr=start;
    preptr=ptr;
   
    new_node->data=new_data;
   
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
       
    }
    preptr->next=new_node;
    new_node->next=ptr;
   
}

void deletebegin(struct Node *start){
    printf("deleting a node at begining \n");
    struct Node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
}
