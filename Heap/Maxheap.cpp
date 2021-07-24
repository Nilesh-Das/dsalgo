#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MaxHeap {
    vector<int> maxheap;

public:
    void heapify(int i) {
        int n = maxheap.size();
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < n && maxheap[l] > maxheap[largest])
            largest = l;
        if(r < n && maxheap[r] > maxheap[largest])
            largest = r;
        if(largest != i) {
            swap(maxheap[i], maxheap[largest]);
            heapify(largest);
        }
    }

    void insert(int x) {
        int n = maxheap.size();
        maxheap.push_back(x);
        if(n == 0) return;
        for(int i=n/2-1; i>=0; i--)
            heapify(i);
    }

    void erase(int x) {
        int n = maxheap.size();
        for(int i=0; i<n; i++) {
            if(x == maxheap[i]) {
                swap(maxheap[i], maxheap[n-1]);
                maxheap.pop_back();
                break;
            }
        }
        for(int i=n/2-1; i>=0; i--)
            heapify(i);
    }

    void print() {
        for(int x : maxheap)
            cout << x << ' ';
        cout << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    MaxHeap H;
    H.insert(3);
    H.insert(4);
    H.insert(9);
    H.insert(5);
    H.insert(2);

    cout << "Max-Heap array: ";
    H.print();

    H.erase(4);

    cout << "After deleting an element: ";

    H.print();
    
    return 0;
}