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
struct mlnode
{
	int data;
	mlnode *next;
	mlnode *down;
};
typedef struct mlnode *mlptr;
struct queue
{
	int size=50;
	int front=-1;
	int rear=-1;
	mlptr elements[100];
};
void enqueue(queue &q,mlptr p)
{
	if ((q.rear+1)%q.size==q.front)
	{
		cout<<"full\n";
	}
	else
	{
		if (q.front==-1)
		{
			q.front=0;
			q.rear=0;
		}
		else
		{
			q.rear=(q.rear+1)%q.size;
		}
		q.elements[q.rear]=p;
	}
}
mlptr dequeue(queue &q)
{
	mlptr p;
     if (q.front==-1)
     {
     	cout<<"empty\n";
     }
     else
     {
     	if (q.front==q.rear)
     	{
     		p=q.elements[q.front];
     		q.front=-1;
     		q.rear=-1;
     	}
     	else
     	{
     		p=q.elements[q.front];
     		q.front=(q.front+1)%q.size;
     	}
     	return p;
     }
}
void insert(mlptr &ml)
{
	int n;
	cin>>n;
	if (n==-1)
	{
		return;
	}
	else
	{
		mlptr t;
		t=new(mlnode);
		t->data=n;
		t->next=NULL;
		t->down=NULL;
		if (ml==NULL)
		{
			ml=t;
		}
		else
		{
			mlptr l;
			l=ml;
			while(l->next!=NULL)
			{
				l=l->next;
			}
			l->next=t;
		}
		cin>>n;
		if (n==1)
		{
			insert(t->down);
		}
		insert(ml);
	}
}
void depthwise(mlptr ml,lptr &l)
{
	if (ml==NULL)
	{
		return;
	}
	else
	{
		addend(l,ml->data);
		depthwise(ml->down,l);
		depthwise(ml->next,l);
	}

}
void levelwise(mlptr ml , lptr &l,queue &q)
{
	while(ml!=NULL)
	{
		addend(l,ml->data);
		if (ml->down!=NULL)
		{
			enqueue(q,ml);
		}
		ml=ml->next;
	}
	while(q.front!=-1)
	{
		mlptr k;
		k=dequeue(q);
		levelwise(k->down,l,q);
	}
}
int main()
{
	mlptr ML;
	ML=NULL;
	insert(ML);
	lptr L;
	L=NULL;
	queue q;
	levelwise(ML,L,q); 
	print(L);
	L=NULL;
	depthwise(ML,L);
	print(L);
}
