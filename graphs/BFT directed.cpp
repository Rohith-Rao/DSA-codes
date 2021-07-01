#include <iostream>
#include <queue>
using namespace std;
void bft_directed(int v,int **G,int start)
{
    queue <int> q;
    int visit[v+1]={0};
    q.push(start);
    visit[start]=1;
    while(!q.empty())
    {
    	int f=q.front();
    	q.pop();
       for (int i = 1; i < v+1; i++)
       {
       	  if (G[f][i]==1)
       	  {
       	      if (visit[i]==0)
       	      	{
       	      		q.push(i);
       	      		visit[i]=1;
       	      		cout<<f<<" "<<i<<endl;
       	      	}
       	  }
       }
    }
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
	int start;
	cin>>start;
    bft_directed(v,G,start);
}


/*
5
7
1 2
1 4
2 3
2 5
3 1
3 4
4 5
1
*/