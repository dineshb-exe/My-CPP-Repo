#include<iostream>
#include<cstdio>
using namespace std;
struct avl {
   int d;
   struct avl *l;
   struct avl *r;
}*r;
class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int);
      void show(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void postorder(avl*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = 0;
      r->r = 0;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) {
   int i;
   if (p!=0) {
      show(p->r,l+1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t != NULL){
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
   }
}
void avl_tree::preorder(avl *t) {
   if (t != NULL){
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
   }
}
void avl_tree::postorder(avl *t) {
   if (t != NULL){
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << " ";
   }
}
int main() {
   int ch=1, i;
   avl_tree avl;
   while (ch>0&&ch<7) {
      cout<<"1.Insert Element into the tree"<<endl<<"2.show Balanced AVL Tree"<<endl<<"3.InOrder traversal"<<endl<<"4.PreOrder traversal"<<endl<<"5.PostOrder traversal"<<endl<<"6.Height"<<endl<<"7.Exit"<<endl<<"Enter your Choice: ";
      cin>>ch;
         if(ch==1){
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
         }
         else if(ch==2){
            if (r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
         }
         else if(ch==3){
            cout << "Inorder Traversal:" << endl;
            avl.inorder(r);
            cout << endl;
         }
         else if(ch==4){
            cout << "Preorder Traversal:" << endl;
            avl.preorder(r);
            cout << endl;
         }
         else if(ch==5){
            cout << "Postorder Traversal:" << endl;
            avl.postorder(r);
            cout << endl;
         }
         else if(ch==6){
            cout<<avl.height(r);
            cout<<endl;
         }
   }
}