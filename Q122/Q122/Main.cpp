#include<iostream>
using namespace std;

class DateTime{
private:
	int year, month, day, hour, minute, second;
public:
	friend istream& operator>>(istream&, DateTime&);
	friend ostream& operator<<(ostream&, DateTime&);
	void run(){
		if (second != 59){
			second++;
		}
		else{
			second = 0;
			if (minute != 59){
				minute++;
			}
			else{
				minute = 0;
				if (hour != 23){
					hour++;
				}
				else{
					hour = 0;
					if (day != lastDay()){
						day++;
					}
					else{
						day = 1;
						if (month != 12){
							month++;
						}
						else{
							month = 1;
							year++;
						}
					}
				}
			}
		}
	}
	int lastDay(){
		switch (month){
		case 1:return 31;
		case 3:return 31;
		case 5:return 31;
		case 7:return 31;
		case 8:return 31;
		case 10:return 31;
		case 12:return 31;
		case 2:return isSpecialYear() ? 29 : 28;
		case 4:return 30;
		case 6:return 30;
		case 9:return 30;
		case 11:return 30;
		}
	}
	bool isSpecialYear(){
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
			return true;
		}
		else{
			return false;
		}
	}
	DateTime& operator++(int){
		DateTime* oldTime = new DateTime(*this);
		++(*this);
		return *oldTime;
	}
	DateTime& operator++(){
		run();
		return *this;
	}
};
istream& operator>>(istream& in, DateTime& time){
	in >> time.year >> time.month >> time.day >> time.hour >> time.minute >> time.second;
	return in;
}
ostream& operator<<(ostream& out, DateTime& time){
	out << time.year << " " 
		<< time.month << " " 
		<< time.day << " " 
		<< time.hour << " " 
		<< time.minute << " " 
		<< time.second;
	return out;
}
int main(){
	DateTime time;
	cin >> time;
	time++;
	cout << time;
	//system("pause");
}