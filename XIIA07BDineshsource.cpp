//                                       											 Sri:
#include<iostream>
#include<ctime>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<windows.h>

using namespace std;

const int N=10;
const int M=21;
const int P=31;
const int L=51;

void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

struct Edible_Products {
	char name1[P];
	int Quantity1;
	char batch_no[M];
	int pID1;
	double rate1;
	char dateofMan1[P];
	char dateofExpiry[P];
	char category[M];
	int dtoe;
	Edible_Products(){
		strcpy(name1,"Not Found");
		Quantity1=0;
		strcpy(batch_no,"Undefined");
		pID1=0;
		rate1=0.0;
		strcpy(dateofMan1,"??/??/????");
		strcpy(dateofExpiry,"??/??/????");
		strcpy(category,"Undefined");
		dtoe=0;
	}

};
struct Non_Edible_Product{
	char name2[M];
	int Quantity2;
	int pID2;
	char dateofMan2[P];
	char batch_no[M];
	double rate2;
	char category[M];
	Non_Edible_Product(){
		strcpy(name2,"Not Found");
		Quantity2=0;
		strcpy(batch_no,"Undefined");
		pID2=0;
		rate2=0.0;
		strcpy(dateofMan2,"??/??/????");
		strcpy(category,"Undefined");
	}
};
struct Product_Supplier {
	char name3[M];
	int sID;
	char Product_name[L];
	char contact1[11];
	int Quantity3;

	Product_Supplier(){
		strcpy(name3,"Not Found");
		sID=0;
		strcpy(Product_name,"Not Found");
		strcpy(contact1,"Undefined");
		Quantity3=0;
	}
};
struct Customer{
	char name4[M];
	int CustomerID;
	char address[L];
	char date3[P];
	char contact2[11];
	char e_mail_ID[L];
	char Premium_Subs;

	Customer(){
		strcpy(name4,"Not Found");
		CustomerID=0;
		strcpy(address,"Not found in the city ");
		strcpy(date3,"??/??/????");
		strcpy(contact2,"Undefined");
		strcpy(e_mail_ID,"someone@nowhere.com");
		Premium_Subs='N';
	}
};
struct Delivery {
	char name5[M];
	int Orderno;
	int CustID;
	char Address[L];
	char products[L];
	char Deadline[P];
	char contact3[11];

	Delivery(){
		strcpy(name5,"Not Found");
		CustID=0;
		Orderno=0;
		strcpy(Address,"Not found in the city");
		strcpy(products,"Currently No Products");
		strcpy(contact3,"Undefined");
		strcpy(Deadline,"??/??/????");
	}
};
struct Billing{
	char name6[M];
	int quan;
	double rate3;
	double amt;
	Billing(){
		strcpy(name6,"Unknown ");
		quan=0;
		rate3=0.0;
		amt=0.0;
	}
};

struct user {
	char username[M];
	int userID;
	char usertype;
	char DOB[P];
	char DOJ[P];
	char contact3[11];
	char password[M];
	double fund;

	user(){
	fund=0;
	}
	/*
	Description:
	This function is used to write Edible Products' details in the file
	Function ID:Add_Edible_Product_Details
	Parameter: an object of type Edible_Products, an integer taking the value OF product iD, a charcter denoting whether a product has to be added or quantity
	Return type: void
	*/

	void Add_Edible_Product_Details(Edible_Products &e,int pd){
		fstream f1("Edible_Products1.dat",ios::in|ios::out|ios::binary);
		f1.seekp(long((pd-1)*sizeof(Edible_Products)),ios::beg);
		f1.write((char *)&e,sizeof(e));
		f1.close();

	}
	/*
	Description:
	This function is used to ADD quantities in the file
	Function ID: Alter_Edible_Quantity
	Parameter: an object of type Edible_Products, an integer taking the value OF product iD, an integer denoting quantity to be added, an integer denoting the number of days of expire
	Return type: void
	*/
	void Alter_Edible_Quantity(Edible_Products &e,int pd,int q,int d,char x1[11], char x2[11]){
		if(fund>=0.3*(q*e.rate1)){
			fstream f1s("Edible_Products1.dat",ios::in|ios::out|ios::binary);
			f1s.seekg(long((pd-1)*sizeof(Edible_Products)),ios::beg);
			f1s.read((char*)&e,sizeof(Edible_Products));
			e.Quantity1+=q;
			e.dtoe=d;
			strcpy(e.dateofMan1,x1);
			strcpy(e.dateofExpiry,x2);
			fund-=0.3*(q*e.rate1);
			f1s.seekp(long((pd-1)*sizeof(Edible_Products)),ios::beg);
			f1s.write((char*)&e,sizeof(Edible_Products));
			f1s.close();
		}
		else{
			gotoxy(35,2);
			cout<<"You don't have the money to buy these goods ";
		}
	}

