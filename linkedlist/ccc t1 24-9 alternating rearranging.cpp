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
void addafter(lptr p,int n,int x)
{
   while(p->data!=x)
   {
   	 p=p->next;
   }
   lptr T;
   T=new(node);
   T->data=n;
   T->next=p->next;
   p->next=T;

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
	lptr s,e;
	s=L;
	e=L;
	while(1>0)
	{
		e=s;
		lptr x=s;
		int i=0;
		while(e->next!=NULL)
		{
			if (i==0)
			{
				e=e->next;
				i++;
			}
			else
			{
				e=e->next;
				x=x->next;
			}
		}
        addafter(s,e->data,s->data);
        x->next=NULL;
        s=s->next->next;

        if (s->next==NULL || s->next->next==NULL)
        {
        	break;
        }

	}
	print(L);
}
