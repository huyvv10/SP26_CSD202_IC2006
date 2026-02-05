#include <iostream>
#include <stack>
using namespace std;
//Convert n from Decimal to Binary
void decToBin(int n) {
	if (n==0) {
		cout<<"0";
		return;
	}
	stack<int> st;
	while (n!=0){
		st.push(n%2);
		n = n/2;
	}
	while (!st.empty()){
		cout<<st.top();
		st.pop();
	}
}
int main(){
	int n;
	cout<<"Input n = "; cin>>n;
	decToBin(n);	
	return 0;
}
