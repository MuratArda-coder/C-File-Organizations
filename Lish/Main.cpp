#include<iostream>

#include "lisch.h"

using namespace std;

int main() {
	
	int keys[] = {58,60,35,68,6,53,19,10,43,21,32};
	
	cout<<"My Lish Table"<<endl;
	
	LISCH L(11);
	
	for(int i=0;i<11;i++)
		L.insert(keys[i]);
	cout<<"index\tkeys\tlink\t"<<endl;
	for(int i=0;i<11;i++) {
		cout<<i<<"\t";
		cout<<L.data_vec[i].data<<"\t";
		cout<<L.data_vec[i].link<<"\n";
	}
	for(int i=0;i<11;i++){
		int key = keys[i];
		cout<<"keys:"<<key<<"\t"<<"probes:"<<L.find_num_probes(key)<<endl;
	}
	cout<<"average number of probes:"<<L.find_average_num_probes()<<endl;
	
	cout<<"does include 21:"<<L.does_include(21)<<endl;
	cout<<"does include 37:"<<L.does_include(37)<<endl;
	
	return 0;
}
