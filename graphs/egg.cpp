#include <iostream>
#include <vector>
using namespace std;
void find_indegree(int **G.int v,int indegree[])
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
void reduce_adjacents(int **G,int indegree[],int v,int val,int visit2[])
{
	for (int i = 1; i < v+1; i++)
	{
		if (G[val][i]==1)
		{
			visit2[i]=1;
			indegree[i]--;
		}
	}
}
void paths(int **G,int v,int indegree[])
{
	int visit1[v+1]={0};
	int visit2[v+1]={0}''
	for (int i = 1; i < v+1; ++i)
	{
		if (visit1[1]==0)
		{
			if (visit2[i]==0)
			{
				visit1[i]=1;
				cout<<i<<" ";
				reduce_adjacents(int **G,indegree,v,i,visit2);
			}
		}
		if (i==v)
		{
			for (int j = 0; j < v+1; j++)
			{
				visit2[j]=0;
			}
			i=1;
		}
	}
}
int main()
{
	int v,e;
	v=8;
	e=7;
	int **G;
    G=new int *[v+1];
	for (int i = 0; i < v+1; i++)
	{
		G[i]=new int [v+1];
	}
     for (int i = 0; i < v+1; i++)
     {
     	for (int j = 0; j < v+1; j++)
     	{
     		G[i][j]=0;
    	}
    }
    G[1][2]=1;
    G[2][3]=1;
    G[3][4]=1;
    G[4][5]=1;
    G[6][7]=1;
    G[7][8]=1;
    G[8][3]=1;
    int indegree[v+1]={0};
    find_indegree(G,v,indegree);
    paths(G,v,indegree);
}