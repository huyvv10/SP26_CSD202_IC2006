#include <iostream>
#include <string>

using namespace std;
class Car{
	public: 
		string _id;
		string _name;
		int	   _color;
		double _price;
		Car (){
		}
		Car(string id, string name, int color, double price){
			this->_id=id;
			this->_name=name;
			this->_color=color;
			this->_price=price;
		}
		void displayCar(){
			cout<<"("<<_id<<", "<<_name<<", "<<_color<<", "<<_price<<")"<<endl;
		}
};

class Node{
	public:
		Car* info;
		Node* next;
		Node(Car* x){
			this->info = x;
			this->next = nullptr;
		}	
};

class SinglyLinkedListObj{
	private:
		Node *head, *tail;
	public: 
		SinglyLinkedListObj(){
			head=tail=nullptr;
		}
		~SinglyLinkedListObj(){}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst (Car* x){
			Node* newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
		}
		
		void display(){
			Node* cur=head;
			while (cur!=nullptr){
				cur->info->displayCar();
				cur=cur->next;
			}
		}
	
};

int main(){
	SinglyLinkedListObj myList;
	myList.addFirst(new Car("V09", "Vinfast VF9", 5, 55000.5));	
	myList.addFirst(new Car("V07", "Vinfast VF7", 2, 35000));	
	myList.addFirst(new Car("V34", "Vinfast VF34", 3, 20000.5));	
	myList.addFirst(new Car("M01", "Mazda CX8", 6, 42000.5));	
	myList.display();
	return 0;
}
