#include <iostream>
#include <string>
using namespace std;
bool subsequence(string a,string b,int la,int lb,int i,int j)
{
	if(i>la-1)
	{
		return true;
	}
	if(j>lb-1)
    {
        return false;
    }
	if(a[i]==b[j])
    {
        i++;
        j++;
    }
    if(a[i]!=b[j])
    {
        i++;

    }
	subsequence(a,b,la,lb,i,j);

}
int main()
{
    string a,b;
    cin>>a>>b;
    int la,lb;
    la=a.length();
    lb=b.length();
    int i=0,j=0;
    int k;
    if(subsequence(a,b,la,lb,i,j))
    {
        k=1;
    }
    else k=0;
    cout<<k;
}
