#include <iostream>
#include <vector>
using namespace std;
//Vector STL

int main() {
	int n = 5;
	vector<int> a;
	a.push_back(5);
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	a.push_back(3);
	for(int i=0; i<n; i++) cout << a[i] << ' ';
	return 0;
}