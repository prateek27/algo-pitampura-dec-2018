#include <iostream>
using namespace std;

class Queue {
private:
	int ms;
	int cs;
	int *arr;
	int front;
	int rear;
public:
	Queue(int ms = 4) {
		this->arr = new int[ms];
		this->front = 0;
		this->rear = ms-1;
		this->ms = ms;
		this->cs = 0;
	}

	bool isFull() {
		return this->cs == this->ms;
	}

	bool isEmpty() {
		return this->cs == 0;
	}

	void enqueue(int x) {
		if(isFull()) {
			cout<<"Queue is full!!";
			return;
		}
		rear = (rear+1)%ms;
		arr[rear] = x;
		cs++;
	}

	void dequeue() {
		if(isEmpty()) {
			cout<<"Queue is empty!!";
			return;
		}
		front = (front+1)%ms;
		cs--;
	}
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
