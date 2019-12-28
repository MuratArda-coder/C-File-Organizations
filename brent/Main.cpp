#include<iostream>

#include "brent.h"

using namespace std;



int main() {
	
	cout<<"Brent’s Method TABLE"<<endl;
	
	int keys[] = {27,18,29,28,39,13,16,42,17};
	
	cout<<"MyBrent’s Method Table"<<endl;
	
	Brent B(11);
	cout<<"Inserting..."<<endl;
	for(int i=0;i<9;i++) {
		B.insert(keys[i]);
		cout<<keys[i]<<" is inserted"<<endl;
		cout<<"//////////////////////////////"<<endl;
		for(int i=0;i<11;i++) {
			cout<<i<<"\t";
			cout<<B.data_vec[i].data<<"\n";
		}
		cout<<"//////////////////////////////"<<endl;
	}
	cout<<"index\tkeys\t"<<endl;
	for(int i=0;i<11;i++) {
		cout<<i<<"\t";
		cout<<B.data_vec[i].data<<"\n";
	}
	for(int i=0;keys[i]!='\0';i++){
		int key = keys[i];
		cout<<"keys:"<<key<<"\t"<<"probes:"<<B.find_num_probes(key)<<endl;
	}
	cout<<"average number of probes:"<<B.find_average_num_probes()<<endl;
	
	return 0;
}
