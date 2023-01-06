#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
const int N=10000;
int main(){
  char name[N],letter,sal[15],junk[N];
  int i=0,max,s,j=0,len;
  ifstream f1;
  f1.open("input.txt");
  ofstream f2;
  f2.open("output.txt");
  i=0;
  while(!f1.eof()){
   f1.getline(name,N,',');
   f1.get(letter);
   f1.get(sal,15,',');
   f1.getline(junk,N);
   s=1;
   for(len=0;sal[len]!='\0';len++);
   j=len-1;
   int j2=0;
   cout<<sal<<endl;
   while(j>=0){
    s+=(int(sal[j2])-48)*(pow(10,j));
    j--;
    j2++;
   }
   cout<<s<<endl;
   if(i==0)
    max=s;
   else{
    if(s>max)
     max=s;
   }
   i++;
  }
  f2<<max<<endl;
  f1.close();
  f2.close();
}
