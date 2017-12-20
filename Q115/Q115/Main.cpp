#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
class BinarySearch{
public:
	T* list;
	int size;

	friend istream& operator>>(istream& in, BinarySearch<T>& bs){
		in >> bs.size;
		bs.list = new T[bs.size];
		for (int i = 0; i < bs.size; i++){
			in >> bs.list[i];
		}
		return in;
	}

	void sortList(){
		sort(list, list + size);
		/*
		for (int i = 0; i < size - 1; i++){
			for (int j = 1; j < size; j++){
				if (list[i]>list[j]){
					T tmp = list[j];
					list[j] = list[i];
					list[i] = tmp;
				}
			}
		}*/
	}

	int binarySearch(T findItem){
		int start = 0;
		int end = size - 1;
		int count = 0;

		while (start <= end){
			int mid = start + (end - start) / 2;
			count++;
			if (findItem == list[mid]){
				return count;
			}
			else if (findItem > list[mid]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		return count;
	}	
};
template <class T>
void run(){
	BinarySearch<T> bs;
	cin >> bs;
	bs.sortList(); 
	T findItem;
	cin >> findItem;
	cout << bs.binarySearch(findItem);
}
int main(){
	run<int>();
	cout << endl;
	run<double>();
	cout << endl;
	run<char>();
	//system("pause");
}