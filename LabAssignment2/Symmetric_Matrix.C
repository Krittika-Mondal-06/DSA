#include <stdio.h>  
int main(){  
    int a[3][3], b[3][3], s, row, col, isSym;  
	printf("Enter the size of matrix: \n");
	scanf("%d", &s);
    printf("\nEnter the elements in matrix of size %dx%d: \n", s, s);  
    for(row=0; row<s; row++)  {  
        for(col=0; col<s; col++)  { 
            scanf("%d", &a[row][col]);  } }  
    for(row=0; row<s; row++)  {  
        for(col=0; col<s; col++)  {  
            b[row][col] = a[col][row];   } }  
    isSym = 1;  
    for(row=0; row<s && isSym; row++)      {  
        for(col=0; col<s; col++)  {    
            if(a[row][col] != b[row][col])  {  
                isSym = 0;  
                break;     }}}  
    if(isSym == 1)  {  
        printf("\nEntered matrix is symmetric.\n");  
        for(row=0; row<s; row++)  {  
            for(col=0; col<s; col++)  {  
                printf("%d ", a[row][col]);  }  
            printf("\n");        }} 
    else  
    {  printf("\nEntered matrix is not symmetric.\n");
        for(row=0; row<s; row++)  {  
            for(col=0; col<s; col++)  {  
                printf("%d ", a[row][col]);  }  
            printf("\n");  }}
    return 0;}