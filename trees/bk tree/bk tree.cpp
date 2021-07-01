#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct bknode
{
  string s;
  bknode *ptr[7]={NULL};
};
typedef bknode *bkptr;
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
void insert(bkptr &B,string s)
{
  if (B==NULL)
  {
      B=new(bknode);
    B->s=s;
    return;
  }
  else
  {
    int k=distance(B->s,s);
    insert(B->ptr[k],s);
  }
}
void search(vector<bkptr> &v,vector <bkptr> &v1,int &ind,string k,int n)
{
  if (ind==v.size())
  {
    return;
  }
     bkptr t=v[ind];
     ind++;
     int d=distance(k,t->s);
     if(d<=n)
     {
         v1.push_back(t);
     }
     int l=d-n;
     int e=d+n;
     for (int i = 0; i < 7; i++)
     {
       if (i >= l && i <= e)
       {
         if (t->ptr[i]!=NULL)
         {
             int x=distance(t->ptr[i]->s,k);
          /*   if(x<=n)
           {v1.push_back(t->ptr[i]);}*/
           v.push_back(t->ptr[i]);
         }
       }
     }
     search(v,v1,ind,k,n);
}
void preorder(bkptr B)
{
    if(B==NULL)
    {
        return;
    }
    cout<<B->s<<" ";
    for(int i=0;i<7;i++)
    {
        preorder(B->ptr[i]);
    }
}
int main()
{
   bkptr B=NULL;
   string s;
   cin>>s;
   while(s!="#")
   {
      insert(B,s);
      cin>>s;
   }
   cin>>s;
   vector<bkptr> v;
   vector <bkptr> v1;
   v.push_back(B);
   int n;
   cin>>n;
   int ind=0;
   search(v,v1,ind,s,n);
   for (int i = 0; i < v1.size(); i++)
   {
       int x=distance(v1[i]->s,s);
     cout<<x<<" "<<v1[i]->s<<" ";
   }
}