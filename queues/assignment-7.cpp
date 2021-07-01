#include <iostream>
using namespace std;
struct queues
{
	int size;
	int front=-1;
	int rear=-1;
	string elements[50];
};
void enqueue(struct queues &q,string x)
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
string dequeue(struct queues &q )
{   string t;
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
void binary(int n)
{  struct queues q;
    q.size=20;
	if(n==0)
	{
	    cout<<"0"<<endl;
	}
	else if (n==1)
	{
		cout<<"1"<<endl;
	}
	else
	{
		enqueue(q,"1");
		for (int i = 2; i <= n; i++)
		{    string s;
			s=dequeue(q);
			enqueue(q,s+"0");
			enqueue(q,s+"1");
		}
		string l;
		l=dequeue(q);
		cout<<l<<endl;
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
struct stackint
{
  int size;
  int top=-1;
  int elements[50];
};
void pushint(struct stackint &s,int n)
{
  if(s.top==s.size-1)
  {
    cout<<"no space\n";
  }
  else
  {
    s.top++;
    s.elements[s.top]=n;
    return;
  }
}
int popint(struct stackint &s)
{
  if(s.top==-1)
  {
    cout<<"stack empty"<<endl;
  }
  else{
    return s.elements[s.top--];
  }
}
void reverseque(struct queues &q,int n)
{    int k;
  struct stackint s;
  s.size=20;
    for (int i = 0; i < n/2; i++)
    {
      k=dequeue(q);
      enqueue(q,k);
    }
    for (int i = 0; i < n/2; i++)
    {
      k=dequeue(q);
      pushint(s,k);
    }
    while(s.top!=-1)
    {
      k=popint(s);
      enqueue(q,k);
    }
    for (int i = 0; i < n/2; i++)
    {
      k=dequeue(q);
      enqueue(q,k);
    }
    for (int i = 0; i < n/2; i++)
    {
      k=dequeue(q);
      pushint(s,k);
    }
    for (int i = 0; i < n/2; i++)
    {
      k=dequeue(q);
      enqueue(q,k);
      k=popint(s);
      enqueue(q,k);
    }

}







void swap(int &p,int &q)
{
  int t;
  t=p;
  p=q;
  q=t;
  return;
}
void permutation(char a[],int l,int r)
{
  if (l==r)
  {
    cout<<a<<endl;
  }
  else
  {
    for (int i = l; i <= r; i++)
    {
      swap(a[l],a[i]);
      permutation(a,l+1,r);
      swap(a[l],a[i]);
    }
  }
}






int main()
{   
    int n;
    cin>>n;
    binary(n);

 

    char a[100];
  int n;
  cin>>n;
  cin>>a;
  permutation(a,0,n-1);
   



   struct queues q;
  q.size=20;
  int n=0,k;
  cin>>k;
  while(k!=-1)
  {
    enqueue(q,k);
    n++;
    cin>>k;

  }
  reverseque(q,n);
  for (int i = 0; i < n; i++)
  {
    k=dequeue(q);
    cout<<k<<" ";
  }




  

}