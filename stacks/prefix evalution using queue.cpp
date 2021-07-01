#include <iostream>
#include <string>
using namespace std;
union u
{
	int in;
	char c;
};
struct queue
{
	int size;
	int front=-1;
	int rear=-1;
	union u elements[50];
};
void enqueueint(struct queue &q,int n)
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
		q.elements[q.rear].in=n;
	}
}
void enqueuechar(struct queue &q,char n)
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
		q.elements[q.rear].c=n;
	}
}
int dequeueint(struct queue &q)
{     int t;
	if (q.front==-1)
	{
		cout<<"full\n";
	}
	else
	{
		if (q.front==q.rear)
		{   t=q.elements[q.front].in;
			q.front=-1;
			q.rear=-1;
		}
		else
		{
             t=q.elements[q.front].in;
             q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
char dequeuechar(struct queue &q)
{     char t;
	if (q.front==-1)
	{
		cout<<"full\n";
	}
	else
	{
		if (q.front==q.rear)
		{   t=q.elements[q.front].c;
			q.front=-1;
			q.rear=-1;
		}
		else
		{
             t=q.elements[q.front].c;
             q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
int operetion(char a,int n1,int n2)
{
	switch(a)
	{
		case '+':
		return (n1+n2);
		case '-':
		return (n1-n2);
		case '*':
		return (n1*n2);
		case '/':
		return (n1/n2);
	}
}
int prefixevaluation(string s)
{
    struct queue q;
    q.size=20;
    int l=s.length();
    struct queue tag;
    tag.size=20;
    for (int i = 0; i < l; i++)
    {
    	if (s[i]>='0' && s[i]<='9')
    	{   s[i]=s[i]-'0';
    		enqueueint(tag,0);
    		enqueueint(q,s[i]);
    	}
    	else
    	{
    		enqueueint(tag,1);
    		enqueuechar(q,s[i]);
    	}
    }
    union u a,b,c;
    int k[3];
        k[0]=dequeueint(tag);
        if (k[0]==0)
        {
        	a.in=dequeueint(q);
        }
        else
        {
        	a.c=dequeuechar(q);
        }
        k[1]=dequeueint(tag);
        if (k[1]==0)
        {
        	b.in=dequeueint(q);
        }
        else
        {
        	b.c=dequeuechar(q);
        }
        k[2]=dequeueint(tag);
        if (k[2]==0)
        {
        	c.in=dequeueint(q);
        }
        else
        {
        	c.c=dequeuechar(q);
        }
    while(q.front!=q.rear || q.front==-1)
      {  if (k[0]==1 && k[1]==0 && k[2]==0)
        {
            int result;
            result=operetion(a.c,b.in,c.in);
            enqueueint(q,result);
            enqueueint(tag,0);
            if (q.front==q.rear)
            {
            	break;
            }
            k[0]=dequeueint(tag);
            if (k[0]==0)
              {
        	     a.in=dequeueint(q);
              }
            else
            {
        	    a.c=dequeuechar(q);
             }
            k[1]=dequeueint(tag);
             if (k[1]==0)
                {
               	b.in=dequeueint(q);
                 }
             else
                 {
        	       b.c=dequeuechar(q);
                 }
            k[2]=dequeueint(tag);
             if (k[2]==0)
                {
        	      c.in=dequeueint(q);
                }
              else
                  {
        	         c.c=dequeuechar(q);
                  }

        }
        else
            {
               if (k[2]==0)
               {
               	  enqueueint(q,c.in);
               	  enqueueint(tag,0);
               }
               else
               {
               	  enqueuechar(q,c.c);
               	  enqueueint(tag,1);
               }
               k[2]=k[1];
               if (k[2]==0)
               {
               	 c.in=b.in;
               }
               else
               {
               	c.c=b.c;
               }
               k[1]=k[0];
               if (k[1]==0)
               {
               	   b.in=a.in;
               }
               else
               {
               	 b.c=a.c;
               }
               k[0]=dequeueint(tag);
               if (k[0]==0)
               {
               	  a.in=dequeueint(q);
               }
               else
               {
               	  a.c=dequeuechar(q);
               }
                
             }
       }

       int d=dequeueint(q);
       return d;
}
int main()
{
	string s;
	s="-+*9+28*+4863";
	int k=prefixevaluation(s);
	cout<<k;
}

