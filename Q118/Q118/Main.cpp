#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Hero{
public:
	string id;
	string name;
	int hp;
	int atk;
	virtual void power() =0;
	virtual void beAttacked(int enemyAtk){
		this->hp -= enemyAtk;
	}
	Hero(string id, string name, int hp, int atk):id(id),name(name),hp(hp),atk(atk){}

	bool isDead(){
		return hp <= 0;
	}
	virtual void print() = 0;
};
class Warrior :public Hero{
public:
	Warrior() :Hero("1", "Warrior", 12, 2){}
	void power()override{
		this->hp++;
	}
	void print()override{
		cout << name << " " << atk << " " << hp;
	}
};
class Magician :public Hero{
	bool hasPower = true;
public:
	Magician() :Hero("2", "Magician", 2, 6){}
	void power()override{
	}
	virtual void beAttacked(int enemyAtk)override{
		if (hasPower){
			hasPower = false;
		}
		else{
			this->hp -= enemyAtk;
		}
	}
	void print()override{
		cout << name << " " << atk << " " << hp;
	}
};
class Leader :public Hero{
public:
	Leader() :Hero("3", "Leader", 6, 6){}
	void power()override{
		this->atk++;
	}
	void print()override{
		cout << name << " " << atk << " " << hp;
	}
};
vector<Hero*> teamA, teamB;

Hero* selectHero(int code){
	switch (code){
	case 1:
		return new Warrior;
	case 2:
		return new Magician;
	case 3:
		return new Leader;
	}
}
int main(){
	int num;
	cin >> num;
	int role;
	for (int i = 0; i < num; i++){
		cin >> role;
		teamA.push_back(selectHero(role));
	}
	for (int i = 0; i < num; i++){
		cin >> role;
		teamB.push_back(selectHero(role));
	}

	int p1 = 0, p2 = 0;
	while (p1 != num && p2 != num){
		Hero* hero1 = teamA[p1];
		Hero* hero2 = teamB[p2];
		//hero1->print();
		//hero2->print();
		hero1->beAttacked(hero2->atk);
		//cout << "hero1 loss: " << hero2->atk << " now hp: " << hero1->hp << endl;
		hero2->beAttacked(hero1->atk);
		//cout << "hero2 loss " << hero1->atk << " now hp: " << hero2->hp << endl;
		if (hero1->isDead()){
			p1++;
		}
		else{
			hero1->power();
		}
		if (hero2->isDead()){
			p2++;
		}
		else{
			hero2->power();
		}
	}
	if (p1 == num && p2 == num){
		cout << "All Dead";
		//system("pause");
		return 0;
	}
	for (; p1 < num; p1++){
		Hero* hero1 = teamA[p1];
		hero1->print();
		if (p1 != num - 1){
			cout << endl;
		}
	}

	for (; p2 < num; p2++){
		Hero* hero2 = teamB[p2];
		hero2->print();
		if (p2 != num - 1){
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}