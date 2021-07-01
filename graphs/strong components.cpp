#include <iostream>
#include <queue>
using namespace std;
void dft_directed(int **G,int visit1[],int v,int start)
{
    visit1[start]=1;
    cout<<start<<" ";
    for (int i = 1; i < v+1; i++)
    {
        if (G[start][i]==2)
        {
            if (visit1[i]==0)
            {
                dft_directed(G,visit1,v,i);
            }
        }
    }
}
void reverse(int **G,int v)
{
    for (int i = 1; i < v+1; i++)
    {
        for (int j = 1; j < v+1;j++)
        {
            if (G[i][j]==1)
            {
                G[i][j]=0;
                G[j][i]=2;
            }
        }
    }
}
void post_ordering(int **G,int visit[],int v,int start,int &k,int pnum[])
{
    visit[start]=1;
    for (int i = 1; i < v+1; i++)
    {
        if (G[start][i]==1)
        {
            if (visit[i]==0)
            {
                post_ordering(G,visit,v,i,k,pnum);
            }
        }
    }
    pnum[start]=k;
    k++;
}
int main()
{
    int v;
    int e;
    //cin>>v>>e;
    v=10;
    e=15;
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
    G[1][2]=1;
    G[1][4]=1;
    G[2][3]=1;
    G[2][6]=1;
    G[3][1]=1;
    G[3][4]=1;
    G[3][5]=1;
    G[4][5]=1;
    G[6][3]=1;
    G[7][6]=1;
    G[7][8]=1;
    G[8][10]=1;
    G[8][6]=1;
    G[10][9]=1;
    G[9][8]=1;
    int visit[v+1]={0};
    int pnum[v+1]={0};
    int k=1;
    post_ordering(G,visit,v,2,k,pnum);
    post_ordering(G,visit,v,8,k,pnum);
    post_ordering(G,visit,v,7,k,pnum);
    reverse(G,v);
    int visit1[v+1]={0};
    while(1>0)
    {
        int flag=0;
        for (int i = 1; i < v+1; i++)
        {
            if (visit1[i]==0)
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            break;
        }
        else
        {
            int max=-1;
            int s;
            int i;
            for ( i = 1; i < v+1; i++)
            {
                if (pnum[i]>max && visit1[i]==0)
                {
                    max=pnum[i];
                    s=i;
                }
            }
            dft_directed(G,visit1,v,s);
            cout<<endl;
        }
    }
}
