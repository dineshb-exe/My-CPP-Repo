#include<iostream>
#include<string>
using namespace std;

class vehicle{
protected:
    float mileage;
    int price;
};
class Car: public vehicle{
protected:
    int ownership_cost;
    float warranty;
    int sc;
    string fuel_type;
};
class Bike: public vehicle{
protected:
    int cylinders;
    int gears;
    string cooling;
    string wheel;
    int ft_size;

};


class Ford: public Car{
    string model_type;
public:
    void read(){
        cout<<"Enter the model type: ";
        cin>>model_type;
        cout<<"Enter the ownership cost: ";
        cin>>ownership_cost;
        cout<<"Enter the warranty period (in years): ";
        cin>>warranty;
        cout<<"Enter the seating capacity: ";
        cin>>sc;
        cout<<"Enter the fuel type: ";
        cin>>fuel_type;
        cout<<"Enter the mileage of the car: ";
        cin>>mileage;
        cout<<"Enter the price of the car: ";
        cin>>price;
    }
    void display(){
        cout<<"Model Type: "<<model_type<<endl;
        cout<<"Ownership Cost: "<<ownership_cost<<endl;
        cout<<"Warranty: "<<warranty<<endl;
        cout<<"Seating Capacity: "<<sc<<endl;
        cout<<"Fuel Type: "<<fuel_type<<endl;
        cout<<"Mileage: "<<mileage<<endl;
        cout<<"Price of the car: "<<price<<endl;
    }
};

class Audi: public Car{
    string model_type;
public:
    void read(){
        cout<<"Enter the model type: ";
        cin>>model_type;
        cout<<"Enter the ownership cost: ";
        cin>>ownership_cost;
        cout<<"Enter the warranty period (in years): ";
        cin>>warranty;
        cout<<"Enter the seating capacity: ";
        cin>>sc;
        cout<<"Enter the fuel type: ";
        cin>>fuel_type;
        cout<<"Enter the mileage of the car: ";
        cin>>mileage;
        cout<<"Enter the price of the car: ";
        cin>>price;
    }
    void display(){
        cout<<"Model Type: "<<model_type<<endl;
        cout<<"Ownership Cost: "<<ownership_cost<<endl;
        cout<<"Warranty: "<<warranty<<endl;
        cout<<"Seating Capacity: "<<sc<<endl;
        cout<<"Fuel Type: "<<fuel_type<<endl;
        cout<<"Mileage: "<<mileage<<endl;
        cout<<"Price of the car: "<<price<<endl;
    }
};
class Bajaj: public Bike{
    string make_type;
public:
    void read(){
        cout<<"Enter the make type: ";
        cin>>make_type;
        cout<<"Enter the cylinders: ";
        cin>>cylinders;
        cout<<"Enter the number of gears: ";
        cin>>gears;
        cout<<"Enter the cooling type: ";
        cin>>cooling;
        cout<<"Enter the wheel type: ";
        cin>>wheel;
        cout<<"Enter the fuel tank size (in inches): ";
        cin>>ft_size;
        cout<<"Enter the mileage of the bike: ";
        cin>>mileage;
        cout<<"Enter the price of the bike: ";
        cin>>price;
    }
    void display(){
        cout<<"Make Type: "<<make_type<<endl;
        cout<<"Cylinder: "<<cylinders<<endl;
        cout<<"Number of gears: "<<gears<<endl;
        cout<<"Cooling Type: "<<cooling<<endl;
        cout<<"Wheel Type: "<<wheel<<endl;
        cout<<"Fuel Tank (in inches): "<<ft_size<<endl;
        cout<<"Mileage: "<<mileage<<endl;
        cout<<"Price: "<<price<<endl;
    }
};
class TVS: public Bike{
    string make_type;
public:
    void read(){
        cout<<"Enter the make type: ";
        cin>>make_type;
        cout<<"Enter the cylinders: ";
        cin>>cylinders;
        cout<<"Enter the number of gears: ";
        cin>>gears;
        cout<<"Enter the cooling type: ";
        cin>>cooling;
        cout<<"Enter the wheel type: ";
        cin>>wheel;
        cout<<"Enter the fuel tank size (in inches): ";
        cin>>ft_size;
        cout<<"Enter the mileage of the bike: ";
        cin>>mileage;
        cout<<"Enter the price of the bike: ";
        cin>>price;
    }
    void display(){
        cout<<"Make Type: "<<make_type<<endl;
        cout<<"Cylinder: "<<cylinders<<endl;
        cout<<"Number of gears: "<<gears<<endl;
        cout<<"Cooling Type: "<<cooling<<endl;
        cout<<"Wheel Type: "<<wheel<<endl;
        cout<<"Fuel Tank (in inches): "<<ft_size<<endl;
        cout<<"Mileage: "<<mileage<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

int main(){
    Audi a4;
    Ford MustangGT400;
    Bajaj Pulsar;
    TVS Streak;
    a4.read();
    a4.display();
    MustangGT400.read();
    MustangGT400.display();
    Pulsar.read();
    Pulsar.display();
    Streak.read();
    Streak.display();
}
