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
  
int main() {
    int year;
    string months[12]={"Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"};
        cin>>year;
    int D=dayofweek(1,1,year);
    cout<<D<<endl;
    string days[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    bool leap=0;
    if((year%4==0&&year%100!=0)||year%400==0)
    leap=1;
    int dats[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap==0)
    dats[1]-=1;
    cout<<year<<endl<<endl;
    int end=0;
    for(int k=0;k<12;k++)
    {
        end=0;
        cout<<"\t\t"<<months[k]<<endl;
        int count=1;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                if(j==0)
                {
                    cout<<days[i]<<"     ";
                }
                else{
                    if((j-1)*7+i<D)
                    {cout<<"      ";}
                    else{
                        if((j-1)*7+i-D+1<=dats[k])
                        {
                            cout<<((j-1)*7+i-D+1);
                            if((j-1)*7+i-D+1==dats[k])
                            {end=i;}
                        }
                    cout<<"     ";
                    }
                 
                }
            }
            cout<<endl<<endl<<endl;
            
        }
        D=end+1;
        
    }
    
}
