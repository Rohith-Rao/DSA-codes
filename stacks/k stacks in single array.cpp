#include <iostream>
using namespace std;
struct kstacks
{
	int size;
	int min;
	int max;
	int top;
};
void kpush(struct kstacks &s,int elements[],int n)
{
	if (s.top==s.max)
	{
		cout<<"stack full\n";
	}
	else
	{
		s.top++;
		elements[s.top]=n;
	}
}
int kpop(struct kstacks s,int elements[])
{
	if (s.top==s.min-1)
	{
		cout<<"stack empty\n";
	}
	else
	{
		return elements[s.top--];
	}
}
int main()
{  int n;
	cin>>n;
	int elements[n];
	int k;
	cin>>k;
	struct kstacks s[k];
	for (int i = 0; i < k; i++)
	{   s[i].min=(i*n)/k;
		s[i].max=(i+1)*(n/k)-1;
		s[i].size=n/k;
		s[i].top=(i*n)/k-1;
	}
    


}