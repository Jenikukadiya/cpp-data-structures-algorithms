#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city
{
    char name[100];
    int x,y;
    struct city * next;
};

 struct city * insert(struct city *head, char name[],int x , int y )
{
     struct city * newcity = (struct city *)malloc(sizeof(struct city));
     strcpy(newcity->name,name);
     newcity->x=x;
     newcity->y=y;
     newcity->next=NULL;
     head = newcity ;
     return newcity;
 }
void funprint(struct city * head)
{
    struct city * ptr= head;
    while(ptr!=NULL)
    {
        printf("%s ( %d  , %d ) --> ",ptr->name , ptr->x, ptr->y );
        ptr=ptr->next;
    }
}
int main()
{
    
    struct city * head = NULL;
    printf("1. to insert record \n");
    printf("2.  delete record by name \n");
    printf("3. delete record by coordinate \n");
    printf("4. search record by name \n ");
    printf("5. search a record by cordinates \n");
    printf("6. to print database :\n");
    printf("7 . to exit  \n  ");
    
    
    int choice ,x,y;
    char name[100];
    
    while(true)
    {
        printf("enter choice \n");
        scanf("%d",&choice);
        
        
        switch(choice)
        {
            case 1:
                printf("enter city name : \n");
                scanf("%s ", name);
                printf("enter x cordinate :\n");
                scanf("%d ",&x);
                printf("enter y cordinate : \n");
                scanf("%d ",&y);
                head = insert(head,name,x,y);
                break;
                
            case 6:
                funprint(head);
                break;
            case 7:
                exit(0);
                
        }
    }
}
