#include <iostream>
using namespace std;
struct node
{
	int d;
	int v1;
	int v2;
};
void swap(node &a,node &b)
{
	node t;
	t=a;
	a=b;
	b=t;
}
void maxheap(node a[],int ind,node maxH[],int &smax)
{
   for (int j = 0; j < i; j++)
   {
       maxH[smax]=a[j];
		int x=smax;
		while(x>0 && maxH[(x-1)/2].d<maxH[x].d)
		{
            swap(maxH[(x-1)/2],maxH[x]);
            x=(x-1)/2;
		}
		smax++;
   }
}
int deleteheaproot(node maxH[],int &smax)
{
   int t=maxH[0];
   maxH[0]=maxH[smax-1];
   smax--;
   int x=0;
   while(((2*x)+2)<smax && (maxH[x].d<maxH[(2*x)+1].d || maxH[x].d<maxH[(2*x)+2].d))
   {
       if(maxH[x].d<maxH[(2*x)+1].d && maxH[x].d<maxH[(2*x)+2].d)
        {
         if(maxH[(2*x)+2].d>maxH[(2*x)+1].d)
          {
            swap(maxH[x],maxH[(2*x)+2]);
            x=(2*x)+2;
          }
         else
          {
           swap(maxH[x],maxH[(2*x)+1]);
            x=(2*x)+1;
          }
       }
       else if(maxH[x].d<maxH[(2*x)+1].d)
       {
            swap(maxH[x],maxH[(2*x)+1]);
            x=(2*x)+1;
       }
       else
       {
           swap(maxH[x],maxH[(2*x)+2]);
            x=(2*x)+2;
       }
   }
		return t;
}
void dft_undirected(int **G,int visit[],int v,int start,int end,int &x)
{
    visit[start]=1;
    if (start==end)
    {
    	x=1;
    	return;
    }
    {
    	/* code */
    }
    for (int i = 1; i < v+1; i++)
    {
    	if (G[start][i]==1)
    	{
    		if (visit[i]==0)
    		{
    			cout<<start<<" "<<i<<endl;
    			dft_undirected(G,visit,v,i);
    		}
    	}
    }
}
void minimun_spaning_tree(int **G,int v,node maxH,int smax)
{
   while(smax>=0)
   {
      t=deleteheaproot(maxH,smax);
      int x=0;
      int visit[v+1]={0};
      G[t.v1][t.v2]=0;
      G[t.v2][t.v1]=0;
      dft_undirected(G,visit,v,t.v1,t.v2,x);
      if (x==1)
      {
      	 G[t.v1][t.v2]=1;
      G[t.v2][t.v1]=1;
      }
      else
      {
         cout<<t.v1<<" "<<t.v2<<endl;
      }
   }	
}
int main()
{
	int v;
	int e;
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
	/*int set[v+1];
	for(int i=0;i<v+1;i++)
    {
        set[i]=-1;
    }*/
	node a[e+1];
	int ind=0;
	G[1][2]=2;
	arr[ind].d=2;
	arr[ind].v1=1;
	arr[ind].v2=2;
	ind++;
	G[1][3]=4;
	arr[ind].d=4;
	arr[ind].v1=1;
	arr[ind].v2=3;
	ind++;
	G[1][4]=1;
	arr[ind].d=1;
	arr[ind].v1=1;
	arr[ind].v2=4;
	ind++;
	G[2][1]=2;
	/*arr[ind].d=2;
	arr[ind].v1=2;
	arr[ind].v2=1;
	ind++;*/
	G[2][4]=3;
	arr[ind].d=3;
	arr[ind].v1=2;
	arr[ind].v2=4;
	ind++;
	G[2][5]=10;
	arr[ind].d=10;
	arr[ind].v1=2;
	arr[ind].v2=5;
	ind++;
	G[3][1]=4;
	/*arr[ind].d=4;
	arr[ind].v1=3;
	arr[ind].v2=1;
	ind++;*/
	G[3][4]=2;
	arr[ind].d=2;
	arr[ind].v1=3;
	arr[ind].v2=4;
	ind++;
	G[3][6]=5;
	arr[ind].d=5;
	arr[ind].v1=3;
	arr[ind].v2=6;
	ind++;
	G[4][1]=1;
	/*arr[ind].d=1;
	arr[ind].v1=4;
	arr[ind].v2=1;
	ind++;*/
	G[4][2]=3;
	/*arr[ind].d=3;
	arr[ind].v1=4;
	arr[ind].v2=2;
	ind++;*/

	G[4][3]=2;
	/*arr[ind].d=2;
	arr[ind].v1=4;
	arr[ind].v2=3;
	ind++;*/

	G[4][5]=7;
	arr[ind].d=7;
	arr[ind].v1=4;
	arr[ind].v2=5;
	ind++;
	G[4][6]=8;
	arr[ind].d=8;
	arr[ind].v1=4;
	arr[ind].v2=6;
	ind++;
	G[4][7]=4;
	arr[ind].d=4;
	arr[ind].v1=4;
	arr[ind].v2=7;
	ind++;
	G[5][2]=10;
	/*arr[ind].d=10;
	arr[ind].v1=5;
	arr[ind].v2=2;
	ind++;*/

	G[5][4]=7;
	/*arr[ind].d=7;
	arr[ind].v1=5;
	arr[ind].v2=4;
	ind++;*/

	G[5][7]=6;
	arr[ind].d=6;
	arr[ind].v1=5;
	arr[ind].v2=7;
	ind++;

	G[6][3]=5;
	/*arr[ind].d=5;
	arr[ind].v1=6;
	arr[ind].v2=3;
	ind++;*/

	G[6][4]=8;
	/*arr[ind].d=8;
	arr[ind].v1=6;
	arr[ind].v2=4;
	ind++;*/

	G[6][7]=1;
	arr[ind].d=1;
	arr[ind].v1=6;
	arr[ind].v2=7;
	ind++;

	G[7][6]=1;
	/*arr[ind].d=1;
	arr[ind].v1=7;
	arr[ind].v2=6;
	ind++;*/
	G[7][4]=4;
	/*arr[ind].d=4;
	arr[ind].v1=7;
	arr[ind].v2=4;
	ind++;*/
	G[7][5]=6;
	/*arr[ind].d=6;
	arr[ind].v1=7;
	arr[ind].v2=5;
	ind++;*/
	node maxH[50];
	int smax=0;
	maxheap(a,ind,maxH,smax);
		/*for(int i=0;i<7;i++)
        {
            set[i]=-1;
        }*/
       /* for(int i=0;i<smin;i++)
        {
            if(arr[i].d==1)
            {
                cout<<arr[i].v1<<" "<<arr[i].v2<<endl;
            }
        }
        cout<<"x\n";
        cout<<smin<<endl;*/
	minimun_spaning_tree(G,v,maxH,smax);
	//bft_undirected(v,G,1);
}
