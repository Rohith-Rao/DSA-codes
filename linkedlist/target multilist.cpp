#include <iostream>
using namespace std;
struct mlnode
{
	int data;
	int count;
	mlnode *next[5];
};
typedef struct mlnode *mlptr;
struct stack
{
    int size=50;
    int top=-1;
    mlptr elements[50];
};
void push(stack &s,mlptr p)
{
    if(s.top==s.size)
    {
        cout<<"full\n";
    }
    else
    {
        s.top++;
        s.elements[s.top]=p;
    }
}
mlptr pop(stack &s)
{
    if(s.top==-1)
    {
        cout<<"empty\n";
    }
    else{
        mlptr t;
        t=s.elements[s.top];
        s.top--;
        return t;
    }
}
void insert(mlptr &ml)
{
	int n;
	cin>>n;
   mlptr t;
   t=new(mlnode);
   t->data=n;
   cin>>n;
   t->count=n;
   for(int i=0;i<t->count;i++)
   {
       t->next[i]=NULL;
   }
   while(1>0)
   {
       if (t->count>1)
       {
       	  while(t->count!=0)
       	  {
       	  	 insert(t->next[t->count-1]);
       	  	 t->count--;
       	  }
       	  break;
       }
       if (ml==NULL)
       {
       	   ml=t;
       }
       else
       {
       	mlptr l=ml;
       	while(l->next[0]!=NULL)
       	{
       		l=l->next[0];
       	}
       	l->next[0]=t;
       }
       cin>>n;
       t=new(mlnode);
       t->data=n;
       cin>>n;
       t->count=n;
        for(int i=0;i<t->count;i++)
         {
            t->next[i]=NULL;
         }
       if(t->count==0)
       {
           break;
       }
   }
}
mlptr fstart(mlptr p,int start)
{
    while(p->data!=start)
    {
        p=p->next[0];
    }
    return p;
}
void path(mlptr &ml,int end,stack &s1,stack &s2)
{
    while(ml->next[0]!=NULL)
    {
      if (ml->count>1)
      {
         push(s1,ml);
      }
      push(s2,ml);
      ml=ml->next[0];
    }
    push(s2,ml);
    if (ml->data==end)
    {
       break;
    }
    mlptr p;
    p=pop(s1);
    mlptr l;
    l=pop(s1);
    while(p!=l)
    {
      l=pop(s2);
    }
    path(p,end,s1,s2);

}
int main()
{
    mlptr ML;
    ML=NULL;
    insert(ML);
    int start,end;
    cin>>start;
    cin>>end;
    stack s1,s2;
    ML=fstart(ML,int start);
    path(ml,end,s1,s2);
}
