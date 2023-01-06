#include<iostream.h>
#include<fstream.h>

struct noun{
	char id[21];
	char category[21];
};

int main(){
	noun n,n1;
	fstream f1("mini_database.dat",ios::in|ios::out|ios::binary);
	cout<<"Enter ID: ";
	cin.getline(n.id,21);
	cout<<"Enter Category: ";
	cin.getline(n.category,21);
	long pos=66*sizeof(noun);
	f1.seekp(pos,ios::beg);
	f1.write((char*)&n,sizeof(noun));
	f1.seekg(pos,ios::beg);
	f1.read((char*)&n1,sizeof(noun));
	cout<<"ID: "<<n1.id<<"\tCategory: "<<n1.category<<"\n";
	f1.close();
}

