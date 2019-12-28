#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;

class Product{
	
	public:
		int id;
		string name;
		int amount;
		bool priority;
		bool bought;
	public:
		Product(int i,string n,int a,bool p) {
			id = i;
			name = n;
			amount = a;
			priority = p;
			bought = false;
		}
		
};

class ShoppingList {
	
	public:
		int id;
		int size;
		vector<Product> products;
	public:
		ShoppingList(int,int);
		int insert(Product);
		void printAll();
		void printShoppingList();
		int checkBought(int);
	
};
