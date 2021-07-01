#include <iostream>
#include <queue>
using namespace std;
void min_spanning_tree(int **G,int v,int visit[],int D[],int start,int pv[])
{
	queue<int> q;
	q.push(start);
	int k=0;
	while(q.size()>0)
	{
		int t=q.front();
		q.pop();

			if (k==0 && visit[t]==0)
			{
				visit[t]=1;
				D[t]=0;
				pv[t]=0;
				for (int i = 1; i < v+1; ++i)
				{
					if(G[t][i]!=0)
					{
						q.push(i);
						if (D[i]>G[t][i])
						{
							D[i]=G[t][i];
							pv[i]=t;
						}
					}
				}
				k++;
			}
			else if(visit[t]==0)
			{
                 visit[t]=1;
                 for (int i = 1; i < v+1; ++i)
				{
					if(G[t][i]!=0)
					{
						q.push(i);
						if (D[i]>G[t][i])
						{
							D[i]=G[t][i];
							pv[i]=t;
						}
					}
				}
			}
			

	}
	int ans=0;
	for (int i = 1; i < v+1; i++)
	{
		for (int j = 1; j < v+1; j++)
		{
			if (pv[j]==i)
			{
				cout<<i<<" "<<j<<endl;
				ans=ans+G[i][j];
			}
		}
	}
	cout<<ans;
}
int main()
{
	int v;
	int e;
	//cin>>v>>e;
	v=7;
	e=12;
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

	/*while(e--)
	{
		int a,b;
		cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
	}*/
	G[1][2]=2;
	G[1][3]=4;
	G[1][4]=1;
	G[2][1]=2;
	G[2][4]=3;
	G[2][5]=10;
	G[3][1]=4;
	G[3][4]=2;
	G[3][6]=5;
	G[4][1]=1;
	G[4][2]=3;
	G[4][3]=2;
	G[4][5]=7;
	G[4][6]=8;
	G[4][7]=4;
	G[5][2]=10;
	G[5][4]=7;
	G[5][7]=6;
	G[6][3]=5;
	G[6][4]=8;
	G[6][7]=1;
	G[7][6]=1;
	G[7][4]=4;
	G[7][5]=6;
	int visit[v+1]={0};
	int pv[v+1]={0};
	int D[v+1];
	for (int i = 0; i < v+1; i++)
	{
		D[i]=100000;
	}
	int start=1;
    min_spanning_tree(G,v,visit,D,start,pv);
}
