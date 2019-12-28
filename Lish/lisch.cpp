#include "lisch.h"


LISCH::LISCH(int table_size){
	data_vec.resize(table_size);
	for(int i = 0;i<data_vec.size();i++) {
		data_vec[i] = lisch_entry();
		data_vec[i].link = -1;//means no link :empty
	}
}


void LISCH::insert(int new_data){
	int hashKey;
	hashKey = new_data%data_vec.size();
	if(data_vec[hashKey].valid == false) {
		data_vec[hashKey].data = new_data;
		data_vec[hashKey].valid = true;
		data_vec[hashKey].link = -1;
	}
	else {
		for(int i = data_vec.size()-1 ;i>=0;i--) {	
			if(data_vec[i].valid == false) {
				data_vec[i].data = new_data;
				data_vec[i].valid = true;
				if(data_vec[hashKey].link == -1)
					data_vec[hashKey].link = i;
				else {
					while(true) {
						hashKey = data_vec[hashKey].link;
						if(data_vec[hashKey].link == -1){
							data_vec[hashKey].link = i;
							break;
						}
					}
				}
				break;
			}
		}
	}
}



int LISCH::find_num_probes(int key) const{
	int prob = 1;
	int hashKey = key%data_vec.size();
	if(data_vec[hashKey].data == key)
		return prob;
	while(data_vec[hashKey].link != -1 || prob>data_vec.size()) {
		prob++;
		hashKey = data_vec[hashKey].link;
		if(data_vec[hashKey].data == key)
			return prob;
	}
	return 0;
}



double LISCH::find_average_num_probes() const{
	int prob = 0;
	int count = 0;
	for(int i = 0;i<data_vec.size();i++) {
		if(data_vec[i].valid == true)  {
			prob += find_num_probes(data_vec[i].data);	
			count++;
		}
	}
	return (double)prob/(double)count;
}


bool LISCH::does_include(int key) const{
	int hashKey = key%data_vec.size();
	if(data_vec[hashKey].data == key)
		return true;
	while(data_vec[hashKey].link != -1) {
		hashKey = data_vec[hashKey].link;
		if(data_vec[hashKey].data == key)
			return true;
	}
	return false;
}
