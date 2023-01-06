#include<iostream.h>
#include<fstream.h>

struct noun{
	char id[21];
	char category[21];
};

int main(){
	fstream f1("mini_database.dat",ios::in|ios::out|ios::binary);
	int i;
//	  noun n;
	/*for(i=0;i<100;i++){
		cout<<"Enter the ID: ";
		cin.getline(n.id,21);
		cout<<"Enter the category: ";
		cin.getline(n.category,21);
		f1.write((char*)&n,sizeof(n));
	}*/
	noun n1;
	f1.seekp(0L,ios::beg);
	for(i=0;i<100;i++){
		f1.read((char*)&n1,sizeof(n1));
		cout<<"ID: "<<n1.id<<"\tCategory: "<<n1.category<<"\n";
	}
	f1.close();
}

