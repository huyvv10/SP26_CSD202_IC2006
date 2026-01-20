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

		//Insert x into the position pos
		void addAtPos(int x, int pos) {
			int size = countNode();
			if (pos<0 || pos>size) return;
			if (pos==0) {
				addFirst(x);
				return;
			}
			if (pos==size) {
				addLast(x);
				return;
			}
			Node* newNode = new Node(x);
			int i=0;
			Node* cur = head;
			while (cur!=nullptr) {
				if (i+1==pos) {
					newNode->next = cur->next;
					cur->next = newNode;
					break;
				}
				i++;
				cur = cur->next;
			}
		}
		
		//Return the value of an element before x.
		//Return -999 in case find not found x.
		int getValuePre(int x){
			int rs = -999;
			Node* cur = head;
			if (cur->info==x) return rs;
			while (cur->next!=nullptr){
				if (cur->next->info==x){
					rs = cur->info; break;
				}
				cur=cur->next;
			}			
			return rs;
		}
		
		//Return the value of an element after x.
		//Return -999 in case find not found x.
		int getValuePost(int x){
			int rs = -999;
			Node* cur = head;
			if (tail->info==x) return rs;
			while (cur->next!=nullptr){
				if (cur->info==x){
					rs = cur->next->info;
					break;
				}
				cur = cur->next;
			}			
			return rs;
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

		//Return the value at the beginning of the list
		//Return -999 incase the list is empty.
		int getFirst() {
			if (isEmpty()) return -999;
			return head->info;
		}

		//Return the value at the last of the list
		//Return -999 incase the list is empty.
		int getLast() {
			if (isEmpty()) return -999;
			return tail->info;
		}

		//Return the value at the position pos
		//Return -999 incase pos is out of range.
		int getValueAtPos(int pos) {
			int i=0, rs = -999;
			int size = countNode();
			if (pos<0 || pos>=size) return rs;
			Node* cur=head;
			while (cur!=nullptr) {
				if (i==pos) {
					rs = cur->info;
					break;
				}
				i++;
				cur=cur->next;
			}
			return rs;
		}
		
		//Remove the first element in the list
		void removeFirst(){
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
		
		//Remove the last element in the list
		void removeLast(){
			if (isEmpty()) return;
			Node* temp;
			if (head->next==nullptr) {
				temp=head;
				head=tail=nullptr; 
				delete temp;
				return;
			}			
			Node* cur=head;
			while (cur->next!=tail){
				cur=cur->next;
			}
			temp=tail;
			tail=cur;
			cur->next=nullptr;
			delete temp;							
		}
		
		//Remove the elemment at the position pos
		void removeAtPos(int pos){
			int size = countNode();
			if (pos<0 || pos>=size) return;
			if (pos==0) {
				removeFirst();
				return;
			}
			if (pos==size-1){
				removeLast(); return;
			}
			Node* cur=head;
			int i=0;
			while (i+1!=pos){
				cur=cur->next;
				i++;
			}
			cur->next=cur->next->next;
		}
		
		//Remove the element with value as x first found from the left
		void remove(int x){
			if (isEmpty()) return;
			if (head->info == x){
				head=head->next; return;
			}		
			Node* cur=head;
			while (cur->next!=nullptr){
				if (cur->next->info==x){
					cur->next=cur->next->next; return;
				}					
				cur=cur->next;
			}
		}
		
		//Remove all elements with value as x
		void removeAll(int x){
			if (isEmpty()) return;
			while(head!=nullptr && head->info==x){
				removeFirst();
			}
			Node* cur=head;
			while (cur!=nullptr && cur->next!=nullptr){
				if (cur->next==tail && cur->next->info==x) removeLast();
				if(cur->next!=nullptr && cur->next->info==x){
					Node* temp = cur->next;
					cur->next=cur->next->next;
					delete temp;
				} else
					cur=cur->next;
			}
		}
		
		//Remove the element right before x (first found from the left)
		void removePre(int x){
			if (isEmpty() || head->info==x) return;
			if (head->next->info==x){ removeFirst(); return;}
			Node* cur=head;
			while (cur!=nullptr && cur->next!=nullptr){
				if (cur->next->next!=nullptr && cur->next->next->info==x){
					Node* temp = cur->next;
					cur->next=cur->next->next;
					delete temp;
					return;
				}
				cur=cur->next;
			}
		}
		
		//Remove the element right after x (first found from the left)
		void removePost(int x){
			if (isEmpty() || head->next==nullptr) return;
			Node* cur = head;
			while (cur!=nullptr && cur->next!=nullptr){
				if (cur->next->next==tail && cur->next->info==x) { removeLast(); return;}
				if (cur->next!=nullptr && cur->info==x){
					Node* temp=cur->next;
					cur->next=cur->next->next;
					delete temp;
					return;
				}
				cur=cur->next;
			}
		}
		
		//Update newValue for the element at the position pos
		void editAtPos(int newValue, int pos){
			int i=0, size = countNode();
			if (pos < 0 || pos >= size) return;
			Node* cur = head;
			while (i!=pos){
				cur=cur->next;
				i++;
			}
			cur->info=newValue;
		}
		
		//Update newValue for the element before the one with value as x.
		void editPre(int x, int newValue){
			
		}
		
		//Update newValue for the element after the one with value as x.
		void editPost(int x, int newValue){
			
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
	myList.addFirst(6);
	myList.addFirst(8);
	myList.addFirst(8);
	myList.addFirst(5);
//	myList.addFirst(3);
	myList.addFirst(8);
	myList.addFirst(8);
	myList.addFirst(9);
//	myList.addFirst(4);
//	myList.display();
//	myList.addLast(7);
//	myList.addLast(5);
//	myList.addLast(6);
	myList.addLast(2);
	myList.display();
//	cout<<"Number of nodes: "<<myList.countNode()<<endl;
//	cout<<"Number of nodes using for: "<<myList.size()<<endl;
//	cout<<"Input a value to search its position: ";
	int x, pos, rs;
//	cin>>x;
//	pos=myList.findFirstPosOfNode(x);
//	if (pos>=0)
//		cout<<"The position first found "<<x<<" is: "<<pos<<endl;
//	else
//		cout<<"Find not found "<<x<<" in the list."<<endl;
//	cout<<"The maximum value: "<<myList.getMaxValue()<<endl;
//	cout<<"The minimum value: "<<myList.getMinValue()<<endl;
//	cout<<"Input value to add: ";
//	cin>>x;
//	cout<<"Input position to add: ";
//	cin>>pos;
//	myList.addAtPos(x,pos);
//	myList.display();

//	cout<<"The value at the beginning: "<<myList.getFirst()<<endl;
//	cout<<"The value at the end: "<<myList.getLast()<<endl;
//	cout<<"Input position to get value: ";
//	cin>>pos;
//	rs = myList.getValueAtPos(pos);
//	if (rs != -999) {
//		cout<<"The value at position "<<pos<<" is: "<<rs<<endl;
//	} else {
//		cout<<"The position "<<pos<<" is out of the range."<<endl;
//	}

//	cout<<"Input value to get its previous value: ";
//	cin>>x;
//	rs = myList.getValuePre(x);
//	if (rs != -999){
//		cout<<"The value before "<<x<<" is: "<<rs<<endl;
//	} else {
//		cout<<"Does not exist an element before "<<x<<endl;
//	}
//	cout<<"Input value to get value after its: ";
//	cin>>x;	
//	rs = myList.getValuePost(x);
//	if (rs != -999){
//		cout<<"The value before "<<x<<" is: "<<rs<<endl;
//	} else {
//		cout<<"Does not exist an element after "<<x<<endl;
//	}	
//	cout<<"\nRemove first element"<<endl;
//	myList.removeFirst();
//	myList.display();
//	cout<<"\nRemove last element"<<endl;
//	myList.removeLast();
//	myList.display();
//	cout<<"Remove at pos"<<endl;
//	cout<<"Input position of element to remove: ";
//	cin>>pos;
//	myList.removeAtPos(pos);
//	myList.display();
//	cout<<"Remove element with value as x"<<endl;
//	cout<<"Input value to remove: ";
//	cin>>x;
//	myList.remove(x);
//	myList.display();
//	cout<<"Remove all element with value as x"<<endl;
//	cout<<"Input value to remove: ";
//	cin>>x;
//	myList.removeAll(x);
//	myList.display();
//	cout<<"Remove an element before the one with value as x"<<endl;
//	cout<<"Input value to remove: ";
//	cin>>x;
//	myList.removePre(x);
//	myList.display();
//	cout<<"Remove an element after the one with value as x"<<endl;
//	cout<<"Input value to remove: ";
//	cin>>x;
//	myList.removePost(x);
//	myList.display();
	cout<<"Update new value for the element at the position pos"<<endl;
	cout<<"Input the position to update new value: ";
	cin>>pos;
	cout<<"Input the new value: ";
	cin>>x;
	myList.editAtPos(x,pos);
	myList.display();

	return 0;
}
