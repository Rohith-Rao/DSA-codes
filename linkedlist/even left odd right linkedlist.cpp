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
void arrangeevenodd(lptr &p)
{
    lptr t1,t2,t3;
    t1=p;
    t3=p;
    while(t1->next!=NULL)
    {
    	t1=t1->next;
    }
    t2=t1;
    while(t3!=t1)
    {
    	if (t3->data%2==1)
    	{
    		addend(t2,t3->data);
    		t2=t2->next;
            deletelement(p,t3->data);
    	}
    	t3=t3->next;
    }
    if(t1->data%2==1)
    {
        addend(t2,t1->data);
        t2=t2->next;
        deletelement(p,t1->data);
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
	arrangeevenodd(L);
	print(L);
}