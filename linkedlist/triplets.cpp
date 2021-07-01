#include <iostream>
using namespace std;
struct dlnode
{
	dlnode *right;
	int data;
	dlnode *left;
};
typedef struct dlnode *dlptr;
void addend(dlptr &p,int n)
{
	dlptr t;
	t=new(dlnode);
	t->data=n;
	t->right=NULL;
	t->left=NULL;
	if (p==NULL)
	{
		p=t;
	}
	else
	{
		dlptr t1=p;
		while(t1->right!=NULL)
		{
			t1=t1->right;
		}
        t1->right=t;
        t->left=t1;
	}
}
int main()
{
	dlptr D;
	D=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(D,n);
		cin>>n;
	}
	int s;
	cin>>s;
	dlptr l,h,k;
	k=D;
	while(k->right!=NULL)
	{
		l=D;
		h=D;
		while(h->right!=NULL)
	       {
		     h=h->right;
	       }
        while(1>0)
        {
        	if (l==h || l->data>h->data)
        	{
        		break;
        	}
             else if (l==k)
             {
             	l=l->right;
             }
             else if (h==k)
             {
             	h=h->left;
             }
             else if (l==h)
             {
             	break;
             }
             else
             {
             	int sum=0;
             	sum=(2*k->data)+l->data+h->data;
             	if (sum>s)
             	{
             		h=h->left;
             	}
             	else if (sum < s)
             	{
             		l=l->right;
             	}
             	else
             	{
             		cout<<k->data<<" "<<l->data<<" "<<h->data<<endl;
             		l=l->right;
             		h=h->left;
             	}
             }

        }
        k=k->right;
	}
}
