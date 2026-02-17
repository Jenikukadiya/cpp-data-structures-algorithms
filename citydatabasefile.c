#include<stdio.h>
#include<stdlib.h>
struct city
{
    char name [100];
    int x ,  y ;
};
void insert()
{
  FILE *fp;
  char name[100];
  int x, y ;

   fp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "a");

    if(fp == NULL)
   {
    printf("error openeing file \n");

   }

    printf("enter city name \n ");
    scanf("%s", name );

    printf("enter x and y cordinates \n ");
    scanf("%d %d ", &x , &y);

    fprintf(fp,"%s %d %d", name , x,y);
   
    fclose(fp);
    printf("city inserted ");
}

void delete()
{
    FILE *fp;
    fp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", )
}
int main ()
{
    
    printf("1. to insert record \n");
    printf("2.  delete record by name \n");
    printf("3. delete record by coordinate \n");
    printf("4. search record by name \n ");
    printf("5. search a record by cordinates \n");
    printf("6. to print database :\n");
    printf("7 . to exit  \n  ");
    
    
    int choice ,x,y;
    char name[100];
    
    while(1)
    {
        printf("enter choice \n");
        scanf("%d",&choice);
        
        
        switch(choice)
        {
            case 1:
                insert();
                break ;
                
            case 3 :
                delete();
                break;
                
        }
    }
}
