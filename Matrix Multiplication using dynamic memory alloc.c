#include<stdio.h>
#include<stdlib.h>


int main(){
   
int **a, **b,**multi,i,j,k;
int row1,col1,row2,col2;

printf("\nEnter the Order of the First matrix...\n");
scanf("%d %d",&row1,&col1);
printf("\nEnter the Order of the Second matrix...\n");
scanf("%d %d",&row2,&col2);

if(col1!=row2){
    printf("cant perform multiplication");
    exit(EXIT_SUCCESS);
}

a=(int**) malloc(row1*sizeof(int*));

for(i=0;i<col1;i++)
    a[i]=(int*)malloc(col1*sizeof(int));

b=(int**) malloc(row2*sizeof(int*));

for(i=0;i<col2;i++)
    b[i]=(int*)malloc(col2*sizeof(int));

multi=(int**)calloc(row1,sizeof(int*));

for(i=0;i<col2;i++)
    multi[i]=(int*)calloc(col2,sizeof(int));
   

    printf("enter values for 1st matrix");
    for(i=0;i<row1;i++)
        for(j=0;j<col1;j++)
            scanf("%d",&a[i][j]);

    printf("enter values for 2nd matrix");
    for(i=0;i<row2;i++)
        for(j=0;j<col2;j++)
            scanf("%d",&b[i][j]);

printf("both matrix are entered \n");

printf("\n Entered Matrix 1: \n");
for(i=0;i<row1;i++){
    for(j=0;j<col1;j++)
        printf("%d ",a[i][j]);
    printf("\n");
}

printf("\n Entered Matrix 2: \n");
for(i=0;i<row2;i++){
    for(j=0;j<col2;j++)
        printf("%d ",b[i][j]);
    printf("\n");
}      



    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
                multi[i][j]=0;
                for(k=0;k<col1;k++)
                    multi[i][j]= multi[i][j]+(a[i][k]*b[k][j]);

        }
        printf("\n");
    }


   printf("\nThe Multiplication of two matrix is\n");
   for(i=0;i<row1;i++){
       printf("\n");
       for(j=0;j<col2;j++)
            printf("%d\t",multi[i][j]);  
   }
    printf("\n");

return 0;
   
}