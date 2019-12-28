#include "lq.h"


LQ::LQ(int table_size){
	data_vec.resize(table_size);
	for(int i=0;i<table_size;i++) {
		data_vec[i] = lq_entry();
		data_vec[i].data = -1;
	}	
}


void LQ::insert(int new_data){
	int hashKey = new_data%data_vec.size();
	int increment = new_data/data_vec.size();
	int initial_hashKey = hashKey;
	if(data_vec[hashKey].valid == false) {
		data_vec[hashKey].data = new_data;
		data_vec[hashKey].valid = true;
	}
	else {
		hashKey = (hashKey+increment)%data_vec.size();
		while(data_vec[hashKey].valid == true && hashKey != initial_hashKey) {
			hashKey = (hashKey+increment)%data_vec.size();
		}
		if(hashKey == initial_hashKey) {
			return;
		}
		else {
			data_vec[hashKey].data = new_data;
			data_vec[hashKey].valid = true;
		}
	}
}



int LQ::find_num_probes(int key) const{
	int prob = 1;
	int hashKey = key%data_vec.size();
	int increment = key/data_vec.size();
	int initial_hashKey = hashKey;
	if(data_vec[hashKey].data == key){
		return prob;
	}
	else {
		hashKey = (hashKey+increment)%data_vec.size();
		while(hashKey != initial_hashKey) {
			prob++;
			if(data_vec[hashKey].data == key) {
				return prob;
			}
			hashKey = (hashKey+increment)%data_vec.size();
		}
		if(hashKey == initial_hashKey) {
			return 0;
		}
	}
}



double LQ::find_average_num_probes() const{
	int prob = 0;
	int count = 0;
	for(int i = 0;i<data_vec.size();i++){
		if(data_vec[i].valid == true) {
			prob += find_num_probes(data_vec[i].data);
			count++;
		}
	}
	return (double)prob/(double)count;
}

bool LQ::does_include(int key) const{
	int hashKey = key%data_vec.size();
	int increment = key/data_vec.size();
	int initial_hashKey = hashKey;
	if(data_vec[hashKey].data == key) {
		return true;
	}
	else {
		hashKey = (hashKey+increment)%data_vec.size();
		while(hashKey != initial_hashKey) {
			if(data_vec[hashKey].data == key) {
				return true;
			}
			hashKey = (hashKey+increment)%data_vec.size();
		}
		return false;
	}
}
