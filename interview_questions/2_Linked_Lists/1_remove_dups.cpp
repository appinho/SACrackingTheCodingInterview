/*
Remove Dups: Write code to remove duplicates from an unsorted linked list. FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

/* HINTS
9 Have you tried a hash table? You should be able to do this in a single pass of the linked list.
40 Without extra space, you'll need time. Try using two pointers,
where the second one searches ahead of the first one.
*/

/*
Don't use it-- after erasing: http://www.cplusplus.com/reference/list/list/erase/
Difference between ++i and i++ https://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i
*/

#include <list>
#include <set>
#include <iostream>

using namespace std;

void removeDupsEasy(list<int> & l){

	l.sort();
	l.unique();
}

void removeDups(list<int> & l){

	set<int> buffer;
	for(list<int>::iterator it = l.begin(); it != l.end(); ++it){
		if(buffer.find(*it) == buffer.end()){
			buffer.insert(*it);
		}
		else{
			l.erase(it);
		}
	}
}

void removeDupsWithoutBuffer(list<int> & l){

	list<int>::iterator current = l.begin();
	while(current != l.end()){
		list<int>::iterator runner = current;
		++runner;
		while(runner != l.end()){
			if(*current == *runner){
				l.erase(runner);
			}
			++runner;
		}
		++current;
	}
	/*
	list<int>::iterator current = l.begin();
	for(list<int>::iterator current = l.begin(); current != l.end(); current++){
		list<int>::iterator runner = current;
		runner++;
		for(; runner != l.end(); runner++){
			if(*current == *runner){
				l.erase(runner);
			}
		}
	}
	*/
}

void printList(const list<int> & l){

	for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}
int main(){

	list<int> l({1,2,3,4,3,2,5,6,1,1,1,7,8,6,7,9,10});
	printList(l);
	removeDupsWithoutBuffer(l);
	printList(l);

	return 0;
}