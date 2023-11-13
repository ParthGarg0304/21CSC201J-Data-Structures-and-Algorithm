//Infix to Postfix conversion
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

char stack[100];
int top=-1;

int isEmpty() //if stack is empty
{
    return top== -1;
}

int isFull() //if stack is full
{
    return top== MAX - 1;
}

char peek() //return top element
{
    return stack[top];
}

char pop() //function to delete element
{
    if(isEmpty())
    {return 0;}
    char ch = stack[top];
    top--;
    return (ch);
}

void push(char a) //function to insert element
{
    if(isFull())
    {
        printf("Stack Full");
    }
    else
    {
        top++;
        stack[top] = a;
    }
}

//Function to check if the given character is operand
int checkIfOperand(char ch)
{
    return(ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

// Function to compare precedence of operators
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        return 1;
       
        case '*':
        case '/':
        return 2;
       
        case '^':
        return 3;
    }
    return -1;
}

//Function for infix to postfix conversion
int covertInfixToPostfix(char *expr)
{
    printf("Postfix expression is: ");
    int i,j;
   
    for(i=0,j= -1;expr[i];++i)   //till expr is empty
   
    {
        if(checkIfOperand(expr[i]))
        {
            expr[++j] = expr[i];
        }
       
        else if(expr[i] == '(')
        {
            push(expr[i]);
        }
       
        else if(expr[i] == ')')
        {
            if (expr[i] == ')')
            {//keep popping & adding to expression until opening pair found
            while (!isEmpty() && peek() != '(')
            expr[++j] = pop();
            pop();
            }
   }
   
   else //if an opertor
   {
       while(!isEmpty() && precedence(expr[i])<=precedence(peek()))
       expr[++j] = pop();
       push(expr[i]);
   }
    }
   
    /*Once all inital expression characters are traversed adding all left elements from stack to expression*/
    while(!isEmpty())
    expr[++j] = pop();
    expr[++j] = '\0';
    printf ("%s",expr);
}

int main()
{
  char expression[100];
  printf("Enter Infix expression: "); //input infix expression
  scanf("%s",expression);
  covertInfixToPostfix(expression);
  return 0;
}