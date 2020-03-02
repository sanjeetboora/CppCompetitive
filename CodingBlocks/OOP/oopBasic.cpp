#include <iostream>
using namespace std;
class Car{
	int price;
public:
	//int wheels;
	const int wheels;
	char name[20];
	//default constructor
	// Car(){
	// 	cout<<"my Constructor"<<endl;
	// }

	//parameterized constructor
	// Car(int p, int w, char n[]){
	// 	cout<<"my parameterized Constructor"<<endl;
	// 	price = p;
	// 	wheels =w;
	// 	//name = n;
	// 	strcpy(name,n);
	// }
	//initialization list
	Car(int p, int w, char n[]): wheels(w){
		cout<<"my initialization list Constructor"<<endl;
		price = p;
		strcpy(name,n);
	}

	// Car(int p, int w, char n[]): wheels(w){
	// 	setPrice(p);
	// 	strcpy(name,n);
	// }

	// deep copy constructor
	Car(Car &c):wheels(c.wheels){
		price = c.price;
		strcpy(name,c.name);
	}
	int getPrice(){
		return price;
	}
	void setPrice(int p){
		if(p>100){
			price = p;
		}
	}



	void print(){
		cout<<"price : "<<price<<endl;
		cout<<"wheels : "<<wheels<<endl;
		cout<<"name : "<<name<<endl;
	}

};

int main(int argc, char const *argv[])
{
	// Car c;
	// c.price= 20;
	// c.wheels = 4;
	// c.name[0] ='a';
	// c.name[1] ='b';
	// c.name[2] ='c';
	// c.print();
	Car D(20, 4, "abc");
	Car E(D);
	D.name[0] = 'm';
	
	D.print();
	E.print();




	return 0;
}