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
int find(lptr p,int n)
{
	if (p==NULL)
	{
		return 0;
	}
	else
	{
		int flag=0;
		while(p!=NULL)
		{
			if (p->data==n)
			{
				flag=1;
				break;
			}
			p=p->next;
		}
		return flag;
	}
}
void printcircles(lptr l,lptr s,lptr &c)
{
    if (s==l && c!=NULL)
       {
       	   return;
       }
    else
    {

    	int f;
    	f=find(c,s->data);
    	if (f==1)
    	{
    		printcircles(l,s->next,c);
    	}
    	else
    	{

            lptr t,k;
            t=s->next;
            k=s;
            int flag=0;
            while(t!=s)
            {
            	if (t->data==s->data )
            	{
            		while(k!=t)
            		{
            			cout<<k->data<<" ";
            			k=k->next;
            		}
            		cout<<k->data<<endl;
            		flag=1;
            	}
            	t=t->next;
            }
            if (flag==1)
            {
            	while(k!=t)
            	{
            		cout<<k->data<<" ";
            		k=k->next;
            	}
            	cout<<k->data<<endl;
            }
            addend(c,s->data);
            printcircles(l,s->next,c);
    	}

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
	lptr t=L;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=L;
	lptr s=L;
	lptr c=NULL;
	printcircles(L,s,c);
}
