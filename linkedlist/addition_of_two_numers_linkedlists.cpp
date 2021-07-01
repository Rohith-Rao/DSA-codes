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

	cout<<p->data;
	print(p->next);
}
void reverseprint(lptr p)
{
	if (p==NULL)
	{
		return;
	}
	reverseprint(p->next);
	cout<<p->data;
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
void intolist(lptr &p,int n)
{
    if(n==0)
    {
        return;
    }
    intolist(p,n/10);
    addend(p,n%10);
}
int main()
{
	lptr L1;
	L1=NULL;
	int n;
	cin>>n;
	intolist(L1,n);
	lptr L2;
	L2=NULL;
	cin>>n;
	intolist(L2,n);
	lptr L3;
	L3=NULL;
	int s,c=0;
	while(L1->next!=NULL)
	{
		lptr x=L1;
		lptr y=L2;
		lptr x1=L1;
		lptr y1=L2;
		int i=0;
		while(x->next!=NULL)
		{
		    if(i==0)
            {x=x->next;
            y=y->next;
            i++;}
            else
            {
                x=x->next;
                y=y->next;
                x1=x1->next;
                y1=y1->next;
            }
		}

		s=x->data+y->data+c;
		if (s>9)
		{
			c=s/10;
			s=s%10;
		}
		else
		{
		    c=0;
		}

		addend(L3,s);
		x1->next=NULL;
		y1->next=NULL;

	}
	s=L1->data+L2->data+c;
	addend(L3,s);
	reverseprint(L3);

}

