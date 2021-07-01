#include <iostream>
using namespace std;
struct s10
{
	int y;
	s10 *z;
};
struct s9
{
	s9 *w;
	int x;
};
struct s8
{
	s9 *t;
	int u;
	s10 *v;
};
struct s7
{
	int n;
	char o;
	s8 *p;
};
struct s6
{
	s7 *q;
	int r;
	s6 *s;
};
struct s5
{
	int l;
	s6 *m;
};
struct s4
{
	s7 *j;
	s5 *k;
};
struct s3
{
	s4 *g;
	s3 *h;
	s5 *i;
};
struct s2
{
	char e;
	s3 *f;
};
struct s1
{
	s1 *a;
	int b;
	s2 *c;
	s1 *d;
};
int main()
{
	s1 *s;
	s=new(s1);
	s->c=new(s2);
	s->c->f=new(s3);
	s->c->f->i=new(s5);
	s->c->f->g=new(s4);
	s->c->f->g->j=new(s7);
	cin>>s->c->f->g->j->n;
	s->c->f->i->m=new(s6);
	cin>>s->c->f->i->m->r;
	s->c->f->g->j->p=new(s8);
	cin>>s->c->f->g->j->p->u;
	if(s->c->f->g->j->p->u%2==0)
	{
		s->c->f->g->j->p->t=new(s9);
		s->c->f->g->j->p->t->x=s->c->f->g->j->n;
		s->c->f->g->j->p->v=new(s10);
		s->c->f->g->j->p->v->y=s->c->f->i->m->r;
	}
	else
	{
	    s->c->f->g->j->p->t=new(s9);
		s->c->f->g->j->p->t->x=s->c->f->i->m->r;
		s->c->f->g->j->p->v=new(s10);
		s->c->f->g->j->p->v->y=s->c->f->g->j->n;
	}
	cout<<s->c->f->g->j->n<<" "<<s->c->f->i->m->r<<" "<<s->c->f->g->j->p->u<<" "<<s->c->f->g->j->p->t->x<<" "<<s->c->f->g->j->p->v->y<<endl;
}
