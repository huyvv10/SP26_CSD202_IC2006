#include <iostream>
#include <algorithm>

using namespace std;
void inputArr(int a[], int n) {
	for(int i=0; i<n; i++) {
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}

void display(int a[], int n) {
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void displayReverse(int a[], int n) {
	for (int i=n-1; i>=0; i--)
		cout<<a[i]<<" ";
	cout<<endl;
}
void calculate(int a[], int n) {
	int S=0, S1=0, S2=0;
	for(int i=0; i<n; i++) {
		cout<<a[i]<<" ";
		S+=a[i];
	}
	cout<<S<<endl;
	for(int i=0; i<n; i++) {
		if(a[i]%2==1) {
			cout<<a[i]<<" ";
			S1+=a[i];
		}
	}
	cout<<S1<<endl;
	for(int i=0; i<n; i++) {
		if(a[i]%2==0) {
			cout<<a[i]<<" ";
			S2+=a[i];
		}
	}
	cout<<S2<<endl;
}

bool isPrime(int n){
	if (n<2) return false;
	for (int i=2; i*i<=n; i++)
		if (n%i==0) return false;
	return true;	
}

void listPrime(int a[], int n){
	int S=0;
	for (int i=0; i<n; i++)
		if (isPrime(a[i])){
			cout<<a[i]<<" ";
			S+=a[i];
		}
	cout<<"\n"<<S<<endl;	
}
//Bubble sort
void sortAsc(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--){
			if (a[j]<a[j-1]){
				int tg=a[j]; a[j]=a[j-1]; a[j-1]=tg;
			}
		}
}
//Bubble sort
void sortDesc(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--){
			if (a[j]>a[j-1]){
				int tg=a[j]; a[j]=a[j-1]; a[j-1]=tg;
			}
		}
}
int main() {
	int n;
	cout<<"Input n = ";
	cin>>n;
	int arr[n];

	inputArr(arr,n);
	display(arr,n);
	displayReverse(arr,n);
	calculate(arr,n);
	listPrime(arr,n);
//	sort(arr,arr+n);
	sortAsc(arr,n);
	display(arr,n);
	sortDesc(arr,n);
	display(arr,n);
	return 0;
}
