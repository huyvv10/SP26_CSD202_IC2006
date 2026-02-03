#include <iostream>
using namespace std;

class Node{
	public:
		int info;	
		Node* next;
		Node* prev;
		Node(int _info){
			this->info=_info;
			this->next=nullptr;
			this->prev=nullptr;
		}
};

class DoubleLinkedListMan{
	private:
		Node *head, *tail;
	public:
		DoubleLinkedListMan(){
			head=tail=nullptr;
		}	
		~DoubleLinkedListMan(){
			Node* cur=head;
			while (cur!=nullptr){
				Node* tmp=cur;
				cur=cur->next;
//				delete tmp->info;	//in case obj
				delete tmp;
			}
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst(int x){
			Node* newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
 		
 		void addLast(int x){
 			Node* newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
			} else {
				tail->next=newNode;
				newNode->prev=tail;
				tail=newNode;
			}
		}
		
		int countNodes(){
			int count=0;
			Node* cur=head;
			while (cur!=nullptr){
				count++;
				cur=cur->next;
			}
			return count;
		}
		//Insert x into the position pos
		void addAtPos(int x, int pos){
			int size=countNodes();
			if (pos<0 || pos>size) return;
			if (pos==0) {
				addFirst(x); return;
			}
			if (pos==size) {
				addLast(x); return;
			}
			Node* newNode = new Node(x);
			Node* cur=head;
			int i=0;
			while (cur!=nullptr){
				if (i==pos){
					cur->prev->next=newNode;
					newNode->prev=cur->prev;
					newNode->next=cur;
					cur->prev=newNode;
					break;
				}
				cur=cur->next;
				i++;
			}
		}
		
		void removeFirst(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node* tmp=head;
				head=tail=nullptr;
				delete tmp;
				return;
			}
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}
		
		void removeLast(){
			if (isEmpty()) return;
			if (head->next==nullptr){
				Node* tmp=head;
				head=tail=nullptr; 
				delete tmp;
				return;
			}
			Node* tmp=tail;
			tail->prev->next=nullptr;
			tail=tail->prev;
			delete tmp;			
		}
		
		void removeAtPos(int pos){
			int size=countNodes();
			if (pos<0 || pos>=size) return;
			if (pos==0){
				removeFirst(); return;
			}			
			if (pos==size-1){
				removeLast(); return;
			}
			int i=0;
			Node* cur=head;
			while (i!=pos){
				i++;
				cur=cur->next;
			}
			Node* tmp=cur;
			cur->next->prev=cur->prev;
			cur->prev->next=cur->next;
			delete tmp;
		}
		
		void remove(int x){
			
		}
 		//Traversal 
 		void display(){
 			Node* cur=head;
 			while (cur!=nullptr){
 				cout<<cur->info<<" ";
 				cur=cur->next;
			}
			cout<<endl;
		}
};

int main(){
	DoubleLinkedListMan myList;
	myList.addFirst(8);
	myList.addFirst(5);
	myList.addFirst(9);
	myList.addFirst(2);
	myList.display();
	myList.addLast(4);
	myList.addLast(9);
	myList.addLast(6);
	myList.display();
	int x, pos;
//	cout<<"Input x = "; cin>>x;
//	cout<<"Input position pos = "; cin>>pos;
//	myList.addAtPos(x, pos);
//	myList.display();
	cout<<"\nRemove first"<<endl;
	myList.removeFirst();
	myList.display();
	cout<<"\nRemove last"<<endl;
	myList.removeLast();
	myList.display();
	cout<<"Input position to delete pos = "; cin>>pos;	
	myList.removeAtPos(pos);
	myList.display();
	
	return 0;
}
