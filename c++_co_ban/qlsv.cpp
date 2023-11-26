#include<iostream>
#include <string>
using namespace std;

class Sinhvien {
public:
	string name;
	int age;
	int score;
	Sinhvien (string _name,int _age, int _score) {
		name = _name;
		age = _age;
		score = _score;

	}
	void displayInfo() {
		cout << "Ten: "<<name<< endl;
		cout << "Tuoi: " << age << endl;
		cout << "Diem so: " << score << endl;
		
	}
};

int main(){

	Sinhvien sv1("Anh", 25, 10);
	
	sv1.displayInfo();
	return 0;

}
// done