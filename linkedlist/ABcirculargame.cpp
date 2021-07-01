#include <iostream>
using namespace std;
struct node
{
	char data;
	node *next;
};
typedef struct node *lptr;
void print(lptr p)
{
	
	lptr t=p;
	while(t->next!=p)
	{
	    cout<<t->data<<" ";
		t=t->next;
	}
	cout<<t->data<<endl;
}
void addend(lptr &p,char n)
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
int countA(lptr l)
{
	int c=0;
	lptr t=l;
	while(t->next!=l)
	{
		if (t->data=='A')
		{
			c++;
		}
		t=t->next;
	}
	if (t->data=='A')
	{
		c++;
	}
	return c;
}
void addB(lptr l,lptr &t)
{
    for (int i = 0; i < 8; i++)
    {
        t=t->next;
        if(t->data=='B')
        {
            t=t->next;
        }
    }
    t->data='B';
    t=t->next;
}
void game(lptr l,lptr &t)
{
	int c;
	c=countA(l);
	cout<<c<<endl;
    if (c==15)
    {
    	return;
    }
    addB(l,t);
    print(l);
    game(l,t);
}
int main()
{
	lptr L;
	L=NULL;
	for (int i = 0; i < 30; i++)
	{
		addend(L,'A');
	}
	lptr t=L;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=L;
	t=L;
	game(L,t);
    print(L);
}
