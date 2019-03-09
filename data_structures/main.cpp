// Main function to test all self developed data structures

#include "hashtable.h"


int main(){
	
	HashTable ht(5);
	ht.insert(123, "hi");
	ht.insert(20, "abc");
	ht.insert(422, "aa");
	ht.insert(224, "qs");
	ht.insert(323, "p1");

	ht.get(123);
	ht.get(422);
	ht.get(323);
	ht.get(21);
}