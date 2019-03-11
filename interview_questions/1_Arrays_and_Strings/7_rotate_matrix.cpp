// Rotate an image matrix 90 degree

/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

/* HINTS
Try thinking about it layer by layer. Can you rotate a specific layer?

Rotating a specific layer would just mean swapping the values in four arrays.
If you were asked to swap the values in two arrays,
could you do this? Can you then extend it to four arrays?
*/

#include <iostream>
class Matrix{

public:
	Matrix(){
		size_ = 3;
		matrix_ = new int[size_ * size_];
		for(int i = 0; i < size_ * size_; i++){
			matrix_[i] = i + 1;
		}
	}

	void rotateMatrixBy90(){
		int * new_matrix = new int[size_ * size_];
		for(int j = 0; j < size_; j++){
			for(int i = size_ - 1; i >= 0; i--){
				new_matrix[j * size_ + size_ - 1 - i] = getElement(i,j);
			}
		}
		matrix_ = new_matrix;
	}

	void rotateMatrixBy90InPlace(){
		for(int j = 0; j < size_; j++){
			for(int i = size_ - 1; i >= 0; i--){
				matrix_[j * size_ + size_ - 1 - i] = getElement(i,j);
			}
		}
		matrix_ = new_matrix;
	}

	void printMatrix(){

		for(int i = 0; i < size_; i++){
			for(int j = 0; j < size_; j++){
				std::cout << getElement(i,j) << " ";
			}
			std::cout << std::endl;
		}
	}

	int getElement(const int i, const int j){
		return matrix_[j + i * size_];
	}
private:
	int * matrix_;
	int size_;
};


int main(){
		
	Matrix m;
	m.printMatrix();
	m.rotateMatrixBy90();
	m.printMatrix();
	return 0;
}

/*
1 2 3     7 4 1
4 5 6  -> 8 5 2
7 8 9     9 6 3
*/