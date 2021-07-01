#include <iostream>
#include <string>
using namespace std;
struct hnode
{
	int freq;
	int code;
	char charecter;
	hnode *lchild;
	hnode *rchild;
};
typedef struct hnode *hptr;
struct queue
{
	int size=50;
	int front=-1;
	int rear=-1;
	hptr elements[100];
};
void enqueue(queue &q,hptr h)
{
	if ((q.rear+1)%q.size==q.front)
	{
		cout<<"full\n";
	}
	else
	{
		if (q.rear==-1 && q.front==-1)
		{
			q.front=0;
			q.rear=0;
		}
		else
		{
			q.rear=(q.rear+1)%q.size;
		}
		q.elements[q.rear]=h;
	}
}
hptr dequeue(queue &q)
{
    hptr h;
    if (q.front==-1)
    {
    	cout<<"empty\n";
    }
    else
    {
    	if (q.front==q.rear)
    	{
    		h=q.elements[q.front];
    		q.front=-1;
    		q.rear=-1;
    	}
    	else
    	{
    		h=q.elements[q.front];
    		q.front=(q.front+1)%q.size;
    	}
    	return h;
    }
}
void remove(queue &q,hptr m)
{
	while(1>0)
	{
		hptr t;
		t=dequeue(q);
		if (t->charecter==m->charecter && t->freq==m->freq)
		{
			break;
		}
		else
		{
			enqueue(q,t);
		}
	}
}
hptr minimun(queue q)
{
	hptr m;
	int min=10000;
	while(q.front!=-1)
	{
       hptr t;
       t=dequeue(q);
       if (t->freq<min)
       {
       	  min=t->freq;
       	  m=t;
       }
	}
	return m;
}
hptr construct(queue q)
{

	while(1>0)
	{
    if (q.front==q.rear)
	  {
		hptr h;
		h=dequeue(q);
		return h;
	   }
      hptr m1,m2;
      m1=minimun(q);
      remove(q,m1);
      m2=minimun(q);
      remove(q,m2);
      if(m1->freq==m2->freq)
      {
          hptr o;
          o=m2;
          m2=m1;
          m1=o;
      }
      hptr t;
      t=new(hnode);
      t->charecter='w';
      t->freq=m1->freq+m2->freq;
      t->rchild=m1;
      t->lchild=m2;
      enqueue(q,t);
      t=NULL;
	}

}
void codein(hptr h,int i)
{
	if (h==NULL)
	{
		return;
	}
	h->code=i;
	codein(h->lchild,0);
	codein(h->rchild,1);
}
void fillcode(hptr H)
{
	codein(H->lchild,0);
	codein(H->rchild,1);
}
void printdata(hptr h,char c[],int &l)
{
	if (h==NULL)
	{
		return;
	}
	else if (h->lchild==NULL && h->rchild==NULL)
	{
		cout<<"( "<<h->charecter<<" "<<h->freq<<" )\n";
        c[l]=h->charecter;
        l++;
	}
	else
	{
		printdata(h->lchild,c,l);
		printdata(h->rchild,c,l);
	}
}
void paths(hptr h,int a[],int b[],int i,int &j)
{
   if (h==NULL)
   {
   	 return;
   }
   a[i]=h->code;
   i++;
   if (h->lchild==NULL && h->rchild==NULL)
   {
   	  for (int k = 0; k < i; k++)
   	  {
   	  	 b[j]=a[k];
   	  	 j++;
   	  }
   	  b[j]=-1;
   	  j++;
   }
   else
   {
   	 paths(h->lchild,a,b,i,j);
   	 paths(h->rchild,a,b,i,j);
   }
}
int findc(char k,char c[],int l)
{
   for (int i = 0; i < l; i++)
   {
   	  if (c[i]==k)
   	  {
   	  	return i;
   	  }
   }
}
void printpath(int b[],int j,int x,int g[],int &r)
{
	int t=0;
	for (int i = 0; i < j; i++)
	{
		if (t==x)
		{
			while(b[i]!=-1)
			{
				cout<<b[i];
				g[r]=b[i];
				i++;
				r++;
			}
			break;
		}
		else if (b[i]==-1)
		{
			t++;
		}
	}
}
void huffmancode(string s,char c[],int b[],int l,int j,int g[],int &r)
{
    int t=s.length();
    for (int i = 0; i < t; i++)
    {
    	char k=s[i];
    	int x=findc(k,c,l);
    	printpath(b,j,x,g,r);
    	cout<<endl;
    }
    cout<<endl;
}
void huffmancodetostring(hptr H,int g[],int r)
{
    int i=0;
    while(i<r)
    {
        hptr t=H;
        while(t->lchild!=NULL && t->rchild!=NULL)
        {
            if(g[i]==0)
            {
                t=t->lchild;
            }
            if(g[i]==1)
            {
                t=t->rchild;
            }
            i++;
        }
        cout<<t->charecter;

    }
}
int main()
{
   queue q;
   hptr p;
   p=NULL;
   char k;
   int f;
   cin>>k>>f;
   while(k!='#' && f>0)
   {
      p=new(hnode);
      p->charecter=k;
      p->freq=f;
      p->lchild=NULL;
      p->rchild=NULL;
      enqueue(q,p);
      p=NULL;
      cin>>k>>f;
   }
  hptr H;
  H=construct(q);
  fillcode(H);
  char c[1000];
  int l=0;
  printdata(H,c,l);
  int a[1000];
  int b[1000];
  int i=0,j=0;
  paths(H->lchild,a,b,i,j);
  paths(H->rchild,a,b,i,j);
  string s;
  cin>>s;
  int g[1000];
  int r=0;
  huffmancode(s,c,b,l,j,g,r);
  huffmancodetostring(H,g,r);
}

a 10
e 15
i 12
s 3
t 4
p 13
n 1
# -1