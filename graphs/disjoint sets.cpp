#include <iostream>
using namespace std;
int find(int set[],int x)
{
	if (set[x]==-1)
	{
		return x;
	}
	else
	{
		return find(set,set[x]);
	}
}
void uni(int set[],int x,int y)
{
	if (set[y]==-1)
	{
		set[y]=x;
	}
	else if (set[x]==-1)
	{
		set[x]=y;
	}
	else
	{
	    uni(set,find(set,set[x]),find(set,set[y]));
		//set[find(set,x)]=set[find(set,y)];
		cout<<find(set,x)<<" "<<find(set,y)<<endl;
	}
}
int main()
{
   int n;
   cin>>n;
   int set[n+1];
   for (int i = 0; i < n+1; i++)
   {
   	 set[i]=-1;
   }
   while(1>0)
   {
   	 int x,y;
   	 cin>>x;
   	 if (x==-1)
   	 {
   	 	break;
   	 }
   	 cin>>y;
   	 uni(set,x,y);
   }
   while(1>0){
   int a,b;
   cin>>a>>b;
   if(a==-1)
   {
       break;
   }
   if (find(set,a)==find(set,b))
   {
   	  cout<<"same\n";
   }
   else
   {
   	cout<<"diff\n";
   }
   }
}
