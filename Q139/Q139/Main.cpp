#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Polygon{
protected:
	string polygonid,group;
	int red, green, blue;
public:
	Polygon(string polygonid, int red, int green, int blue) :polygonid(polygonid),red(red), green(green), blue(blue){}
	virtual void setColor(int r, int g, int b) = 0;
	virtual int getNum() = 0;
	virtual string getName() = 0;
	virtual double grayValue() = 0;
	virtual void print() = 0;
};
class normalPolygon :public Polygon{
public:
	normalPolygon(string polygonid, int red, int green, int blue) :Polygon(polygonid, red, green, blue){}
	void setColor(int r, int g, int b)override{
		red = r;
		green = g;
		blue = b;
	}
	int getNum()override{
		return stoi(polygonid.substr(1, polygonid.length()-1));
	}
	string getName()override{
		return polygonid;
	}
	double grayValue()override{
		return red*0.299 + green*0.587 + blue*0.114;
	}
	void print()override{
		cout << polygonid << " " << red << " " << green << " " << blue;
	}
};
class reversePolygon :public Polygon{
public:
	reversePolygon(string polygonid, int red, int green, int blue) :Polygon(polygonid, red, green, blue){}
	void setColor(int r, int g, int b)override{
		red = 255 - r;
		green = 255 - g;
		blue = 255 - b;
	}
	int getNum()override{
		return stoi(polygonid.substr(1, polygonid.length() - 1));
	}
	string getName()override{
		return polygonid;
	}
	double grayValue()override{
		return red*0.299 + green*0.587 + blue*0.114;
	}
	void print()override{
		cout << polygonid << " " << red << " " << green << " " << blue;
	}
};
class singlePolygon :public Polygon{
public:
	singlePolygon(string polygonid, int red, int green, int blue) :Polygon(polygonid, red, green, blue){}
	void setColor(int r, int g, int b)override{
		red = r;
		green = 0;
		blue = 0;
	}
	int getNum()override{
		return stoi(polygonid.substr(1, polygonid.length() - 1));
	}
	string getName()override{
		return polygonid;
	}
	double grayValue()override{
		return red*0.299 + green*0.587 + blue*0.114;
	}
	void print()override{
		cout << polygonid << " " << red << " " << green << " " << blue;
	}
};
vector<Polygon*> list;
class Group{
private:
	string name;
	int size;
	vector<Polygon*> group;
public:
	string getName(){
		return name;
	}
	void setName(string name){
		this->name = name;
	}
	void add(string str){
		for (int i = 0; i < list.size(); i++){
			if (list[i]->getName() == str){
				group.push_back(list[i]);
			}
		}
	}
	void setColor(int r,int g,int b){
		for (int i = 0; i < group.size(); i++){
			group[i]->setColor(r,g,b);
		}
	}
};
vector<Group> groupList;
void operation(){
	string op;
	cin >> op;
	if (op == "Add"){
		cin >> op;
		if (op == "normal"){
			cin >> op;
			normalPolygon* polygon = new normalPolygon(op,0,0,0);
			list.push_back(polygon);
		}
		else if (op == "single"){
			cin >> op;
			singlePolygon* polygon = new singlePolygon(op,0,0,0);
			list.push_back(polygon);
		}
		else if (op == "reverse"){
			cin >> op;
			reversePolygon* polygon = new reversePolygon(op,0,0,0);
			list.push_back(polygon);
		}
	}
	else if (op == "Set"){
		int red = 0, green = 0, blue = 0;
		cin >> op >> red >> green >> blue;
		for (int i = 0; i < list.size(); i++){
			if (list[i]->getName() == op){
				list[i]->setColor(red, green, blue);
			}
		}
		for (int i = 0; i < groupList.size(); i++){
			if (groupList[i].getName() == op){
				groupList[i].setColor(red, green, blue);
			}
		}
	}
	else if (op == "Group"){
		Group group;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++){
			string str;
			cin >> str;
			group.add(str);
		}
		string name;
		cin >> name;
		group.setName(name);
		groupList.push_back(group);
	}
}
void normalSort(){
	for (int i = 0; i < list.size() - 1; i++){
		for (int j = i + 1; j < list.size(); j++){
			if (list[i]->getNum() > list[j]->getNum()){
				Polygon* tmp;
				tmp = list[j];
				list[j] = list[i];
				list[i] = tmp;
			}
		}
	}
}
void graySort(){
	for (int i = 0; i < list.size() - 1; i++){
		for (int j = i + 1; j < list.size(); j++){
			if (list[i]->grayValue() > list[j]->grayValue()){
				Polygon* tmp;
				tmp = list[j];
				list[j] = list[i];
				list[i] = tmp;
			}
			else if (list[i]->grayValue() == list[j]->grayValue()){
				if (list[i]->getNum() > list[j]->getNum()){
					Polygon* tmp;
					tmp = list[j];
					list[j] = list[i];
					list[i] = tmp;
				}
			}
		}
	}
}
void sort(){
	string op;
	cin >> op;
	if (op == "Normal"){
		normalSort();
	}
	else if (op == "Gray"){
		graySort();
	}
}
void output(){
	for (int i = 0; i < list.size(); i++){
		list[i]->print();
		if (i != list.size() - 1){
			cout << endl;
		}
	}
}
int main(){
	int num;
	cin >> num;
	for (int i = 0; i < num; i++){
		operation();
	}
	sort();
	output();
	//system("pause");
	return 0;
}