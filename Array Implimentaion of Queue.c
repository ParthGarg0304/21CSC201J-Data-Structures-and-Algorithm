#include <stdio.h>
#include <stdlib.h>

#define MAX 20 // maximum length
int queue[MAX];
int front=-1, rear=-1;

void insert();
int delete_element();
void display();

int main()
{
    int ch, val;
    printf("\n 1. Insert element");
    printf("\n 2. Delete element");
    printf("\n 3. Display the queue");
    printf("\n 4. EXIT");
    do
    {
        printf("\n Enter your option : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            insert();
            break;
            
            case 2:
            val = delete_element();
            if (val!=-1)
            printf("\n The number deleted is : %d", val);
            break;
            
            case 3:
            display();
            break;
        }
        
    }while(ch!=4);
    
    return 0;
}

void insert()
{
    int val;
    printf("\n Enter the number to be inserted : ");
    scanf("%d", &val);
    if(rear==MAX-1){                        //Full
        printf("\n OVERFLOW");
    }
    else if(front==-1 && rear==-1){       //Empty
        front=0;
        rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=val;
}


int delete_element(){
    if(front==-1 && rear==-1)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    else
    {
        return queue[front];
    }
}


void display(){
    int i;
    if(front == -1 && rear==-1){
        printf("\n UNDERFLOW");
    }
    else
    {
        for(i=front;i<=rear;i++){     //traversing from front to rear
            printf("\t %d", queue[i]);
        }
        
    }
}
