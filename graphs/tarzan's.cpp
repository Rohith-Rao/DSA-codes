#include <iostream>
#include <vector>
#include <stack>
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
void dfs(int **G,int v,int num[],int low[],int p[],int start,int cut[],vector <node> &k,stack<int> &s,int m[])
{
    static int time=0;
    int childern=0;
    num[start]=low[start]=time++;
    s.push(start);
    m[start]=1;
    for (int i = 1; i < v+1; i++)
    {
    	if (G[start][i]==1)
    	{
    	    if (num[i]==-1)
    	    {
    		  childern++;
    		  p[i]=start;
    		  dfs(G,v,num,low,p,i,cut,k,s,m);
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
    	    else if (p[start]!=i &&m[i]==1)
    	    {
    	    	low[start]=min(low[start],num[i]);
    	    }
    	}
    }
    if (low[start]==num[start])
    {
    	while(s.top()!=start)
    	{
    		cout<<s.top()<<" ";
    		m[s.top()]=0;
    		s.pop();
    	}
    	cout<<s.top()<<endl;
    	m[s.top()]=0;
    	s.pop();
    }
}
int main()
{
	int v,e;
	v=10;
	e=15;
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
	int p[v+1];
	int num[v+1];
	for (int i = 0; i < v+1; i++)
	{
		p[i]=-1;
		num[i]=-1;
	}
	int low[v+1];
	int cut[v+1]={};
	int m[v+1]={};
	vector <node> k;
	stack<int> s;
	for(int i=1;i<v+1;i++)
    {
        if(num[i]==-1)
        {
            dfs(G,v,num,low,p,i,cut,k,s,m);
        }
    }
	/*dfs(G,v,num,low,p,2,cut,k,s);
	while(!s.empty())
    {
        s.pop();
    }
	dfs(G,v,num,low,p,8,cut,k,s);
	cout<<"x"<<endl;
		while(!s.empty())
    {
        s.pop();
    }
	dfs(G,v,num,low,p,7,cut,k,s);*/

}
