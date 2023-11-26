#include<iostream>
#include <string>

using namespace std;

int choice;
//tao class bankaccount
class BankAccount {
protected:
	int accnumber;
	int balance;
	string ownername;
public:

	BankAccount (int acc, int bala, string name) {
		accnumber = acc;
		balance = bala;
		ownername = name;
	}
	void deposit(int amount) {
			balance = balance + amount;
			cout << "so du sau khi gui: " << balance << endl;
	}
	void withdraw(int amount) {
		if (balance <= 0) {
			cout << "tai khoang het tien roi";
		}
		else {
			balance = balance - amount;
			cout << "so du sau khi rut: " << balance << endl;
		}
	}
	void displayInfo() {
		cout << "Ten Tk: " << accnumber << endl;
		cout << "so du hien tai: " << balance << endl;
		cout << "chu so huu " << ownername << endl;

	}
};
//ham kiem tra nhap thong tin tu ban phim
void check() {
	while (1) {
		if (choice == 1 || choice == 2 || choice == 3|| choice==4 ) {
			break;
		}
		else {
			cout << "nhap sai moi nhap lai";
		}
		cin >> choice;
	}
}

int main() {

	BankAccount tk1(123,100000,"Tuan Anh");
	
	int number;
	
	while (choice!=4) {
		cout << "\n_______________________________________\n";
		cout << "xin moi chon viec ban muon lam\n";
		cout << "1 xem thong tin\n";
		cout << "2 rut tien\n";
		cout << "3 gui tien\n";
		cout << "4 exit\n";
		cin >> choice;
		
		check();
		
		switch (choice)
		{
		case 1:
			tk1.displayInfo();
			break;
		case 2:
			cout << "xin moi nhap so tien muon rut:";
			cin >> number;
			tk1.withdraw(number);
			break;
		case 3:
			cout << "xin moi nhap so tien muon gui:";
			cin >> number;
			tk1.deposit(number);
			break;
		case 4:
			cout << "bye bye chuc ban 1 ngay tot lanh ^^";
			break;
		default:
			break;

		}
	}
	return 0;

}//done
