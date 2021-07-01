/*Life is of Arrival Departure 
Love is Forever*/
#include <iostream>
#include <queue>
using namespace std;
void dft_directed(int **G,int visit[],int v,int start,int at[],int dt[],int &time)
{
    visit[start]=1;
    at[start]=time;
    time++;
    int i;
    for ( i = 0; i < v; i++)
    {
    	if (G[start][i]==1)
    	{
    		if (visit[i]==0)
    		{
    			//cout<<start<<" "<<i<<endl;
    			dft_directed(G,visit,v,i,at,dt,time);
    		}
    	}
    }
    dt[start]=time;
    time++;
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
	int at[v+1]={0};
	int dt[v+1]={0};
	int time=0;
	int start;
	cin>>start;
	int visit[v+1]={0};
	dft_directed(G,visit,v,start,at,dt,time);
	while(1>0){
	int flag=0;
	int i;
	for ( i = 0; i < v; i++)
	{
		if (visit[i]==0)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
	{
		dft_directed(G,visit,v,i,at,dt,time);
	}
	else
	{
		break;
	}
    }
    for (int i = 0; i < v; i++)
    {
    	cout<<at[i]<<" "<<dt[i]<<endl;;
    }
}



