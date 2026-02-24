#include <iostream>
using namespace std;
class Node{
	public:
		int info;
		Node *left, *right;
		Node(int _info){
			this->info=_info;
			this->left=nullptr;
			this->right=nullptr;
		}
};

class BSTree{
	public:
		Node* root;
		BSTree(){
			this->root=nullptr;
		}
		~BSTree(){}
		
		bool isEmpty(){
			return this->root==nullptr;
		}	
		
		void addNode(int x){
			Node* newNode = new Node(x);
			if (isEmpty()){
				this->root=newNode;
				return;
			}
			Node* p=this->root;
			while (p!=nullptr){
				if (newNode->info == p->info){
					cout<<x<<" already existed!"<<endl;
					delete newNode;
					return;
				}
				if (newNode->info < p->info){
					if (p->left==nullptr){
						p->left=newNode;
						return;
					} else {
						p=p->left;
					}
				} else {
					if (p->right==nullptr){
						p->right=newNode;
						return;
					} else {
						p=p->right;
					}
				}
			}
		}
		
		void visit(Node* xRoot){
			if (xRoot==nullptr) return;
			cout<<xRoot->info<<" ";
		}
		
		//visit G_L_R
		void preOrder(Node* xRoot){
			if (xRoot==nullptr) return;
			visit(xRoot);					//Visit root
			if (xRoot->left!=nullptr)
				preOrder(xRoot->left);		//Visit left subtree
			if (xRoot->right!=nullptr)
				preOrder(xRoot->right);		//Visit right subtree
		}
		
		//visit L_G_R
		void inOrder(Node* xRoot){
			if (xRoot==nullptr) return;
			if (xRoot->left!=nullptr)
				inOrder(xRoot->left);		//Visit left subtree
			visit(xRoot);					//Visit root
			if (xRoot->right!=nullptr)
				inOrder(xRoot->right);		//Visit right subtree			
		}
		//visit L_R_G
		void postOrder(Node* xRoot){
			if (xRoot==nullptr) return;
			if (xRoot->left!=nullptr)
				postOrder(xRoot->left);		//Visit left subtree
			if (xRoot->right!=nullptr)
				postOrder(xRoot->right);		//Visit right subtree			
			visit(xRoot);					//Visit root
		}
		
		//Count number of nodes within the tree
		int countNodes(Node* xRoot){
			int g=0, l=0, r=0;
			if (xRoot==nullptr) return 0;
			g++;					//Visit root
			if (xRoot->left!=nullptr)
				l=countNodes(xRoot->left);		//Visit left subtree
			if (xRoot->right!=nullptr)
				r=countNodes(xRoot->right);		//Visit right subtree	
			return g+l+r;						
		}
};

int main(){
	BSTree myT;
	myT.addNode(15);
	myT.addNode(10);
	myT.addNode(25);
	myT.addNode(7);
	myT.addNode(13);
	myT.addNode(20);
	myT.addNode(28);
	myT.addNode(4);
	myT.addNode(8);
	myT.addNode(11);
	myT.addNode(14);
	myT.addNode(26);
	myT.addNode(27);
	myT.addNode(12);
	cout<<"Pre_order traversal"<<endl;
	myT.preOrder(myT.root);
	cout<<"\nIn_order traversal"<<endl;
	myT.inOrder(myT.root);
	cout<<"\nPost_order traversal"<<endl;
	myT.postOrder(myT.root);
	cout<<endl;
	cout<<"Number of nodes: "<<myT.countNodes(myT.root)<<endl;
	return 0;
}
