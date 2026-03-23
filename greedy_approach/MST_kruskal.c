#include<stdio.h>
struct edge
{
    int u , v , w;
};
int parent[100];
int find(int x)
{
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}
void unionset(int a , int b )
{
    int rootA=find(a);
    int rootB=find(b);
    parent[rootA]=rootB;
}
void sortEdges(struct edge edges[],int e)
{
    for (int i =0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(edges[j].w > edges[j+1].w)
            {
                struct edge temp = edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
            
            
        }
    }
}
    
void kruskal(struct edge edges [],int e, int n)
{
    for (int i = 0;i<n;i++)
        parent[i]=i;
    
    sortEdges(edges, e);
    
    int count =0;
    int totalcost=0;
    
    printf("edges in MST : \n");
    
    for(int i =0;i<e && count <n-1 ; i++)
    {
        int  u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        
        if (find(u) != find(v))
        {
            printf("%d - %d : %d \n",u,v,w);
            totalcost += w;
            unionset(u,v);
            count++;
        }
    }
    printf("Total cost : %d \n",totalcost);
}
    
int main()
{
    int n =4;
    int e=5;
    
    struct edge edges[5]={
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };
    
    kruskal(edges,e,n);
    
    return 0;
}

