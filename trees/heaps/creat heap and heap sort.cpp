#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void minheap(int a[],int i,int minH[],int &smin)
{
	for (int j = 0; j < i; j++)
	{
		minH[smin]=a[j];
		int x=smin;
		while(x>0 && minH[(x-1)/2]>minH[x])
		{
            swap(minH[(x-1)/2],minH[x]);
            x=(x-1)/2;
		}
		smin++;
	}
}
void maxheap(int a[],int i,int maxH[],int &smax)
{
   for (int j = 0; j < i; j++)
   {
       maxH[smax]=a[j];
		int x=smax;
		while(x>0 && maxH[(x-1)/2]<maxH[x])
		{
            swap(maxH[(x-1)/2],maxH[x]);
            x=(x-1)/2;
		}
		smax++;
   }
}
int deleteheaproot(int minH[],int &smin)
{
   int t=minH[0];
   minH[0]=minH[smin-1];
   smin--;
   int x=0;
   while(((2*x)+2)<smin && (minH[x]>minH[(2*x)+1] || minH[x]>minH[(2*x)+2]))
   {
       if(minH[x]>minH[(2*x)+1] && minH[x]>minH[(2*x)+2])
        {
         if(minH[(2*x)+2]<minH[(2*x)+1])
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
       else if(minH[x]>minH[(2*x)+1])
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
void heapsort(int h[],int minH[],int smin,int &s)
{
	while(smin>0)
	{
		int k;
		k=deleteheaproot(minH,smin);
		h[s]=k;
		s++;
	}
}
int main()
{
	int a[50];
	int i=0;
	int n;
	cin>>n;
	while(n>0)
	{
		a[i]=n;
		i++;
		cin>>n;
	}
	int minH[50];
	int smin=0;
	int maxH[50];
	int smax=0;
	minheap(a,i,minH,smin);
	for (int j = 0; j < smin; j++)
	{
		cout<<minH[j]<<" ";
	}
	cout<<endl;
	maxheap(a,i,maxH,smax);
	for (int j = 0; j < smax; j++)
	{
		cout<<maxH[j]<<" ";
	}
	cout<<endl;
	int h[50];
	int s=0;
	heapsort(h,minH,smin,s);
	for (int j = 0; j < s; j++)
	{
		cout<<h[j]<<" ";
	}

}


// 5 9 3 6 2 4 8 1 7 -1
// 1 2 4 3 6 5 8 9 7
//9 7 8 6 2 3 4 1 5


/*void Heapsort(vector<int>&H,vector<int>&sorted,int s)
{
    int si = s;int v;
    while(s>=1)
    {
            v = ExtractMin(H,s);
        sorted.push_back(v);
        --s;
    }
}

//Min Heap Array
#include<bits/stdc++.h>
using namespace std;
void heapify(int H[],int n,int s)
{
    H[s] = n;
    while(H[(s-1)/2]>H[s])
    {
        swap(H[s],H[(s-1)/2]);
        s = (s-1)/2; 
    }
}
int main()
{
    int N = 9;
    int arr[N] = {5,9,3,6,2,4,8,1,7};
    int H[N];
    H[0] = arr[0];
    for(int i=1;i<N;i++)
        heapify(H,arr[i],i);
    for(int i=0;i<N;i++)
        cout<<H[i]<<" ";
}*/
