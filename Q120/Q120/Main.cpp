#include<iostream>
using namespace std;
class Hamburger{
public:
	virtual int getPrice() = 0;
};
class Meat :public Hamburger{};
class Vegetable :public Hamburger{};
class Beaf :public Meat{
public:
	int getPrice() override{
		return 10;
	}
};
class Pork :public Meat{
public:
	int getPrice() override{
		return 8;
	}
};
class Chicken :public Meat{
public:
	int getPrice() override{
		return 7;
	}
};
class Lettuce :public Vegetable{
public:
	int getPrice() override{
		return 4;
	}
};
class Tomato:public Vegetable{
public:
	int getPrice() override{
		return 3;
	}
};
class Decorator{
private:
	Hamburger* hamburger;
public:
	Decorator(Hamburger* ham) :hamburger(ham){}
	virtual int getPrice(){
		return hamburger->getPrice();
	}
};
class HamburgerFood :public Decorator{
private:
	int num;
public:
	HamburgerFood(Hamburger* ham, int num) :Decorator(ham), num(num){}
	int getPrice() override{
		return num*Decorator::getPrice();
	}
};
class Choose{
public:
	static Meat* chooseMeat(int code){
		switch (code){
		case 1:
			return new Beaf;
		case 2:
			return new Pork;
		case 3:
			return new Chicken;
		}
	}
	static Vegetable* chooseVegetable(int code){
		switch (code){
		case 1:
			return new Lettuce;
		case 2:
			return new Tomato;
		}
	}
};
int main(){
	int meatCode, num1, vegetableCode, num2;
	cin >> meatCode >> num1 >> vegetableCode >> num2;
	//HamburgerFood test1(new Beaf, 1);
	//cout << test1.getPrice();
	HamburgerFood meat(Choose::chooseMeat(meatCode), num1);
	HamburgerFood vegetable(Choose::chooseVegetable(vegetableCode),num2);
	cout << meat.getPrice() + vegetable.getPrice();
}

