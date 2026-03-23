#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low , int mid , int high )
{
    int x=low;
    int y = mid +1;
    int temp[100];
    int k=0;
    
    while(x<=mid && y <=high)
    {
        if(arr[x]< arr[y])
        {
            temp[k]=arr[x];
            k++;
            x++;
        }
        else
        {
            temp[k]=arr[y];
            k++;
            y++;
        }
    }

    while(x<=mid)
    {
        temp[k]=arr[x];
        k++;
        x++;
    }
    while(y<=high)
    {
        temp[k]=arr[y];
        k++;
        y++;
    }
     k=0;
    printf(" \n");
    for(int x =low ; x<= high ; x++)
    {
        arr[x]=temp[k];
        k++;
    }
    
    for(int r=0;r<=high; r++)
    {
        printf("%d-->", arr[r]);
    }
}
void divide(int arr[], int low , int high)
{
    int mid = (low + high) /2;
   
    if(low >=high)
        return ;
        
    if(low<high)
    {
        divide(arr, low, mid);
        divide(arr, mid+1, high);
    }
        merge(arr,low,mid,high);


}

int main ()
{
    int arr[]= {44,10,65,2,1,5};
    printf("the array is :\n");
    for (int i=0; i<6;i++)
    {
        printf("%d --> ",arr[i]);
    }
    printf("\n");
    int low = 0;
    int high = 5;
    divide(arr,low,high);
    
}

