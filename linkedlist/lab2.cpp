#include <iostream>
using namespace std;
struct node
 {
 	int data;
 	node *next;
 };
typedef struct node *lptr;
struct slnode
{
	lptr a;
	lptr b;
	slnode *link;
};
typedef struct slnode *slptr;
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
void sort(slptr &p,lptr l1,lptr l2)
{
   slptr t;
   t=new(slnode);
   t->link=NULL;
   if (p==NULL)
   {
   	 p=t;
   }
   else
   {
   	  slptr t1=p;
   	  while(t1->link!=NULL)
   	  {
   	  	t1=t1->link;
   	  }
   	  t1->link=t;
   }
   if(l1->next==NULL)
   {
       t->a=l1;
       t->b=l2;
       return;
   }
   t->a=l1;
   t->b=l2;
   	   lptr k=l1;
   	   int i=0;
   	   while(l1->data < l2->data)
   	   {
          if (i==0)
          {
          	l1=l1->next;
          	i++;
          }
          else
          {
          	l1=l1->next;
          	k=k->next;
          }
   	   }
   	   k->next=NULL;
   	   lptr x=l2;
   	   i=0;
   	   while(l2->data <l1->data)
   	   {
   	   	if (i==0)
   	   	{
   	   		l2=l2->next;;
   	   		i++;
   	   	}
   	   	else
   	   	{
   	   		l2=l2->next;
   	   		x=x->next;
   	   }

   	   	}
   	   	x->next=NULL;
     sort(p,l1,l2);
}

void print(slptr p)
{
	while(p!=NULL)
	{
        while(p->a !=NULL)
        {
        	cout<<p->a->data<<" ";
        	p->a=p->a->next;
        }
        while(p->b!=NULL)
        {
        	cout<<p->b->data<<" ";
        	p->b=p->b->next;
        }
        p=p->link;
	}
}
int main()
{
	lptr l1=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(l1,n);
		cin>>n;
	}
	lptr l2=NULL;
	cin>>n;
	while(n>0)
	{
		addend(l2,n);
		cin>>n;
	}
    slptr p=NULL;
    sort(p,l1,l2);
    print(p);
}

