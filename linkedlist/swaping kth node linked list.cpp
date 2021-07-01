#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
void print(lptr p)
{
	if (p==NULL)
	{  cout<<endl;
		return;
	}
	cout<<p->data<<" ";
	print(p->next);
}
void addend(lptr &p,int n)
{
	lptr T;
	T=new(node);
	T->data=n;
	T->next=NULL;
	if(p==NULL)
    {
        p=T;
        return;
    }
    lptr t1=p;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
    t1->next=T;
}
int noofnodes(lptr p)
{
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
void swapk(lptr &p ,int k)
{
	lptr f=p;
     int n=noofnodes(p);
     int i=k,j=n-k+1;
     lptr x,y;
     x=p;
     y=p;
     int c=1;
     while(p!=NULL)
     {
         if (c==i)
         {
         	x=p;
         }
         if (c==j)
         {
         	y=p;
         	break;
         }
         c++;
         p=p->next;
     }
     c=x->data;
     x->data=y->data;
     y->data=c;
     p=f;
}
int main()
{
	lptr L;
	int n;
	L=NULL;
	cin>>n;
	while(n>0)
	{
		addend(L,n);
		cin>>n;
	}
	int k;
	cin>>k;
	swapk(L,k);
     print(L);
}
