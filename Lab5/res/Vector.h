#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
	Vector();
	//Vector(unsigned int size);
	Vector(const Vector<T>& v);
	~Vector();
	void clear();
	void push(T& data);
	void pop();
	void insert(unsigned int index, T& data);
	T& get(unsigned int index) const;
	unsigned int getSize() const;
	unsigned int getCapacity() const;
	T& operator[](unsigned int index);
	Vector<T>& operator=(const Vector<T>&);
	void print();

private:
	unsigned int capacity;
	unsigned int mySize;
	T* arr;

};

template<class T>
Vector<T> ::Vector() {
	arr = new T[1];
	capacity = 1;
	mySize = 0;
}

//template<class T>
//Vector<T>::Vector(unsigned int size) {
//	mySize = size;
//	capacity = size;
//	arr = new T[size];
//}

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
void Vector<T>::push(T& data) {
	if (mySize == capacity) {
		T* tmp = new T[2 * capacity];
		for (unsigned int i = 0; i < capacity; i++) {
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
void Vector<T>::insert(unsigned int index, T& data) {
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
T& Vector<T>::get(unsigned int index) const {
	return arr[index];
}

template<class T>
unsigned int Vector<T>::getSize() const {
	return mySize;
}

template<class T>
unsigned int Vector<T>::getCapacity() const {
	return capacity;
}

template<class T>
T& Vector<T> ::operator[](unsigned int index) {
	return arr[index];
}

template<class T>
void Vector<T> ::print() {
	for (unsigned int i = 0; i < mySize; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
Vector<T>::~Vector() {
	delete[] arr;
}

template<class T>
void Vector<T>::clear() {
	mySize = 0;
	capacity = 0;
	arr = 0;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v)
{
	delete[] arr;
	mySize = v.mySize;
	capacity = v.capacity;
	arr = new T[mySize];
	for (unsigned int i = 0; i < mySize; i++)
		arr[i] = v.arr[i];
	return *this;
}

#endif
