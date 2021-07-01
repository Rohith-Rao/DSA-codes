#include <iostream>
using namespace std;
struct slist
{
	int in;
	char c;
	slist *next;
};
typedef struct slist *slptr;
struct node
{
	slist data;
	node *link;
};
typedef struct node *lptr;
void addendslist(slptr &l,int n,char k)
{
	slptr t;
	t=new(slist);
	t->in=n;
	t->c=k;
	t->next=NULL;
	if (l==NULL)
	{
		l=t;
		return;
	}
	else
	{
        slptr t1=l;
        while(t1->next!=NULL)
        {
        	t1=t1->next;
        }
        t1->next=t;
	}
}
void print(slptr l)
{
	while(l!=NULL)
	{
		cout<<l->c<<l->in<<" ";
		l=l->next;
	}
}
int main()
{
	slptr l1,l2,l3;
	l1=NULL;
	l2=NULL;
	l3=NULL;
    int n;
    char k;
    cin>>k>>n;
    while(k!='#' && n!=-1)
    {
    	addendslist(l1,n,k);
    	cin>>k>>n;
    }
    cin>>k>>n;
    while(k!='#' && n!=-1)
    {
    	addendslist(l2,n,k);
    	cin>>k>>n;
    }
    cin>>k>>n;
    while(k!='#' && n!=-1)
    {
    	addendslist(l3,n,k);
    	cin>>k>>n;
    }
    print(l1);
    print(l2);
    print(l3);
}