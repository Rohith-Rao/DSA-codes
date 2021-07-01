#include <iostream>
#include <string>
using namespace std;
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
	int matrix[m+1][n+1];
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
	return matrix[m][n];
}
int main()
{
	string s1,s2;
	while(1>0){
	cin>>s1>>s2;
	if(s1=="#"){
	    break;
	}
	int k=distance(s1,s2);
	cout<<k<<endl;}
}
