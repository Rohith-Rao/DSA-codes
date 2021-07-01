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
void push(lptr &p,int n)
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
int pop(lptr p)
{
	if (p==NULL)
	{
		cout<<"empty\n";
	}
	else
	{
		lptr k=p;
		int i=0;
		while(p->next!=NULL)
		{
			if (i==0)
			{
				p=p->next;
				i++;
			}
			else
			{
				p=p->next;
				k=k->next;
			}
		}
		i=p->data;
		k->next=NULL;
		return i;
	}
}
int peep(lptr p)
{
	if (p==NULL)
	{
		cout<<"empty\n";
	}
	else
	{
		int i=0;
		while(p->next!=NULL)
		{
				p=p->next;
		}
		i=p->data;
		return i;
	}
}
void enquque(lptr &p,int n)
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
int dequque(lptr &p)
{
	if (p==NULL)
	{
		cout<<"empty\n";
	}
	else
	{
		int x=p->data;
		p=p->next;
		return x;
	}
}
int front(lptr p)
{
   if (p==NULL)
	{
		cout<<"empty\n";
	}
	else
	{
		int x=p->data;
		return x;
	}	
}
int main()
{
	lptr L;
	L=NULL;
	push(L,5);
	push(L,7);
	push(L,1);
	push(L,6);
	pop(L);
	pop(L);
	print(L);
	L=NULL;
	enquque(L,5);
	enquque(L,7);
	enquque(L,1);
	enquque(L,6);
	dequque(L);
	dequque(L);
}
