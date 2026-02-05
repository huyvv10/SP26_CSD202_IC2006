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

class Queue{
	private:
		Node *head, *tail;
	public:
		Queue() {
			head=tail=nullptr;
		}
		~Queue() {
			Node* cur=head;
			while (cur!=nullptr) {
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
		}
		//Check wherether the list is emtpy or not
		bool isEmpty() {
			return head==nullptr;
		}	
		
		void enqueue(int x){
			Node* newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}			
		}
		
		void dequeue(){
			if (isEmpty()) return;			//Check the list is empty or not
			Node* temp;
			temp=head;
			if (head->next==nullptr) {		//The list has only node
				head=tail=nullptr; 
				delete temp;
				return;
			}
			head=head->next;
			delete temp;			
		}
		
		int front(){
			return isEmpty() ? -999 : head->info;
		}
		
		int rear(){
			return isEmpty() ? -999 : tail->info;
		}
};
int main(){
	Queue myQ;
	myQ.enqueue(5);
	myQ.enqueue(8);
	myQ.enqueue(2);
	myQ.enqueue(6);
	cout<<myQ.front()<<endl;
	while (!myQ.isEmpty()){
		cout<<myQ.front() << " ";
		myQ.dequeue();
	}
	cout<<endl;
	return 0;
}
