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
void deleteduplicatessorted(lptr p)
{
	if (p==NULL)
	{
		return;
	}
	while(p->next!=NULL)
	{
		if (p->data==p->next->data)
		{
			p->next=p->next->next;
		}
		else
			{
				p=p->next;
			}
	}
}
void deleteduplicatesunsorted(lptr p)
{lptr t,k;
	t=p;
	k=p;
	while(k!=NULL)
	{
		t=k->next;
		lptr x=k;
		while(t!=NULL)
		{
            if (k->data==t->data)
            {
                x->next=t->next;
                t=t->next;
            }
            else
            {
                t=t->next;
                x=x->next;
            }
		}
		k=k->next;

	}
}
int main()
{
	lptr L;
	L=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(L,n);
		cin>>n;
	}
	deleteduplicatesunsorted(L);
	print(L);
}
