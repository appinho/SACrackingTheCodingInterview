#ifndef NODE
#define NODE

template<typename V>
class Node{

public:
	Node(){
		next_ = nullptr;
	}
	Node(const Node & node){
		value_ = node.value_;
		next_ = node.next_;
	}
	Node(const V & value){
		value_ = value;
		next_ = nullptr;
	}

	V value_;
	Node * next_;
};

template<typename K, typename V>
class HashNode{

public:
	HashNode(){
		next_ = nullptr;
	}
	HashNode(const HashNode & node){
		value_ = node.value_;
		next_ = nullptr;
		key_ = node.key_;
	}
	HashNode(const K & key, const V & value){
		value_ = value;
		next_ = nullptr;
		key_ = key;
	}

	K key_;
	V value_;
	HashNode * next_;
};

#endif