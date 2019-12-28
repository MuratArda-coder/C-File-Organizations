#include "brent.h"


Brent::Brent(int table_size){
	data_vec.resize(table_size);
	for(int i=0;i<table_size;i++) {
		data_vec[i] = entry();
		data_vec[i].data = -1;
	}
}

int Brent::h1(int key) const {//adress
	return key%data_vec.size();
}

int Brent::h2(int key) const{//increment
	return key/data_vec.size();
}

int Brent::find_moving_cost(int i,int j) const{ //i = data j = increment
	int cost = 1;
	int adress = h1(i);
	while(data_vec[adress].valid != false && cost!=data_vec.size()*4) {
		cost++;
		adress = h1(adress+j);
	}
	return cost;
}

void Brent::insert(int new_data){
	int adress = new_data%data_vec.size();
	int increment =  new_data/data_vec.size();
	if(data_vec[adress].valid == false) {
		data_vec[adress].valid = true;
		data_vec[adress].data = new_data;
	}
	else {
		int step = find_moving_cost(new_data,increment);
		int i=1;
		for(int n=1;n<=step;n++) {
			for(int j=n;j>0;j--) {
				int next_adress = (adress+(increment*(i-1))) % data_vec.size();
				int next_increment = data_vec[next_adress].data/data_vec.size();
				
				if(data_vec[(next_adress+(next_increment*j))%data_vec.size()].valid == false && step>i+j) {
					data_vec[(next_adress+(next_increment*j))%data_vec.size()].data = data_vec[next_adress].data;
					data_vec[(next_adress+(next_increment*j))%data_vec.size()].valid = true;
					data_vec[next_adress].data = new_data;
					return;
				}
				if(i+j<=step) {
					break;
				}
				i++;
			}
			i=1;
		}
		data_vec[(adress+(increment*(step-1)))%data_vec.size()].data = new_data;
		data_vec[(adress+(increment*(step-1)))%data_vec.size()].valid = true;
	}

}



int Brent::find_num_probes(int key) const{
	int prob = 1;
	int adress = key%data_vec.size();
	int increment =  key/data_vec.size();
	if(data_vec[adress].data == key) {
		return prob;
	}
	else {
		while(data_vec[adress].data != key) {
			prob++;
			adress=(adress+increment)%data_vec.size();
		}
		int step = prob;
		int i=1;
		for(int n=1;n<=step;n++) {
			for(int j=n;j>0;j--) {
				int next_adress = (adress+(increment*(i-1))) % data_vec.size();
				int next_increment = data_vec[next_adress].data/data_vec.size();
				
				if(data_vec[(next_adress+(next_increment*j))%data_vec.size()].data == key && step>i+j) {
					prob = i+j;
					return prob;
				}
				if(i+j<=step) {
					break;
				}
				i++;
			}
			i=1;
		}
		return prob;
	}
}

double Brent::find_average_num_probes() const{
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
