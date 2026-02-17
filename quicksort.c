#include<stdio.h>
 void sorting(int arr[], int p , int pivot , int q)
{
     for (int i =1 ; i<6;i++)
     {
         if(arr[p]<pivot)
         {
             p++;
         }
         if (arr[q]>pivot)
         {
             q++;
         }
     }
     if (p<q)
     {
         int temp ;
         temp=arr[p];
         arr[p]=arr[q];
         arr[q]=temp;
     }
     else
     {
         int temp1;
         temp1=pivot;
         pivot = arr[q];
         arr[q]=temp1;
     }
     
     
 }
int main()
{
    int arr[]={10,4,9,11,23,45,7};
    int pivot = 0;
    int p = 1;
    int q = 5;
    
    sorting (arr,pivot , p , q );
}
