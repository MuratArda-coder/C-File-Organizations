#include<iostream>
#include "computed_chaining.h"

using namespace std;

int main() {
	
	int keys[] = {94,61,14,22,52,34,35,81,28,17,16};
	//int keys[] = {3,14,25,36,5};
	
	cout<<"My computed_chaining Table"<<endl;
	
	ComputedChaining CC(11);
	int size=11;
	for(int i=0;i<size;i++) {
		CC.insert(keys[i]);
		
		cout<<"/////////////////////////"<<endl;
		cout<<"key : "<<keys[i]<<" is inserted!!!"<<endl;
		for(int j=0;j<11;j++) {
			cout<<j<<"\t";
			cout<<CC.data[j].key<<"\t";
			cout<<CC.data[j].plink<<"\n";
		}
		cout<<"/////////////////////////"<<endl;
	}
	cout<<"index\tkeys\tlink\t"<<endl;
	for(int i=0;i<11;i++) {
		cout<<i<<"\t";
		cout<<CC.data[i].key<<"\t";
		cout<<CC.data[i].plink<<"\n";
	}

	
	
	return 0;
}
