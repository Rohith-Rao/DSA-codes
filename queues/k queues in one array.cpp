#include <iostream>
using namespace std;
struct kqueue
{   int k;
	int size;
	int front[50];
	int rear[50];
	int max[50];
	int min[50];
	int elements[50];
};
void kenqueue(struct kqueue &q,int i,int x)
{
	i=i-1;
    if ((q.rear[i]+1)%q.max[i]==q.front[i])
    {
      cout<<"full\n";
    }
    else
    {
      if (q.front[i]==q.min[i]-1)
      {
        q.front[i]=q.min[i];
        q.rear[i]=q.min[i];
      }
      else
      {
        q.rear[i]=(q.rear[i]+1)%q.max[i];
      }
      q.elements[q.rear[i]]=x;
    }
}
int kdequeue(struct kqueue &q ,int i)
{   int t;
	i=i-1;
   if (q.front[i]==q.min[i]-1)
   {
      cout<<"empty\n";
   }
   else
   {
       if (q.front[i]==q.rear[i])
       {   t=q.elements[q.front[i]];
          q.front[i]=q.min[i]-1;
          q.rear[i]=q.min[i]-1;
       }
       else
       {  t=q.elements[q.front[i]];
          q.front[i]=(q.front[i]+1)%q.max[i];
       }
     return t;
   }
}
int main()
{
    kqueue q;
    cin>>q.k;
    q.size=50;
     for (int i = 0; i < q.k; i++)
     {
     	q.min[i]=(i*50)/q.k;
     	q.front[i]=(i*50)/q.k-1;
     	q.rear[i]=(i*50)/q.k-1;
		q.max[i]=(i+1)*(50/q.k)-1;
     }
     kenqueue(q,1,5);
     int b=kdequeue(q,1);
     cout<<b;

}