#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
struct queue
{
	int k;
	lptr L=NULL;
	lptr l[k+2]={NULL};
};
int num(queue q,lptr p)
{
	for (int i = 1; i < q.k+1; ++i)
	{
		if (p==q.l[i])
		{
			return i;
		}
	}
}
void enqueue(queue &q,int n,int x)
{
	if (q.l[n]==NULL)
	{
		q.l[n]=new(node);
		q.l[n]->data=x;
		q.l[n]->next=NULL;
		if (q.L!=NULL)
		{
			q.L=q.l[n];
		}
		else
		{
			lptr t=q.L;
			int i;
			for ( i = 1; i < q.k+1; i++)
			{
				if (q.l[i]==t)
				{
					break;
				}
			}
		    if (i<n)
			{
				lptr p=new(node);
				p->data=x;
				p->next=t;
				t=p;
				q.[n]=p;
			}
			else
			{
				lptr h=t;
				int flag=0;
                while(h->next!=NULL)
                {
                	int f=num(q,h);
                	if (f>n)
                	{
                		flag=1;
                		break;
                	}
                	else
                	{
                		h=h->next;
                	}
                }
                if (flag==0)
                {
                   lptr p=new(node);
                   p->data=x;
                   p->next=NULL;
                   h->next=p;
                   q.l[n]=p;
                }
                else
                {
                	lptr p=new(node);
                	p->data=x;
                	p->next=NULL;
                	while(t->next!=h)
                	{
                		t=t->next;
                	}
                	p->next=t->next;
                	t->next=p;
                	q.[n]=p;
                }
			}
		}

	}
	else
	{
		lptr p=q.[n];
		while(p->next!=q.[n+1])
		{
           p=p->next;
		}
		lptr v=new(node);
		v->data=x;
		v->next=p->next;
		p->next=v;
	}
}
void dequeuq(queue &q,int n)
{
	
}
