#include <stdio.h>
int main()
{
    int row,col,i,j,arr[10][10],count=0;
    printf("Enter the number of rows:");
    scanf("%d",&row);
    printf("Enter the number of columns:");
    scanf("%d",&col);
    printf("Enter element of Matrix:");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i][j]==0)
               count++;
        }
    }
    if(count>((row*col)/2))
    printf("Matrix is a sparse matrix");
    else
    printf("Matrix is not a sparse matrix");
}
