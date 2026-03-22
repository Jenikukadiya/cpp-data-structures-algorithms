#include<stdio.h>
int main()
{

     double loc[]={1 , 1.2 , 1.6 , 2, 2.5 , 3 , 3.2 , 3.5 , 6 , 7};
     double n =10.0 ,temp; // total number of paintings
    
    
    for (int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(loc[j]>loc[j+1])
            {
                temp=loc[j];
                loc[j]=loc[j+1];
                loc[j+1]=temp;
            }
        }
    }
    
    printf("locations where paintings are kept  : \n");
    for(int i=0;i<n;i++)
    {
        printf("%g--",loc[i]);
    }
    printf("\n");
    
    
    double guard_pos;
    double  protected=0;
    int i=0,k=0;
    while(protected <= loc[9])
    {

        guard_pos= loc[i]+1;
        printf("guard position : %g  \n ",guard_pos);
        protected = loc[i]+2;
        printf("protected  boundry of this  guard  from loc   %g \t  to %g \t \n  " ,loc[i],protected);
        
        if(protected>=loc[9])
            break;
        
        
        int j=0;
            while( protected >= loc[j])
            {
                j++;
            }
        i=j;
        k++;
    }
    printf("\n");
}
