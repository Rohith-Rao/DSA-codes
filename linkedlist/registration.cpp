#include <iostream>
using namespace std;
struct rnode;
struct snode
{
	int i;
	rnode *sr;
};
typedef struct snode *sptr;
struct cnode
{
	char c;
    rnode *cr;
};
typedef struct cnode *cptr;
struct rnode
{
	rnode *down;
	rnode *next;
	sptr tos;
	cptr toc;
};
typedef struct rnode *rptr;
void cources(sptr s[],cptr c[],int p)
{
  rptr t=s[p-1]->sr;
  while(t!=NULL)
  {
    cout<<t->toc->c<<" ";
    t=t->down;
  }
  cout<<endl;
}
void students(sptr s[],cptr c[],char q)
{
    rptr t=c[int(q)-65]->cr;
    while(t!=NULL)
    {
      cout<<t->tos->i<<" ";
      t=t->next;
    }
    cout<<endl;
}
int main()
{
    sptr s[10]={NULL};
    cptr c[10]={NULL};
    int n;
    char k;
    cin>>n>>k;
    while(n!=-1 && n!='#')
    {
    	rptr r;
    	r=new(rnode);
    	r->next=NULL;
    	r->down=NULL;
    	r->tos=NULL;
    	r->toc=NULL;
    	if (s[n-1]==NULL)
    	{
    		s[n-1]=new(snode);
    		s[n-1]->i=n;
            s[n-1]->sr=r;
            r->tos=s[n-1];
    	}
    	else
    	{
           rptr t=s[n-1]->sr;
           int flag=0;
           while(t->down!=NULL)
           {
              if (t->down->toc->c > k)
              {
              	 r->down=t->down;
              	 t->down=r;
              	 r->tos=s[n-1];
              	 flag=1;
              	 break;
              }
              t=t->down;
           }
           if (flag==0)
           {
           	  t->down=r;
           	  r->tos=s[n-1];
           }
    	}
    	if (c[int(k)-65]==NULL)
    	{
    		c[int(k)-65]=new(cnode);
    		c[int(k)-65]->c=k;
    		c[int(k)-65]->cr=r;
    		r->toc=c[int(k)-65];
    	}
    	else
    	{
            rptr l=c[int(k)-65]->cr;
            int flag=0;
            while(l->next!=NULL)
            {
            	if (l->next->tos->i > n)
            	{
            		r->next=l->next;
            		l->next=r;
            		r->toc=c[int(k)-65];
            		flag=1;
            		break;
            	}
            	l=l->next;
            }
            if (flag==0)
            {
               l->next=r;
               r->toc=c[int(k)-65];
            }
    	}
    	cin>>n>>k;
    }
    int p;
    cin>>p;
    cources(s,c,p);
    cin>>p;
    cources(s,c,p);
    char q;
    cin>>q;
    students(s,c,q);
    cin>>q;
    students(s,c,q);
}
