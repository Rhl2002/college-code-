#include<bits/stdc++.h>
using namespace std;

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
		else {
			return false;
		}
	}
	bool isempty(){
		if(first==-1 && last==-1 || first>last){
			return true;
		}
		else{
			return false;
		}
	}

	void enqueue(int x){
		if(this->isfull()){
			cout<<"\nQueue is Full\n";
		}
		else{
			if(first==-1 && last==-1){
				first++;
			}
			last++;
			//last = (last+1)%capacity;
			arr[last]=x;
		}
	}

	void dequeue(){
		if(this->isempty()){
			cout<<"\nQueue is Empty\n";
		}
		else{
			first++;
			//first=(first+1)%capacity;
		}
	}

	void display(){
		if(this->isempty()) cout<<"Queue is Empty";
		for(int i=first;i<=last;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	int front(){
		return arr[first];
	}

	int back(){
		return arr[last];
	}

};

int main(){

	myqueue q(4);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(20);
	q.enqueue(20);
	q.enqueue(20);
	q.display();
	//cout<<q.front()<<" "<<q.back()<<endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();


}