#include <iostream>
using namespace std;
union u
{
	int in;
	char c;
};
struct node
{
	union u data;
	node *next;
};
typedef struct node *lptr;
void addchar(lptr &p,char x)
{
	lptr t;
	t->data.c=x;
	t->next=NULL;
	if (p==NULL)
	{
		p=t;
	}
	else
	{
		t->next=p;
		p=t;
	}
}
void addint(lptr &p,int x)
{
    lptr t;
    t->data.in=x;
    t->next=NULL;
    if (p==NULL)
    {
    	p=t;
    }
    else
    {
    	lptr k;
    	k=p;
    	while(k->next!=NULL)
    	{
    		k=k->next;
    	}
    	k->next=t;
    }
}
void print(lptr p,int tag[],int n)
{
	int i=0;
	while(p!=NULL)
	{
        if (tag[i]==0)
        {
        	cout<<p->data.c<<" ";
        }
        else
        {
        	cout<<p->data.in<<" ";
        }
        i++;
	}
}
int main()
{
	int tag[100];
	lptr L;
	union u x;
	int n=0;
	cin>>tag[n];
	if (tag[n]==0)
	{
		cin>>x.c;
	}
	else 
		{
			cin>>x.in;
		}
	while(tag[n]!=0 && x.c!='#')
	{
		if (tag[n]==0)
		{
			addchar(L,x.c);
			n++;
		}
		else
		{
			addint(L,x.in);
			n++;
		}
		cin>>tag[n];
	   if (tag[n]==0)
	     {
		    cin>>x.c;
	      }
	    else cin>>x.in;
	}

}