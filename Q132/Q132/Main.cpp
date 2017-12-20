#include<iostream>
#include<vector>
using namespace std;
class Food{
public:
	double carbohydrate, protein, DF, fat;
	Food(double carbohydrate, double protein, double DF, double fat) 
		:carbohydrate(carbohydrate), protein(protein), DF(DF), fat(fat){}
};
class Rice :public Food{
public:
	Rice() :Food(16.2, 3.7, 0, 0){}
};
class Beef :public Food{
public:
	Beef() :Food(1.8, 17.5, 0, 7.2){}
};
class Bro :public Food{
public:
	Bro() :Food(0.2, 0.4, 3.6, 0){}
};
class Oat :public Food{
public:
	Oat() :Food(12.3, 5.7, 7.3, 3){}
};
class Duck :public Food{
public:
	Duck() :Food(6.9, 9, 0, 9.3){}
};
class Cab :public Food{
public:
	Cab() :Food(2.1, 0.8, 4.3, 0){}
};
class Diet{
public:
	vector<Food> list;
	Diet& operator+=(Food& food){
		list.push_back(food);
		return *this;
	}
	bool if_healthy(){
		return if_carbohydrateHealthy() && if_proteinHealthy() && if_DFHealthy() && if_fatHealthy();
	}
	bool if_carbohydrateHealthy(){
		double sum = 0;
		for (int i = 0; i < list.size(); i++){
			sum += list[i].carbohydrate;
		}
		if (sum >= 13.3){
			return true;
		}
		else{
			return false;
		}
	}
	bool if_proteinHealthy(){
		double sum = 0;
		for (int i = 0; i < list.size(); i++){
			sum += list[i].protein;
		}
		if (sum >= 13.5){
			return true;
		}
		else{
			return false;
		}
	}
	bool if_DFHealthy(){
		double sum = 0;
		for (int i = 0; i < list.size(); i++){
			sum += list[i].DF;
		}
		if (sum >= 3.3){
			return true;
		}
		else{
			return false;
		}
	}
	bool if_fatHealthy(){
		double sum = 0;
		for (int i = 0; i < list.size(); i++){
			sum += list[i].fat;
		}
		if (sum <= 10.3){
			return true;
		}
		else{
			return false;
		}
	}
};
Food* addFood(){
	int code;
	cin >> code;
	switch (code){
	case 1:
		return new Rice;
	case 2:
		return new Beef;
	case 3:
		return new Bro;
	case 4:
		return new Oat;
	case 5:
		return new Duck;
	case 6:
		return new Cab;
	default:
		return nullptr;
	}
}
int main(){
	Diet diet;
	for (int i = 0; i < 3; i++){
		Food* food = addFood();
		if (food == nullptr){
			cout << "-1";
			return 0;
		}
		diet += *food;
	}
	if (diet.if_healthy()){
		cout << "healthy";
	}
	else{
		cout << "unhealthy";
	}
	return 0;
}