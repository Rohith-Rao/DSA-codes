#include <iostream>
#include <queue>
using namespace std;
void find_indegers(int **G,int v,int indegree[])
{
	for (int i = 1; i < v+1; i++)
	{
		int count=0;
		for (int j = 1; j < v+1; j++)
		{
			if (G[j][i]==1)
			{
				count++;
			}
		}
		indegree[i]=count;
	}
}
void find_out_degree(int **G,int v,int outdegree[])
{

    for (int i = 1; i < v+1; i++)
    {
        int count=0;
    	for (int j = 1; j < v+1; j++)
    	{
    		if (G[i][j]==1)
    		{
    			count++;
    		}
    	}
    	outdegree[i]=count;
    }
}
void get_sum(int **G,int v,int s,int e,float &sum,float w[])
{
	if (s==e)
	{
		sum=sum+w[e];
		return;
	}
    else
    {
    	sum=sum+w[s];
    	int x;
    	int max=-1;
    	for (int i = 1; i < v+1; i++)
    	{
    		if (G[s][i]==1)
    		{
    		    if (w[i]>max)
    		    {
    		    	max=w[i];
    		    	x=i;
    		    }
    		}
    	}
    	get_sum(G,v,x,e,sum,w);
    }
}
float time(int **G,int v, float w[],int indegree[],int outdegree[])
{
	int max1=-1,max2=-1;
	int s,e;
	for (int i = 1; i < v+1; i++)
	{
		if (indegree[i]==0)
		{
			if (w[i]>max1)
			{
				max1=w[i];
				s=i;
			}
		}
		if (outdegree[i]==0)
		{
			if (w[i]>max2)
			{
				max2=w[i];
				e=i;
			}
		}
	}
	float sum=0;
    get_sum(G,v,s,e,sum,w);
    return sum;
}
int main()
{
	int v;
	int e;
	cin>>v>>e;
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
	float w[v+1]={0};
	for (int i = 1; i < v+1; i++)
	{
		cin>>w[i];
	}
	while(e--)
	{
		int a,b;
		cin>>a>>b;
        G[a][b]=1;
	}
	int indegree[v+1]={0};
	int outdegree[v+1]={0};
	find_indegers(G,v,indegree);
	find_out_degree(G,v,outdegree);
	for(int i=1;i<v+1;i++)
    {
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
    	for(int i=1;i<v+1;i++)
    {
        cout<<outdegree[i]<<" ";
    }
    cout<<endl;
	float t=time(G,v,w,indegree,outdegree);
	cout<<t;
}
/*
7
8
3.1
2.0
4.6
1.8
0.3
4.0
3.7
1 3
1 5
2 5
3 4
3 6
4 7
5 6
6 7
*/
