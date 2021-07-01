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
void minheap(node arr[],int ind,node minH[],int &smin)
{
	for (int j = 0; j < ind; j++)
	{
		minH[smin]=arr[j];
		int x=smin;
		while(x>0 && minH[(x-1)/2].d>minH[x].d)
		{
            swap(minH[(x-1)/2],minH[x]);
            x=(x-1)/2;
		}
		smin++;
	}
}
int find(int set[],int x)
{
	if (set[x]==-1)
	{
		return x;
	}
	else
	{
		return find(set,set[x]);
	}
}
void uni(int set[],int x,int y)
{
	if (set[y]==-1)
	{
		set[y]=x;
	}
	else if (set[x]==-1)
	{
		set[x]=y;
	}
	else
	{
	    uni(set,find(set,set[x]),find(set,set[y]));
	}
}
node deleteheaproot(node minH[],int &smin)
{
   node t=minH[0];
   minH[0]=minH[smin-1];
   smin--;
   int x=0;
   while(((2*x)+2)<smin && (minH[x].d>minH[(2*x)+1].d || minH[x].d>minH[(2*x)+2].d))
   {
       if(minH[x].d>minH[(2*x)+1].d && minH[x].d>minH[(2*x)+2].d)
        {
         if(minH[(2*x)+2].d<minH[(2*x)+1].d)
          {
            swap(minH[x],minH[(2*x)+2]);
            x=(2*x)+2;
          }
         else
          {
           swap(minH[x],minH[(2*x)+1]);
            x=(2*x)+1;
          }
       }
       else if(minH[x].d>minH[(2*x)+1].d)
       {
            swap(minH[x],minH[(2*x)+1]);
            x=(2*x)+1;
       }
       else
       {
           swap(minH[x],minH[(2*x)+2]);
            x=(2*x)+2;
       }
   }

		return t;
}
void minimun_spaning_tree(node minH[],int smin,int set[])
{
	while(smin>=0)
	{
		node t=deleteheaproot(minH,smin);
		//cout<<t.d<<endl;
		//cout<<t.v1<<" "<<t.v2<<endl;
		int a=t.v1,b=t.v2;
		/*for(int i=0;i<7;i++)
        {
            cout<<set[i]<<" ";
        }
        cout<<endl;*/
		if (find(set,t.v1)!=find(set,t.v2))
		{
			uni(set,a,b);
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
	int set[v+1];
	for(int i=0;i<v+1;i++)
    {
        set[i]=-1;
    }
	node arr[e+1];
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
	/*G[2][1]=2;
	arr[ind].d=2;
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
	/*G[3][1]=4;
	arr[ind].d=4;
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
	/*G[4][1]=1;
	arr[ind].d=1;
	arr[ind].v1=4;
	arr[ind].v2=1;
	ind++;
	G[4][2]=3;
	arr[ind].d=3;
	arr[ind].v1=4;
	arr[ind].v2=2;
	ind++;

	G[4][3]=2;
	arr[ind].d=2;
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
	/*G[5][2]=10;
	arr[ind].d=10;
	arr[ind].v1=5;
	arr[ind].v2=2;
	ind++;

	G[5][4]=7;
	arr[ind].d=7;
	arr[ind].v1=5;
	arr[ind].v2=4;
	ind++;*/

	G[5][7]=6;
	arr[ind].d=6;
	arr[ind].v1=5;
	arr[ind].v2=7;
	ind++;

	/*G[6][3]=5;
	arr[ind].d=5;
	arr[ind].v1=6;
	arr[ind].v2=3;
	ind++;

	G[6][4]=8;
	arr[ind].d=8;
	arr[ind].v1=6;
	arr[ind].v2=4;
	ind++;*/

	G[6][7]=1;
	arr[ind].d=1;
	arr[ind].v1=6;
	arr[ind].v2=7;
	ind++;

	/*G[7][6]=1;
	arr[ind].d=1;
	arr[ind].v1=7;
	arr[ind].v2=6;
	ind++;
	G[7][4]=4;
	arr[ind].d=4;
	arr[ind].v1=7;
	arr[ind].v2=4;
	ind++;
	G[7][5]=6;
	arr[ind].d=6;
	arr[ind].v1=7;
	arr[ind].v2=5;
	ind++;*/
	node minH[50];
	int smin=0;
	minheap(arr,ind,minH,smin);
		for(int i=0;i<7;i++)
        {
            set[i]=-1;
        }
       /* for(int i=0;i<smin;i++)
        {
            if(arr[i].d==1)
            {
                cout<<arr[i].v1<<" "<<arr[i].v2<<endl;
            }
        }
        cout<<"x\n";
        cout<<smin<<endl;*/
	minimun_spaning_tree(minH,smin,set);
}
