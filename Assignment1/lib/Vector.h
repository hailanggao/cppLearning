#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
template <class T>
class Vector
{
public:
	Vector();
	//Vector(unsigned int size);
	Vector(const Vector<T>& v);
	~Vector();
	void clear();
	void push(const T& data);
	void pop();
	void insert(unsigned index, const T& data);
	T& get(unsigned index) const;
	unsigned getSize() const;
	unsigned getCapacity() const;
	typedef T* iterator;
	iterator begin();
	iterator end();
	T& operator[](unsigned index);
private:
	unsigned capacity;
	unsigned mySize;
	T* arr;

};

template<class T>
Vector<T> ::Vector() {
	arr = new T[1];
	capacity = 1;
	mySize = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T>& v) {
	mySize = v.mySize;
	capacity = v.capacity;
	arr = new T[mySize];
	for (unsigned i = 0; i < mySize; i++) {
		arr[i] = v.arr[i];
	}
}

template<class T>
void Vector<T>::push(const T& data) {
	if (mySize == capacity) {
		T* tmp = new T[2 * capacity];
		for (unsigned i = 0; i < capacity; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		capacity *= 2;
		arr = tmp;
	}

	arr[mySize] = data;
	mySize++;
}

template<class T>
void Vector<T>::pop() {
	if (mySize == 0) {
		std::cout << "[ERROR]: IT IS EMPTY ALREADY" << std::endl;
	}
	else {
		mySize--;
	}
}

template<class T>
void Vector<T>::insert(unsigned index, const T& data) {
	if (index == capacity) {
		push(data);
	}
	else if (index < capacity) {
		arr[index] = data;
	}
	else {
		std::cout << "[ERROR]: INDEX(" << index <<
			") IS GREATER THAN CAPACITY(" << capacity << ")." << std::endl;
	}
}

template<class T>
T& Vector<T>::get(unsigned index) const {
	return arr[index];
}

template<class T>
unsigned Vector<T>::getSize() const {
	return mySize;
}

template<class T>
unsigned Vector<T>::getCapacity() const {
	return capacity;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin(){
	return arr;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end(){
	return arr + getSize();
}

template<class T>
T& Vector<T> ::operator[](unsigned index) {
	return arr[index];
}


template<class T>
Vector<T>::~Vector() {
	delete[] arr;
}

template<class T>
void Vector<T>::clear() {
	mySize = 0;
	capacity = 1;
	delete[] arr;
}
#endif
