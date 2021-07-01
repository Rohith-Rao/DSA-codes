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
union u dequeue( struct queue &q,int &tag) {
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
int main()
{
	queue q;
	q.size=20;
	int tag;
	cout<<"enter 0 for int 1 for char 2 for float\n";
	cin>>tag;
	while(tag!=-1)
	{
	if (tag==0)
	{    int t;
		cin>>t;
		enqueueint(q,t);
	}
	else if(tag==1)
	{
		char h;
		cin>>h;
		enqueuechar(q,h);
	}
	else{
		float f;
		enqueuefloat(q,f);
	}
    }
	union u k;
	while(q.front!=-1)
	{
	k=dequeue(q,tag);
	if (tag==0)
	{
		cout<<k.in<<endl;;
	}
	else if(tag==1)
	{
		cout<<k.c<<endl;
	}
	else
	{
		cout<<k.f<<endl;
	}
   }
}