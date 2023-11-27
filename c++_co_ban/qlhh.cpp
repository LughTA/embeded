#include<iostream>
#include <string>
using namespace std;

class Shape {
public:
	
	virtual float calculateArea() = 0;
	virtual float calculatePerimeter() = 0;
};


class Circle :public Shape {
public:
	int radius;
	float calculateArea() {
		return  3.14 * radius * radius;
	}
	float calculatePerimeter(){
		return 3.14 * 2 * radius;
	}

};
class Rectangle :public Shape {
public:
	int length;
	int width;
	float calculateArea() {
		return  length * width;
	}
	float calculatePerimeter() {
		return 2 * (length + width);
	}

};

int main() {

	Circle ht;
	Rectangle hcn;

	ht.radius = 30;
	hcn.width = 5;
	hcn.length = 20;
	

	cout << "dien tich hinh tron: " << ht.calculateArea() << endl;
	cout << "chu vi hinh tron: " << ht.calculatePerimeter() << endl;
	cout << "Dien tich hinh chu nhat: " << hcn.calculateArea() << endl;
	cout << "chu vi hinh chu nhat: " << hcn.calculatePerimeter() << endl;

	return 0;

}//done