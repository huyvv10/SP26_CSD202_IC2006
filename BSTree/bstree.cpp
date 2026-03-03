#include <iostream>
#include <queue>

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

		int countNodesBFS(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;
		}		
		void breadthFirstTraversal(Node* xRoot){
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				visit(p);
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}
		}
		
		//Count all nodes as leaf nodes - external nodes
		int countAllLeafNodes(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				if (p->left==nullptr && p->right==nullptr)
					count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;		
		}
		
		//Return number of internal nodes.
		int countInternalNodes(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				if (p->left!=nullptr || p->right!=nullptr)
					count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;			
		}
		
		//Return number of nodes which only has left subtree
		int countNodesHasOnlyLeftChild(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				if (p->left!=nullptr && p->right==nullptr)
					count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;
		}

		//Return number of nodes which only has right subtree
		int countNodesHasOnlyRightChild(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				if (p->left==nullptr && p->right!=nullptr)
					count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;
		}		

		//Return number of nodes which have two children
		int countNodesHaveTwoChildren(Node* xRoot){
			int count=0;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				if (p->left!=nullptr && p->right!=nullptr)
					count++;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}			
			return count;
		}	
		
		//Return the maximum node - The right most node.
		Node* findTheRightMostNode(Node* xRoot){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			while (p->right!=nullptr){
				p=p->right;
			}
			return p;
		}	

		//Return the minimum node - The left most node.
		Node* findTheLeftMostNode(Node* xRoot){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			while (p->left!=nullptr){
				p=p->left;
			}
			return p;
		}		
		
		Node* deleteByCopyingLeft(Node* xRoot, int x){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			if (x < p->info){
				p->left=deleteByCopyingLeft(p->left, x);
			} else if (x > p->info){
				p->right = deleteByCopyingLeft(p->right, x);
			} else {	
				if (xRoot->left==nullptr)
					return xRoot->right;
				if (xRoot->right==nullptr)
					return xRoot->left;				
				Node* copyNode = findTheRightMostNode(p->left);
				xRoot->info = copyNode->info;
				xRoot->left = deleteByCopyingLeft(xRoot->left, copyNode->info);				
			}
			return xRoot;
		}
		
		//Delete by copying following the right subtree
		Node* deleteByCopyingRight(Node* xRoot, int x){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			if (x < p->info){
				p->left=deleteByCopyingRight(p->left, x);
			} else if (x > p->info){
				p->right = deleteByCopyingRight(p->right, x);
			} else {	
				if (xRoot->left==nullptr)
					return xRoot->right;
				if (xRoot->right==nullptr)
					return xRoot->left;				
				Node* copyNode = findTheLeftMostNode(p->right);
				xRoot->info = copyNode->info;
				xRoot->right = deleteByCopyingRight(xRoot->right, copyNode->info);				
			}
			return xRoot;
		}
		
		//Delete by merging follwowing the left subtree - default
		Node* deleteByMerging(Node* xRoot, int x){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			if (x < p->info){
				p->left=deleteByMerging(p->left, x);
			} else if (x > p->info){
				p->right = deleteByMerging(p->right, x);
			} else {	
				if (xRoot->left==nullptr)
					return xRoot->right;
				if (xRoot->right==nullptr)
					return xRoot->left;				
				Node* mergeNode = findTheRightMostNode(xRoot->left);
				mergeNode->right=xRoot->right;
				return xRoot->left;			
			}
			return xRoot;			
		}
		
		//Delete by merging follwowing the right subtree.
		Node* deleteByMergingRight(Node* xRoot, int x){
			if (xRoot==nullptr) return nullptr;
			Node* p = xRoot;
			if (x < p->info){
				p->left=deleteByMergingRight(p->left, x);
			} else if (x > p->info){
				p->right = deleteByMergingRight(p->right, x);
			} else {	
				if (xRoot->left==nullptr)
					return xRoot->right;
				if (xRoot->right==nullptr)
					return xRoot->left;				
				Node* mergeNode = findTheLeftMostNode(xRoot->right);
				mergeNode->left=xRoot->left;
				return xRoot->right;			
			}
			return xRoot;		
		}
		
		int countPre=0;
		Node* resultPre=nullptr;
		//Return node theK when traversal by preorder
		Node* findNodeTheKPreOrder(Node* xRoot, int theK){
			if (xRoot==nullptr) return nullptr;
			countPre++;
			if (countPre==theK){
				resultPre=xRoot;
			}
			xRoot->left=findNodeTheKPreOrder(xRoot->left, theK);
			xRoot->right=findNodeTheKPreOrder(xRoot->right, theK);
			return resultPre;
		}
		int countIn=0;
		Node* resultIn=nullptr;		
		//Return node theK when traversal by InOrder
		Node* findNodeTheKInOrder(Node* xRoot, int theK){
			if (xRoot==nullptr) return nullptr;
			xRoot->left=findNodeTheKInOrder(xRoot->left, theK);
			countIn++;
			if (countIn==theK){
				resultIn=xRoot;
			}
			xRoot->right=findNodeTheKInOrder(xRoot->right, theK);
			return resultIn;		
		}

		int countPost=0;
		Node* resultPost=nullptr;			
		//Return node theK when traversal by PostOrder
		Node* findNodeTheKPostOrder(Node* xRoot, int theK){
			if (xRoot==nullptr) return nullptr;
			xRoot->left=findNodeTheKPostOrder(xRoot->left, theK);
			xRoot->right=findNodeTheKPostOrder(xRoot->right, theK);
			countPost++;
			if (countPost==theK){
				resultPost=xRoot;
			}
			return resultPost;		
		}
		
		//Return node theK when traversal by Breadth First Order
		Node* findNodeTheKBreadthFirstOrder(Node* xRoot, int theK){
			int count=0;
			Node* result=nullptr;
			queue<Node*> myQ;
			myQ.push(xRoot);
			while (!myQ.empty()){
				Node* p = myQ.front();
				myQ.pop();
				count++;
				if (count==theK){
					result=p; break;
				}
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);	
			}	
			return result;	
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
	cout<<"Number of nodes BFS: "<<myT.countNodesBFS(myT.root)<<endl;
	cout<<"Number of leaf nodes: "<<myT.countAllLeafNodes(myT.root)<<endl;
	cout<<"Number of internal nodes: "<<myT.countInternalNodes(myT.root)<<endl;
	cout<<"Number of nodes only have left subtree: "<<myT.countNodesHasOnlyLeftChild(myT.root)<<endl;
	cout<<"Number of nodes only have right subtree: "<<myT.countNodesHasOnlyRightChild(myT.root)<<endl;
	cout<<"Number of nodes have two children: "<<myT.countNodesHaveTwoChildren(myT.root)<<endl;
	cout<<"---BFS---"<<endl;
	myT.breadthFirstTraversal(myT.root);
	cout<<"\n---Delete by copying---"<<endl;
//	myT.root = myT.deleteByCopyingLeft(myT.root, 10);	//default for PE
//	myT.root = myT.deleteByCopyingRight(myT.root, 10);	//Tham kham
//	myT.breadthFirstTraversal(myT.root);
	cout<<"\n---Delete by merging---"<<endl;
//	myT.root = myT.deleteByMerging(myT.root, 15);	//default
//	myT.root = myT.deleteByMergingRight(myT.root, 15);
//	myT.breadthFirstTraversal(myT.root);

	cout<<"\nFind node:"<<endl;
	Node* nodePre = nullptr;
	nodePre =myT.findNodeTheKPreOrder(myT.root, 5);
	cout<<nodePre->info<<endl;
	
	cout<<"\nFind node BFS:"<<endl;
	Node* nodeBFS = nullptr;
	nodeBFS=myT.findNodeTheKBreadthFirstOrder(myT.root, 5);
	cout<<nodeBFS->info<<endl;
	
	return 0;
}
