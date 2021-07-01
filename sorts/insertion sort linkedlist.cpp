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

void addbefore(lptr &p,int n,int x)
{
	lptr k,m,t;
	k=p;
    m=p;
    t=new(node);
    t->data=n;
    t->next=NULL;
    if(m->data==x)
    {
        t->next=m;
        m=t;
        p=m;
    }
	else {
            int i=0;
	while(m->data!=x)
	{
		if (i==0)
		{
			m=m->next;
			i++;
		}
		else
		{
			m=m->next;
			k=k->next;
		}
	}
	t->next=m;
	k->next=t;
	}
}
void insertionsort(lptr &p)
{
    lptr h;
    h=NULL;
    addend(h,p->data);
    p=p->next;
    lptr t;
    while(p!=NULL)
    {
        t=h;
        while(t->data < p->data && t->next!=NULL)
        {
        	t=t->next;

        }
        if (t->data > p->data)
        {
        	addbefore(h,p->data,t->data);
        }
        else
        {
        	addend(h,p->data);
        }
        p=p->next;

    }
    p=h;
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
	insertionsort(L);
     print(L);
}
