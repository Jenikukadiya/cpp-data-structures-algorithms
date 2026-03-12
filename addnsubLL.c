#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printLL(struct node *head)
{
    struct node *ptr=head;
    while (ptr !=NULL)
    {
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf(" NULL \n");
}
 struct node * insertatend(struct node *head,int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node ));
   
     if(newnode == NULL)
     {
         printf("memory allocation failed  \n");
         exit(1);
     }
     
     if(head == NULL)
     {
         newnode->data = data;
         newnode->next = NULL;
         return newnode;
     }
     struct node *ptr =head;

    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
      
    ptr->next=newnode;
    newnode->data=data;
    newnode->next =NULL;
     return head;

}
int LLtoNumber(struct node *head)
{
    int num=0;
    while(head!=NULL)
    {
        num=num*10+head->data;
        head=head->next;
    }
    return num ;
}

struct node* NumbertoLL(int num)
{
    struct node*head =NULL;
    int arr[20],i=0;
    
    while(num>0)
    {
        arr[i++]=num%10;
        num=num/10;
    }
    
    for(int j = i-1; j >= 0; j--)
      head=  insertatend(head, arr[j]);
    
    return head;
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;

    int n1 = 5146;
    int n2 =8923;
    
    
    int temp =n1;
    int arr[10] ,i=0;
    while(temp>0)
    {
        arr[i++]=temp%10;
        temp=temp/10;
    }
    
    for (int j=i-1;j>=0;j--)
       head1= insertatend(head1,arr[j]);
    
    int temp2=n2;
    int arr2[10] , k=0;
    while(temp2>0)
    {
        arr2[k++]=temp2%10;
        temp2=temp2/10;
    }
    
    for(int j =k-1;j>=0;j--)
    {
       head2= insertatend(head2, arr2[j]);
        
    }
    
    printf("linked list 1 :");
    printLL(head1);
    
    printf("linked list 2:");
    printLL(head2);
    
    int sum = LLtoNumber(head1) + LLtoNumber(head2);
    
    struct node *result = NumbertoLL(sum);

        printf("Result Linked List: ");
    printLL(result);

        return 0;
    
}

