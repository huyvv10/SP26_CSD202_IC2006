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

class SinglyLinkedListMng {
	private:
		Node *head, *tail;
	public:
		SinglyLinkedListMng() {
			head=tail=nullptr;
		}
		~SinglyLinkedListMng() {
			Node* cur=head;
			while (cur!=nullptr) {
				Node* tmp=cur;
				cur=cur->next;
				delete tmp;
			}
//			cout<<"Thu hoi bo nho"<<endl;
		}
		//Check wherether the list is emtpy or not
		bool isEmpty() {
			return head==nullptr;
		}

		//Add an element to the beginning of the list
		void addFirst(int x) {
			Node* newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
		}

		//Add an element to the last of the list
		void addLast(int x) {
			Node* newNode = new Node(x);
			if (isEmpty()) {
				head=tail=newNode;
			} else {
				tail->next=newNode;
				tail=newNode;
			}
		}

		//Count number of nodes existing in the list
		int countNode() {
			int count=0;
			Node* cur=head;
			while(cur!=nullptr) {
				count++;
				cur=cur->next;
			}
			return count;
		}

		//Count number of nodes existing in the list using for loop
		int size() {
			int count=0;
			for (Node* cur=head; cur!=nullptr; cur=cur->next) {
				count++;
			}
			return count;
		}

		//Return the position first found x. Return -1 if find not found
		int findFirstPosOfNode(int x) {
			int pos=-1, i=0;
			Node* cur=head;
			while (cur!=nullptr) {
				if (cur->info==x) {
					pos=i;
					break;
				}
				i++;
				cur=cur->next;
			}
			return pos;
		}

		//Return the maximum value in the list
		int getMaxValue() {
			int max=-999;
			
			if (!isEmpty()) {
				max=head->info;
				Node* cur=head->next;
				while (cur!=nullptr) {
					if (cur->info>max)
						max=cur->info;
					cur=cur->next;
				}
			}
			return max;
		}

		//Return the minimum value in the list
		int getMinValue() {
			int min=-999;
			if (!isEmpty()) {
				min=head->info;
				Node* cur=head->next;
				while (cur!=nullptr) {
					if (cur->info<min)
						min=cur->info;
					cur=cur->next;
				}
			}
			return min;
		}
		//Display the list info
		void display() {

			Node* cur=head;
			while (cur!=nullptr) {
				cout<<cur->info<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}
};

int main() {
	SinglyLinkedListMng myList;
	myList.addFirst(8);
	myList.addFirst(5);
	myList.addFirst(3);
	myList.addFirst(9);
	myList.addFirst(4);
	myList.display();
	myList.addLast(7);
	myList.addLast(5);
	myList.addLast(2);
	myList.display();
	cout<<"Number of nodes: "<<myList.countNode()<<endl;
	cout<<"Number of nodes using for: "<<myList.size()<<endl;
	cout<<"Input a value to search its position: ";
	int x, pos;
	cin>>x;
	pos=myList.findFirstPosOfNode(x);
	if (pos>=0)
		cout<<"The position first found "<<x<<" is: "<<pos<<endl;
	else
		cout<<"Find not found "<<x<<" in the list."<<endl;
	cout<<"The maximum value: "<<myList.getMaxValue()<<endl;
	cout<<"The minimum value: "<<myList.getMinValue()<<endl;
	return 0;
}
