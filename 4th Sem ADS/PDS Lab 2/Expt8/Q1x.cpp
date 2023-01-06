#include<iostream>
#include<queue>
using namespace std;
const int m=5;
struct node{
	int* d;
	node** c;
	int li;//Stores the index of the recently inserted element
	node(){
		d=0;
		c=0;
		li=-1;
	}
}*root;
class B_Tree{
	public:
		int leafcheck(node* t){
			int f=1;
			for(int i=0;i<m&&f==1;i++){
				if(t->c[i]!=0)
					f=0;
			}
			return f;			
		}
		node* findparent(int val){
			node* t=root;
			while((t->c[0])->nf!=1||(t->c[1])->nf!=1){
                if((t->rc)->nf==1){
                    if(val>t->d)
                        return t;
                    else
                        t=t->lc;
                }
                else if((t->rc)->nf==1){
                    if(val<t->d)
                        return t;
                    else
                        t=t->rc;
                }
                else if((t->lc)->nf!=1&&(t->rc)->nf!=1){
                    if(val>t->d)
                    t=t->rc;
                    else
                    t=t->lc;
                }
            }
            return t;
		}
		void split(node*& t,int mid1){
			if(findparent(t)==0){
				node* n1=new node;
				node* n2=new node;
				t->c[0]=n1;
				t->c[1]=n2;
				for(int i=0;i<m;i++){
					n1->c[i]=0;
					n2->c[i]=0;
				}
				int j=0,k=0;
				for(int i=0;i<t->li;i++){
					if(t->d[i]>t->d[mid1]){
						n2->d[j]=t->d[i];
						j++;
					}
					else if(t->d[i]<t->d[mid1]){
						n1->d[k]=t->d[mid1];
						k++;
					}
				}
				t->li=0;
				t->d[t->li]=t->d[mid1];
			}
			
		}
		void insert(node*& t,int val){
			if(t==0){
				t=new node;
				t->d=new int[m];
				t->d[++t->li]=val;
				t->c=new node*[m];
				int i;
				for(i=0;i<m;i++)
				t->c[i]=0;
				t->d[0]=val;
			}
			else{
				if(leafcheck(t)){
					//If the leaf node is full
					if(t->li==m-2){
						int f=0;
						for(int i=0;i<=t->li&&f==0;i++){
							if(val<t->d[i]){
								int j;
								for(j=t->li+1;j>i;j--)
								t->d[j]=t->d[j-1];
								t->d[i]=val;
								t->li++;
								f=1;								
							}
						}
						if(f==0)
						t->d[++t->li]=val;
						int mid=t->li/2;
						split(t,mid);
					}
					//If leaf is not full
					else{
						int f=0;
						for(int i=0;i<=t->li&&f==0;i++){
							if(val<t->d[i]){
								int j;
								for(j=t->li+1;j>i;j--)
								t->d[j]=t->d[j-1];
								t->d[i]=val;
								t->li++;
								f=1;								
							}
						}
						if(f==0)
						t->d[++t->li]=val;
					}
				}
				else{
					if(val<t->d[0]){
						insert(t->c[0],val);
					}
					else if(val<t->d[1]&&val>t->d[0]){
						insert(t->c[1],val);
					}
					else if(val<t->d[2]&&val>t->d[1]){
						insert(t->c[2],val);
					}
					else if(val<t->d[3]&&val>t->d[2]){
						insert(t->c[3],val);
					}
					else if(val>t->d[3]){
						insert(t->c[4],val);
					}
				}				
			}
		}
		void traverse(node* t){
        	if(t!=0){
				queue<node* > q;
        		q.push(t);
        		while(!(q.empty())){
            		t=q.front();
            		q.pop();
            		for(int i=0;i<=t->li;i++)
                		cout<<t->d[i]<<" ";
            		cout<<endl;
            		for(int i=0;i<m;i++)
                		q.push(t->c[i]);
        		}
        	}
        	else{
        		cerr<<"Tree Empty";
			}
        }
    
};

int main(){
	root=0;
	B_Tree b1;
	b1.insert(root,1);
	b1.insert(root,8);
	b1.insert(root,2);
	b1.insert(root,12);
	b1.insert(root,25);
	b1.traverse(root);
}
