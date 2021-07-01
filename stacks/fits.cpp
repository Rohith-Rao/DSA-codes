void conversion()
{     int n1,n2;
       int a[n1],a[n2];
       cin>>n1>>n2;
       for (int i = 0; i < n1; i++)
       {
           cin>>a[i];
       }
       for (int i = 0; i < n2; i++)
       {
           cin>>b[i];
       }
    while(a[n1-1]>b[0])
    {
        int j=0;
        for(int i=0;i<n1&&j<n2;i++)
        {
            if(a[i]>b[j])
            {
                int c=a[i];
                a[i]=b[j];
                b[j]=c;
                j++;
            }
        }
    }
    for(int i=0;i<n1;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    return;
}
int main()
{
    conversion();
}