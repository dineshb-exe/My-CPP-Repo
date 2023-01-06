#include<iostream>
using namespace std;
class date{
	int d;
	int m;
	int y;
	public:
		date(){
			d=1;
			m=1;
			y=1900;
		}
		void read(){
			cout<<"Enter the day: ";
			cin>>d;
			cout<<"Enter the month: ";
			cin>>m;
			cout<<"Enter the year: ";
			cin>>y;
		}
		int operator <(date const &d1){
			cout<<"Date 1: "<<d<<"/"<<m<<"/"<<y<<endl;
			cout<<"Date 2: "<<d1.d<<"/"<<d1.m<<"/"<<d1.y<<endl;
			if(y<d1.y){
				return 1;
			}
			else if(y>d1.y){
				return 0;
			}
			else{
				if(m<d1.m){
					return 1;
				}
				else if(m>d1.m){
					return 0;
				}
				else{
					if(d<d1.d){
						return 1;
					}
					else{
						return 0;
					}
				}
			}
		}

};
int main(){
	date da;
	date db;
	da.read();
	db.read();
	if(da<db){
		cout<<"Date 1 falls earlier!!!";
	}
	else
	cout<<"Date 2 falls earlier!!!";
}

