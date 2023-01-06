#include<iostream>
using namespace std;
struct node{
	int d;
	node* lc;
	node* rc;
	bool col;//1 for Black, 0 for Red
}*root;
class RB_Trees{
	public:
		int height(node* t){
			int h = 0;
   			if (t!=NULL){
      			int lh=height(t->lc);
      			int rh=height(t->rc);
      			int mh= (lh>rh)?lh:rh;
      			h=mh+1;
   			}
   			return h;
		}
		int difference(node* t){
			int lh=height(t->lc);
			int rh=height(t->rc);
			int dif=lh-rh;
			return dif;
		}
		node* rr_rotate(node *parent) {
			node *t;
   			t=parent->rc;
   			parent->rc=t->lc;
    		t->lc=parent;
   			cout<<"Right-Right Rotation\n";
   			return t;
		}
		node* ll_rotate(node* parent) {
   			node *t;
   			t = parent->lc;
   			parent->lc=t->rc;
   			t->rc=parent;
   			cout<<"Left-Left Rotation\n";
   			return t;
		}
		node* lr_rotate(node* parent) {
   			node *t;
   			t=parent->lc;
   			parent->lc=rr_rotate(t);
   			cout<<"Left-Right Rotation\n";
   			return ll_rotate(parent);
		}
		node* rl_rotate(node* parent) {
   			node *t;
   			t = parent->rc;
   			parent->rc=ll_rotate(t);
   			cout<<"Right-Left Rotation";
   			return rr_rotate(parent);
		}
		node* balance(node* t){
			if(difference(t)>1){
				if(difference(t->lc)>0)
				//RR Rotate
				t=rr_rotate(t);
				else if(difference(t->lc)<0)
				//LR Rotate
				t=lr_rotate(t);
			}
			else if(difference(t)<-1){
				if(difference(t->rc)<0)
				//LL Rotate
				t=ll_rotate(t);
				else if(difference(t->rc)>0)
				//LR Rotate
				t=lr_rotate(t);
			}
		}
		node* findparent(int val){
			node* t=root;
			while(t->lc!=0||t->rc!=0){
					if(t->d>val)
					t=t->rc;
					else
					t=t->lc;
				}
				return t;
		}
		void insert(node* t,int val){
			if(t==0){
				t=new node;
				t->d=val;
				t->lc=0;
				t->rc=0;
				if(t==root)
				t->col=1;
				else
				t->col=0;
				return;
			}
			else{
				node* n=new node;
				n->d=val;
				n->lc=0;
				n->rc=0;
				n->col=0;
				t=findparent(val);
				if(val>t->d)
				t->rc=n;
				else
				t->lc=n;
				//If the parent is Red
				if(t->col==0){
					node* sib=root;
					//Finding the sibling
					while(sib->lc!=t||sib->rc!=t){
						if(t->d>sib->d)
						sib=sib->rc;
						else
						sib=sib->lc;
					}
					if(sib->lc==t)
					sib=sib->rc;
					else
					sib=sib->lc;
					//If the sibling is Nil
					if(sib==0){
						t=balance(t);
						
					}
					//If parent's Sibling is black 
					if(sib->col==1){
						t=balance(t);
						
							
					}
					//If parent's sibling is red
					else{
						node* tp=findparent(t->d);
						t->col=1-t->col;
						sib->col=1-sib->col;
						while(tp!=root){
							tp->col=1-tp->col;
							tp=findparent(tp->d);
						}
					}
				}
				//If the parent is black
				else{
					return;
				}
			}
		}
		void inorder(node *t) {
   			if (t!=NULL){
      			inorder(t->lc);
      			cout << t->d << " ";
      			inorder(t->rc);
   			}
		}
};
int main(){
	root=0;
	cout<<"Hello\n";
	RB_Trees rb1;
	rb1.insert(root,5);
	rb1.inorder(root);
	rb1.insert(root,3);
	rb1.insert(root,4);
	rb1.insert(root,10);
	rb1.inorder(root);
	
}
