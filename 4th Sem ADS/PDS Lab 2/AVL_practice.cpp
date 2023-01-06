#include<iostream.h>
using namespace std;
struct avl_node{
    int data;
    avl_node* lc;
    avl_node* rc;
}*root;
class avl_tree{
public:
    avl_node* ll_rotate(avl_node* p){
        avl_node* t=p->rc;
        p->rc=t->lc;
        t->lc=p;
        return t;
    }
    avl_node* rr_rotate(avl_node* p){
        avl_node* t=p->lc;
        p->lc=t->rc;
        t->rc=p;
        return t;
    }
    avl_node*
};
