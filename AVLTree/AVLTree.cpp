#include <iostream>
#include <queue>

using namespace std;
class Node {
	public:
		int info;
		int height;
		Node *left, *right;
		Node(int _info) {
			this->info=_info;
			this->height=1;
			this->left=nullptr;
			this->right=nullptr;
		}
};

class AVLTree {
	public:
		Node* root;

		AVLTree() {
			this->root=nullptr;
		}

		~AVLTree() {}

		bool isEmpty() {
			return this->root==nullptr;
		}

		int getHeight(Node* xRoot) {
			if (xRoot==nullptr) return 0;
			return xRoot->height;
		}

		int getBalance(Node* xRoot) {
			if (xRoot==nullptr) return 0;
			return getHeight(xRoot->left) - getHeight(xRoot->right);
		}

		Node* rightRotation(Node* xRoot) {
			Node* k = xRoot->left;
			xRoot->left = k->right;
			k->right = xRoot;
			return k;
		}

		Node* leftRotation(Node* xRoot) {
			Node* k = xRoot->right;
			xRoot->right = k->left;
			k->left = xRoot;
			return k;
		}

		Node* addAVLNode(Node* xRoot, int x) {
			if (xRoot==nullptr) return new Node(x);
			if (x < xRoot->info) {
				xRoot->left = addAVLNode(xRoot->left, x);
			} else if (x > xRoot->info) {
				xRoot->right = addAVLNode(xRoot->right, x);
			} else
				return xRoot;
			xRoot->height = max(getHeight(xRoot->left), getHeight(xRoot->right))+1;
			int balanceFactor = getBalance(xRoot);
			//Left subtree is heavier
			if (balanceFactor>1) {
				//Case 1
				if (x < xRoot->left->info)
					return rightRotation(xRoot);
				//Case 3
				if (x > xRoot->left->info) {
					xRoot->left=leftRotation(xRoot->left);
					return rightRotation(xRoot);
				}
			} else if (balanceFactor<-1) {
				//Case 2
				if (x > xRoot->right->info)
					return leftRotation(xRoot);
				//Case 4
				if (x < xRoot->right->info) {
					xRoot->right=rightRotation(xRoot->right);
					return leftRotation(xRoot);
				}
			}
			return xRoot;
		}

		//Return the maximum node - The right most node.
		Node* findTheRightMostNode(Node* xRoot) {
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			while (p->right!=nullptr) {
				p=p->right;
			}
			return p;
		}

		//Return the minimum node - The left most node.
		Node* findTheLeftMostNode(Node* xRoot) {
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			while (p->left!=nullptr) {
				p=p->left;
			}
			return p;
		}

		Node* deleteByCopyingLeft(Node* xRoot, int x) {
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			if (x < p->info) {
				p->left=deleteByCopyingLeft(p->left, x);
			} else if (x > p->info) {
				p->right = deleteByCopyingLeft(p->right, x);
			} else {
				if (xRoot->left==nullptr)
					return xRoot->right;
				if (xRoot->right==nullptr)
					return xRoot->left;
				Node* copyNode = findTheRightMostNode(p->left);
				xRoot->info = copyNode->info;
				xRoot->left = deleteByCopyingLeft(xRoot->left, copyNode->info);
				
				//Balance the tree
				xRoot->height = max(getHeight(xRoot->left), getHeight(xRoot->right))+1;
				int balanceFactor = getBalance(xRoot);
				//Left subtree is heavier
				if (balanceFactor>1) {
					//Case 1
					if (x < xRoot->left->info)
						return rightRotation(xRoot);
					//Case 3
					if (x > xRoot->left->info) {
						xRoot->left=leftRotation(xRoot->left);
						return rightRotation(xRoot);
					}
				} else if (balanceFactor<-1) {
					//Case 2
					if (x > xRoot->right->info)
						return leftRotation(xRoot);
					//Case 4
					if (x < xRoot->right->info) {
						xRoot->right=rightRotation(xRoot->right);
						return leftRotation(xRoot);
					}
				}
			}
			return xRoot;
		}

		void visit(Node* xRoot) {
			if (xRoot==nullptr) return;
			cout<<xRoot->info<<" ";
		}

		void breadthFirstTraversal(Node* xRoot) {
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()) {
				Node* p = myQ.front();
				myQ.pop();
				visit(p);
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
			}
		}


};

int main() {
	AVLTree myAVL;
	myAVL.root = myAVL.addAVLNode(myAVL.root, 15);
	myAVL.root = myAVL.addAVLNode(myAVL.root, 8);
	myAVL.root = myAVL.addAVLNode(myAVL.root, 22);
	myAVL.root = myAVL.addAVLNode(myAVL.root, 10);
	myAVL.root = myAVL.addAVLNode(myAVL.root, 13);
	myAVL.root = myAVL.addAVLNode(myAVL.root, 5);
	myAVL.breadthFirstTraversal(myAVL.root);
	cout<<endl;
	myAVL.root = myAVL.deleteByCopyingLeft(myAVL.root, 10);
	myAVL.breadthFirstTraversal(myAVL.root);	
	cout<<endl;
	return 0;
}