#pragma once
class Vector
{
private:
	int* data;//A pointer to an array of integers
	int capacity;//The length of the vector
	int size;//The number of values actually in the vector
public:
	Vector(int num = 2);//constructor
	Vector(const Vector& temp);//copy constructor
	~Vector();//destructor
	int getCapacity();//Returning the length of the vector
	int getSize();//Returning the number of values in the vector
	void print();//Data printing
	void assign(Vector vec);//A method that functions as an = operator
	bool isEqual(Vector vec);//A method that functions as an == operator
	int& at(int index);//A method that functions as an [] operator
	int scalmul(Vector vec);//A method that performs scalar multiplication
	Vector strnewcat(Vector vec1);//A method that concatenates 2 vectors
	void clear();//A method that empties the vector
	void delLast();//A method that deletes the last member of a vector
	void insert(int val);//A method that places the value in the next free position in the array
};

