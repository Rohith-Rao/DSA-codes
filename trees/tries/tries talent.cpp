#include <iostream>
#include <string>
using namespace std;
struct enode;
struct tnode
{
	int tag;
	union {
		tnode *ptr[4]={NULL};
        enode *ptr=NULL;
	}p;
};
struct snode;
struct enode
{
	int tag;
	snode *sptr=NULL;
};
struct snode
{
	string s;
};