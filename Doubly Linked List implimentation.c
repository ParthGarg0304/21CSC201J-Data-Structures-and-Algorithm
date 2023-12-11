// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node //create a node
{
    int data; //data part
    struct node *next; //pointer part
    struct node *prev;
};

void display(struct node *start) //to display the linked list
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL) //to traverse till end node
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
       
    }
    printf("\n");
   
}

struct node *insert_begin(struct node *start) //insertion at beginning
{
    struct node *new_node;
    int num;
    printf("\nEnter value for insertion at beginning");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    start->prev=new_node;
    new_node->next=start;
   
    new_node->prev=NULL;
    start=new_node;
    return start;
   
}

struct node *insert_end(struct node *start) //insertion at end
{
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter value for insertion at end");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    if(start==NULL) //no node present
    {
        start=new_node;
        return start;
       
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
       
    }
   
    new_node->prev=ptr;
    ptr->next=new_node;
    return start;
   
}

void insert_after(struct node *start) //insertion after a node
{
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\nEnter value for insertion after a node:");
    scanf("%d",&num);
   
    printf("\nEnter the no. after which the data has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    preptr=ptr;
   
    while(preptr->data!=val && ptr!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
       
    }
   
    if (ptr==NULL)
    {
        printf("Value %d not found in the linked list.\n",val);
        free(new_node);
        return;
       
    }
    new_node->prev=preptr;
    new_node->next=ptr;
    ptr->prev=new_node;
    preptr->next=new_node;
   
}
struct node *delete_begin(struct node *start) //deletion from beginning
{
    printf("After deleting a node from beginning:\n");
    if(start==NULL)
    {
        printf("Linked list is empty.\n");
        return start; // Return the unchanged start pointer
    }
       
        struct node *ptr;
        ptr=start;
        start=start->next;
        start->prev=NULL;
       
        free(ptr);
        return start; // Return the updated start pointer
}

struct node *delete_end(struct node *start) //deletion from end
{
    printf("After deleting a node at end:\n");
    if(start==NULL)
    {
        printf("Linked list is empty.\n");
        return start;
       
    }
   
    struct node *ptr,*preptr;
    ptr=start;
    preptr=NULL; // Initialize preptr to NULL
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(preptr==NULL)
    {
        free(ptr);
        return NULL;
       
    }
   
    preptr->next=NULL;
    free(ptr);
    return start;
   
}
int main()
{
   
    struct node *start=NULL;
   
    start=insert_begin(start);
    display(start);
   
    start=insert_end(start);
    display(start);
    start=insert_begin(start);
    display(start);
    start=insert_end(start);
    display(start);
    insert_after(start);
    printf("Linked list entered:\n");
    display(start);
   
    start=delete_begin(start);
    display(start);
   
    start=delete_end(start);
    display(start);
    printf("end of program");
   
    return 0;
   
}

