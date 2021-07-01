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
void alternatemerge(lptr &p,lptr q)
{
    lptr t;
    t=NULL;
    int i=0;
    while(p!=NULL && q!=NULL)
    {
    	if (i%2==0)
    	{
    		addend(t,p->data);
    		p=p->next;
    	}
    	else
    	{
    		addend(t,q->data);
    		q=q->next;
    	}
    	i++;
    }
    while(p!=NULL)
    {
    	addend(t,p->data);
    	p=p->next;
    }
    while(q!=NULL)
    {
    	addend(t,q->data);
    	q=q->next;
    }
    p=t;
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
	lptr L1;
	L1=NULL;
	cin>>n;
	while(n>0)
	{
		addend(L1,n);
		cin>>n;
	}
	alternatemerge(L,L1);
	print(L);
}