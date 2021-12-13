#include <iostream>
using namespace std;



class CircularQueue{
public:
	int length;
	int headIndex;
	int tailIndex; // first empty cell
	int capacity;
	int* dynamicQueue;

	CircularQueue(int c){
		capacity = c;
		length=0, headIndex=0, tailIndex=0;
		dynamicQueue = new int[capacity];
	}

	void enqueue(int n){
		if (length < capacity){
			dynamicQueue[tailIndex] = n;
			length++;
			tailIndex = ((tailIndex +1) % capacity); // update circular tail index
		}
		/* else: you need to dequeue some elements first! */
	}

	int dequeue(){
		if (length >= 1 ){
			int element = dynamicQueue[headIndex];
			length--, headIndex =((headIndex +1) % capacity);
			return element;
		}
	}

	void getHead(){
		cout << "\nHead: " << dynamicQueue[headIndex] << "\n";
	}

	void getTail(){
		/* adding capacity to tailIndex-1, so that if index =0, then index-1 should be (capacity-1) not -1,
		 * 		because the circular indexing */
		cout << "\nTail: " << dynamicQueue[(tailIndex+capacity-1)%capacity] << "\n";
	}

	void printQueueIndex0(){
		cout << "\nStart from index 0 \n";
		for (int i=0; i< capacity; i++){
			cout << dynamicQueue[i] << " ";
		}
		cout << "\nEnd\n";
	}

	void printQueueHeadIndex() {
		cout << "\nStart from head index \n";
		for (int i = headIndex; i <= length; i++) {
			cout << dynamicQueue[i] << " ";
		}
		cout << "\nEnd\n";
	}

};



int main(void){
	CircularQueue testQ = CircularQueue(5);

	testQ.enqueue(10);
	testQ.enqueue(15);
	testQ.enqueue(20);

	testQ.getHead();
	testQ.getTail();

	testQ.dequeue();

	testQ.getHead();
	testQ.getTail();

	testQ.printQueueIndex0();
	testQ.printQueueHeadIndex();

	testQ.enqueue(25);
	testQ.enqueue(30);
	testQ.enqueue(35);
	testQ.enqueue(40);
	testQ.enqueue(45);

	testQ.getHead();
	testQ.getTail();

	testQ.printQueueIndex0();
	testQ.printQueueHeadIndex();

}



