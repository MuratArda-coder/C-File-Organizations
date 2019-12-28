#include<iostream>

#include "lq.h"

using namespace std;

void printTable(LQ table) {
	
}

int main() {
	cout<<"LINEAR QUOTIENT TABLE"<<endl;
	
	int keys[] = {27,18,29,28,39,13,16,42,17};
	
	cout<<"My Liner Quotient Table"<<endl;
	
	LQ L(11);
	cout<<"Inserting.."<<endl;
	for(int i=0;keys[i]!='\0';i++) {
		L.insert(keys[i]);
		cout<<keys[i]<<" is inserted"<<endl;
	}
	cout<<"index\tkeys\t"<<endl;
	for(int i=0;i<11;i++) {
		cout<<i<<"\t";
		cout<<L.data_vec[i].data<<"\n";
	}
	for(int i=0;keys[i]!='\0';i++){
		int key = keys[i];
		cout<<"keys:"<<key<<"\t"<<"probes:"<<L.find_num_probes(key)<<endl;
	}
	cout<<"average number of probes:"<<L.find_average_num_probes()<<endl;
	
	cout<<"does include 42:"<<L.does_include(42)<<endl;
	cout<<"does include 17:"<<L.does_include(17)<<endl;
	cout<<"does include 15:"<<L.does_include(15)<<endl;
	
	return 0;
}
