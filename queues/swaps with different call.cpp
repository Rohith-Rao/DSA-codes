#include <iostream>
using namespace std;
void swap1(int x,int y)
{
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<x<<" "<<y<<endl;
}
void swap2(int &x,int &y)
{
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<x<<" "<<y<<endl;
}
void swap3(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    cout<<*x<<" "<<*y<<endl;
}
void swap4(int x,int &y){
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<x<<" "<<y<<endl;
}
void swap5(int x,int *y)
{
    x=x+*y;
    *y=x-*y;
    x=x-*y;
    cout<<x<<" "<<*y<<endl;
}
void swap6(int&x,int *y)
{
    x=x+*y;
    *y=x-*y;
    x=x-*y;
    cout<<x<<" "<<*y<<endl;
}
using namespace std;
int main() {
    int a=1,b=2;
    int *p=&a,*q=&b;
    cout<<"case 1"<<endl;
    swap1(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<"case 2"<<endl;
    swap2(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<"case 3"<<endl;
    swap3(p,q);
    cout<<a<<" "<<b<<endl;
    cout<<"case 4"<<endl;
    swap4(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<"case 5"<<endl;
    swap5(a,q);
    cout<<a<<" "<<b<<endl;
    cout<<"case 6"<<endl;
    swap6(a,q);
    cout<<a<<" "<<b<<endl;
}
