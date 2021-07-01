void print(int **a,string s,string s1,int i,int j)
{
    if(i==0&&j==0)
    return;
    
    char c;
    
    if(i&&j&&a[i][j]==a[i-1][j-1]+1)
    {c='C';print(a,s,s1,i-1,j-1);}
    else if(j&&a[i][j]==a[i][j-1]+1)
    {c='A';print(a,s,s1,i,j-1);}
    else if(i&&a[i][j]==a[i-1][j]+1)
    {c='D';print(a,s,s1,i-1,j);}
    else if(i&&j&&a[i][j]==a[i-1][j-1])
    {c='N';print(a,s,s1,i-1,j-1);}
    //cout<<i<<" "<<j<<endl;
    cout<<c<<" ";
    if(c=='A')
    cout<<s1[j-1];
    else
    cout<<s[i-1];
    if(c=='C'||c=='N')
    cout<<" "<<s1[j-1];
    cout<<endl;
}
int dist(string s,string s1)
{
    int m=s.size(),n=s1.size(),i,j;
    int **a=new int *[m+1];
    for(i=0;i<=m;i++)
    a[i]=new int[n+1];
    for(i=0;i<=n;i++)
    a[0][i]=i;
    for(i=0;i<=m;i++)
    a[i][0]=i;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[i-1]==s1[j-1])
            a[i][j]=a[i-1][j-1];
            else 
            {
                int mi=min(a[i][j-1],a[i-1][j]);
                mi=min(mi,a[i-1][j-1]);
                a[i][j]=mi+1;
            }
        }
    }
    i=m;j=n;
    /*for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }*/
    //if(m<n)
    print(a,s,s1,m,n);
    /*else
    print(a,s1,s,n,m);*/
    return a[m][n];
}