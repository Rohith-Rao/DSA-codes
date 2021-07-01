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
int count(lptr L)
{
	int c=0;
	lptr t=L;
	if (t->next==NULL)
	{
		return 1;
	}
	while(t->next!=L)
	{
		c++;
		t=t->next;
	}
	c++;
	return c;
}
void deletenode(lptr &l)
{
	int c=count(l);
	if (c==2)
	{
		l=l->next;
		l->next=NULL;
		return;
	}
	else
	{
		lptr t=l;
		while(t->next!=l)
		{
			t=t->next;
		}
		t->next=l->next;
		l=l->next;
	}
}
void execute(lptr &l,int m)
{
	int c=count(l);
	if (c==1)
	{
		cout<<endl;
		return;
	}
	for (int i = 0; i < m-1; i++)
	{
		l=l->next;
	}
	cout<<l->data<<" ";
	deletenode(l);
	execute(l,m);

}
int main()
{
	lptr L;
	L=NULL;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin>>k;
		addend(L,k);
	}
	lptr t=L;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=L;
	int m;
	cin>>m;
	execute(L,m);
}
