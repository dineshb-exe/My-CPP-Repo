#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class date {
	int d;
	int m;
	int y;
public:
	date() {
		d = 0;
		m = 0;
		y = 0;
	}
	void read() {
		cout << "Enter the date in (DD/MM/YYYY) format one by one";
		cin >> d >> m >> y;
	}
	void display() {
		cout << setw(2) << setfill('0') << d << '/' << setw(2) << setfill('0') << m << '/' << setw(4) << setfill('0') << y<<endl;
	}
};

class Product {
	char* name;
	int pid;
	date mfd;
	date expiry;
	int price;
	char* category;
	int size;
public:
	Product() {
		int s;
		cout << "Enter the size of strings: ";
		cin >> s;
		size = s;
		name = new char[s];
		category = new char[s];
		strcpy(name,"Unknown");
		strcpy(category,"Unknown");
		pid = -1;
		price = 0;

	}
	~Product() {
		delete[] name;
		delete[] category;
		cout << "Object Destroyed! \n";
	}
	void read1() {
		cin.get();
		cout << "Enter the product name: ";
		cin.getline(name, size);
		cout << "Enter the product ID: ";
		cin >> pid;
		cin.get();
		cout << "Enter the category of the product: ";
		cin.getline(category, size);
		cout << "Enter the selling price of the product: ";
		cin >> price;
		mfd.read();
		expiry.read();

	}
	void display1() {
		cout << "Product Name: " << name << endl;
		cout << "Product ID: " << pid << endl;
		cout << "Category: " << category << endl;
		cout << "Price starts at: Rs. " << price << endl;
		mfd.display();
		expiry.display();

	}
};

int main() {
	Product p1;
	p1.display1();
	p1.read1();
	p1.display1();
}
