#include<bits/stdc++.h>
using namespace std;

class mystack{
	int t,capacity,*arr;
public:
	mystack(int cap){
		capacity=cap;

        arr = new int[capacity];
		t=-1;
	}

	bool isempty(){
		if(t==-1) return true;
		else return false;
	}

	bool isfull(){
		if(t==(capacity-1)) return true;
		else return false;
	}

	int top(){
		return arr[t];
	}

	void push(int x){
		if(this->isfull()){
			cout<<"\nStack Overflow :Stack is full\n";
		}
		else{
			t++;
			arr[t]=x;
		}
	}

	void pop(){
		if(this->isempty()){
			cout<<"\nStack Underflow :Stack is Empty\n";
		}
		else{
			t--;
		}
	}

	void display(){
		for(int i=0;i<=t;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

};


int main(){
	mystack st(3);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	cout<<st.isfull()<<endl;
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	
}