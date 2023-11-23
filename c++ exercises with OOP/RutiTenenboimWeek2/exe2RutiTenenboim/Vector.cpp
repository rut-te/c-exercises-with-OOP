#include "Vector.h"
#include <cmath>
#include <iostream>
using namespace std;

Vector::Vector(int num)//constructor
{
	float temp = log(num) / log(2);//Checking the log 2 of the received number and saving it with the digits after the point
	int temp2 = log(num) / log(2);//Checking the log 2 of the received number and saving it without the digits after the point
	if (temp - temp2 != 0)//Checking whether the received number is a power of 2
	{
		capacity = pow(2, ceil(log(num) / log(2)));//If the number is not a power of 2, converting it to the nearest power of 2
	}
	else
		capacity = num;//If the number is a power of 2, keep it as it is
	data = new int[capacity];//Creating an array the size of the number we found
	size = 0;//making the size zero
}

Vector::Vector(const Vector& temp)//copy constructor
{
	capacity = temp.capacity;
	size = temp.size;
	data = new int[capacity];//Create an array of the new size
	for (int i = 0; i < size; i++)//Put the data in the new array
	{
		data[i] = temp.data[i];
	}
	
}

Vector::~Vector()//destructor
{
	if(data)
		delete[]data;
}

int Vector::getCapacity()//Returning the length of the vector
{
	return capacity;
}

int Vector::getSize()//Returning the number of values in the vector
{
	return size;
}

void Vector::print()//Data printing
{
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

void Vector::assign(Vector temp)//A method that functions as an = operator
{
	int* newData = new int[temp.capacity];//Create an array of the new size
	for (int i = 0; i < temp.capacity; i++)//Putting the data in the array
	{
		newData[i] = temp.data[i];
	}
	delete[]data;
	data = newData;//Saving the array we created instead of the previous array
	capacity = temp.capacity;
	size = temp.size;
}

bool Vector::isEqual(Vector vec)//A method that functions as an == operator
{
	if (size == vec.size)//Checking if there is equality in size
	{
		for (int i = 0; i < size; i++)//Checking if the values are equal
		{
			if (data[i] != vec.data[i])
				return false;
		}
	}
	else
		return false;
	return true;
}

int& Vector::at(int index)//A method that functions as an [] operator
{
	if (index > size - 1)
		return data[index];
	else
		return data[0];
}

int Vector::scalmul(Vector vec)//A method that performs scalar multiplication
{
	int sum = 0;
	if (size != vec.size)//If the size is not the same return -1
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else
	{
		for (int i = 0; i < size; i++)//If size is equal perform scalar multiplication
			sum += data[i] * vec.data[i];
	}
	return sum;
}

Vector Vector::strnewcat(Vector vec1)//A method that concatenates 2 vectors
{
	int help;
	int temp = capacity + vec1.capacity;//Calculate the new size
	float temp1 = log(temp) / log(2);
	int temp2 = log(temp) / log(2);
	if (temp1 - temp2 != 0)//Checking if the new size is a power of 2 if not calculating the nearest power
	{
		help = pow(2, ceil(log(temp) / log(2)));
	}
	else//If so, leave the size as it is
		help = temp;
	Vector newVec(help);//Creating a new vector of the requested size
	newVec.size = size + vec1.size;
	newVec.capacity = help;
	for (int i = 0; i < newVec.size; i++)//Put the values in the new vector
	{
		if (i < size)
			newVec.data[i] = data[i];
		else
			newVec.data[i] = vec1.data[i-size];
	}
	return newVec;//Returning the new vector
}

void Vector::clear()//A method that empties the vector
{
	for (int i = 0; i < size; i++)
		data[i] = NULL;
	size = 0;
}

void Vector::delLast()//A method that deletes the last member of a vector
{
	if (size == 0)
		cout << "ERROR" << endl;
	else
	{
		size = size - 1;
		int* newData = new int[size];//Creating a new array whose size is 1 less than the previous array
		for (int i = 0; i < size; i++)//Putting the values
		{
			newData[i] = data[i];
		}
		delete[]data;
		data = newData;//exchange between the vectors
	}
}

void Vector::insert(int val)//A method that places the value in the next free position in the array
{
	size = size + 1;//Increasing the size by 1
	if (size == capacity)//In case you need to increase the size of the array
	{
		capacity = capacity * 2;
		int* newData = new int[capacity];
		for (int i = 0; i < size - 1; i++)
		{
			newData[i] = data[i];
		}
		newData[size - 1] = val;
		delete[]data;
		data = newData;
	}
	else//In case you don't need to increase the size of the array
	{
		data[size - 1] = val;
	}
}
