/*#include<iostream>
#include<vector>
using namespace std;
template <int i>
void fun(){
    i=20;
    cout<<i;
}
int main(){
/*    vector<int> n;
    for(int i=0;i<5;i++)
        n.push_back(i);
    for(int i=0;i<5;i++)
        cout<<n[i]<<endl;
    n.erase(n.begin());
    for(int i=0;i<5;i++)
        cout<<n[i]<<endl;

    fun<10>();
}
*/
#include<iostream>

using namespace std;

template <class T, class U, class V=double>

class A

{

            T x;

            U y;

            V z;

            static int count;

};

int main()

{

            A <int, double> a;

            A <double,double> b;

            cout << sizeof(a) <<"  "<<sizeof (b)<<" "<<sizeof();

            return 0;

}
