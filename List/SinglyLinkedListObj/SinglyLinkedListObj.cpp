#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Car{
	public: 
		string _id;
		string _name;
		int	   _color;
		double _price;
		Car (){}
		Car(string id, string name, int color, double price){
			this->_id=id;
			this->_name=name;
			this->_color=color;
			this->_price=price;
		}
		void displayCar(){
			cout<<left<<setw(5)<<_id<<setw(20)<< _name<<setw(7)<<_color<<right<<setw(10)<<setprecision(10)<<_price<<endl;
//			cout<<"("<<left<<setw(5)<<_id<<", "<<setw(20)<< _name<<", "<<setw(7)<<_color<<", "<<right<<setw(10)<<setprecision(10)<<_price<<")"<<endl;
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
		~SinglyLinkedListObj(){
			Node* cur=head;
			while (cur!=nullptr){
				Node* tmp = cur;
				cur=cur->next;
				delete tmp->info;
				delete tmp;
			}
		}
		
		bool isEmpty(){
			return head==nullptr;
		}
		
		void addFirst (Car* x){
			Node* newNode = new Node(x);
			if (x->_color == 4 || x->_name[0]=='X') return;
			if (isEmpty()){
				head=tail=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
		}
		
		void addLast (Car* x){
			Node* newNode = new Node(x);
			if (isEmpty()){
				head=tail=newNode;
				return;
			}
			tail->next=newNode;
			tail=newNode;			
		}
		
		void addFromTheKeyboard(){
			string id, name;
			int color;
			double price;
			cin.ignore(); //Clear buffer
			cout<<"Input car Id: "; getline(cin, id); 
			cout<<"Input car name: "; getline(cin, name);
			cout<<"Input car color: "; cin>>color;
			cout<<"Input car price: "; cin>>price;
			Car* x = new Car(id, name, color, price);
			addFirst(x);
		}
		//Count number of cars are existing in the list
		int count(){
			int i=0;
			Node* cur=head;
			while (cur!=nullptr){
				i++;
				cur=cur->next;
			}
			return i;
		}
		
		//Return number of cars with color as xColor
		int countByColor(int xColor){
			int i=0;
			Node* cur=head;
			while (cur!=nullptr){
				if (cur->info->_color==xColor) i++;
				cur=cur->next;
			}
			return i;			
		}
		
		//Show cars which name containing xName ignore case sensitivity
		void searchCarByName(string xName){
			
		}
		
		//Edit car info by ID
		void updateCarInforById(string xId, Car* newCar){
			
		}
		
		//Remove car by its Id
		void removeCarById(string xId){
			
		}
		
		//Sort the car list by their price in descending order
		void sortCarListByPriceDesc(){
			
		}
		
		//Display car list with price in the range [firstPrice, secondPrice]
		void displayCarInRange(double firstPrice, double secondPrice){
			
		}
		
		void display(){
			Node* cur=head;
			cout<<left<<setw(5)<<"ID"<<setw(20)<<"Car Name"<<setw(7)<<"Color"<<right<<setw(10)<<setprecision(2)<<"Price"<<endl;
			cout<<left<<setw(5)<<"--"<<setw(20)<<"--------"<<setw(7)<<"-----"<<right<<setw(10)<<setprecision(2)<<"-----"<<endl;
			while (cur!=nullptr){
				cur->info->displayCar();
				cur=cur->next;
			}
			cout<<endl;
		}
};

int main(){
	SinglyLinkedListObj myList;
	myList.addFirst(new Car("V09", "Vinfast VF9", 5, 55000.5));	
	myList.addFirst(new Car("V07", "Vinfast VF7", 2, 35000));	
	myList.addFirst(new Car("V34", "Vinfast VF34", 4, 20000.5));	
	myList.addFirst(new Car("M01", "Mazda CX8", 6, 42000.5));	
	myList.addFirst(new Car("M02", "Xpander Cross", 7, 40000.5));	
	myList.display();
	myList.addLast(new Car("M02", "Mazda 3", 2, 22000));	
	myList.addLast(new Car("T01", "Toyota Camry 2.5", 2, 68000));	
	myList.display();
	cout<<"Number of cars: "<<myList.count()<<endl;
	int xColor;
	cout<<"Input color to count: "; cin>>xColor;
	cout<<"Number of cars with color as "<<xColor<<": "
		<<myList.countByColor(xColor)<<endl;
	myList.addFromTheKeyboard();
	myList.display();	
	
	return 0;
}
