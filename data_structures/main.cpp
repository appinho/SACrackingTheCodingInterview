// Main function to test all self developed data structures

#include "array.h"
#include "linked_list.h"
#include "hashtable.h"

#include <string>

int main(){
	
	Array<std::string> a(20, "ha");
	a.print_array();
	std::string s = a.get_element_at(12);
	s = a.get_element_at(23);

	LinkedList<int> ll;
	ll.push_back(2);
	ll.push_back(5);
	ll.print_list();
	ll.print_size();

	HashTable<int, std::string> ht(5);
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