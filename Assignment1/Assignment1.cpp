#include <iostream>
#include "ShoppingList.h"

using namespace std;
using std::vector;

int main() {
	
	ShoppingList sl1(1,20);
	Product p1(1, "bread", 2, true);
	Product p2(2, "egg", 6, true);
	Product p3(3, "milk", 1, false);
	Product p4(4, "water", 1, true);
	Product p5(5, "soda", 3, false);
	Product p6(3, "pasta", 1, false);
	sl1.insert(p1);
	sl1.insert(p2);
	sl1.insert(p3);
	sl1.insert(p4);
	sl1.insert(p5);
	sl1.insert(p6);

	sl1.checkBought(4);
	sl1.checkBought(6);
	
	sl1.printAll();

	sl1.printShoppingList();
	
}
