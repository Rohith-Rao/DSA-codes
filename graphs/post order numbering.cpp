#include <iostream>
#include <queue>
using namespace std;
void dft_directed(int **G,int visit[],int v,int start,int &k,int pnum[])
{
    visit[start]=1;
    for (int i = 1; i < v+1; i++)
    {
    	if (G[start][i]==1)
    	{
    		if (visit[i]==0)
    		{
    			//cout<<start<<" "<<i<<endl;

    			dft_directed(G,visit,v,i,k,pnum);
    		}
    	}
    }
    pnum[start]=k;
    k++;
}
int main()
{
	int v;
	int e;
	//cin>>v>>e;
	v=10;
	e=15;
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
	int visit[v+1]={0};
	int pnum[v+1]={0};
	int k=1;
    dft_directed(G,visit,v,2,k,pnum);

    dft_directed(G,visit,v,8,k,pnum);
    dft_directed(G,visit,v,7,k,pnum);
   /* for(int i=1;i<v+1;i++)
    {
        cout<<visit[i]<<" ";
    }
    cout<<endl;*/
    for (int i = 1; i < v+1; i++)
    {
    	cout<<i<<" "<<pnum[i]<<endl;
    }
}
