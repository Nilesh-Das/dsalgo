#include <iostream>
using namespace std;
#define max 1000
//Queue implementation using array

class queue {
	int f, b;
	int a[max];
public:
	queue() { f=-1; b=-1;}
	bool empty();
	void enqueue(int x);
	void dequeue();
	void front();
	void back();
};

bool queue :: empty() {
	return (f==-1);
}

void queue :: enqueue(int x) {
	if(this->empty()) {
		f = 0;
	}
	a[++b] = x;
	cout << x << " enqueued into queue\n";
}

void queue :: dequeue() {
	if(this->empty()) {
		cout << "queue is empty\n";
	} else {
		cout << a[f] << " dequeued from queue\n";
		(f>=b)?f=b=-1:f++;
	}
}

void queue :: front() {
	if(this->empty()) {
		cout << "queue is Empty\n";
	} else {
		cout << a[f] << " is front of queue\n";
	}
}

void queue :: back() {
	if(this->empty()) {
		cout << "queue is Empty\n";
	} else {
		cout << a[b] << " is back of queue\n";
	}
}


int main() {
	queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.front(); q.back();
	q.dequeue();
	q.dequeue();
	q.front(); q.back();
	return 0;
}