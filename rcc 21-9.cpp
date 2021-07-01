//Code  to Conquer
//Rapid to Land
#include <iostream>
using namespace std;
int main()
{
    int c1[100],p1[100],c2[100],p2[100],r[100];
    int n;
    cin>>n;
    int i=0,j=0,k=0;
    while(n>=0)
    {
        if(i%2==0)
        {
            c1[j]=n;
            i++;
            j++;
        }
        else
        {
            p1[k]=n;
            i++;
            k++;
        }
        cin>>n;
    }
    cin>>n;
     i=0;
     int l=0,m=0;
    while(n>=0)
    {
        if(i%2==0)
        {
            c2[l]=n;
            i++;
            l++;
        }
        else
        {
            p2[m]=n;
            i++;
            m++;
        }
        cin>>n;
    }
    int g=0,h=0,f=0;
    while(g<k && h<m)
    {
        if (p1[g]>p2[h])
        {
            r[f]=c1[g];
            f++;
            r[f]=p1[g];
            f++;
            g++;
        }
        else if(p2[h]>p1[g])
        {
           r[f]=c2[h];
           f++;
           r[f]=p2[h];
           f++;
           h++;
        }
        else
        {
            r[f]=c1[g]+c2[h];
            f++;
            r[f]=p1[g];
            f++;
            g++;
            h++;
        }
    }
    while(g<k)
    {
        r[f]=c1[g];
        f++;
        r[f]=p1[g];
        f++;
        g++;
    }
    while(h<m)
    {
        r[f]=c2[h];
        f++;
        r[f]=p2[h];
        f++;
        h++;
    }
    for ( i = 0; i < (2*k)+(2*m)-2; i++)
    {
        cout<<r[i]<<" ";
    }
}
