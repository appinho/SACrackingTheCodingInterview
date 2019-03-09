// Own implemented Hast Table class
#include <string>
#include <vector>
#include <list>
#include <iostream>

const int N = 5;

using namespace std;

struct HashNode{
	int key_;
	string value_;

	HashNode(int key, string value){
		key_ = key;
		value_ = value;	
	}
};

class HashTable{

public:
	HashTable(){
		buffer_size_ = N;
		buffer_ = vector<list<HashNode>>(N,list<HashNode>());
	}

	HashTable(const long size){
		buffer_size_ = size;
		buffer_ = vector<list<HashNode>>(size,list<HashNode>());
	}

	void insert(const int key, const string value){
		int hash_key = computeHashKey(key);
		buffer_[hash_key].push_back(HashNode(key, value));
		cout << value << " generates hash key: "
			<< hash_key << endl;
	}

	void get(const int key){

		int hash_key = computeHashKey(key);
		if(buffer_[hash_key].size() == 1){
			cout << buffer_[hash_key].front().value_ << endl;
			return;
		}
		else{
			for(list<HashNode>::iterator it = buffer_[hash_key].begin();
				it != buffer_[hash_key].end(); ++it){
				if((*it).key_ == key){
					cout << (*it).value_ << endl;
					return;
				}
			}
		}
		cout << "No entry found" << endl;
	}

private:

	int computeHashKey(const int hash_code){
		return hash_code % buffer_size_;
	}

	int buffer_size_;
	vector<list<HashNode>> buffer_;
};