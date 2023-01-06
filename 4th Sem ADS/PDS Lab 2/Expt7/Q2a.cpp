#include<iostream>
using namespace std;
struct electrician{
    int id;
    string client;
    int gender;
    int man;
    electrician(){
        gender=1;
    }
};
struct avl {
   electrician d;
   struct avl *l;
   struct avl *r;
}*r,*x;
class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, electrician);
      void show(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void postorder(avl*);
      avl* update(avl* t,int k);
      int w_count(avl *t,int k);
      int m_count(avl* t,int k);
      int finddif(avl* t,int k);
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
   cout<<"Right-Right Rotation\n";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation\n";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation\n";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation\n";
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
avl *avl_tree::insert(avl *r, electrician v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = 0;
      r->r = 0;
      return r;
   }
   else if (v.id < (r->d).id ){
      r->l = insert(r->l, v);
      r = balance(r);
   }
   else if (v.id >= (r->d).id){
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
         cout << p->d.id;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t != NULL){
      inorder(t->l);
      cout << t->d.id << " ";
      inorder(t->r);
   }
}
void avl_tree::preorder(avl *t) {
   if (t != NULL){
      cout << t->d.id << " ";
      preorder(t->l);
      preorder(t->r);
   }
}
void avl_tree::postorder(avl *t) {
   if (t != NULL){
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d.id << " ";
   }
}
avl* avl_tree::update(avl* t,int k){
    if(t!=0){
        if(t->d.id==k){
            cout<<"Electrician updated!!\n";
            t->d.gender=0;
            return t;
        }
        else{
            if(t->d.id>k){
                return update(t->l,k);
            }
            else if(t->d.id<k){
                return update(t->r,k);
            }
            else if(t->l==0&&t->r==0){
                cout<<"Electrician not updated! \n";
                return t;
            }
        }
    }
}
int avl_tree::w_count(avl* t,int k){
    if(t!=0){
        int w=0;
        if(t->d.id<k){
            if(t->d.gender==1)
                w++;
        }
        return w+w_count(t->l,k)+w_count(t->r,k);
    }
    else{
        return 0;
    }
}
int avl_tree::m_count(avl* t,int k){
    if(t!=0){
        int m=0;
        if(t->d.id<k){
            if(t->d.gender==0)
                m++;
        }
        return m+m_count(t->l,k);
    }
    else{
        return 0;
    }
}
int avl_tree::finddif(avl* t,int k){
    int w=w_count(t,k);
    int m=m_count(t,k);
    return w-m;
}

int main() {
   int ch=1;
   electrician i;
   avl_tree avl;
   while (ch>0&&ch<10) {
      cout<<"1.Insert Element into the tree"<<endl<<"2.show Balanced AVL Tree"<<endl<<"3.InOrder traversal"<<endl<<"4.PreOrder traversal"<<endl<<"5.PostOrder traversal"<<endl<<"6.Update the gender "<<endl<<"7.Get thee women count: "<<endl<<"8.Get the men count"<<endl<<"9. Find the difference between men and women count: "<<"Enter your Choice: ";
      cin>>ch;
         if(ch==1){
            cout << "Enter value to be inserted: ";
            cin>>i.id;
            cout<<"Enter the name of the client: ";
            cin>>i.client;
            cin.get();
            r = avl.insert(r, i);
         }
         if(ch==2){
            if (r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
         }
         if(ch==3){
            cout << "Inorder Traversal: " << endl;
            avl.inorder(r);
            cout << endl;
         }
         if(ch==4){
            cout << "Preorder Traversal: " << endl;
            avl.preorder(r);
            cout << endl;
         }
         if(ch==5){
            cout << "Postorder Traversal: " << endl;
            avl.postorder(r);
            cout << endl;
         }
         if(ch==6){
            int a;
            cout<<"Enter the value to be updated: ";
            cin>>a;
            x=avl.update(r,a);
            cout<<endl;
         }
         if(ch==7){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Women count: "<<avl.w_count(r,k)<<endl;
         }
         if(ch==8){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Men Count: "<<avl.m_count(r,k)<<endl;
         }
         if(ch==9){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Difference: "<<avl.finddif(r,k)<<endl;
         }

   }
}
