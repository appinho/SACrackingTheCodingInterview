// Own implemented Array class

#ifndef ARRAY
#define ARRAY

#include <iostream>

template< class T>
class Array{

public:
	Array(){

	}	
	Array(const int size){
		size_ = size;
		buffer_ = new T[size];
	}

	Array(const int size, const T value){
		size_ = size;
		buffer_ = new T[size];
		for(int i = 0; i < size; i++){
			buffer_[i] = value;
		}
	}

	T operator [] (int index) const{
		return buffer_[index];
	}

	void print_array(){
		for(int i = 0; i < size_; i++){
			std::cout << buffer_[i] << " ";
		}
		std::cout << std::endl;
	}

	T get_element_at(const int index){
		if(index < 0 || index >= size_){
			T default_value;
			return default_value;
		}
		return buffer_[index];
	}

	int size(){
		return size_;
	}

private:
	T * buffer_;
	int size_;
};

#endif
