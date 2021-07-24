#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    int sz;
    vector<int> tree;
public:
    NumArray(vector<int>& nums) {
        sz = nums.size();
        tree.resize(sz+1);
        for(int i = 0; i < sz; i++)
            update(i, nums[i]);
    }
    
    void update(int index, int val) {
        for(int i = index+1; i < sz; i += i & -i)
            tree[i] += val;
    }
    
    int qry(int index) {
        int res = 0;
        for(int i = index+1; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }
    
    int sumRange(int left, int right) {
        cout << qry(right) << ' ' <<  qry(left) << '\n';
        return qry(right) - qry(left-1);
    }
};

int main() {
	vector<int> v = {1,2,3,4,5};
	NumArray* obj = new NumArray(v);
	cout << obj->sumRange(0,1) << '\n';
	obj->update(0,2);
	cout << obj->sumRange(0,2) << '\n';
	cout << obj->sumRange(0,3) << '\n';
}
