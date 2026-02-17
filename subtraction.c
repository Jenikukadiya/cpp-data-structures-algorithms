#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printLL(struct node * head)
{
    struct node *  ptr = head ;
    while (ptr  != NULL)
    {
        printf("%d ->>", ptr->data);
        ptr=ptr->next;
    }
    printf("null");
    printf(" \n");
}
struct node* insertatend(struct node*head,int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node ));
    newnode->data = data ;
    newnode->next =NULL;
    
    if (head == NULL)
    {
        return newnode ;
    }
    struct node *ptr = head ;
    while (ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = newnode;
    
    return head;
   
}
struct node* reverseLL(struct node* head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct node * subtractLL(struct node* h1,  struct node* h2)
{
    h1 = reverseLL(h1);
    h2= reverseLL(h2);
    
    int borrow = 0 ;
    struct node * result = NULL;
    
    while (h1 != NULL)
    {
        int d1 = h1->data - borrow ;
        int d2 = (h2 != NULL )? h2->data : 0;
        
        if(d1 < d2)
        {
            d1 = d1+10;
            borrow = 1;
        }
        else
        {
            borrow = 0 ;
        }
        
        int sub = d1-d2;
        result = insertatend(result, sub);
        
        h1 = h1->next;
        if(h2 != NULL)
            h2=h2->next;
    }
    
    return reverseLL(result);
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    
    int n1=3456;
    int temp = n1;
    int arr1[5];
    int i =0;
    while (temp >0)
    {
        arr1[i++] =temp%10;
        temp = temp/10;
    }
    
    for (int j=i-1 ; j >=0 ; j-- )
    {
        head1 = insertatend(head1,arr1[j]);
    }
    
    int n2 = 8923;
    int temp1 = n2;
    int k =0 ;
    int arr2[6];
    
    while (temp1>0)
    {
        arr2[k++]= temp1%10;
        temp1=temp1/10;
    }
    
    for( int j = i-1 ; j>=0 ;j--)
    {
        head2 = insertatend(head2,arr2[j]);
    }
    printf("1 Linked List  \n");
    printLL(head1);
    
    printf("2 Linked List \n");
    printLL(head2);
    
    struct node* result = subtractLL(head2, head1);

    printf("subtratct LL2 - LL1 ");
    
    printf("Result Linked List\n");
    printLL(result);

}
