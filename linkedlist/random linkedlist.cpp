#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *random;
};
typedef struct node *lptr;
void insert(lptr &p)
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    lptr t;
    
}
void Print(lptr L , struct node* a[] , int j , int n)
{
    if(L==NULL) return;
    cout<<L->data<<" ";
    if(a[j] == L&& j<n)
    Print(L->random, a, j+1,n);
    else
    Print(L->next,a,j,n);
}
void Combination(lptr L, struct nd* a[], struct node* arr[], int j, int n, int i)
{
    if(Check(L, arr, i-1))
    {
        Print(L,arr,0,i);
        cout<<endl;
    }
    for(j ; j<=n ; j++)
    {
        arr[i] = a[j]->ptr;
        Combination(L,a,arr,j+1,n,i+1);
    }
    
}
bool Check (lptr L , struct node* a[] , int n )
{
    int i = 0;
    while(L != NULL)
    {
        if(L == a[i]){
            L = L->random;i++;}
        else{
            L = L->next;
        }
    }
    if(i==n+1)
    return true;
    return false;
}
int main()
{
	lptr L;
	L=NULL;
	insert(L);
}