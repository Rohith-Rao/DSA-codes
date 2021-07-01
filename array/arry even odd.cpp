#include <iostream>
using namespace std;
int main() {
    int n;
    n=9;
    int a[n];
    int even=0;
    for(int i=0;i<n;i++)
    {cin>>a[i];
    	if(a[i]%2==0)
	     {
	       even++;
         } 
	}
    int x=even;
    
    for(int i=0;i<even;i++)
    {
        if(a[i]%2==1)
        {
            while(a[i]%2!=0){
            if(a[x]%2==0)
            {
                int s;
                s=a[i];
                a[i]=a[x];
                a[x]=s;
                x++;
            }
            else{
                x++;
            }}
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
