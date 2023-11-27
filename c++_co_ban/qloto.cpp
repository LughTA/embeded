#include<iostream>
#include <string>

using namespace std;

int choice;

class car {
protected:
	float speed;
	string color;
	int fuelCapacity;
public:

	car(float sp, string cl,int fc) {
		speed = sp;
		color = cl;
		fuelCapacity = fc;
	}
	void accelerate(int amount) {
		speed = speed + amount;
		cout << "Toc do sau khi tang: " << speed << "km/h" << endl;
	}
	void brake(int amount) {
		if (speed <= 0) {
			cout << "Xe dang dung im roi!!!";
		}
		else {
			speed = speed - amount;
			if (speed < 0) speed = 0;
			cout << "Toc do sau khi giam: " << speed << "km/h" << endl;
		}
	}
	void displayInfo() {
		cout << "Toc do xe: " << speed<<" km/h" << endl;
		cout << "Mau xe: " << color << endl;
		cout << "dung tich xang: " << fuelCapacity<< "lit" << endl;

	}
};
void check() {
	while (1) {
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
			break;
		}
		else {
			cout << "nhap sai moi nhap lai";
		}
		cin >> choice;
	}
}

int main() {

	car c1(60,"xanh", 20);

	int number;

	while (choice != 4) {
		cout << "\n_______________________________________\n";
		cout << "xin moi chon viec ban muon lam\n";
		cout << "1 xem thong tin xe\n";
		cout << "2 tang toc\n";
		cout << "3 giam toc\n";
		cout << "4 exit\n";
		cin >> choice;

		check();

		switch (choice)
		{
		case 1:
			c1.displayInfo();
			break;
		case 2:
			cout << "Tang toc xe them bao nhiu?:";
			cin >> number;
			c1.accelerate(number);
			break;
		case 3:
			cout << "Giam toc xe di bao nhiu?:";
			cin >> number;
			c1.brake(number);
			break;
		case 4:
			cout << "bye bye lai xe an toan nha ^^";
			break;
		default:
			break;

		}
	}
	return 0;

}//done