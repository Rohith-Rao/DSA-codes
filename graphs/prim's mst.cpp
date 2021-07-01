#include <iostream>
using namespace std;
void min_spanning_tree(int **G,int v,int visit[],int D[],int start,int pv[])
{
    int flag=0;
    for (int i = 1; i < v+1; i++)
    {

    	if (visit[i]==0)
    	{
    		flag=1;
    		break;
    	}
    }
    if (flag==0)
    {
    	return;
    }
    else
    {
    	visit[start]=1;
    	for (int i = 1; i < v+1; i++)
    	{
    		if (G[start][i]!=0)
    		{
    		    if(visit[i]==0)
                {

    			if (D[i]> G[start][i])
    			{
    				D[i]=G[start][i];
    				pv[i]=start;
    			}
                }
    		}
    	}
    	int min=1000,next;
    	for (int i = 1; i < v+1; i++)
    	{
    		if (visit[i]==0)
    		{
    			if (D[i]< min)
    			{
    			    min=D[i];
    			    next=i;
    			}
    		}
    	}
    	min_spanning_tree(G,v,visit,D,next,pv);
    }
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
    int sum=0;
    
    for (int i = 1; i < v+1; i++)
    {
    	for (int j = 1; j < v+1; j++)
    	{
    		if (pv[j]==i)
    		{
    			cout<<i<<" "<<j<<endl;
    		}
    	}
    }
}