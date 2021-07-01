#include <iostream>
#include <string>
using namespace std;
void print(int **matrix,string s1,string s2,int i,int j)
{
    if(i==0&&j==0)
    {
    	return;
    }
    char c;
    if(i&&j&&a[i][j]==a[i-1][j-1]+1)
    {
    	c='C';
    	print(a,s,s1,i-1,j-1);
    }
    else if(j&&a[i][j]==a[i][j-1]+1)
    {
    	c='A';
    	print(a,s,s1,i,j-1);
    }
    else if(i&&a[i][j]==a[i-1][j]+1)
    {
    	c='D';
    	print(a,s,s1,i-1,j);
    }
    else if(i&&j&&a[i][j]==a[i-1][j-1])
    {
    	c='N';
    	print(a,s,s1,i-1,j-1);
    }
    cout<<c<<" ";
    if(c=='A')
    cout<<s1[j-1];
    else
    cout<<s[i-1];
    if(c=='C'||c=='N')
    cout<<" "<<s1[j-1];
    cout<<endl;
}
int min(int a,int b,int c)
{
   if (a < b && a < c)
   {
   	  return a;
   }
   else if (b < a && b < c)
   {
   	 return b;
   }
   else
   {
   	return c;
   }
}
int distance(string s1,string s2)
{
	int m=s1.length();
	int n=s2.length();
	int **matrix;
	matrix=new int *[m+1];
	for (int i = 0; i < n+1; i++)
	{
		matrix[i]=new int [n+1];
	}
	for (int i = 0; i < m+1; i++)
	{
		matrix[i][0]=i;
	}
	for (int i = 0; i < n+1; i++)
	{
		matrix[0][i]=i;
	}
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			if(s1[i-1]!=s2[j-1])
			{
				int k=min(matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1])+1;
			    matrix[i][j]=k;
			}
            else
            {
            	matrix[i][j]=matrix[i-1][j-1];
            }
		}
	}

    print(matrix,s1,s2,m,n);
	return matrix[m][n];
}
int main()
{
	string s1,s2;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s1>>s2;
        int k=distance(s1,s2);
        cout<<k<<endl;
	}
	
}
