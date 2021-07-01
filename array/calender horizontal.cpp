#include <iostream>
using namespace std;
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;
}
int leapyear(int year) {
   int s;
   if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
   {
       s=1;
   }
   else
   s=0;
   return s;
}
int main()
{
    int d,m,y;
    cin>>d>>m>>y;
    int w,l;
    w=dayofweek(d,m,y);
    l=leapyear(y);
    for(int i=1;i<=12;i++)
    {
        if(i==1)
        {
            cout<<"                JANUARY             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==2 && l==1)
        {   d=1;
            cout<<"               FEBBRUARY     "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>29)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>29)
               {
                   break;
               }
            }

        }
        else if(i==2&&l==0)
        {
            d=1;
            cout<<"               FEBBRUARY     "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>28)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>28)
               {
                   break;
               }
            }

        }
        else if(i==3)
        {   d=1;
            cout<<"                MARCH             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==4)
        {   d=1;
            cout<<"                APRIL             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>30)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>30)
               {
                   break;
               }
            }
        }
        else if(i==5)
        {   d=1;
            cout<<"                MAY             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==6)
        {   d=1;
            cout<<"                JUNE             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>30)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>30)
               {
                   break;
               }
            }
        }
        else if(i==7)
        {   d=1;
            cout<<"                JULY             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==8)
        {   d=1;
            cout<<"                AUGUST             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==9)
        {   d=1;
            cout<<"                SEPTEMBER             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>30)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>30)
               {
                   break;
               }
            }
        }
        else if(i==10)
        {   d=1;
            cout<<"                OCTOBER             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
        else if(i==11)
        {   d=1;
            cout<<"                NOVEMBER             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>30)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>30)
               {
                   break;
               }
            }
        }
        else if(i==12)
        {   d=1;
            cout<<"                DECEMBER             "<<endl;
            cout<<"sun\tmon\ttue\twed\tthu\tfri\tsat"<<endl;
            for(int j=0;j<w;j++)
            {
                cout<<"\t";
            }
            for(int j=0;j<(7-w);j++)
            {
                cout<<d<<"\t";
                d++;
            }
            cout<<endl;
            while(1>0)
            {
                for(int j=0;j<7;j++)
                {
                    cout<<d<<"\t";
                    d++;
                    if(d>31)
                    {
                        if(j<=5)
                        {
                            w=j+1;
                        }
                        else
                            w=0;
                        break;
                    }
                }
               cout<<endl;
               if(d>31)
               {
                   break;
               }
            }
        }
    }
}

