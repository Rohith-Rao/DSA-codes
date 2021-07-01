#include <iostream>
using namespace std;
struct qnode
{
	int data;
	qnode *cptr[4]={NULL};
};
typedef qnode *qptr;