#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,5};
    int a ;
    printf("enter number you want to search \n");
    scanf("%d",&a);
    for (int i = 0 ;i<5;i++)
    {
        if(a==arr[i])
        {
            printf("element found  in array %d ",a);
        }
    }
    return 0 ;
}
