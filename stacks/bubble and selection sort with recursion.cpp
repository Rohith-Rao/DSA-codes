#include<iostream>
#include<algorithm>
using namespace std;
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void bs1(int a[],int n,int i,int j)
{
    if(j==n-i-1)
    return;
    if(a[j]>a[j+1])
    swap(&a[j],&a[j+1]);
    bs1(a,n,i,j+1);
}
void bubblesort(int a[],int n,int i)
{
    if(i==n-1)
    return;
    int j=0;
    bs1(a,n,i,j);
    bubblesort(a,n,i+1);
}
void ss(int a[],int i,int n,int &min,int &ind)
{
    if(i==n)
    return;
    if(a[i]<min)
    {
        min=a[i];
        ind=i;
    }
    ss(a,i+1,n,min,ind);
}
void selectionsort(int a[],int n,int i)
{
    if(i==n)
    return;
    int min=a[i],ind=i,j;
    ss(a,i,n,min,ind);
    swap(&a[i],&a[ind]);
    selectionsort(a,n,i+1);
}
int main()
{
    int n=6,a[n],i;
    for(i=0;i<n;i++)
    cin>>a[i];
    selectionsort(a,n,0);
    //sort(a,a+n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    //cout<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];
    bubblesort(a,n,0);
    //sort(a,a+n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}