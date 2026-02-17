#include<stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low ;
    int j = mid + 1;
    int k =0 ;
    
    int temp[100];
    while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
    while (i <= mid)
            temp[k++] = arr[i++];
    
    while (j <= high)
            temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
            arr[i] = temp[k];
}
 void divide(int arr[],int low ,int high )
{
      if (low >= high)
          return ;
     
     if(low<high)
     {
         int mid =(low +high)/2;
         
         findmiddle(arr,low,mid);
         findmiddle(arr,mid+1,high);
     }
     merge(arr,low,mid,high);
}
 int main()
{
     int arr[] ={10,80,30,50,60};
     int low =0;
     int high = 4;
     
     divide(arr, low, high);
     printf("Sorted array:\n");
         for (int i = 0; i <= high ; i++)
             printf("%d ", arr[i]);

         return 0;
 }
