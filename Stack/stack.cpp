#include <iostream>
using namespace std;

class Node {
	public:
		int info;
		Node* next;
		Node(int _info) {
			this->info=_info;
			this->next=nullptr;
		}
};

class Stack {
	private:
		Node *head;
		int top;
	public:
		Stack() {
			top=-1;
			head=nullptr;
		}
		~Stack() {
			Node* cur=head;
			while (cur!=nullptr) {
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
		}
		bool isEmpty() {
			return top==-1;
		}

		void push(int x) {
			Node* newNode = new Node(x);
			if (isEmpty()) {
				head=newNode;
			} else {
				newNode->next=head;
				head=newNode;
			}
			top++;
		}

		int pop() {
			int rs=-999;
			if (isEmpty()) {
				cout<<"Stack is empty"<<endl;
			} else {
				rs = head->info;
				Node* tmp=head;
				head=head->next;
				delete tmp;
				top--;
			}
			return rs;
		}

		int Top() {
			return isEmpty() ? -999 : head->info;
		}
};

//Convert n from Decimal to Binary
void decToBin(int n) {
	if (n==0) {
		cout<<"0";
		return;
	}
	Stack st;
	while (n!=0){
		st.push(n%2);
		n = n/2;
	}
	while (!st.isEmpty()){
		cout<<st.pop();
	}
}

int main() {
	Stack st;
	st.push(5);
	st.push(2);
	st.push(9);
	st.push(7);
	cout<<st.pop()<<" ";
	cout<<st.pop()<<" ";
	cout<<st.pop()<<" ";
	cout<<endl;
//	cout<<st.pop()<<" ";
	cout<<st.Top()<<" ";
	cout<<endl;
	int n;
	cout<<"Input n = "; cin>>n;
	decToBin(n);
	return 0;
}
