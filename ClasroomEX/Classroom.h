#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;

class Student{
	public:
		int id;
		string name;
		bool valid;
	public:
		Student(string s, int i){
			id = i;
			name = s;
			valid = 1;
		}
};

class Classroom{
	public:
		int capacity;
		int id;
		vector<Student> students;
	public:
		Classroom(int,int);
		void insert(Student);
		Student search(int) ;
		void update(Student);
		void printClass();
		Student searchValid(int);
};
