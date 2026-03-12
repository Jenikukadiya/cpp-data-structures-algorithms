#include<stdio.h>

int quick(int arr[],int low, int high )
{
    int pivot = arr[low];
    int i=low+1;
    int j = high;
    int temp;
    while(i<=j)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot  && j>= low)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j ;
}
 void sort(int arr[], int low , int high )
{
     int z ;
     
     if(low < high)
     {
         z= quick(arr,low,high);
         sort(arr,low,z-1);
         sort(arr,z+1,high);
     }
     
     
}
int main()
{
    int arr[]={44, 10 , 8 ,65, 9, 11};
    
    int low = 0 ;
    int high = 5;
    
    sort(arr,low,high);
    printf("sorted array \n");
    for (int i=0; i< high ; i++)
    {
        printf("%d --> ", arr[i]);
    }
}
