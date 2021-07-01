#include <iostream>
using namespace std;
struct trpnode
{
	trpnode *lc;
	char key;
	int pri;
	trpnode *rc;
};
typedef trpnode *trpptr;
void left_rotation(trpptr &BT)
{
    trpptr r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}
void right_rotation(trpptr &BT)
{
    trpptr l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}
void inorder(trpptr T)
{
	if (T==NULL)
	{
		return;
	}

	inorder(T->lc);
	cout<<T->key<<" "<<T->pri<<" ";
	inorder(T->rc);
}
void insert(trpptr &T,char k,int n)
{
	if (T==NULL)
	{
		T=new(trpnode);
		T->key=k;
		T->pri=n;
		T->lc=NULL;
		T->rc=NULL;
		return;
	}
	if (k < T->key)
	{
		insert(T->lc,k,n);
	}
	else
	{
		insert(T->rc,k,n);
	}
	if (T->lc!=NULL && T->rc!=NULL)
	{
		if (T->pri > T->lc->pri && T->pri >T->rc->pri)
		{
			if (T->lc->pri < T->rc->pri)
			{
				right_rotation(T);
			}
			else
			{
				left_rotation(T);
			}
		}
		else if (T->lc->pri <T->pri)
		{
			right_rotation(T);
		}
		else if(T->rc->pri < T->pri)
		{
			left_rotation(T);
		}
	}
	else if (T->lc==NULL)
	{
		if (T->rc->pri < T->pri)
		{
			left_rotation(T);
		}
	}
	else
	{
		if (T->lc->pri < T->pri)
		{
			right_rotation(T);
		}
	}
}
void del(trpptr T,trpptr p,int c,int flag)
{
   if (c==0)
   {
   	  if (flag==0)
   	  {
   	  	 p->lc=NULL;
   	  }
   	  else if (flag==1)
   	  {
   	  	 p->rc=NULL;
   	  }
   	  return;
   }
   else if (c==1)
   {
   	  if (flag==0)
   	  {
   	     p->lc=T->lc;
   	  }
   	  else if (flag==1)
   	  {
   	  	 p->rc=T->lc;
   	  }
   	  return;
   }
   else if (c==2)
   {
   	  if (flag==0)
   	  {
   	     p->lc=T->rc;
   	  }
   	  else if (flag==1)
   	  {
   	  	 p->rc=T->rc;
   	  }
   	  return;
   }
   else if (c==3)
   {
   	  if (T->lc->key >T->key)
   	  {
   	  	 T->key=T->lc->key;
   	  	 T->pri=T->lc->pri;
   	  	 if (T->lc->lc!=NULL && T->lc->rc!=NULL)
		{
			c=3;
		}
		else if (T->lc->lc!=NULL)
		{
			c=1;
		}
		else if (T->lc->rc!=NULL)
		{
			c=2;
		}
		else
		{
			c=0;
		}
		del(T->lc,T,c,0);
   	  }
   	  else
   	  {
   	  	T->key=T->rc->key;
   	  	 T->pri=T->rc->pri;
   	  	 if (T->rc->lc!=NULL && T->rc->rc!=NULL)
		{
			c=3;
		}
		else if (T->rc->lc!=NULL)
		{
			c=1;
		}
		else if (T->rc->rc!=NULL)
		{
			c=2;
		}
		else
		{
			c=0;
		}
		del(T->rc,T,c,1);
   	  }
   }
}
void delete_el(trpptr T,trpptr p, char k,int flag)
{
	if (T->key==k)
	{
		int c;
		if (T->lc!=NULL && T->rc!=NULL)
		{
			c=3;
		}
		else if (T->lc!=NULL)
		{
			c=1;
		}
		else if (T->rc!=NULL)
		{
			c=2;
		}
		else
		{
			c=0;
		}
		del(T,p,c,flag);
		return;
	}
	if (T->key < k)
	{
		p=T;
		delete_el(T->lc,p,k,0);
	}
	else
	{
		p=T;
		delete_el(T->rc,p,k,1);
	}
}
int main()
{
	trpptr T=NULL;
	char k;
	cin>>k;
	while(k!='#')
	{
		int n;
		cin>>n;
		insert(T,k,n);
		cin>>k;
	}
	inorder(T);
	trpptr p=NULL;
    cin>>k;
    delete_el(T,p,k,0);

    cin>>k;
    p=NULL;
    delete_el(T,p,k,0);
    inorder(T);
}
//p 45 s 63 h 21 m 36 e 27 g 9 #