#include "Classroom.h"


Classroom::Classroom(int i,int cap){
	capacity = cap;
	id = i;
}
		
void Classroom::insert(Student s){
	students.push_back(s);
}
// you can see vector at() approach here.
// Speed MID
void Classroom::update(Student s){
	
	for(int i = 0;i<students.size();i++) {
		if(students.at(i).id==s.id) {
			students.at(i).name = s.name;
			students.at(i).valid = s.valid;
			break;
		}
	}
}
// you can see vector iterator approach here.
// Speed MAX
void Classroom::printClass(){
	cout << "Capacity of the course with ID "<< id << " is:" << capacity << endl;
	cout << "Students are:" << endl;
	vector<Student>::iterator ptr;
	for(ptr = students.begin();ptr<students.end();ptr++) {
		cout<< "ID:" << ptr->id << " Name:" << ptr->name << endl;
	}
}
// you can see vector array approach here.
// Speed MIN
Student Classroom::search(int sid){
	for(int i = 0;i<students.size();i++) {
		if(students[i].id==sid) {
			return students[i];
		}
	}
	Student s1("There is no user like this",-1);
	return s1;
}

Student Classroom::searchValid(int sid){
	for(int i = 0;i<students.size();i++) {
		if(students[i].id==sid && students[i].valid == 1 ) {
			return students[i];
		}
	}
	Student s1("There is no user like this",-1);
	return s1;
}


