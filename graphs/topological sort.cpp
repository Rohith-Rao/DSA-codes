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
void reduce_adjacents(int **G,int indegree[],int v,int val)
{
	for (int i = 1; i < v+1; i++)
	{
		if (G[val][i]==1)
		{
			indegree[i]--;
		}
	}
}
void topological_sort(int **G,int v,int indegree[],int visit[])
{
    for (int i = 1; i < v+1; i++)
    {
    	if (indegree[i]==0)
    	{
    		if (visit[i]==0)
    		{
    			visit[i]=1;
    			cout<<i<<" ";
    			reduce_adjacents(G,indegree,v,i);
    			i=1;
    		}
    	}
    }
    cout<<endl;
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

	while(e--)
	{
		int a,b;
		cin>>a>>b;
        G[a][b]=1;
	}
	int indegree[v+1]={0};
	int visit[v+1]={0};
	find_indegers(G,v,indegree);
	topological_sort(G,v,indegree,visit);
}

/*
7
7
1 2
1 3
2 5
3 5
4 6
5 7
6 3
1 2 4 6 3 5 7
*/

/*
7
9
1 2
1 3
1 5
2 4
3 6
3 5
4 6
5 7
6 7
1 2 3 4 5 6 7
*/