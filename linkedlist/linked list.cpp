//Twinkle Twinkle Linked Lists
#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
void addend(lptr p,int n)
{
	lptr T;
	T=new(node);
	T->data=n;
	T->next=NULL;
	while(p->next!=NULL)
	{
		p=p->next;
	}
    p->next=T;
}
void print(lptr p)
{
	if (p==NULL)
	{  cout<<endl;
		return;
	}
	cout<<p->data<<" ";
	print(p->next);
}
void reverseprint(lptr p)
{
	if (p==NULL)
	{
		return;
	}
	reverseprint(p->next);
	cout<<p->data<<" ";
}
int find(lptr p,int n)
{
	while(p!=NULL)
	{
		if (p->data==n)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void addfront(lptr &p,int n)
{
	lptr T;
	T=new(node);
	T->data=n;
	T->next=p;
	p=T;

}
void addafter(lptr p,int n,int x)
{
   while(p->data!=x)
   {
   	 p=p->next;
   }
   lptr T;
   T=new(node);
   T->data=n;
   T->next=p->next;
   p->next=T;

}
void addbefore(lptr &p,int n,int x)
{
	lptr k,m,t;
	k=p;
    m=p;
    t=new(node);
    t->data=n;
    t->next=NULL;
    if(m->data==x)
    {
        t->next=m;
        m=t;
        p=m;
    }
	else {
            int i=0;
	while(m->data!=x)
	{
		if (i==0)
		{
			m=m->next;
			i++;
		}
		else
		{
			m=m->next;
			k=k->next;
		}
	}
	t->next=m;
	k->next=t;
	}
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
int minimun(lptr p)
{
	int m=10000;
	while(p!=NULL)
	{
		if (p->data<m)
		{
			m=p->data;
		}
		p=p->next;
	}
	return m;
}
int maximum(lptr p)
{
	int m=-1;
	while(p!=NULL)
	{
		if (p->data>m)
		{
			m=p->data;
		}
		p=p->next;
	}
	return m;
}
void middlenode(lptr p)
{
	lptr t1,t2;
	t1=p;
	t2=p;
	while(t2->next!=NULL)
	{
		t1=t1->next;
		t2=t2->next->next;
	}

	cout<<t1->data<<endl;
}
void odddnoofatavalues(lptr p)
{
	int n=0;
	while(p!=NULL)
	{
		if (p->data%2==1)
		{
			n++;
		}
		p=p->next;

	}
	cout<<n<<endl;
}
void evennoofdatavalues(lptr p)
{
	int n=0;
	while(p!=NULL)
	{
		if (p->data%2==0)
		{
			n++;
		}
        p=p->next;
	}
	cout<<n<<endl;
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
void deletemin(lptr &p)
{
    int k=minimun(p);
    deletelement(p,k);

}
void deletemax(lptr &p)
{
    int k=maximum(p);
    deletelement(p,k);
}
int main()
{
	int n;
	lptr L;
	L=new(node);
	cin>>n;
	L->data=n;
	L->next=NULL;
	cin>>n;
	while(n>0)
	{
	    addend(L,n);
	    cin>>n;
	}
    print(L);
    int k;
    cin>>k;
    addfront(L,k);
    print(L);
    int x,y;
    cin>>x>>y;
    addbefore(L,x,y);
    print(L);
    cin>>x>>y;
    addafter(L,x,y);
    print(L);
    cin>>k;
    deletelement(L,k);
    print(L);
    deletemin(L);
    print(L);
    deletemax(L);
    print(L);

}