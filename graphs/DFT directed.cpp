#include <iostream>
#include <queue>
using namespace std;
void dft_directed(int **G,int visit[],int v,int start)
{
    visit[start]=1;
    for (int i = 1; i < v+1; i++)
    {
    	if (G[start][i]==1)
    	{
    		if (visit[i]==0)
    		{
    			cout<<start<<" "<<i<<endl;
    			dft_directed(G,visit,v,i);
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
	int visit[v+1]={0};
	dft_directed(G,visit,v,start);
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