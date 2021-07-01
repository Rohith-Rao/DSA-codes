#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
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
void print(lptr p)
{
	if (p==NULL)
	{  cout<<endl;
		return;
	}
	cout<<p->data<<" ";
	print(p->next);
}
int game(lptr p,lptr q)
{
	int i=0;
	int sa=0,sb=0;
	while(1>0)
	{
        if (p==NULL && q==NULL)
        {
        	break;
        }
        if (i%2==0)
        {
        	if (p==NULL)
        	{
        		sa=sa+q->data;
        		q=q->next;
        	}
        	else if (q==NULL)
        	{
        		sa=sa+p->data;
        		p=p->next;
        	}
        	else
        	{
        		if (p->data > q->data)
        		{
        			sa=sa+p->data;
        			p=p->next;
        		}
        		else
        		{
        			sa=sa+q->data;
        			q=q->next;
        		}
        	}
        }
        else
        {
        	if (p==NULL)
        	{
        		sb=sb+q->data;
        		q=q->next;
        	}
        	else if (q==NULL)
        	{
        		sb=sb+p->data;
        		p=p->next;
        	}
        	else
        	{
        		if (p->data > q->data)
        		{
        			sb=sb+p->data;
        			p=p->next;
        		}
        		else
        		{
        			sb=sb+q->data;
        			q=q->next;
        		}
        	}

        }
        i++;
	}
	if (sb>=sa)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
int main()
{
	lptr L1,L2;
	L1=NULL;
	L2=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(L1,n);
		cin>>n;
	}
	cin>>n;
	while(n>0)
	{
		addend(L2,n);
		cin>>n;
	}
	n=game(L1,L2);
	if (n==1)
	{
		cout<<"A\n";
	}
	else if (n==2)
	{
		cout<<"B\n";
	}
}
