#include <iostream>
using namespace std;

class GPU{
protected:
	int price; 
	int hashRate;
public:
	int getPrice(){
		return price;
	}
	int getHashRate(){
		return hashRate;
	}
	virtual double Calculate() = 0;
	friend istream& operator>>(istream& in, GPU& g);
};

istream& operator>>(istream& in, GPU& g){
	in >> g.price >> g.hashRate;
	return in;
}

class Card1 :public GPU{
	GPU::price;
	GPU::hashRate;
public:
	Card1(){}
	Card1(int m_price,int m_hashRate){
		price = m_price;
		hashRate = m_hashRate;
	}
	
	double Calculate(){
		return hashRate*0.02 - 16.2;
	}
};

class Card2 :public GPU{
	GPU::price;
	GPU::hashRate;
public:
	Card2(){}
	Card2(int m_price, int m_hashRate){
		price = m_price;
		hashRate = m_hashRate;
	}
	double Calculate(){
		return hashRate*0.02 - 28.8;
	}
};

class Card3 :public GPU{
	GPU::price;
	GPU::hashRate;
public:
	Card3(){}
	Card3(int m_price, int m_hashRate){
		price = m_price;
		hashRate = m_hashRate;
	}
	double Calculate(){
		return hashRate*0.02 - 19.44;
	}
};

int main(){
	Card1 card1;
	Card2 card2;
	Card3 card3;

	cin >> card1 >> card2 >> card3;
	double dailyIncome = card1.Calculate() + card2.Calculate() + card3.Calculate();
	if (dailyIncome <= 0){
		cout << -1;
		return 0;
	}
	double calDay = (card1.getPrice() + card2.getPrice() + card3.getPrice()) / dailyIncome;
	int day = 0;
	if (calDay != (int)calDay){
		day = calDay + 1;
	}
	else{
		day = calDay;
	}
	cout << day;
	//system("pause");
	return 0;
}