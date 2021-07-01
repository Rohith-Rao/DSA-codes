//Success is the sum of small daily efforts repeated on a daily basis 
#include <iostream>
#include <string>
using namespace std;
struct mlnode
{
	int tag;
	union
	{
		char cdata;
		mlnode *dlink;
	}data;
	mlnode *next;
};
typedef struct mlnode *mlptr;
void insert(mlptr &ML , string s , int start , int end )
{
    mlptr ml = ML ;
    while(ml!=NULL && ml->next != NULL)
        ml = ml->next;
    for( int i = start+1 ; i < end ; i++ )
    {
        mlptr temp = new(mlnode) ;
        temp->next = NULL;
        if(s[i]=='{')
        {
            temp->tag = 1 ;
            temp->data.dlink = NULL ;
            ml->next = temp;
            ml = ml->next;
            int low = i , high;
            int flag=1;
            i++;
            while(1>0)
            {
                if(s[i]=='{')
                    {
                        flag++;
                    }
                if(s[i]=='}')
                {
                    flag--;
                }
                if(flag==0)
                {
                    break;
                }
                i++;
            }
             high=i;
            insert(ml->data.dlink , s , low, high );
        }
        else{
            if(ML==NULL)
            {
                temp->tag = 0;
                temp->data.cdata = s[i];
                ML = temp ;
                ml = ML;
            }else{
                temp->tag = 0;
                temp->data.cdata = s[i];
                ml->next = temp ;
                ml = ml->next;
            }
        }
    }
}
void print(mlptr ml)
{
	if (ml==NULL)
	{
	    cout<<"} ";
	    return;
	}
		if (ml->tag==0)
		{
			cout<<ml->data.cdata<<" ";
		}
		else
		{
		    cout<<"{ ";
			print(ml->data.dlink);
		}

	print(ml->next);
}
int main()
{
	string s="";
	while(1>0)
    {
        char c;
        cin>>c;
        if(c=='#')
        {
            break;
        }
        s=s+c;
    }
	mlptr ML;
	ML=NULL;
	int n=s.length();
	insert(ML,s,0,n-1);
	cout<<"{ ";
	print(ML);
}


