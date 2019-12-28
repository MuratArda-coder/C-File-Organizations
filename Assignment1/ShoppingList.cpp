#include "ShoppingList.h"
#include <algorithm>
using namespace std;
using std::vector;

bool shortByPrioritiy(Product &p1, Product &p2) {
	return (p1.priority > p2.priority);
}

ShoppingList::ShoppingList(int i,int s) {
	id = i;
	size = s;
}

int ShoppingList::insert(Product p) {
	vector<Product>::iterator ptr;
	for(ptr = products.begin();ptr<products.end();ptr++) {
		if(ptr->id == p.id) {
			cout<<"There is a product with the same id in the shopping list"<<endl;
			return 0;
		}
	}
	products.push_back(p);
	std::sort(products.begin(),products.end(),shortByPrioritiy);
	return 1;
}

void ShoppingList::printAll() {
	vector<Product>::iterator ptr;
	cout<<"id	name	amount	priority	bought"<<endl;
	for(ptr = products.begin();ptr<products.end();ptr++) {
		cout<<ptr->id<<"	";
		cout<<ptr->name<<"	";
		cout<<ptr->amount<<"	";
		/////////////////////////////////////////	
		if(ptr->priority == true)
			cout<<"high"<<"		";
		else
			cout<<"low"<<"		";
		/////////////////////////////////////////	
		if(ptr->bought == true)
			cout<<"+"<<"	";
		else
			cout<<"-"<<"	";
		/////////////////////////////////////////
		cout<<endl;
	}
}

void ShoppingList::printShoppingList() {
	vector<Product>::iterator ptr;
	cout<<"id	name	amount	priority	bought"<<endl;
	for(ptr = products.begin();ptr<products.end();ptr++) {
		if(ptr->bought == false) {
			cout<<ptr->id<<"	";
			cout<<ptr->name<<"	";
			cout<<ptr->amount<<"	";
			/////////////////////////////////////////
			if(ptr->priority == true)
				cout<<"high"<<"		";
			else
				cout<<"low"<<"		";
			/////////////////////////////////////////	
			cout<<"-"<<"	"<<endl;	
		}
	}	
}

int ShoppingList::checkBought(int id) {
	vector<Product>::iterator ptr;
	for(ptr = products.begin();ptr<products.end();ptr++) {
		if(ptr->id == id) {
			ptr->bought = true;
			return 1;
		}
	}
	cout<<"There is no product with that id"<<endl;
	return 0;
}






