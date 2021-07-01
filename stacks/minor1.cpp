#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
void insert(lptr &L)
{
    lptr l;
    int n;
    while(cin>>n,n>0)
    {
        lptr temp = new(node);
        temp->data = n;
        if(L == NULL)
        {
            L = temp;l = L;
        }else{
            l ->next = temp;
            l = l->next;
        }
    }
}
int main()
{
	lptr L1=NULL,L2=NULL,L3=NULL,L4=NULL,L5=NULL;
    insert(L1);
    insert(L2);
    insert(L3);
    insert(L4);
    insert(L5);
    

}