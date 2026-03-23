#include<stdio.h>
int main()
{
    int a , n=5;
    int coins[]={1,2,10,5,10000};
    

    for(int i=0; i<n-1; i++)
       {
           for(int j=0; j<n-i-1; j++)
           {
               if(coins[j] > coins[j+1])
               {
                   int temp = coins[j];
                   coins[j] = coins[j+1];
                   coins[j+1] = temp;
               }
           }
       }
    
    printf("enter total  amount \n");
    scanf("%d",&a);
    
    int remain=a;
    
    while(remain>0)
    {
       // printf("hi");
        int i =0,coin=coins[0];
            while(remain>coins[i])
            {
                 coin=coins[i];
                i++;
            }
        remain=remain-coin;
        printf("coin used %d \n",coin);
        
    }

}
