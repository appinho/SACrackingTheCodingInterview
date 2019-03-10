// Own implemented Linked List class

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

#include <iostream>

template <typename...> class LinkedList;

template<typename T>
class LinkedList<T>{

public:
	LinkedList(){
		root_ = new Node<T>();
	}

	void push_back(const Node<T> node){

		Node<T> * current = root_;

		while(current->next_ != nullptr){
			current = current->next_;
		}
		Node<T> * new_node = new Node<T>(node);
		current->next_ = new_node;
	}

	int size(){
		int size = 0;
		Node<T> * current = root_;
		while(current->next_ != nullptr){
			current = current->next_;
			size++;
		}
		return size;
	}

	Node<T> * begin(){
		Node<T> * front_node;
		if(root_->next_ != nullptr)
			front_node = root_->next_;
		return front_node;
	}

	T front(){
		return begin()->value_;
	}

	Node<T> * end(){
		Node<T> * current_node = root_;
		while(current_node->next_ != nullptr){
			current_node = current_node->next_;
		}
		return current_node;
	}

	void print_size(){
		std::cout << "Size of LL: " << size() << std::endl;
	}

	void print_list(){

		Node<T> * current = root_;
		std::cout << "root";
		while(current->next_ != nullptr){
			current = current->next_;
			std::cout << " -> " << current->value_;
		}
		std::cout << std::endl;
	}

private:
	Node<T> * root_;
};

template<typename K, typename V>
class LinkedList<K,V>{

public:
	LinkedList(){
		root_ = new HashNode<K,V>();
	}

	void push_back(const HashNode<K,V> node){

		HashNode<K,V> * current = root_;

		while(current->next_ != nullptr){
			current = current->next_;
		}
		HashNode<K,V> * new_node = new HashNode<K,V>(node);
		current->next_ = new_node;
	}

	int size(){
		int size = 0;
		HashNode<K,V> * current = root_;
		while(current->next_ != nullptr){
			current = current->next_;
			size++;
		}
		return size;
	}

	HashNode<K,V> * begin(){
		HashNode<K,V> * front_node;
		if(root_->next_ != nullptr)
			front_node = root_->next_;
		return front_node;
	}

	HashNode<K,V> * end(){
		HashNode<K,V> * current_node = root_;
		while(current_node->next_ != nullptr){
			current_node = current_node->next_;
		}
		return current_node;
	}

	void print_size(){
		std::cout << "Size of LL: " << size() << std::endl;
	}

	void print_list(){

		HashNode<K,V> * current = root_;
		std::cout << "root";
		while(current->next_ != nullptr){
			current = current->next_;
			std::cout << " -> " << current->value_;
		}
		std::cout << std::endl;
	}

private:
	HashNode<K,V> * root_;
};

#endif