#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city
{
    char name[30];
    int x,y;
    
};
void removerecordbycor()
{
    
    int dx,dy;
    printf("enter cordinate x & y you wnat to delete \n");
    scanf("%d %d",&dx,&dy);
    
    FILE *fp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt","r");
    FILE *temp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/temp.txt","w");
    
    if(fp == NULL || temp == NULL)
    {
        printf("File opening error\n");
        return;
    }
    
    int x,y;
    char name[30];
    
    while(fscanf(fp," %s %d %d", name,&x,&y) == 3)
    {
        if( x!= dx && y!=dy)
        {
            fprintf(temp,"%s %d %d \n",name,x,y);
        }
    }
    
    fclose(fp);
    fclose(temp);
    
    if(remove("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt") == 0)
        printf("Removed successfully\n");
    
    if(rename("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/temp.txt","/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt") == 0)
    {
        printf("Renamed successfully\n");
    }
    
}
void removerecordbyname()
{
    char dname[50];
    printf("Enter city name you want to delete:\n");
    scanf("%s", dname);
    
    FILE *fp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt","r");
    FILE *temp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/temp.txt","w");
    
    if(fp == NULL || temp == NULL)
    {
        printf("File opening error\n");
        return;
    }
    
    
    
    {
        int x,y;
        char name[30];
        
        while(fscanf(fp," %s %d %d", name,&x,&y) == 3)
        {
            if(strcmp(name,dname) != 0)
            {
                fprintf(temp,"%s %d %d \n",name,x,y);
            }
        }
        
        fclose(fp);
        fclose(temp);
        
        if(remove("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt") == 0)
            printf("Removed successfully\n");
        
        if(rename("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/temp.txt","/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt") == 0)
        {
            printf("Renamed successfully\n");
        }
    }
}
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
    scanf("%s",name);

    printf("enter x and y cordinates \n ");
    scanf("%d %d",&x,&y);
    
    
    fprintf(fp,"%s %d %d \n",name,x,y);
    printf("city inserted  \n");
    
    fclose(fp);
    
}

int searchbycordinates()
{
    FILE *fp;
    fp=fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "r" );
    
    if(fp ==NULL)
    {
        printf("file not found \n");
    }
    
    int sx,sy;
    printf("enter  x cordinates of city you want to search \n");
    scanf("%d",&sx);
    
    printf("enter  y cordinates of city you want to search \n");
    scanf("%d",&sy);
    
    char name[50];
    int x,y;
    while(fscanf(fp,"%s %d %d " ,name,&x,&y) == 3 )
    {
        if(x==sx && y==sy)
        {
            fclose(fp);
            return 1 ;
        }
    }
    fclose(fp);
    return 0;
}
int searchbycity()
{
    FILE *fp;
    char sname[50];
    fp = fopen ("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "r" );
    printf("enter city name to search \n");
    scanf("%s",sname);
    if(fp ==NULL)
    {
        printf("file not found \n");
    }
   
    int x,y;
    char name[50];
    while(fscanf(fp,"%s %d %d " ,name,&x,&y) == 3 )
    {
        if(strcmp(name,sname) == 0 )
        {
            fclose(fp);
            return 1 ;
        }
        
    }
    fclose(fp);
    return 0;
}
void printdatabase()
{
    FILE *fp =fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "r" );
    printf("enter city name to search \n");
    
    char name[50];
    int x , y;
    while(fscanf(fp,"%s %d %d ", name,&x,&y)== 3)
    {
        printf("%s %d %d \n",name, x,y);
    }
}
void insertionSort(struct city arr[], int n)
{
    int i, j;
    struct city key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j].name, key.name) > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void sortingfile()
{
    FILE *fp ;
    fp= fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "r" );
    
    if(fp == NULL)
    {
        printf("File not found\n");
        return;
    }
    char name[30];

    int n =0;
    struct city arr[100];
    while(fscanf(fp,"%s %d %d ",arr[n].name,&arr[n].x,&arr[n].y)==3)
    {
        n++;
    }
    fclose(fp);
    fp = fopen("/Users/jeni/Library/Mobile Documents/com~apple~TextEdit/Documents/citydb.txt", "w");
    insertionSort(arr,n);
    
    for(int i=0;i<n;i++)
    {
        fprintf(fp, "%s %d %d\n", arr[i].name, arr[i].x, arr[i].y);
    }
    fclose(fp);
}

int main ()
{
    
    printf("1. to insert record \n");
    printf("2.  delete record by name \n");
    printf("3. delete record by coordinate \n");
    printf("4. search record by name \n ");
    printf("5. search a record by cordinates \n");
    printf("6. to print database :\n");
    printf("7. orderd list \n");
    printf("8. to exit  \n  ");
    
    
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
                break;
                
            case 2:
                removerecordbyname();
                break;
            case 3:
                removerecordbycor();
                break;
            case 4 :
                if(searchbycity())
                    printf(" city found \n");
                else
                    printf("city not found \n");
                break;
                
            case 5:
                if(searchbycordinates())
                    printf(" city found  by cordinates \n");
                else
                    printf("city not found by cordinates  \n");
                break;
            case 6 :
                printdatabase();
                break;
            case 7 :
                sortingfile();
                printf("file sorted sucessfully \n");
                break;
            case 8 :
                exit(0);
        }
    }
}
