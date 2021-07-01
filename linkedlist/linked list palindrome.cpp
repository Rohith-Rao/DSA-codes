#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
struct stack1
{
  int size;
  int top=-1;
  int elementstack[50];
};
void push1(struct stack1 &s,int n)
{
  if(s.top==s.size-1)
  {
    cout<<"no space\n";
  }
  else
  {
    s.top++;
    s.elementstack[s.top]=n;
    return;
  }
}
int pop1(struct stack1 &s)
{
  if(s.top==-1)
  {
    cout<<"stack empty"<<endl;
  }
  else{
    return s.elementstack[s.top--];
  }
}
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
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
int checkpalindrome(lptr p)
{
    lptr t,k;
    stack1 s;
    t=p;
    k=p;
    while(k!=NULL)
    {
       push1(s,k->data);
       k=k->next;
    }
    int flag=0;
    int m;
    while(t!=NULL)
    {
        m=pop1(s);
        if (t->data!=m)
        {
        	flag=1;
        	break;
        }
        t=t->next;
    }
    if (flag==0)
    {
    	return 1;
    }
    else return 0;
}
int main()
{
	lptr L;
	L=NULL;
     int n;
     cin>>n;
     while(n>0)
     {
     	addend(L,n);
     	cin>>n;
     }
     n=checkpalindrome(L);
    cout<<n<<endl;
}