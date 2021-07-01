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
void deletelement(lptr &p,int n)
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
lptr partition(lptr &p)
{
    lptr t=p;
    while(t->next->next!=NULL)
    {
    	t=t->next;
    }
    lptr e=t->next;
    t=p;
    while(p!=e)
    {
    	t=p;
    	while(t!=e)
    	{
    	if (p->data >e->data)
    	{
    		addend(p,p->data);
    		deletelement(p,p->data);
    		break;
    	}
    	t=t->next;
        }
        p=p->next;
    }
    return e;	
}
void quicksort(lptr &p)
{
	lptr k;
	k=partition(p);
	lptr t=p;
    while(t->next!=k)
    {
    	t=t->next;
    }
    t->next=NULL;
    quicksort(p);
    quicksort(k->next);
    t=p;
    while(t->next!=NULL)
    {
    	t=t->next;
    }
    t->next=k;


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
	quicksort(L);
	print(L);
}