	/*
	Description:
	This function is used to delete Edible Products' details in the file
	Function ID:Delete_Edible_Products
	Parameter: an object of type Edible_Products,a character array having the name of the product, an integer denoting the quantity to be deleted, an integer taking the value OF product iD
	Return type: void
	*/
	void Delete_Edible_Products(Edible_Products &e,char prod_del1[M],int quan,int pdno){
		fstream f2s("Edible_Products1.dat",ios::in|ios::out|ios::binary);
		f2s.seekg(long((pdno-1)*sizeof(Edible_Products)),ios::beg);
		f2s.read((char*)&e,sizeof(Edible_Products));
		if(quan>e.Quantity1||e.Quantity1==0){
			system("cls");
			gotoxy(50,1);
			cout<<"SUPERMARKET";
			gotoxy(35,5);
			cerr<<"There are only "<<e.Quantity1<<"units in the market \n";
		}
		else if(quan<e.Quantity1){
			if((!(strcmp(prod_del1,e.name1))&&pdno!=e.pID1)||(strcmp(prod_del1,e.name1))&&pdno==e.pID1||(strcmp(prod_del1,e.name1))&&pdno!=e.pID1){
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(30,2);
				cerr<<"Name and Product number didin't match Try entering appropriate Name and Number";
			}
			else{
				e.Quantity1=e.Quantity1-quan;
				f2s.seekp(long((pdno-1)*sizeof(Edible_Products)),ios::beg);
				f2s.write((char*)&e,sizeof(e));
				f2s.close();
			}
		}

		else {
			f2s.close();
			fstream f2("Edible_Products1.dat",ios::out|ios::in|ios::binary);
			fstream f3("Temp.dat",ios::out|ios::binary);
			while(f2.read((char*)&e,sizeof(e))){
				if((strcmp(prod_del1,e.name1))&&pdno!=e.pID1){
					f3.write((char*)&e,sizeof(e));
				}
				else if((!(strcmp(prod_del1,e.name1))&&pdno!=e.pID1)||(strcmp(prod_del1,e.name1))&&pdno==e.pID1){
					system("cls");
					gotoxy(50,1);
					cout<<"SUPERMARKET";
					gotoxy(35,2);
					cerr<<"Name and Product number didin't match \nTry entering appropriate Name and Number";
				}
				else{
					Edible_Products e1;
					f3.write((char*)&e1,sizeof(e1));
				}
			}
			f3.close();
			f2.close();
			char filename[51]="Edible_Products1.dat";
			getch();
			remove(filename);
			rename("Temp.dat","Edible_Products1.dat");
		}

	}
	/*
	Description:
	This function is used to display the details of edible products
	Function iD: displayEdible
	Parameters: an object of type Edible_Products, an integer denoting the product ID
	Return type: void
	*/
	void displayEdible(Edible_Products &e,int pd){
		fstream f4("Edible_Products1.dat",ios::out|ios::in|ios::binary);
		system("cls");
		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(50,2);
		cout<<"Details: ";

		f4.seekg(long((pd-1)*sizeof(Edible_Products)),ios::beg);
		f4.read((char*)&e, sizeof(e));
		gotoxy(40,5);
		cout<<"Name:";
		gotoxy(40,6);
		puts(e.name1);
		gotoxy(40,8);
		cout<<"Quantity:";
		gotoxy(40,9);
		cout<<e.Quantity1;
		gotoxy(40,10);
		cout<<"Batch No.:";
		gotoxy(40,11);
		cout<<e.batch_no;
		gotoxy(40,12);
		cout<<"Category: ";
		gotoxy(40,13);
		puts(e.category);
		gotoxy(40,14);
		cout<<"Rate:";
		gotoxy(40,15);
		cout<<e.rate1;
		gotoxy(40,16);
		cout<<"Mfg.Date:";
		gotoxy(40,17);
		puts(e.dateofMan1);
		gotoxy(40,18);
		cout<<"Expiry Date:";
		gotoxy(40,19);
		puts(e.dateofExpiry);
		gotoxy(40,20);
		cout<<"No. of days left to expire: ";
		gotoxy(40,21);
		cout<<e.dtoe<<'\n';
		f4.close();
	}

