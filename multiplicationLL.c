#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* shiftleft(struct node * head,int zero)
{
    while(zero--)
    {
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data =0;
        newnode->next=head;
        head=newnode;
    }
    return head;
}
struct node * insertatend(struct node *head, int data)
{
    struct node *newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next =NULL;
    
    if (head == NULL)
    {
        head=newnode;
        return newnode;
    }
    
    struct node * ptr=head;
    while(ptr->next!= NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return head;
}
struct node* addlists (struct node* l1, struct node* l2)
{
    struct node *result =NULL;
    int carry=0;
    
    while(l1!=NULL || l2 != NULL || carry)
    {
        int sum=carry;
        if(l1)
        {
            sum = sum + l1->data;
            l1=l1->next;
        }
        if(l2)
        {
            sum = sum+ l2->data;
            l2=l2->next;
        }
        
        result = insertatend(result, sum % 10);
        carry = sum / 10 ;
    }
    return result ;
}

void printReverse(struct node *head)
{
    if(head == NULL)
        return;

    
    printReverse(head->next);
    printf("%d->", head->data);
    

}
struct node *multiplydigit(struct node * head, int digit )
{
    struct node * result = NULL;
    int carry = 0;
    struct node * ptr=head;
    while (ptr!=NULL)
    {
        int product = ptr->data * digit +carry ;
        result = insertatend(result, product % 10);
        carry = product /10;
        ptr=ptr->next;
    }
    if (carry >0)
    {
        result=insertatend(result, carry);
    }
    return result;
}

struct node * multiply(struct node *l1, struct node *l2)
{
    struct  node * result=NULL;
    int shift=0;
    while(l2!=NULL)
    {
       struct node * temp= multiplydigit(l1, l2->data);
        temp= shiftleft(temp,shift);
        result= addlists(result,temp);
        
        shift++;
        l2=l2->next;
    }
    return result;
}


int main()
{
    struct node *head1 = NULL;
    int n1=24;
    int temp;
    int arr[10];
    temp=n1;
    int i=0;
    
    
    while(temp!=0)
    {
        arr[i]=temp%10;
        i++;
        temp=temp/10;
        
    }
    
    
    for(int i=0;i<2;i++)
    {
         head1=insertatend(head1,arr[i]);
    
    }

    printReverse(head1);
    printf("\n");

    struct node *head2 = NULL;
    int n2=12;
    int temp2;
    int arr1[10];
    temp2=n2;
     i=0;
    
    
    while(temp2!=0)
    {
        arr1[i]=temp2%10;
        i++;
        temp2=temp2/10;
        
    }
    
    
    for(int i=0;i<2;i++)
    {
         head2=insertatend(head2,arr1[i]);
    
    }

    printReverse(head2);
    struct node * result = multiply(head1,head2);
    
    printf("multipplication result :");
    printReverse(result);
    printf("\n");
    
    
    // exponential code
    printf("24^4 is : \n");
    struct node * result1=NULL;
    result1=multiply(head1,head1);
    struct node *result2= multiply(head1,result1);
    struct node * result3 =multiply(head1, result2);

    printReverse(result3);
    return 0;
}
