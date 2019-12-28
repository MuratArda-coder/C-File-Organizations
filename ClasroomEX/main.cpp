#include <iostream>
#include <fstream>

#include "Classroom.h"

int main(){

	Classroom c1(1,30);
	Student s1("Yusuf",1);
	Student s2("Gökhan",2);

	c1.insert(s1);
	c1.insert(s2);

	c1.printClass();

	int id = 1;
	Student searched = c1.search(id);
	cout << "Searched:"<< id << "  Result=> " <<searched.id << "  " << searched.name << endl;	
	id = 7;
	searched = c1.search(id);
	cout << "Searched:"<< id << "  Result=>" <<searched.id << "  " << searched.name << endl;


	s1.name = "Yusuf Can";
	s1.valid = 0;
	c1.update(s1);

	id = 1;
	searched = c1.search(id);
	cout << "Searched:"<< id << "  Result=> " <<searched.id << "  " << searched.name << endl;

	id = 1;
	searched = c1.searchValid(id);
	cout << "Valid Searched:"<< id << "  Result=>" <<searched.id << "  " << searched.name << endl;



	return 0;
}