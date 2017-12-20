#include<iostream>
using namespace std;
class ThreeDPoint{
private:
	int x = 0;
	int y = 0;
	int z = 0;
public:
	ThreeDPoint(){}
	ThreeDPoint(const ThreeDPoint& other){
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	ThreeDPoint& operator+(ThreeDPoint& other){
		ThreeDPoint* newPoint = new ThreeDPoint(*this);
		newPoint->x = x + other.x;
		newPoint->y = y + other.y;
		newPoint->z = z + other.z;
		return *newPoint;
	}
	friend ThreeDPoint& operator++(ThreeDPoint& point);
	friend istream& operator>>(istream& in, ThreeDPoint& point);
	friend ostream& operator<<(ostream& out, ThreeDPoint& point);
};
ThreeDPoint& operator++(ThreeDPoint& before){
	before.x += 1;
	before.y += 1;
	before.z += 1;
	return before;
}
istream& operator>>(istream& in, ThreeDPoint& point){
	in >> point.x >> point.y >> point.z;
	return in;
}
ostream& operator<<(ostream& out, ThreeDPoint& point){
	out << "x:" << point.x << ",y:" << point.y << ",z:" << point.z;
	return out;
}
int main(){
	ThreeDPoint point1,point2;
	cin >> point1;
	point1++;
	cout << point1 << endl;
	cin >> point2;
	cout << point1 + point2;
	return 0;
}