	/*
	Description:
	This function is used to write Non-Edible Products' details in the file
	Function ID:Add_NonEdible_Product_Details
	Parameter: an object of type Non_Edible_Product, an integer taking the value OF product iD
	Return type: void
	*/
	void Add_NonEdible_Product_Details(Non_Edible_Product &ne,int pd){
			fstream f5("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
			f5.seekp((pd-1)*sizeof(Non_Edible_Product),ios::beg);
			f5.write((char *)&ne,sizeof(ne));
			f5.close();
	}

	/*
	Description:
	This function is used to ADD quantities of non-edible products in the file
	Function ID: Alter_NonEdible_Quantity
	Parameter: an object of type Edible_Products, an integer taking the value OF product iD, an integer denoting quantity to be added
	Return type: void
	*/

	void Alter_NonEdible_Quantity(Non_Edible_Product &ne,int pd,int q,char x[11]){

		if(fund>=0.3*(q*ne.rate2)){
			fstream f5s("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
			f5s.seekg(long((pd-1)*sizeof(Non_Edible_Product)),ios::beg);
			f5s.read((char*)&ne,sizeof(Non_Edible_Product));
			ne.Quantity2+=q;
			strcpy(ne.dateofMan2,x);
			f5s.seekp(long((pd-1)*sizeof(Non_Edible_Product)),ios::beg);
			fund-=0.3*(q*ne.rate2);
			f5s.write((char*)&ne,sizeof(Non_Edible_Product));
			f5s.close();
		}
		else
		cout<<"You don't have the money to buy these goods ";
	}
	/*
	Description:
	This function is used to delete Non-Edible Products' details in the file
	Function ID:Delete_NonEdible_Products
	Parameter: an object of type Non_Edible_Product,a character array having the name of the product, an integer denoting the quantity to be deleted, an integer taking the vLUE OF product iD
	Return type: void
	*/
	void Delete_NonEdible_Products(Non_Edible_Product &ne,char prod_del2[M],int quan2,int npd){
		fstream f6s("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
		f6s.seekg(long((npd-1)*sizeof(Non_Edible_Product)),ios::beg);
		f6s.read((char*)&ne,sizeof(Non_Edible_Product));

		if(quan2>ne.Quantity2||ne.Quantity2==0){
			cerr<<"There are only "<<ne.Quantity2<<"Products in the market ";
		}
		else if(quan2<ne.Quantity2){
            if((!(strcmp(prod_del2,ne.name2))&&npd!=ne.pID2)||(strcmp(prod_del2,ne.name2))&&npd==ne.pID2){
					system("cls");
					gotoxy(50,1);
					cout<<"SUPERMARKET";
					gotoxy(35,2);
            	cerr<<"Name and Product number didin't match Try entering appropriate Name and Number";
				}
			else{
         	ne.Quantity2=ne.Quantity2-quan2;
            f6s.seekp(long((npd-1)*sizeof(Non_Edible_Product)),ios::beg);
            f6s.write((char*)&ne,sizeof(ne));
            f6s.close();
         }
		}
		else {
			f6s.close();
			fstream f6("Non_Edible_Products.dat",ios::out|ios::in|ios::binary);
			fstream f7("Temp.dat",ios::out|ios::binary);
			while(f6.read((char*)&ne,sizeof(ne))){
				if((strcmp(prod_del2,ne.name2))&&npd!=ne.pID2){
					f7.write((char*)&ne,sizeof(ne));
				}
				else if((!(strcmp(prod_del2,ne.name2))&&npd!=ne.pID2)||(strcmp(prod_del2,ne.name2))&&npd==ne.pID2){
					system("cls");
					gotoxy(50,1);
					cout<<"SUPERMARKET";
					gotoxy(35,2);
					cerr<<"Name and Product number didin't match \nTry entering appropriate Name and Number";
				}
				else{
					Non_Edible_Product ne1;
					f7.write((char*)&ne1,sizeof(ne1));
				}
			}
			f6.close();
			f7.close();
			char filename2[51]="Non_Edible_Products.dat";
			remove(filename2);
			rename("Temp.dat","Non_Edible_Products.dat");
		}

	}

	/*
	Description:
	This function is used to display the details of non edible products
	Function iD: displayNonEdible
	Parameters: an object of type Non_Edible_Product, an integer denoting the product ID
	Return type: void
	*/
	void displayNonEdible(Non_Edible_Product &ne,int npd){
		fstream f8("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(40,2);
		cout<<"Details: ";
		f8.seekg(long((npd-1)*sizeof(Non_Edible_Product)),ios::beg);
		f8.read((char*)&ne, sizeof(ne));
		gotoxy(40,3);
		cout<<"Name:";
		gotoxy(40,4);
		puts(ne.name2);
		gotoxy(40,5);
		cout<<"Quantity: ";
		gotoxy(40,6);
		cout<<ne.Quantity2;
		gotoxy(40,7);
		cout<<"Batch No.: ";
		gotoxy(40,8);
		puts(ne.batch_no);
		gotoxy(40,9);
		cout<<"Rate: ";
		gotoxy(40,10);
		cout<<ne.rate2;
		gotoxy(40,11);
		cout<<"Category ";
		gotoxy(40,12);
		puts(ne.category);
		gotoxy(40,13);
		cout<<"Mfg. Date: ";
		gotoxy(40,14);
		puts(ne.dateofMan2);

		f8.close();
	}

	/*
	Description:
	This function is used to write Product Supplier's details in the file
	Function ID:Add_ProductSupplier
	Parameter: an object of type Product_Supplier
	Return type: void
	*/
	void Add_ProductSupplier(Product_Supplier &p,int pd){
		fstream f9("Product_Supplier.dat",ios::in|ios::out|ios::binary);
		f9.seekp(long((pd-1)*sizeof(Product_Supplier)),ios::beg);
		f9.write((char*)&p,sizeof(p));
		f9.close();

	}

	/*
	Description:
	This function is used to delete Product Suppliers' details in the file
	Function ID:Delete_ProductSupplier
	Parameter: an object of type Product_Supplier,a character array having the name of the product supplier
	Return type: void
	*/
	void Delete_ProductSupplier(Product_Supplier &p,char supplier_del[M],int supID){
		fstream f10("Product_Supplier.dat",ios::out|ios::in|ios::binary);
		fstream f11("Temp.dat",ios::out|ios::binary);
		while(f10.read((char*)&p,sizeof(p))){
			if((strcmp(supplier_del,p.name3))&&supID!=p.sID){
				f11.write((char*)&p,sizeof(p));
			}
			else if((!(strcmp(supplier_del,p.name3))&&supID!=p.sID)||(strcmp(supplier_del,p.name3))&&supID==p.sID){
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(35,2);
				cerr<<"Name and Supplier id didn't match Try entering appropriate Name and Number";
			}
			else{
				Product_Supplier p1;
				f11.write((char*)&p1,sizeof(p1));
			}
		}
		f11.close();
		f10.close();
		char filename3[51]="Product_Supplier.dat";
		remove(filename3);
		rename("Temp.dat","Product_Supplier.dat");
	}

	/*
	Description:
	This function is used to display the details of product supplier
	Function iD: DisplayProductSupplier
	Parameters: an object of type Product_Supplier, an integer denoting the supplier ID
	Return type: void
	*/
	void DisplayProductSupplier(Product_Supplier &p,int supID){
		fstream f12a("Product_Supplier.dat",ios::in|ios::out|ios::binary);
		p.sID=supID;

		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(40,2);
		cout<<"Supplier Details: ";
		f12a.seekg((p.sID-1)*sizeof(Product_Supplier),ios::beg);
		f12a.read((char*)&p,sizeof(p));
		gotoxy(40,3);
		cout<<"Name: ";
		gotoxy(40,4);
		puts(p.name3);
		gotoxy(40,5);
		cout<<"Supplier ID:";
		gotoxy(40,6);
		cout<<p.sID;
		gotoxy(40,7);
		cout<<"Product(s) supplied: ";
		gotoxy(40,8);
		puts(p.Product_name);
		gotoxy(40,9);
		cout<<"Contact No.";
		gotoxy(40,10);
		puts(p.contact1);
		gotoxy(40,11);
		cout<<"Quantity Supplied ";
		gotoxy(40,12);
		cout<<p.Quantity3;

		f12a.close();
	}
	/*
	Description:
	This function is used to check whether a product is about to expire and also displays the quantity of such products
	Function iD:Check_Expiry
	Parameters:A variable of type Edible_Products
	return type:void
	*/
	void Check_Expiry(Edible_Products &e){
		time_t crtme;
		crtme = time(0);

		tm *lcl = localtime(&crtme);

		if(lcl->tm_hour=9 && lcl->tm_min==34){
			fstream f19("Edible_Products1.dat",ios::in|ios::out|ios::binary);
			e.dtoe-=1;
			f19.seekp(long((e.pID1-1)*sizeof(e)),ios::beg);
			f19.write((char*)&e,sizeof(e));
			f19.close();
		}

		if(e.dtoe>0&&e.dtoe<=10){
			gotoxy(40,3);
			cout<<e.name1<<" will expire in "<<e.dtoe<<" days \a";
			gotoxy(40,5);
			cout<<"There are "<<e.Quantity1<<" units in the market \n \n";
		}

	}
	/*Description:
	This function is used to add the details of a customer
	Function Id:Add_Customer
	Parameters:An object of type Customer,an integer denoting customer ID
	return type:void
	*/
	void Add_Customer(Customer &c,int cid){
		fstream f14("Customer.dat",ios::in|ios::out|ios::binary);
		f14.seekp(long((cid-1)*sizeof(c)),ios::beg);
		f14.write((char*)&c,sizeof(c));
		f14.close();

	}
	/*Description:
	This function is used to delete the details of a customer
	Function Id:Delete_Customer
	Parameters:An object of type cutomer, an integer denoting the customer ID, a string denoting the name of customer
	return type: void
	*/
	void Delete_Customer(Customer &c,char customer_del[M],int cid){
		fstream f15("Customer.dat",ios::out|ios::in|ios::binary);
		fstream f16("Temp.dat",ios::out|ios::binary);
		while(f15.read((char*)&c,sizeof(c))){
			if((strcmp(customer_del,c.name4))&&cid!=c.CustomerID){
				f16.write((char*)&c,sizeof(c));
			}
			else if((!(strcmp(customer_del,c.name4))&&cid!=c.CustomerID)||(strcmp(customer_del,c.name4))&&cid==c.CustomerID){
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(35,2);
				cerr<<"Name and Customer ID didin't match \nTry entering appropriate Name and Number";
			}
			else{
				Customer c1;
				f16.write((char*)&c1,sizeof(c1));
			}
		}
		f16.close();
		f15.close();
		char filename4[51]="Customer.dat";
		remove(filename4);
		rename("Temp.dat","Customer.dat");
	}
	/*Description:
	This function is used to display the details of a customer
	Function Id:Display_Customer
	Parameters:An object of type cutomer, an integer denoting the customer ID
	return type: void
	*/
	void Display_Customer(Customer &c, int &cusID){
		fstream f17("Customer.dat",ios::in|ios::out|ios::binary);
		c.CustomerID=cusID;
		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(40,2);
		cout<<"Customer Details: \n";
		f17.seekg(long((cusID-1)*sizeof(Customer)),ios::beg);
		f17.read((char*)&c,sizeof(c));
		gotoxy(40,3);
		cout<<"Name: \n";
		gotoxy(40,4);
		puts(c.name4);
		gotoxy(40,5);
		cout<<"Customer ID: ";
		gotoxy(40,6);
		cout<<c.CustomerID;
		cout<<"Date of Last Purchase: ";
		gotoxy(40,7);
		puts(c.date3);
		gotoxy(40,8);
		cout<<"Contact number: ";
		gotoxy(40,9);
		puts(c.contact2);
		gotoxy(40,10);
		cout<<"E-Mail ID: ";
		gotoxy(40,11);
		puts(c.e_mail_ID);
		gotoxy(40,12);
		cout<<"Premium Subscriber: ";
		gotoxy(40,13);
		cout<<c.Premium_Subs;

		f17.close();
	}
	/*Description:
	This function is used to add the details of pending delivery
	Function Id:Add_DeliveryDetails
	Parameters:An object of type Delivery,an integer denoting delivery number
	return type:void
	*/
	void Add_DeliveryDetails(Delivery d,int dlno){
		fstream f18("Delivery.dat",ios::in|ios::out|ios::binary);
		f18.seekp(long((dlno-1)*sizeof(Delivery)),ios::beg);
		f18.write((char*)&d,sizeof(Delivery));
		f18.close();
	}
	/*Description:
	This function is used to delete the details of delivery orders
	Function Id:Delete_DeliveryDetails
	Parameters:An object of type Delivery, an integer denoting the order ID, a string denoting the name of customer
	return type: void
	*/
	void Delete_DeliveryDetails(Delivery &d,int dlno,char cname[M]){
		fstream f19("Delivery.dat",ios::in|ios::out|ios::binary);
		fstream f20("Temp.dat",ios::out|ios::binary);
		while(f19.read((char*)&d,sizeof(Delivery))){
			if((strcmp(cname,d.name5))&&dlno!=d.Orderno){
				f20.write((char*)&d,sizeof(d));
			}
			else if((!(strcmp(cname,d.name5))&&dlno!=d.Orderno)||(strcmp(cname,d.name5))&&dlno==d.Orderno)
			cerr<<"Name and Order Number didin't match \nTry entering appropriate Name and Number";
			else{
				Delivery d1;
				f20.write((char*)&d1,sizeof(d1));
			}
		}
		f20.close();
		f19.close();
		char filename4[51]="Delivery.dat";
		remove(filename4);
		rename("Temp.dat",filename4);

	}
	/*Description:
	This function is used to display the details of a Delivery
	Function Id:Display_Customer
	Parameters:An object of type Delivery, an integer denoting the order number
	return type: void
	*/
	void Display_Delivery(Delivery &d,int dlno){
		fstream f21("Delivery.dat",ios::in|ios::out|ios::binary);
		d.Orderno=dlno;
		f21.seekg(long((dlno-1)*sizeof(Delivery)),ios::beg);
		f21.read((char*)&d,sizeof(Delivery));
		system("cls");
		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(40,2);
		cout<<"Delivery Details: ";
		gotoxy(40,3);
		cout<<"Name: "<<d.name5;
		gotoxy(40,4);
		cout<<"Order Number: ";
		gotoxy(40,5);
		cout<<d.Orderno;
		cout<<"Customer ID ";
		gotoxy(40,6);
		cout<<d.CustID;
		cout<<"Address: ";
		gotoxy(40,7);
		cout<<d.Address;
		gotoxy(40,8);
		cout<<"Deadline: ";
		gotoxy(40,9);
		cout<<d.Deadline;
		gotoxy(40,10);
		cout<<"Contact Number: ";
		gotoxy(40,11);
		cout<<d.contact3;
		f21.close();
	}
	/*Description:
	This function is used to input the name and quantity of product to be billed and return the total amount after billing
	Function Id:Supermarket_Billing
	Parameters:No Parameter
	return type: double
	*/
	double Supermarket_Billing(){
		Billing b;
		int chc1=0,chc2=0,chc3=0,chc4;
		Edible_Products e;
		Non_Edible_Product n1;
		cout<<"Does the buyer have an account in the market: (Enter 0 for no user id for yes) ";
		cin>>chc4;

		Customer cb;
		do {
			chc1=chc2=0;
			cin.get();
			system("cls");
			gotoxy(50,1);
			cout<<"SUPERMARKET";
			cout<<"\nEnter the name of the product: ";
			cin.getline(b.name6,M);
			cout<<"Enter the quantity to be purchased ";
			cin>>b.quan;
			fstream f22("Edible_Products1.dat",ios::in|ios::out|ios::binary);
			while(chc1==0&&!f22.eof()){
				f22.read((char*)&e,sizeof(e));
				if(strcmp(e.name1,b.name6)==0)
				chc1=1;
			}
			if(chc1==1){
				if(chc4>0){
					char check[M];
					cin.get();
					cout<<"Enter the Name of the customer\n(Make sure you enter the case of alphabets appropriately): \n";
					cin.getline(check,M);
					fstream f27("Customer.dat",ios::in|ios::out|ios::binary);
					f27.seekg(long((chc4-1)*sizeof(cb)),ios::beg);
					f27.read((char*)&cb,sizeof(cb));
					if(strcmp(cb.name4,check)==0){
						if(cb.Premium_Subs=='Y')
						b.rate3=(85*e.rate1)/100;
						else
						b.rate3=(95*e.rate1)/100;
						cin.get();
						char d[11];
						cout<<"Enter Today's date in (DD/MM/YYYY) Format ";
						cin.getline(d,11);
						strcpy(cb.date3,d);
						f27.seekp(long((chc4-1)*sizeof(cb)),ios::beg);
						f27.write((char*)&cb,sizeof(cb));
					}
					f27.close();
				}
				else
				b.rate3=e.rate1;
				Delete_Edible_Products(e,e.name1,b.quan,e.pID1);
				f22.close();
			}

			else if(chc1==0){
				fstream f24("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
				while(chc2==0&&!f24.eof()){
					f24.read((char*)&n1,sizeof(n1));
					if(strcmp(n1.name2,b.name6)==0)
					chc2=1;
				}
				if(chc2==1){
					if(chc4>0){
					char check[M];
					cin.get();
					cout<<"Enter the Name of the customer\n(Make sure you enter the case of alphabets appropriately) \n";
					cin.getline(check,M);
					fstream f28("Customer.dat",ios::in|ios::out|ios::binary);
					f28.seekg(long((chc4-1)*sizeof(cb)),ios::beg);
					f28.read((char*)&cb,sizeof(cb));
					if(strcmp(cb.name4,check)==0){
						if(cb.Premium_Subs=='Y')
						b.rate3=(85*n1.rate2)/100;
						else
						b.rate3=(95*n1.rate2)/100;
						cin.get();
						char d[11];
						cout<<"Enter Today's date in (DD/MM/YYYY) Format ";
						cin.getline(d,11);
						strcpy(cb.date3,d);
						f28.seekp(long((chc4-1)*sizeof(cb)),ios::beg);
						f28.write((char*)&cb,sizeof(cb));
					}
					f28.close();
				}
				else
				b.rate3=n1.rate2;
				Delete_NonEdible_Products(n1,n1.name2,b.quan,n1.pID2);
				}
				f24.close();
			}

			b.amt+=b.rate3*b.quan;
			system("cls");
			gotoxy(50,1);
			cout<<"SUPERMARKET";
			cout<<"\nDo you want to continue purchasing? \n(Enter 0 for no and 1 for yes): ";
			cin>>chc3;

		}
		while(chc3==1);
		cout<<"The bill has been generated\nRs."<<b.amt<<" is to be paid\n";
		return b.amt;
	}
	/*Description:
	This function is used to check whether any edible product is deficient
	Function Id:checkQuane
	Parameters:an object of type Edible_Products
	return type: void
	*/
	void checkQuane(Edible_Products &e){
		if(e.Quantity1<10&&e.dtoe>10){
			gotoxy(35,5);
			cout<<e.name1<<" is set to get over in the market";
			gotoxy(40,6);
			cout<<"You have only "<<e.Quantity1<<" units";
		}
	}
	/*Description:
	This function is used to check whether any non edible product is deficient
	Function Id:checkQuanne
	Parameters:an object of type Non_Edible_Product
	return type: void
	*/
	void checkQuanne(Non_Edible_Product &ne){
		if(ne.Quantity2<10&&ne.Quantity2>0){
			gotoxy(40,3);
			cout<<ne.name2<<" is set to get over";
		}
	}

};

int main(){
	int c1,c2;
	user user1;
	user user2;
	gotoxy(50,1);
	cout<<"WELCOME TO SUPERMARKET!!";
	gotoxy(50,3);
	cout<<"Press any key to continue\n";
	getch();
	system("cls");
	fstream f12("User1.dat",ios::in|ios::out|ios::binary);
	gotoxy(50,1);
	cout<<"SUPERMARKET";
	gotoxy(40,3);
	cout<<"Enter 1 to create an account";
	gotoxy(40,4);
	cout<<"Enter 2 to login";
	gotoxy(40,5);
	cout<<"Enter 3 to close the application\n";
	gotoxy(40,7);
	cin>>c1;
	while(c1==1||c1==2){
		system("cls");
		if(1==c1){
			cin.get();
			gotoxy(50,1);
			cout<<"SUPERMARKET";
			gotoxy(40,3);
			cout<<"Enter your username ";
			gotoxy(40,4);
			cin.getline(user1.username,M);
			gotoxy(40,5);
			cout<<"Enter your usertype ";
			gotoxy(40,6);
			cin.get(user1.usertype);
			gotoxy(40,7);
			cin.get();
			gotoxy(40,8);
			cout<<"Enter your DOB ";
			gotoxy(40,9);
			cin.getline(user1.DOB,P);
			gotoxy(40,10);
			cout<<"Enter your date of joining ";
			gotoxy(40,11);
			cin.getline(user1.DOJ,P);
			gotoxy(40,12);
			cout<<"Enter your contact no. ";
			gotoxy(40,13);
			cin.getline(user1.contact3,11);
			cin.get();
			char p;
			gotoxy(40,14);
			cout<<"Enter your password ";
			gotoxy(40,15);
			p=getch();
			if(p!='\b'&&p!='\r')
			cout<<".";
			while(p=='\b'||p=='\r'){
				p=getch();
				if(p!='\b'&&p!='\r')
				cout<<".";
			}
			int co=0;
			while(p!='\r'&&co<M){
				if((p>='a'&&p<='z')||(p>='A'&&p<='Z')||(p>='0'&&p<='9'))
				user1.password[co]=p;

				co++;
				p=getch();
				if(p!='\b'||co<=0)
				cout<<".";
				if(p=='\b'&&co>0)
        		{
        		    cout<<"\b \b";
        		    co-=2;
        		}
				if(p=='\b'&&co==0)
				co=0;

			}
			user1.password[co]='\0';
			gotoxy(40,17);
			cout<<"Enter your User ID (Should be > 0)";
			gotoxy(40,18);
			cin>>user1.userID;
			f12.seekp(long((user1.userID-1)*sizeof(user)),ios::beg);
			f12.write((char*)&user1,sizeof(user1));

		}
		else if(2==c1){
			char psswrd1[M];
			int uID1;
			gotoxy(50,1);
			cout<<"SUPERMARKET";
			gotoxy(40,2);
			cout<<"Enter your user ID: ";
			gotoxy(40,3);
			cin>>uID1;
			cin.get();
			gotoxy(40,4);
			cout<<"Enter your password: "<<endl;
			char p2;
			gotoxy(40,5);
			p2=getch();
			if(p2!='\b'&&p2!='\r')
			cout<<".";
			while(p2=='\b'||p2=='\r'){
	 			p2=getch();
				if(p2!='\b'&&p2!='\r')
				cout<<".";
			}
			int co2=0;
			while(p2!='\r'&&co2<M){
				if((p2>='a'&&p2<='z')||(p2>='A'&&p2<='Z')||(p2>='0'&&p2<='9'))
					psswrd1[co2]=p2;

				co2++;
				p2=getch();
				if(p2!='\b')
				cout<<".";
				if(co2==0)
				if(p2!='\b')
					cout<<".";
				if(p2=='\b'&&co2>0)
        		{
        		    cout<<"\b \b";
        		    co2-=2;
        		}


			}
			psswrd1[co2]='\0';
			f12.seekg(long((uID1-1)*sizeof(user)),ios::beg);
			f12.read((char*)&user2,sizeof(user));
			if(!(strcmp(psswrd1,user2.password))&&uID1==user2.userID){
				system("cls");
				int ch;
				Edible_Products ex;
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(40,2);
				fstream f13s("Edible_products1.dat",ios::in|ios::out|ios::binary);
				while(f13s.read((char*)&ex,sizeof(ex))){
					user2.Check_Expiry(ex);
				}
				f13s.close();
				gotoxy(40,7);
				cout<<"Press Enter to continue ";
				getch();
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(40,3);
				fstream f26s("Edible_products1.dat",ios::in|ios::out|ios::binary);
				while(f26s.read((char*)&ex,sizeof(ex))){
					user2.checkQuane(ex);
				}
				f26s.close();
				gotoxy(40,7);
				cout<<"Press Enter to continue ";
				getch();
				system("cls");
				Non_Edible_Product nx;
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				fstream f27s("Non_Edible_Products.dat",ios::in|ios::out|ios::binary);
				while(f27s.read((char*)&ex,sizeof(ex))){
					user2.checkQuanne(nx);
				}
				f27s.close();
				gotoxy(40,7);
				cout<<"Press Enter to continue ";
				getch();
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(40,3);
				cout<<"Fund found in the market:"<<user2.fund<<'\n';
				getch();
				system("cls");
				gotoxy(50,1);
				cout<<"SUPERMARKET";
				gotoxy(40,3);
				cout<<"Enter 1 to add edible product details ";
				gotoxy(40,4);
				cout<<"Enter 2 to delete edible product details ";
				gotoxy(40,5);
				cout<<"Enter 3 to view the details of edible products ";
				gotoxy(40,6);
				cout<<"Enter 4 to add  non-edible product details ";
				gotoxy(40,7);
				cout<<"Enter 5 to delete non-edible product details ";
				gotoxy(40,8);
				cout<<"Enter 6 to view the details of non-edible products ";
				gotoxy(40,9);
				cout<<"Enter 7 to add details of a product supplier ";
				gotoxy(40,10);
				cout<<"Enter 8 to delete details of a product supplier ";
				gotoxy(40,11);
				cout<<"Enter 9 to display the details of product supplier ";
				gotoxy(40,12);
				cout<<"Enter 10 to increase quantity of edible product ";
				gotoxy(40,13);
				cout<<"Enter 11 to increase quantity of Non-edible product ";
				gotoxy(40,14);
				cout<<"Enter 12 to add Customer Details ";
				gotoxy(40,15);
				cout<<"Enter 13 to delete Customer Details ";
				gotoxy(40,16);
				cout<<"Enter 14 to display customer details ";
				gotoxy(40,17);
				cout<<"Enter 15 to add Delivery order ";
				gotoxy(40,18);
				cout<<"Enter 16 to delete delivery order ";
				gotoxy(40,19);
				cout<<"Enter 17 to display delivery orders ";
				gotoxy(40,20);
				cout<<"Enter 18 to bill the products ";
				gotoxy(40,21);
				cout<<"Enter 19 to sign out ";
				gotoxy(40,22);
				cin>>ch;
				while(ch>0&&ch<19){
					system("cls");
					if(ch==1){
						Edible_Products e1;
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,3);
						cout<<"Enter the name of the product: ";
						gotoxy(40,4);
						cin.getline(e1.name1,P);
						gotoxy(40,5);
						cout<<"Enter the quantity to be added: ";
						gotoxy(40,6);
						cin>>e1.Quantity1;
						cin.get();
						gotoxy(40,7);
						cout<<"Enter the batch no.: ";
						gotoxy(40,8);
						cin.getline(e1.batch_no,M);
						gotoxy(40,9);
						cout<<"Enter the rate of the product: ";
						gotoxy(40,10);
						cin>>e1.rate1;
						gotoxy(40,11);
						cout<<"Enter the product ID: ";
						gotoxy(40,12);
						cin>>e1.pID1;
						gotoxy(40,13);
						cout<<"Enter the number of days remaining for the product to expire: ";
						gotoxy(40,14);
						cin>>e1.dtoe;
						cin.get();
						gotoxy(40,15);
						cout<<"Enter the manufacturing date: "<<endl;
						gotoxy(40,16);
						cin.getline(e1.dateofMan1,P);
						gotoxy(40,17);
						cout<<"Enter the date of expiry: "<<endl;
						gotoxy(40,18);
						cin.getline(e1.dateofExpiry,P);
						gotoxy(40,19);
						cout<<"Enter the category to which the product belongs to: "<<endl;
						gotoxy(40,20);
						cin.getline(e1.category,M);

						user2.Add_Edible_Product_Details(e1,e1.pID1);
					}
					else if(ch==2){
						Edible_Products e2;
						char prod_del[M];
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,3);
						cout<<"Enter the name of product you want to delete (Case Sensitive): ";
						gotoxy(40,4);
						cin.getline(prod_del,21);
						int quan1,pdno1;
						gotoxy(40,5);
						cout<<"Enter the product ID: ";
						gotoxy(40,6);
						cin>>pdno1;
						gotoxy(40,7);
						cout<<"Enter the quantity of the product you want to remove: ";
						gotoxy(40,8);
						cin>>quan1;
						cin.get();
						user2.Delete_Edible_Products(e2,prod_del,quan1,pdno1);
						getch();
					}
					else if(ch==3){
						Edible_Products e3;
						int pd1;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the ID of the product: ";
						gotoxy(40,3);
						cin>>pd1;
						cin.get();
						user2.displayEdible(e3,pd1);
						gotoxy(40,22);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==4){
						Non_Edible_Product ne1;
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the name of the product: ";
						gotoxy(40,3);
						cin.getline(ne1.name2,M);
						gotoxy(40,4);
						cout<<"Enter the quantity: ";
						gotoxy(40,5);
						cin>>ne1.Quantity2;
						cin.get();
						gotoxy(40,6);
						cout<<"Enter the Mfg. Date: ";
						gotoxy(40,7);
						cin.getline(ne1.dateofMan2,P);
						gotoxy(40,8);
						cout<<"Enter the rate of the product: ";
						gotoxy(40,9);
						cin>>ne1.rate2;
						gotoxy(40,10);
						cout<<"Enter the product ID: ";
						gotoxy(40,11);
						cin>>ne1.pID2;
						cin.get();
						gotoxy(40,12);
						cout<<"Enter the category: ";
						gotoxy(40,13);
						cin.getline(ne1.category,M);

						user2.Add_NonEdible_Product_Details(ne1,ne1.pID2);
					}

					else if(ch==5){
						Non_Edible_Product ne2;
						char prod_del[21];
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the name of product you want to delete (Case sensitive): ";
						gotoxy(40,3);
						cin.getline(prod_del,21);
						int nquan,npid;
						gotoxy(40,5);
						cout<<"Enter the quantity the product you want to remove ";
						gotoxy(40,6);
						cin>>nquan;
						gotoxy(40,7);
						cout<<"Enter the product ID";
						gotoxy(40,8);
						cin>>npid;
						cin.get();
						user2.Delete_NonEdible_Products(ne2,prod_del,nquan,npid);
						gotoxy(40,9);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==6){
						Non_Edible_Product ne3;
						int pd2;
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the product ID: ";
						cin>>pd2;
						cin.get();
						user2.displayNonEdible(ne3,pd2);
						gotoxy(40,16);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==7){
						Product_Supplier p1;
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the name of supplier: ";
						gotoxy(40,3);
						cin.getline(p1.name3,M);
						gotoxy(40,4);
						cout<<"Enter the name of product(s): ";
						gotoxy(40,5);
						cin.getline(p1.Product_name,L);
						gotoxy(40,6);
						cout<<"Enter the contact no.:";
						gotoxy(40,7);
						cin.getline(p1.contact1,11);
						gotoxy(40,8);
						cout<<"Enter the supplier ID: ";
						gotoxy(40,9);
						cin>>p1.sID;
						gotoxy(40,10);
						cout<<"Enter the Quantity";
						gotoxy(40,11);
						cin>>p1.Quantity3;

						user2.Add_ProductSupplier(p1,p1.sID);

					}
					else if(ch==8){
						Product_Supplier p2;
						char Sup_del[M];
						int psID;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the supplier ID: ";
						gotoxy(40,3);
						cin>>psID;
						cin.get();
						gotoxy(40,5);
						cout<<"Enter the name to be deleted: ";
						gotoxy(40,6);
						cin.getline(Sup_del,M);
						user2.Delete_ProductSupplier(p2,Sup_del,psID);
						gotoxy(40,7);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==9){
						Product_Supplier p3;
						int supID1;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the supplier ID: ";
						gotoxy(40,3);
						cin>>supID1;
						system("cls");
						user2.DisplayProductSupplier(p3,supID1);
						gotoxy(40,13);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==10){
						Edible_Products e4;
						int pid,q1,dtoe2;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the product ID ";
						gotoxy(40,3);
						cin>>pid;
						gotoxy(40,4);
						cout<<"Enter the quantity to be added: ";
						gotoxy(40,5);
						cin>>q1;
						gotoxy(40,6);
						cout<<"Enter the number of days left for the product to expire: ";
						gotoxy(40,7);
						cin>>dtoe2;
						cin.get();
						char dc1[11],dc2[11];
						gotoxy(40,9);
						cout<<"Enter the new manufacturing date: ";
						gotoxy(40,10);
						cin.getline(dc1,11);
						gotoxy(40,11);;
						cout<<"Enter the new expiry date: ";
						gotoxy(40,12);
						cin.getline(dc2,11);
						user2.Alter_Edible_Quantity(e4,pid,q1,dtoe2,dc1,dc2);
						fstream f25("User1.dat",ios::in|ios::out|ios::binary);
						f25.seekp(long((user2.userID-1)*sizeof(user)),ios::beg);
						f25.write((char*)&user2,sizeof(user));
						f25.close();
					}
					else if(ch==11){
						Non_Edible_Product ne4;
						int pid2,q2;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the product ID \n";
						gotoxy(40,3);
						cin>>pid2;
						gotoxy(40,4);
						cout<<"Enter the quantity to be added: ";
						gotoxy(40,5);
						cin>>q2;
						cin.get();
						char dc1[11];
						gotoxy(40,6);
						cout<<"Enter the new manufacturing date: ";
						gotoxy(40,7);
						cin.getline(dc1,11);
						user2.Alter_NonEdible_Quantity(ne4,pid2,q2,dc1);
						fstream f26("User1.dat",ios::in|ios::out|ios::binary);
						f26.seekp(long((user2.userID-1)*sizeof(user)),ios::beg);
						f26.write((char*)&user2,sizeof(user));
						f26.close();
					}
					else if(ch==12){
						Customer c1;
						cin.get();
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the name of customer: ";
						gotoxy(40,3);
						cin.getline(c1.name4,M);
						gotoxy(40,4);
						cout<<"Enter the address of the customer: ";
						gotoxy(40,5);
						cin.getline(c1.address,L);
						gotoxy(40,6);
						cout<<"Enter the date of previous purchase: (Enter it in DD/MM/YYYY format)\n";
						gotoxy(40,7);
						cin.getline(c1.date3,P);
						gotoxy(40,8);
						cout<<"Enter the customer ID: ";
						gotoxy(40,9);
						cin>>c1.CustomerID;
						cin.get();
						gotoxy(40,10);
						cout<<"Enter the contact number: ";
						gotoxy(40,11);
						cin.getline(c1.contact2,11);
						gotoxy(40,12);
						cout<<"Enter the e-mail ID ofthe customer: ";
						gotoxy(40,13);
						cin.getline(c1.e_mail_ID,L);
						gotoxy(40,14);
						cout<<"Enter whether has premium subscription: ";
						gotoxy(40,15);
						cin>>c1.Premium_Subs;
						user2.Add_Customer(c1,c1.CustomerID);
					}
					else if(ch==13){
						Customer c2;
						char cus_del[M];
						int cd;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the Customer ID: ";
						gotoxy(40,3);
						cin>>cd;
						cin.get();
						gotoxy(40,4);
						cout<<"Enter the name of the customer: ";
						gotoxy(40,5);
						cin.getline(cus_del,M);
						user2.Delete_Customer(c2,cus_del,cd);
					}

					else if(ch==14){
						Customer c3;
						int cd;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the Customer ID: ";
						gotoxy(40,3);
						cin>>cd;
						system("cls");
						user2.Display_Customer(c3,cd);
						gotoxy(40,16);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==15){
						Delivery d1;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the order number: ";
						gotoxy(40,3);
						cin>>d1.Orderno;
						cin.get();
						gotoxy(40,4);
						cout<<"Enter the name of the customer: ";
						gotoxy(40,5);
						cin.getline(d1.name5,M);
						gotoxy(40,6);
						cout<<"Enter the address of the customer: \n";
						gotoxy(40,7);
						cin.getline(d1.Address,L);
						gotoxy(40,8);
						cout<<"Enter the Customer ID: ";
						cin>>d1.CustID;
						cin.get();
						gotoxy(40,9);
						cout<<"Enter the products to be delivered: ";
						gotoxy(40,10);
						cin.getline(d1.products,L);
						gotoxy(40,11);
						cout<<"Enter the deadline: ";
						gotoxy(40,12);
						cin.getline(d1.Deadline,P);
						gotoxy(40,13);
						cout<<"Enter the contact Number of the Customer: ";
						gotoxy(40,14);
						cin.getline(d1.contact3,11);
						user2.Add_DeliveryDetails(d1,d1.Orderno);
					}
					else if(ch==16){
						Delivery d2;
						char ddel[M];
						int ono;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the order Number: ";
						gotoxy(40,3);
						cin>>ono;
						cin.get();
						gotoxy(40,4);
						cout<<"Enter the name of the customer: ";
						gotoxy(40,5);
						cin.getline(ddel,M);
						user2.Delete_DeliveryDetails(d2,ono,ddel);
					}
					else if(ch==17){
						Delivery d3;
						int ono;
						gotoxy(50,1);
						cout<<"SUPERMARKET";
						gotoxy(40,2);
						cout<<"Enter the Order Number: ";
						gotoxy(40,3);
						cin>>ono;
						system("cls");
						user2.Display_Delivery(d3,ono);
						gotoxy(40,12);
						cout<<"Press any key to continue ";
						getch();
					}
					else if(ch==18){
						user2.fund+=(user2.Supermarket_Billing());
						fstream f23("User1.dat",ios::in|ios::out|ios::binary);
						f23.seekp(long((user2.userID-1)*sizeof(user)),ios::beg);
						f23.write((char*)&user2,sizeof(user2));
						f23.close();
						cout<<"Press any key to continue ";
						getch();
					}

					system("cls");
						gotoxy(50,1);
					cout<<"SUPERMARKET";
					gotoxy(40,3);
					cout<<"Enter 1 to add edible product details ";
					gotoxy(40,4);
					cout<<"Enter 2 to delete edible product details ";
					gotoxy(40,5);
					cout<<"Enter 3 to view the details of edible products ";
					gotoxy(40,6);
					cout<<"Enter 4 to add  non-edible product details ";
					gotoxy(40,7);
					cout<<"Enter 5 to delete non-edible product details ";
					gotoxy(40,8);
					cout<<"Enter 6 to view the details of non-edible products ";
					gotoxy(40,9);
					cout<<"Enter 7 to add details of a product supplier ";
					gotoxy(40,10);
					cout<<"Enter 8 to delete details of a product supplier ";
					gotoxy(40,11);
					cout<<"Enter 9 to display the details of product supplier ";
					gotoxy(40,12);
					cout<<"Enter 10 to increase quantity of edible product ";
					gotoxy(40,13);
					cout<<"Enter 11 to increase quantity of Non-edible product ";
					gotoxy(40,14);
					cout<<"Enter 12 to add Customer Details ";
					gotoxy(40,15);
					cout<<"Enter 13 to delete Customer Details ";
					gotoxy(40,16);
					cout<<"Enter 14 to display customer details ";
					gotoxy(40,17);
					cout<<"Enter 15 to add Delivery order ";
					gotoxy(40,18);
					cout<<"Enter 16 to delete delivery order ";
					gotoxy(40,19);
					cout<<"Enter 17 to display delivery orders ";
					gotoxy(40,20);
					cout<<"Enter 18 to bill the products ";
					gotoxy(40,21);
					cout<<"Enter 19 to sign out ";
					gotoxy(40,22);
					cin>>ch;
				}

			}

		}
		system("cls");
		gotoxy(50,1);
		cout<<"SUPERMARKET";
		gotoxy(40,3);
		cout<<"Enter 1 to create an account";
		gotoxy(40,4);
		cout<<"Enter 2 to login";
		gotoxy(40,5);
		cout<<"Enter 3 to close the application\n";
		gotoxy(40,7);
		cin>>c1;
		}
	system("cls");
	f12.close();
}
/*
Done by:
B.Dinesh
XII 'A'
Roll No. 07
*/

