#include<iostream>
#include<string>
using namespace std;

class Student{
public:
	string id, name;
	int age;
	double weight;
	double gradeMath, gradeEnglish, gradeCpp;
	double getGPA(){
		return (gradeMath*4 + gradeEnglish*4 + gradeCpp*3) / 11.0 / 2;
	}
	friend istream& operator>>(istream&, Student&);
	bool operator<(Student& stu){
		return this->getGPA() < stu.getGPA();
	}
	bool operator==(Student& stu){
		return this->getGPA() == stu.getGPA();
	}
};
istream& operator>>(istream& in, Student& student){
	in >> student.id >> student.name >> student.age >> student.weight >> student.gradeMath >> student.gradeEnglish >> student.gradeCpp;
	return in;
}
bool operator<(string& op1, string& op2){
	for (int i = 0; i < op1.length(); i++){
		if (i >= op2.length()){
			return false;
		}
		if (op1[i] < op2[i]){
			return true;
		}
		else if (op1[i] > op2[i]){
			return false;
		}
	}
	if (op1.length() == op2.length()){
		return false;
	}
	return true;//
}
template <class T>
int compare(T o1, T o2){
	if (o1 < o2){
		return -1;
	}
	else if (o1 == o2){
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	Student stu1, stu2;
	cin >> stu1 >> stu2;
	cout << compare<string>(stu1.name, stu2.name) << " "
		<< compare<int>(stu1.age, stu2.age) << " "
		<< compare<double>(stu1.weight, stu2.weight) << " "
		<< compare<Student>(stu1, stu2);
	//system("pause");
}