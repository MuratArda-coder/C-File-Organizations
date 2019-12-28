#include "computed_chaining.h"
#include <assert.h>

#include<iostream>
using namespace std;

using std::vector;

ComputedChaining::ComputedChaining(int size) {
		data.resize(size);
		for(int i=0;i<size;i++) {
			data[i] = entry();
			data[i].plink = -1;
			data[i].key = -1;
		}
}

int ComputedChaining::h1(int key) {
	return key%data.size();
}

int ComputedChaining::h2(int key) {
	if (key<data.size())
		return 1;
	return key/data.size();
}


void ComputedChaining::insert(int key) {
	int addr = h1(key);
	int inc = h2(key);
	
	if(data[addr].valid == false) {
		data[addr].key = key;
		data[addr].valid = true;
	}
	else if(h1(data[addr].key) == addr) {
		while(true) {
			if(data[addr].plink == -1) {
				break;
			}
			//cout<<"addr: "<<addr<<" 	"<<"plink"<<data[addr].plink<<endl;
			addr = h1(h2(data[addr].key)*data[addr].plink+addr);
		}
		
		int dataInc = h2(data[addr].key);
		int pointAddr = addr;
		int count = 0;
		
		while(data[addr].valid == true) {
			addr = h1(addr+dataInc);
			count++;
		}
		//cout<<"addr:"<<addr<<endl;
		data[pointAddr].plink = count;
		data[addr].key = key;
		data[addr].valid = true;
		
	}
	else {
		int addrPre = h1(data[addr].key);
		while(data[h1(h2(data[addrPre].key)*data[addrPre].plink+addrPre)].key != data[addr].key) {
			addrPre = h1(h2(data[addrPre].key)*data[addrPre].plink+addrPre);
		}
		
		vector<int> memory;
		data[addrPre].plink = -1;
		memory.push_back(data[addr].key);
		
		data[addr].key = key;
		int oldAddr = addr;
		
		int count = 0;
		while(true) {
			if(data[addr].plink == -1) {
				break;
			}
			
			addr = h1(h2(memory[count])*data[addr].plink+addr);
			memory.push_back(data[addr].key);
			data[addr].key = -1;
			
			data[oldAddr].plink = -1;
			oldAddr = addr;
			data[oldAddr].valid = false;
			
			count++;
		}
		for(int i = 0;i<memory.size();i++) {
			cout<<"memory "<<i<<" :"<<memory[i]<<endl;;
		}
		
		for(int i = 0;i<memory.size();i++) {
			cout<<"re inserted :"<<memory[i]<<endl;;
			insert(memory[i]);
		}
	}


}


int ComputedChaining::remove(int pos) {


}
