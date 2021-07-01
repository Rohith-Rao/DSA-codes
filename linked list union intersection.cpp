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
void deleteduplicates(lptr p)
{
	if (p==NULL)
	{
		return;
	}
	while(p->next!=NULL)
	{
		if (p->data==p->next->data)
		{
			p->next=p->next->next;
		}
		else
			{
				p=p->next;
			}
	}
}
void unionsorted(lptr L1,lptr L2,lptr &L3)
{
	deleteduplicates(L1);
	deleteduplicates(L2);
	while(L1!=NULL && L2!=NULL)
	{
	    if (L1->data < L2->data)
	    	{
	    			addend(L3,L1->data);
	    			L1=L1->next;
	    	}
	    else if(L2->data < L1->data)
	    {
                addend(L3,L2->data);
                L2=L2->next;

	    }
	    else
        {
            addend(L3,L2->data);
            L1=L1->next;
            L2=L2->next;
        }
	}
	while(L1!=NULL)
	{
		addend(L3,L1->data);
		L1=L1->next;
	}
	while(L2!=NULL)
	{
		addend(L3,L2->data);
		L2=L2->next;
	}

}
void intersectionsorted(lptr L1,lptr L2,lptr &L3)
{
    while(L1!=NULL && L2!=NULL)
	{
	    if (L1->data < L2->data)
	    	{

	    			L1=L1->next;
	    	}
	    else if(L2->data < L1->data)
	    {

                L2=L2->next;

	    }
	    else
        {
            addend(L3,L2->data);
            L1=L1->next;
            L2=L2->next;
        }
	}
}
void differencesorted(lptr L1,lptr L2,lptr &L3)
{
	lptr k=L3;
	lptr t;
	L3=NULL;
	while(L1!=NULL)
    {
        t=k;
        int flag=0;
        while(t!=NULL)
        {
            if(L1->data==t->data)
            {
                flag=1;
                break;
            }
            t=t->next;
        }
        if(flag==0)
        {
            addend(L3,L1->data);
        }
        L1=L1->next;
    }

}
void unionunsorted(lptr L1,lptr L2,lptr &L3)
{
	lptr t=L1;
	while(t!=NULL)
	{
		addend(L3,t->data);
		t=t->next;
	}
	while(L2!=NULL)
	{
		t=L1;
		int flag=0;
		while(t!=NULL)
		{
            if (L2->data==t->data)
            {
            	flag=1;
            	break;
            }
            t=t->next;
		}
		if (flag==0)
		{
			addend(L3,L2->data);
		}
		L2=L2->next;
	}
}
void intersectionunsorted(lptr L1,lptr L2,lptr &L3)
{
	lptr t;
	while(L1!=NULL)
	{
		t=L2;
		int flag=0;
		while(t!=NULL)
		{
             if (L1->data==t->data)
             {
             	 flag=1;
             	 break;
             }
             t=t->next;
		}
		if (flag==1)
		{
			addend(L3,L1->data);
		}
		L1=L1->next;
	}
}
void differenceunsorted(lptr L1,lptr L2,lptr &L3)
{
	lptr t;
	while(L1!=NULL)
	{
		t=L2;
		int flag=0;
		while(t!=NULL)
		{
             if (L1->data==t->data)
             {
             	 flag=1;
             	 break;
             }
             t=t->next;
		}
		if (flag==0)
		{
			addend(L3,L1->data);
		}
		L1=L1->next;
	}
}
int main()
{
    lptr L1=NULL;
    int n;
    cin>>n;
    while(n>0)
    {
        addend(L1,n);
        cin>>n;
    }
    lptr L2=NULL;
    cin>>n;
    while(n>0)
    {
        addend(L2,n);
        cin>>n;
    }
    lptr L3=NULL;
    unionsorted(L1,L2,L3);
    print(L3);
    L3=NULL;
    intersectionsorted(L1,L2,L3);
    print(L3);
    differencesorted(L1,L2,L3);
    print(L3);



    L1=NULL;
    cin>>n;
    while(n>0)
    {
        addend(L1,n);
        cin>>n;
    }
    L2=NULL;
    cin>>n;
    while(n>0)
    {
        addend(L2,n);
        cin>>n;
    }
    L3=NULL;
    unionunsorted(L1,L2,L3);
    print(L3);
    L3=NULL;
    intersectionunsorted(L1,L2,L3);
    print(L3);
    L3=NULL;


}