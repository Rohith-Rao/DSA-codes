#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *next;
};
typedef struct node *lptr;
void addend(lptr &p,int n)
{
    lptr T;
    T=new(node);
    T->data=n;
    T->next=NULL;
    if(p==NULL)
    {
        p=T;
        return;
    }
    lptr t1=p;
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
    t1->next=T;
}
void degeree(int **G,int deg[],int v)
{
    for (int i = 1; i < v+1; i++)
    {
        int count=0;
        for (int j = 1;j < v+1; j++)
        {
            if (G[i][j]==1)
            {
                count++;
            }
        }
        deg[i]=count;
    }
}
void dft_undirected(int **G,int v,int start,int start2,lptr &t,int deg[],int n)
{
    if(start==start2 && n>0)
    {
        addend(t,start);
        return;
    }
    addend(t,start);
    for (int i = 1; i < v+1; i++)
    {
        if (G[start][i]==1)
        {
            G[start][i]=0;
            G[i][start]=0;
            deg[start]--;
            deg[i]--;
            dft_undirected(G,v,i,start2,t,deg,n+1);
            break;

        }
    }
}
int main()
{
    int v;
    v=12;
    int **G;
    G=new int *[v+1];
    for(int i=0;i<v+1;i++)
    {
        G[i]=new int [v+1];
    }
    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0 ;j < v+1; j++)
        {
            G[i][j]=0;
        }
    }
    G[1][3]=1;
    G[1][4]=1;
    G[2][3]=1;
    G[2][8]=1;
    G[3][2]=1;
    G[3][6]=1;
    G[3][9]=1;
    G[3][7]=1;
    G[3][4]=1;
    G[3][1]=1;
    G[4][1]=1;
    G[4][3]=1;
    G[4][7]=1;
    G[4][10]=1;
    G[4][5]=1;
    G[4][11]=1;
    G[5][4]=1;
    G[5][10]=1;
    G[6][3]=1;
    G[6][9]=1;
    G[7][3]=1;
    G[7][4]=1;
    G[7][10]=1;
    G[7][9]=1;
    G[8][2]=1;
    G[8][9]=1;
    G[9][6]=1;
    G[9][8]=1;
    G[9][3]=1;
    G[9][7]=1;
    G[9][10]=1;
    G[9][12]=1;
    G[10][12]=1;
    G[10][9]=1;
    G[10][7]=1;
    G[10][4]=1;
    G[10][11]=1;
    G[10][5]=1;
    G[11][4]=1;
    G[11][10]=1;
    G[12][9]=1;
    G[12][10]=1;
    int start;
    int x=0;
    lptr ans=NULL;
    int deg[v+1];
    degeree(G,deg,v);
    while(1>0)
    {
        int flag=0;
            lptr p;
            lptr t=NULL;
            if (x==0)
            {
                start=1;
                x++;
            }
            else
            {
                p=ans;
               while(deg[p->data]==0)
               {
                p=p->next;
                if(p==NULL)
                {
                    flag=1;
                    break;
                }
               }
               if(flag!=1)
               start=p->data;
            }
            if(flag==1)
            {
                break;
            }
            dft_undirected(G,v,start,start,t,deg,0);
            if (x==1)
            {
                ans=t;
                x++;
            }
            else
            {
                lptr s=p->next;
                p->next=t->next;
                while(t->next!=NULL)
                {
                    t=t->next;
                }
                t->next=s;
            }

    }
    while(ans!=NULL)
    {

        cout<<ans->data<<" ";
        ans=ans->next;
    }
    cout<<endl;
}
