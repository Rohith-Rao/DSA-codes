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
	lptr t1=L;
	n=2;
	while(n<=5)
	{
		t=t->next;
		n++;
	}
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
	t1->next=t;

	lptr st,ft;
	st=L;
	ft=L;
	int flag=0;
	while(1>0)
	{
		st=st->next;
		ft=ft->next->next;
		if (ft->next==NULL)
		{
			flag=1;
			break;
		}
		else if (st==ft)
		{
			break;
		}
	}
	if (flag==0)
	{
		cout<<"1\n";
		cout<<t->data<<endl;
	}

}
