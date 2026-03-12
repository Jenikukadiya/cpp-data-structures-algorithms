#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void funprint(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d-->",ptr->data);
        ptr=ptr->next;
       
    }
    printf("\n");
}
 struct node* insertatbeg(struct node *head , int data)
{
     struct node *newnode = (struct node*)malloc(sizeof(struct node));
     newnode->data = data;
     newnode->next = head;
     
     return newnode;
     
 }

void insertatend(struct node *head, int data)
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node ));
    struct node * ptr;
    ptr=head;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next =newnode;
    newnode->data=data;
    newnode->next = NULL;
    
}
 struct node* getmiddle(struct node * start, struct node* end)
{
     if (start == NULL)
          return NULL;
     
     int pos=0;
     struct node * ptr = start;
     while(ptr!= end )
     {
         pos++;
         ptr=ptr->next;
     }
     int mid = pos/2;
     int K =0 ;
     ptr=start;
     while(K<mid)
     {
         K++;
         ptr=ptr->next;
     }
     
     return ptr;
     
 }
int  binarysearch(struct node * head , int key)
{
    funprint(head);
    struct node *start = head ;
    struct node *end = NULL;
    
    while (start != end )
    {
        struct node *mid = getmiddle(start,end);
        if (mid == NULL)
            return 0 ;
        if(mid->data == key )
            return 1;
        else if (mid->data <key)
            start=mid->next;
        else
            end = mid ;
        
    }
    return 0 ; 
}
int main()
{
    int choice , data;
    struct node *head = NULL;
    printf("1.insert at begninning \n");
    printf("2.insert at end \n");
    printf("3.binary search \n");
    printf("4 . exit \n");
    
    while(1)
    {
        printf("enter choice \n");
        scanf("%d",&choice);
        
        while(choice == 2 )
        {
            if (head == NULL)
            {
                printf("please enter other choice \n");
                scanf("%d",&choice);
            }
            else
                break;
        }
        
        switch(choice)
        {
            case 1 :
                printf("enter item \n");
                scanf("%d",&data);
                head=insertatbeg(head,data);
                break;
                
            case 2 :
                printf("enter  item \n");
                scanf("%d",&data);
                insertatend(head,data);
                break;
            case 3 :
                printf("enter element to search :\n");
                scanf("%d",&data);
                  if(binarysearch(head , data))
                      printf("element found \n");
                 else
                     printf("element not found ");
                break ;
                
            case 4 :
                exit(0);
        }
    }


}
