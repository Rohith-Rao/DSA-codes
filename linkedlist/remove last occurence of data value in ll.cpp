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
void deletelastlement(lptr p,lptr t)
{
	lptr k=p;
	int i=0;
	while(p!=t)
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
	k->next=p->next;
	delete(t);
}
void deletelastoccurance(lptr p)
{
	lptr t1,t2,t3;
	t1=p;
	t2=p;
	t3=NULL;
	while(t1!=NULL)
	{
		t2=t1->next;
		while(t2!=NULL)
		{
             if (t2->data==t1->data)
             {
             	t3=t2;
             }
             t2=t2->next;
		}
		if (t3!=NULL)
		{
		   deletelastlement(p,t3);
		   t3=NULL;	
		}
		t1=t1->next;
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
	deletelastoccurance(L);
	print(L);
}
