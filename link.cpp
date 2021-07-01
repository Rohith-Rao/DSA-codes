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
void link(lptr p,lptr q)
{
	lptr k=p;
	while(k->data!=6)
	{
		k=k->data;
	}
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=k;
}
int main()
{
	lptr L1;
	L1=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(L1,n);
		cin>>n;
	}
	lptr L2;
	L2=NULL;
	cin>>n;
	while(n>0)
	{
		addend(L2,n);
		cin>>n;
	}
	link(L1,L2);

	while(L1!=NULL)
	{
		lptr h=L2;
		while(h!=NULL)
		{
			if (L1->data==h->data)
			{
			     cout<<L1->data<<endl;

			}
			else

			{
				h=h->data;
			}
		}
		L1=L1->next;

	}

}