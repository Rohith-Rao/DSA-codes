#include <iostream>
#include <queue>
using namespace std;
void shortest_path(int **G,int v,int visit[],int D[],int start,int goal,int pv[])
{
    /*int flag=0;
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
    }*/
    if (start==goal)
    {
    	cout<<start<<" ";
    	while(pv[start]!=0)
    	{
    		cout<<pv[start]<<" ";
    		start=pv[start];
    	}
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
    				D[i]=D[i]+G[start][i];
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
    	shortest_path(G,v,visit,D,next,goal,pv);
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
		int a,b,c;
		cin>>a>>b>>c;
        G[a][b]=c;
	}
	int visit[v+1]={0};
	int D[v+1];
	for (int i = 0; i < v+1; i++)
	{
		D[i]=100000;
	}
	int pv[v+1]={0}; //previous vertex
	int s,g;  // start goal
	cin>>s>>g;
    shortest_path(G,v,visit,D,s,g,pv);
}


/*
7
12
1 2 2
1 4 1
2 4 3
2 5 10
3 1 4
3 6 5
4 3 2
4 5 2
4 6 8
4 7 4
5 7 6
7 6 1
1 6

1 4 6 7
*/



/*
	queue<int> q;
	q.push(s);
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
	int ans[v+1];
	int t=g;
	int i=0;
			while(1>0)
			{
				if (t==0)
				{
					break;
				}
				ans[i]=t;
				t=pv[t];
				i++;
			}
			for(int j=i-1;j>=0;j--)
            {
                cout<<ans[j]<<" ";
            }
            cout<<endl;
*/