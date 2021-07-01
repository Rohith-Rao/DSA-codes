#include<iostream>
using namespace std;
struct stack 
{
    int t;
    int a[64][2];
    int top();
    bool empty();
    void push(int,int);
    void pop();
};
int main()
{
    int a[8][8]={1,1,1,1,1,1,1,1,
               1,0,0,0,0,0,0,1,
               1,0,1,0,1,1,1,1,
               1,0,1,0,0,0,0,1,
               1,1,1,1,1,1,0,1,
               1,0,1,1,0,1,0,1,
               1,0,0,0,0,1,0,1,
               1,1,1,1,1,1,1,1};
    int start[2],end[2];
    cin>>start[1]>>start[0]>>end[1]>>end[0];
    int vis[8][8]={0},flag=0;
    stack s;
    s.t=0;
    s.push(start[0],start[1]);
    //vis[start[0]][start[1]]=1;
    while(a[start[0]][start[1]]==0 && a[end[0]][end[1]]==0 && !s.empty())
    {
        int i=s.top();
        s.pop();
        int x=i/8,y=i%8;
        if(x==end[0] && y==end[1])
        {
            flag=1;
            break;
        }
        vis[x][y]=1;
        if(vis[x+1][y]==0 && a[x+1][y]==0)
        s.push(x+1,y);
        if(vis[x-1][y]==0 && a[x-1][y]==0)
        s.push(x-1,y);
        if(vis[x][y+1]==0 && a[x][y+1]==0)
        s.push(x,y+1);
        if(vis[x][y-1]==0 && a[x][y-1]==0)
        s.push(x,y-1);
    }
    cout<<flag<<endl;
    return 0;
}
int stack :: top()
{
    return (a[t-1][0]*8+a[t-1][1]);
}
bool stack :: empty()
{
    if(t==0)
    return true;
    return false;
}
void stack :: push(int x,int y)
{
    a[t][0]=x;
    a[t][1]=y;
    t++;
}
void stack :: pop()
{
    t--;
}