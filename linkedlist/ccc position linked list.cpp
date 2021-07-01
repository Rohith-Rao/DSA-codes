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
int noofnodes(lptr p)
{
  int n=0;
  while(p!=NULL)
  {
    n++;
    p=p->next;
  }
  return n;
}
void deletelemental(lptr &p,int n)
{   lptr k;
    k=p;
    if(k->data==n)
    {
        k=k->next;
        p=k;
    }
    else
    {
        lptr m;
        m=p;
        int i=0;
        while(k->data!=n)
        {
            if(i==0)
            {
                k=k->next;
                i++;
            }
            else
            {
                k=k->next;
                m=m->next;
            }
        }
        m->next=k->next;
    }

}
void deletelement(lptr &p,lptr t,int n)
{
    int x=noofnodes(t);
    if (n>x)
    {
        return;
    }
    else
    {
        if (n==1)
        {
            p=p->next;
        }
        else
        {
        lptr k,t;
        k=p;
        t=p;
        int e=1;
        int i=0;
        while(e<n)
        {
            if (i==0)
            {
                k=k->next;
                i++;
            }
            else
            {
                k=k->next;
                t=t->next;
            }
            e++;
        }
        deletelemental(L,k->data);
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
	lptr t,t1;
	t=L;
	t1=L;
	int k=1;
	while(t!=NULL)
	{
        deletelement(L,t,t->data);

        t=t->next;
	}
	print(L);
}
