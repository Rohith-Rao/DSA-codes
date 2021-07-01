#include <iostream>
using namespace std;
struct  queue
{
	int size=20;
	int front=-1;
	int rear=-1;
	int elements[50];
};
void enqueue(queue &q,int x)
{
	if ((q.rear+1)%q.size==q.front)
	{
		cout<<"full\n";
	}
	else
	{
		if (q.front==-1)
		{
			q.front=0;
			q.rear=0;
		}
		else
		{
			q.rear=(q.rear+1)%q.size;
		}
		q.elements[q.rear]=x;
	}
}
int dequeue(queue &q)
{
	int t;
	if (q.front==-1)
	{
		cout<<"empty\n";
	}
	else
	{
		if (q.front==q.rear)
		{
			t=q.elements[q.front];
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			t=q.elements[q.front];
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
int getmax(int a[],int n)
{
    int max=-1;
    for (int i = 0; i < n; i++)
    {
    	if (a[i]>max)
    	{
    		max=a[i];
    	}
    }
    return max;

}
void bucketsort(int a[],int n,int pos)
{
	queue q[10];

	for (int i = 0; i < n; i++)
	{
		enqueue(q[(a[i]/pos)%10],a[i]);
	}
	int j=0;
	for (int i = 0; i < 10; i++)
	{
		while(q[i].front!=-1)
		{
           int d=dequeue(q[i]);
           a[j]=d;
           j++;
		}
	}
}
void radixbucketsort(int a[],int n)
{
	int k=getmax( a, n);
	for (int pos=1; k/pos>0 ; pos=pos*10)
	{
		bucketsort(a,n,pos);
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	radixbucketsort(a,n);
}
