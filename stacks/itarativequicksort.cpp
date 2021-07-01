#include <iostream>
using namespace std;
struct stack2
{
	int size;
	int top=-1;
	int elements[50];
};
void push2(struct stack2 &s,int n)
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
int pop2(struct stack2 &s)
{
	if(s.top==-1)
	{
		cout<<"stack empty"<<endl;
	}
	else{
		return s.elements[s.top--];
	}
}
void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
    return;
}
int partition(int a2[], int l, int h)
{
    int x = a2[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (a2[j] <= x) {
            i++;
            swap(a2[i], a2[j]);
        }
    }
    swap(a2[i + 1], a2[h]);
    return (i + 1);
}
void itrativequicksort(int a2[],int start2,int end2)
{
    struct stack2 s;
    s.size=end2-start2+1;
    push2(s,start2);
    push2(s,end2);
    while(s.top>=0)
    {
        start2=pop2(s);
        end2=pop2(s);
        int p=partition2(a2,start2,end2);
        if(p-1>start2)
        {
        	push2(s,start2);
        	push2(s,p-1);
        }
        if (p+1<end2)
        {
        	push2(s,p+1);
        	push2(s,end2);
        }
    }
}
int main()
{
    int n2;
    cin>>n2;
    int a2[n2];
    int i;
    for (i = 0; i < n2; i++)
    	{
    		cin>>a2[i];
    	}
    int start2=0,end2=n2-1;
    itrativequicksort(a2,start2,end2);
    for ( i = 0; i < n2; i++)
    {
    	cout<<a2[i]<<" ";
    }
}
