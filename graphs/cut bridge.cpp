#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int a;
    int b;
};
int min(int a,int b)
{
	if (a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void dfs(int **G,int v,int num[],int low[],int p[],int start,int cut[],vector <node> &k)
{
    static int time=0;
    int childern=0;
    num[start]=low[start]=time++;
    for (int i = 0; i < v+1; i++)
    {
    	if (G[start][i]==1)
    	{
    	    if (num[i]==-1)
    	    {
    		  childern++;
    		  p[i]=start;
    		  dfs(G,v,num,low,p,i,cut,k);
    		  low[start]=min(low[start],low[i]);
    		  if (p[start]==-1 && childern>1 && num[start]<=low[i])
    		  {
    		  	 cut[start]=1;
    		  }
    		  else if (p[start]!=-1 && num[start]<=low[i])
    		  {
    		  	 cut[start]=1;
    		  }
    		  if(num[start]<low[i])
              {
                 // cout<<start<<" "<<i<<endl;
                 node x;
                 x.a=start;
                 x.b=i;
                 k.push_back(x);
              }
    	    }
    	    else if (p[start]!=i)
    	    {
    	    	low[start]=min(low[start],num[i]);
    	    }
    	}


    }
}
int main()
{
	int v,e;
	v=8;
	e=10;
	int **G;
	G=new int *[v+1];
	for (int i = 0; i < v+1; i++)
	{
		G[i]=new int [v+1];
	}
	for (int i = 0; i < v+1; ++i)
	{
		for (int j = 0; j < v+1; j++)
		{
			G[i][j]=0;
		}
	}
	G[0][1]=1;
	G[1][0]=1;
	G[2][0]=1;
	G[0][2]=1;
	G[1][2]=1;
	G[2][1]=1;
	G[2][3]=1;
	G[3][2]=1;
	G[2][5]=1;
	G[5][2]=1;
	G[3][4]=1;
	G[4][3]=1;
	G[5][6]=1;
	G[6][5]=1;
	G[6][7]=1;
	G[7][6]=1;
	G[7][8]=1;
	G[8][7]=1;
	G[5][8]=1;
	G[8][5]=1;
	int p[v+1];
	int num[v+1];
	for (int i = 0; i < v+1; i++)
	{
		p[i]=-1;
		num[i]=-1;
	}
	int low[v+1];
	int cut[v+1]={};
	vector <node> k;
	dfs(G,v,num,low,p,0,cut,k);
	for(int i=0;i<v+1;i++)
    {
        if(cut[i]==1)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<k.size();i++)
    {
        cout<<k[i].a<<" "<<k[i].b<<endl;
    }
}
