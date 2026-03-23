#include<stdio.h>
int compair(int arr[],int s1,int e1,int s2,int e2)
{
    int sum1 = 0, sum2 = 0;

        for(int i = s1; i <= e1; i++)
            sum1 += arr[i];

        for(int i = s2; i <= e2; i++)
            sum2 += arr[i];
    
    if(sum1==sum2) return 0;
    if(sum1<sum2)  return -1;
    else return 1;
}
int  findfake(int coins[],int start,int end )
{
    if (start==end)
        return start;
    
    
    
    int size = end - start + 1;
    if (end - start == 1)
    {
        if (coins[start] < coins[end])
            return start;
        else
            return end;
    }
    int third = size / 3;
    
    int a_start = start;
    int a_end = start + third - 1;

    int b_start = a_end + 1;
    int b_end = b_start + third - 1;

    int c_start = b_end + 1;
    int c_end = end;
    
    int result= compair(coins,a_start,a_end,b_start,b_end);
    
    if (result == 0)
        return findfake(coins, c_start, c_end);
    if (result ==-1)
        return   findfake(coins, a_start, a_end);
    else
         return findfake(coins, b_start, b_end);
    
    
}
int main()
{
    int coins[]={10,10,10,5,10,10,10,10,10,10,10,10};
    
   int r= findfake(coins,0,11);
    printf("index of fake coin is %d \n",r);
    printf("weigh of that fake coin is %d \n",coins[r]);
    
    
}
