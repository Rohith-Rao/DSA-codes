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
void deletenodes(lptr &l)
{
	int c=count(l);
	if (c==2)
	{
		l->next=NULL;
		return;
	}
	else if (c==3)
	{
		l->next=NULL;
		return;
	}
	l->next=l->next->next->next;
	l=l->next;
}
void game(lptr &l)
{
	int c=count(l);
	if (c==1)
	{
		cout<<l->data<<endl;
		return;
	}
    deletenodes(l);
    game(l);
}
int main()
{
	lptr L;
	L=NULL;
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		addend(L,i);
	}
	lptr t;
	t=L;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=L;
	game(L);
}

