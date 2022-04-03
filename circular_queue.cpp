#include<bits/stdc++.h>
using namespace std;
 //not complete
class myqueue{
	int first,last,*arr,capacity;

public:
	myqueue(int cap){
		capacity=cap;
		
        arr = new int[capacity];
		first=-1;
		last=-1;

	}

	bool isfull(){
		if( first==0 && last==(capacity-1)){
			return true;
		}
		if(first==last+1){
			return true;
		}
		return false;
	}
	bool isempty(){
		if(first==-1){
			return true;
		}
				return false;
		
	}

	void enqueue(int x){
		if(this->isfull()){
			cout<<"\nQueue is Full\n";
		}
		else{
			if(first==-1 ){
				first=0;
			}
			//last++;
			last = (last+1)%capacity;
			arr[last]=x;
		}
	}

	void dequeue(){
		if(this->isempty()){
			cout<<"\nQueue is Empty\n";
		}

		if (first== last) {
        first = -1;
        last = -1;
        }
		else{
			//first++;
			first=(first+1)%capacity;
		}
	}

	void display(){
		if(this->isempty()) {
			cout<<"Queue is Empty\n";
			return;
		}
		for(int i=first;i<=last;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	int front(){
		if(this->isempty()){
			return -1;
		}
		return arr[first];
	}

	int back(){
		if(this->isempty()){
			return -1;
		}
		return arr[last];
	}

};

int main(){

	myqueue q(10);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.enqueue(30);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();


}