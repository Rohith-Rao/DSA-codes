#include <iostream>
using namespace std;
union u
{
	int in;
	char c;
	float f;
};
struct  queue
{
	int size=20;
	int front=-1;
	int rear=-1;
	union u elements[50];
	int tag[50];
};
void enqueueint(queue &q,int x)
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
		q.elements[q.rear].in=x;
		q.tag[q.rear]=0;
	}
}
void enqueuefloat(queue &q,float x)
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
		q.elements[q.rear].f=x;
		q.tag[q.rear]=2;
	}
}
union u dequeueall( struct queue &q,int &tag) {
    if(q.front==-1)
    {
        cout<<"Empty"<<endl;
    }else{
        if(q.front==q.rear)
        {
            if(q.tag[q.front]==1)
            {
            union u t;
            t= q.elements[q.front];
            q.front=-1;
            q.rear=-1;
            tag=1;
            return t;
            }
            else if(q.tag[q.front]==0)
            {
                union u t;
                t=q.elements[q.front];
                q.front=-1;
                q.rear=-1;
                tag=0;
                return t;
            }
            else
            {
            	union u t;
            	t=q.elements[q.front];
            	q.front=-1;
            	q.rear=-1;
            	tag=2;
            	return t;
            }
        }
        else{
            if(q.tag[q.front]==1)
            {
            union u t;
            t=q.elements[q.front];
            tag=1;
            q.front=(q.front+1)%q.size;
            return t;
            }
            else if(q.tag[q.front]==0)
            {
                union u t;
                t=q.elements[q.front];
                tag=0;
                q.front=(q.front+1)%q.size;
                return t;
            }
            else
            {
            	union u t;
                t=q.elements[q.front];
                tag=2;
                q.front=(q.front+1)%q.size;
                return t;
            }

        }
    }
}
void enqueuechar(queue &q,char x)
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
		q.elements[q.rear].c=x;
		q.tag[q.rear]=1;
	}
}


struct queues
{
	int size;
	int front=-1;
	int rear=-1;
	int elements[50];
};
void enqueue(struct queues &q,int x)
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
    	q.elements[q.rear]=x;
    }
}
int dequeue(struct queues &q )
{   int t;
   if (q.front==-1)
   {
   	  cout<<"empty\n";
   }
   else
   {
   	   if (q.front==q.rear)
   	   {   t=q.elements[q.front];
   	   	  q.front=-1;
   	   	  q.rear=-1;
   	   }
   	   else
   	   {  t=q.elements[q.front];
   	   	  q.front=(q.front+1)%q.size;
   	   }
     return t;
   }
}
int main()
{   queue q;
    q.size=20;

	union u a[11];
	
	a[0].c='N';
	q.tag[0]=1;
	a[1].c='I';
	q.tag[1]=1;
	a[2].in=17;
	q.tag[2]=0;
	a[3].c='T';
	q.tag[3]=1;
	a[4].in=9;
	q.tag[4]=0;
	a[5].in=20;
	q.tag[5]=0;
	a[6].c='C';
	q.tag[6]=1;
	a[7].c='S';
	q.tag[7]=1;
	a[9].in=21;
	q.tag[9]=0;
	a[10].c='E';
	q.tag[10]=1;
	queue k;
	k.size=20;
	for (int i = 0; i < 10; i++)
	{
		if (q.tag[i]==1)
		{
			enqueuechar(q,a[i].c);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (tag[i]==0)
		{
			enqueueint(q,a[i].in);
		}
	}
	union u o;
	for (int i = 0; i < 10; i++)
	{   int t;
		o=dequeueall(q,t);
		if (t==1)
		{
			enqueuechar(q,o.c);
		}
		else if (t==0)
		{
			enqueueint(k,o.in);
		}
	}
	for (int i = 0; i < 6; i++)
	{   int l;
		o=dequeueall(q,l);
		if (l==1)
		{
			enqueuechar(k,o.c);
		}
	}
	for (int i = 0; i < 10; i++)
	{    int t;
		o=dequeueall(q,t);
		if (t==0)
		{
			enqueueint(q,o.in);
		}
		else
		{
			enqueuechar(q,o.c);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		  int t;
		o=dequeueall(q,t);
		if (t==0)
		{
			cout<<o.in<<" ";
		}
		else
		{
			cout<<o.c<<" ";
		}
	}

}