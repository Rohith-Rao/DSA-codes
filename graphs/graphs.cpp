#include <iostream>
#include <queue>
using namespace std;
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
        G[b][a]=1;
	}
  for (int i = 1; i < v+1; i++)
  {
    for (int j = 1 ;j < v+1; j++)
    {
       cout<<G[i][j]<<" ";
    }
    cout<<endl;
  }
}
/*
5 
7
1 2
1 3
1 4
2 3
3 4
2 5
4 5
*/