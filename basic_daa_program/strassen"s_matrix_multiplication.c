#include<stdio.h>
void strassen (int arr1[2][2],int arr2[2][2],int arr3[2][2])
{
    int p= (arr1[0][0] +arr1[1][1])*(arr2[0][0]+arr2[1][1]);
    int q=(arr1[1][0]+arr1[1][1])*arr2[0][0];
    int r =arr1[0][0]*(arr2[0][1]-arr2[1][1]);
    int s =arr1[1][1]*(arr2[1][0]-arr2[0][0]);
    int t =(arr1[0][0]+arr1[0][1])*arr2[1][1];
    int u=(arr1[1][0] -arr1[0][0])*(arr2[0][0]+arr2[0][1]);
    int v=(arr1[0][1] -arr1[1][1])*(arr2[1][0]+arr2[1][1]);
    
    
   
    arr3[0][0]=p+s-t+v;
    arr3[0][1]=r+t;
    arr3[1][0]=q+s;
    arr3[1][1]=p+r-q+u;
    
    
    
}
void print(int arr[2][2])
{
    for(int i =0 ; i<2;i++)
    {
        for(int j = 0;j<2;j++)
        {
            printf("%d  \t ",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr3[2][2];
    printf(" enter elements of First matrix \n");
    int arr1[2][2];
    for(int i =0 ; i<2;i++)
    {
        for(int j = 0;j<2;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("first matrix \n");
    print(arr1);
    
    
    printf(" enetr elements of Second  matrix \n");
    int arr2[2][2];
    for(int i =0 ; i<2;i++)
    {
        for(int j = 0;j<2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("seconf matrix \n");
    print(arr2);
    
    strassen(arr1,arr2,arr3);
    printf("matrix multipliaction answer \n");
    print(arr3);
    
    return 0 ;
}
