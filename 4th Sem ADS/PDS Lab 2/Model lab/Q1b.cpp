//Sri:
#include<iostream>

using namespace std;

struct electrician{
    int ID;
    string client;
    int gender;
    int women;
    int men;
    electrician(){
        gender=1;
        women=0;
        men=0;
    }
};

struct avl_node{
    electrician data;
    avl_node* lc;
    avl_node* rc;
}*root,*u;

class avl_tree{
public:
    avl_tree(){
        root=0;
    }
    int height(avl_node* t){
        int h=0;
        if(t==0){
            return 0;
        }
        else{
            int lh=height(t->lc);
            int rh=height(t->rc);
            h=((lh>rh)?lh:rh)+1;
            return h;
        }
    }
    int balance_factor(avl_node* t){
        int bf=height(t->lc)-height(t->rc);
        return bf;
    }
    avl_node* rr_rotate(avl_node* t){
        avl_node *t2;
        t2=t->rc;
        t->rc=t2->lc;
        t2->lc=t;
        return t2;
    }
    avl_node* ll_rotate(avl_node* t){
        avl_node *t2;
        t2=t->lc;
        t->lc= t2->rc;
        t2->rc=t;
        return t2;
    }
    avl_node* lr_rotate(avl_node* t){
        avl_node *t2;
        t2=t->lc;
        t->lc=rr_rotate(t2);
        return ll_rotate(t);
    }
    avl_node* rl_rotate(avl_node* t){
        avl_node *t2;
        t2=t->rc;
        t->rc=ll_rotate(t2);
        return rr_rotate(t);
    }
    avl_node* balance(avl_node* t){
        int bf=balance_factor(t);
        if(bf>1) {
            if (balance_factor(t->lc)>0)
                t=ll_rotate(t);
            else
                t=lr_rotate(t);
            }
        else if(bf<-1){
            if (balance_factor(t->rc)>0)
                t=rl_rotate(t);
            else
                t=rr_rotate(t);
        }
        return t;
    }
    void inorder(avl_node* t){
        if(t!=0){
            inorder(t->lc);
            cout<<t->data.ID<<" ";
            inorder(t->rc);
        }
    }
    avl_node* insert_(avl_node* t,electrician val){
        if(t==0){
            t=new avl_node;
            t->data=val;
            t->lc=0;
            t->rc=0;
            return t;
        }
        else{
            if(t->data.ID<val.ID){
                t->lc=insert_(t->lc,val);
                t=balance(t);
            }
            else if(t->data.ID>val.ID){
                t->rc=insert_(t->rc,val);
                t=balance(t);
            }
            return t;
        }
    }
    int w_count(avl_node* t,int k){
        if(t!=0){
            int w=0;
            if(t->data.ID<k){
                if(t->data.gender==1)
                    w++;
            }
            int wc=w+w_count(t->lc,k)+w_count(t->rc,k);
            t->data.women=wc;
            return wc;
        }
        else{
            return 0;
        }
    }
    int m_count(avl_node* t,int k){
        if(t!=0){
            int m=0;
            if(t->data.ID<k){
                if(t->data.gender==0)
                    m++;
            }
            int mc=m+m_count(t->lc,k)+m_count(t->rc,k);
            t->data.men=mc;
            return mc;
        }
        else{
            return 0;
        }
    }
    avl_node* update(avl_node* t,int k){
        if(t!=0){
            if(t->data.ID==k){
                cout<<"Electrician updated!!\n";
                t->data.gender=0;
                return t;
            }
            else{
                if(t->data.ID>k){
                    return update(t->lc,k);
                }
                else if(t->data.ID<k){
                    return update(t->rc,k);
                }
                else if(t->lc==0&&t->rc==0){
                    cout<<"Electrician not updated! \n";
                    return t;
                }
            }
        }
    }
    int finddiff(avl_node* t, int k){
        int w=w_count(t,k);
        int m=m_count(t,k);
        return w-m;
    }
};

int main(){
   int ch=1;
   electrician i;
   avl_tree avl;
   while(ch>0&&ch<7) {
      cout<<"1.Insert Element into the tree"<<endl<<"2.InOrder traversal"<<endl<<"3.Update the gender "<<endl<<"4.Get thee women count: "<<endl<<"5.Get the men count"<<endl<<"6.Find the difference between men and women count: "<<endl<<"Enter your Choice: ";
      cin>>ch;
         if(ch==1){
            cout << "Enter ID of electrician to be inserted: ";
            cin>>i.ID;
            cout<<"Enter the name of the client: ";
            cin>>i.client;
            cin.get();
            root=avl.insert_(root, i);
         }
         if(ch==2){
            cout<<"Inorder Traversal: "<<endl;
            avl.inorder(root);
            cout<<endl;
         }
         if(ch==3){
            int a;
            cout<<"Enter the ID to be updated: ";
            cin>>a;
            u=avl.update(root,a);
            cout<<endl;
         }
         if(ch==4){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Women count: "<<avl.w_count(root,k)<<endl;
         }
         if(ch==5){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Men Count: "<<avl.m_count(root,k)<<endl;
         }
         if(ch==6){
            int k;
            cout<<"Enter the key value: ";
            cin>>k;
            cout<<"Difference between men and women count: "<<avl.finddiff(root,k)<<endl;
         }

   }
}
