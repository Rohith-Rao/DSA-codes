#include <iostream>
using namespace std;
int maxarea(int a[],int n)
{   int le,re,j;
	int max=0,k;
   for (int i = 0; i < n; i++)
   {
   	  if (i==0)
   	  {
   	  	 le=0;
         j=i+1;
   	  	 while(j<=n-1)
   	  	 {
            if (a[j]<=a[i])
            {
            	break;
            }
            j++;
   	  	 }
       k=a[i]*j;
         if (k>max)
         {
         	max=k;
         }
   	  }
   	  else if (i==n-1)
   	  {
   	     re=0;
   	     j=i-1;
   	     while(j>=0)
   	     {
               if(a[j]<=a[i])
               {
               	  break;
               }
               j--;

   	     }
   	     k=(n-j)*a[i];
   	     if (k>max)
   	     {
   	     	max=a[i];
   	     }
   	  }
   	  else
   	  {
          le=i-1;
          re=i+1;
          while(re<=n-1)
   	  	 {
            if (a[re]<=a[i])
            {
            	break;
            }
            re++;
   	  	 }
       k=a[i]*re;
           while(le>=0)
   	     {
               if(a[le]<=a[i])
               {
               	  break;
               }
               le--;

   	     }
   	     k=k+(n-le)*a[i];
   	     if (k>max)
   	     {
   	     	max=k;
   	     }

   	  }
   }
   return max;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l;
	l=maxarea(a,n);
}