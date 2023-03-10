#include<iostream>
#include<ctime>
using namespace std;
using namespace std::chrono;
class Btreenode
{
    int * keys;
    Btreenode**c;
    int t;
    int n;
    bool leaf;
    public:
    Btreenode(int _t,bool leaf);
    void insert_non(int k);
    void splitchild(int i,Btreenode*y);
    void traverse();
    friend class Btree;
};
class Btree
{
    Btreenode*root;
    int t;
    public:
    Btree(int _t)
    {
        t=_t;
    }
    void traverse()
    {
        if(root!=NULL)
        {
            root->traverse();
        }
    }
    void insert(int k);
};
Btreenode ::Btreenode(int t,bool leaf)
{t=_t;
leaf=leaf_;
keys=new int[2*t-1];
c=new Btreenode*[2*t];
n=0;}

void Btree::insert(int k)
{
    if(root==NULL)
    {
        root=new Btreenode(t,true);
        root->keys[0]=k;
        root->n=1;
    }
    else
    {
        if(root->n==2*t-1)
        {
            Btreenode*s=new Btreenode(t,false);
            s->c[0]=root;
            s->splitchild(0,root);
            int i=0;
            if(s->keys[0]<k)
            {
                i++;
            }
            s->c[i]->insert_non(k);
            root=s;
        }
        else
        root->insert_non(k);
    }
}

void Btreenode::splitchild(int i,Btreenode*y)
{
    Btreenode*z=new Btreenode(y->t,y->leaf);
    z->n=t-1;
    for(int j=0;j<t-1;j++)
    {
        z->keys[j]=y->keys[j+t];
    }
    if(y->leaf==false)
    {
        for(int j=0;j<t;j++)
        {
            z->c[j]=y->c[j+t];
        }
    }
    y->n=t-1;
    for(int j=n;j>=i+1;j--)
    {
        this->c[j+1]=this->c[j];
    }
     this->c[i+1]=z;
    for(int j=n-1;j>=i;j--)
    {
        this->keys[j+1]=this->keys[j];
    }

    this->keys[i]=y->keys[t-1];

    n++;
}

void Btreenode::insert_non(int k)
{
    int i;
    i=n-1;
    if(leaf==true)
    {
    while(i>=0 && keys[i]>k)
       { keys[i+1]=keys[i];
           i--;}
    keys[i+1]=k;
    n++;}
    else
    {
        while(i>=0 && keys[i]>k)
        {
            i--;
        }
        if(c[i+1]->n==2*t-1)
        {
            splitchild(i+1,c[i+1]);
            if(keys[i+1]<k)
            i++;

    }
    c[i+1]->insert_non(k);
}}

void Btreenode::traverse()
{int i;
for(i=0;i<n;i++)
{
    if(leaf==false)
    {
        c[i]->traverse();}
        cout<<" "<<keys[i]<<" ";

}
if(leaf==false)
{
    c[i]->traverse();
}

}

int main()
{
    Btree t(3);
    auto start = high_resolution_clock::now();
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(25);
    t.traverse();
    auto stop = high_resolution_clock::now();
    cout<<"\n";
	auto duration = duration_cast<microseconds>(stop - start);
    cout<< duration.count()<<" is time taken in micro seconds";

}
