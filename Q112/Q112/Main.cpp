#include <iostream>
using namespace std;
class Operation{
private:
	double NumberA;
	double NumberB;
public:
	virtual double GetResult() = 0;
	double getA(){
		return NumberA;
	}
	void setA(double num){
		NumberA = num;
	}
	double getB(){
		return NumberB;
	}
	void setB(double num){
		NumberB = num;
	}
};
class OperationAdd :public Operation{
public:
	double GetResult(){
		return getA() + getB();
	}
};
class OperationSub :public Operation{
public:
	double GetResult(){
		return getA() - getB();
	}
};
class OperationMul :public Operation{
public:
	double GetResult(){
		return getA()*getB();
	}
};
class OperationDiv :public Operation{
public:
	double GetResult(){
		if (getB() == 0)
			return -1;
		return getA() / getB();
	}
};
class OperationFactory{
public:
	static Operation* CreateOperation(char operation){
		switch (operation)
		{
		case '+':
			return new OperationAdd();
			break;
		case '-':
			return new OperationSub();
			break;
		case '*':
			return new OperationMul();
			break;
		case '/':
			return new OperationDiv();
			break;
		default:
			return nullptr;
		}
	}
};
int main(){
	char operation;
	double numA, numB;
	cin >> operation >> numA >> numB;
	Operation* op = OperationFactory::CreateOperation(operation);
	op->setA(numA);
	op->setB(numB);
	cout<<op->GetResult();
	return 0;
}