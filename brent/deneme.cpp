#include<iostream>
using namespace std;

int a=2;

void *f(void *key) {
	
	int *x = (int*) key;
	a = *x;
}


int main() {
	
	int k = 5;
	int u = 600;
	
	cout<<a<<endl;
	f(&k);
	cout<<a<<endl;
	
	return 0;
} 
