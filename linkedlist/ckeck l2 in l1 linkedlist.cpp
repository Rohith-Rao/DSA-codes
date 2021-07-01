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
int check(lptr p,lptr q)
{
	lptr t,s;
	while(p!=NULL)
	{
		t=q;
		s=p;
		int flag=0;
		if (s->data==t->data)
		{
			while(t!=NULL)
			{
				if (s->data!=t->data)
				{
					flag=1;
					break;
				}
				s=s->next;
				t=t->next;
			}
			if (flag==0)
			{
				return 1;
			}
		}
		p=p->next;
	}
	return 0;
}
int main()
{
	lptr L;
	int n;
	L=NULL;
	cin>>n;
	while(n>0)
	{
		addend(L,n);
		cin>>n;
	}
	lptr L1;
	L1=NULL;
	cin>>n;
	while(n>0)
	{
		addend(L1,n);
		cin>>n;
	}
	n=check(L,L1);
	cout<<n<<endl;
}