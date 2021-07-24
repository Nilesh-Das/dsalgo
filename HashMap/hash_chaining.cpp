#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
	int BUCKET;
	vector<list<pair<int, int>>> mp;
public:
	MyHashMap() {
		BUCKET = 349;
		mp.resize(BUCKET);
	}

	void put(int key, int val) {
		int idx = key % BUCKET;
		if(mp[idx].empty()) {
			mp[idx].push_back({key, val});
			return;
		}

		for(auto it=mp[idx].begin(); it!=mp[idx].end(); it++) {
			if(it->first == key) {
				it->second = val;
				return;
			}
		}
		mp[idx].push_back({key, val});
	}

	int get(int key) {
		int idx = key % BUCKET;
		if(mp[idx].empty()) return -1;
		for(auto it=mp[idx].begin(); it!=mp[idx].end(); it++) {
			if(it->first == key) return it->second;
		}
		return -1;
	}

	void remove(int key) {
		int idx = key % BUCKET;
		if(mp[idx].empty()) return;
		for(auto it=mp[idx].begin(); it!=mp[idx].end(); it++) {
			if(it->first == key) {it->second=-1; return;}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "ok";
	
	return 0;
}