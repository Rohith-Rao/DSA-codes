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
void reverselist(lptr &p,lptr &b)
{

	if (p->next==NULL)
	{
	    b=p;
		return ;
	}
	else
	{
		reverselist(p->next,b);
		lptr q=p->next;
		q->next=p;
		p->next=NULL;
	}
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
	lptr b;
	b=NULL;
	reverselist(L,b);
	L=b;
     print(L);
}
