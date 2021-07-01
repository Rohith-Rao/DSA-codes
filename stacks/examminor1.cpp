#include<iostream>
using namespace std;

struct node{
    int data;
    char c;
    struct node* next = NULL;
};

typedef struct node* lptr;

void Inser(lptr &L)
{
    lptr l;
    string s;
    while(cin>>s,s[0]!='#')
    {
        lptr temp = new(node);
        temp->data = s[1]-'0';
        temp->c = s[0];
        if(L == NULL)
        {
            L = temp;l = L;
        }else{
            l ->next = temp;
            l = l->next;
        }
    }
}

void Print(lptr L)
{
    if(L==NULL){return;}
    cout<<L->c<<L->data<<" ";
    Print(L->next);
}

bool Search(lptr L, int a, char c)
{
    while(L != NULL)
    {
        if(L->data == a && L->c == c)
        return true;
        L = L->next ;
    }
    return false;
}

int main()
{
    lptr arr[4]={NULL},arr2[4]={NULL};
    lptr b[4]={NULL};
    lptr L1 = NULL, L2 = NULL, L3 = NULL;
    Inser(L1);
    Inser(L2);
    Inser(L3);
    Print(L1);Print(L2);Print(L3);
    while(L2 != NULL)
    {
        lptr temp = new(node);
        temp->data = L2->data;
        temp->c = L2->c;
        if(arr[L2->data%4] == NULL)
        {
            arr[L2->data%4] = temp;
            b[L2->data%4] = arr[L2->data%4];
        }else{
            b[L2->data%4]->next = temp;
            b[L2->data%4] = b[L2->data%4]->next;
        }
        L2 = L2->next;
    }
    while(L3 != NULL)
    {
        lptr temp = new(node);
        temp->data = L3->data;
        temp->c = L3->c;
        if(arr2[L3->data%4] == NULL)
        {
            arr2[L3->data%4] = temp;
            b[L3->data%4] = arr2[L3->data%4];
        }else{
            b[L3->data%4]->next = temp;
            b[L3->data%4] = b[L3->data%4]->next;
        }
        L3 =L3->next;
    }
    while(L1 != NULL)
    {
        if(Search(arr[L1->data%4], L1->data, L1->c) && Search(arr2[L1->data%4], L1->data, L1->c))
        cout<<L1->c<<L1->data<<" "<<endl;
        L1 = L1->next;
    }
}