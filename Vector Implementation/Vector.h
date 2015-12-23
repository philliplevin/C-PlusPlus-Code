#ifndef VECTOR_H
#define VECTOR_H

// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);           // copy constructor
   ~Vector();

   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;

   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element

   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size

   T & operator[](unsigned int index);    // return reference to numbered element
   Vector<T> & operator=(const Vector<T> &);

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

// Member functions for Vector class

template<class T>
Vector<T>::Vector()
{
	// Creates an array on the heap to hold the elements of the Vector 
	my_size = 0;
	my_capacity = 0;
	buffer = new T[0]; 
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	// Returns reference to first element in Vector
	return &buffer[0]; 
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
	// Returns reference to last element in Vector	
    return &buffer[my_size]; 
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
	// Creates an array of size size
	my_size = size; 
	my_capacity = size; 							    
	buffer = new T[size]; 
	
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
	// Creates an array of size size
	// Each index in the array is the element initial
	
	my_size = size;
	my_capacity = size;
	buffer = new T[size];
	
	for(int i = 0; i < size; ++i)
	{
		buffer[i] = initial; 
	}
	
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
	//Copy constructor copies Vector v to array
	
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_capacity];
		
	for(int i = 0; i < my_size; ++i)
	{
		buffer[i] = v.buffer[i];
	}
		
}

template<class T>
Vector<T>::~Vector()
{
	// Deconstructor deletes array which holds elements of the Vector
	if(buffer != NULL)
	{
		delete [] buffer;
	}
}

template<class T>
unsigned int Vector<T>::capacity() const
{
	// Returns the capacity of the Vector
	return my_capacity;
} 

template<class T>
unsigned int Vector<T>::size() const
{
	// Returns the size of the Vector 
	return my_size;
}

template<class T>
bool Vector<T>::empty() const
{
	// Checks to see if the Vector is empty
	// Returns true if empty, false if not empty
	if (my_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
T & Vector<T>:: front()
{
	// Returns the first element in the Vector
	return buffer[0];
}

template<class T>
T & Vector<T>:: back()
{
	// Returns the last element in the Vector
	return buffer[my_size - 1];
}

template<class T>
void Vector<T>:: push_back(const T & value)
{
	// Inserts value in the last position of the Vector
	// If the vector has the same size as its capacity, then the capacity is increased by 5
	if(my_size == my_capacity/sizeof(*buffer))
	{
		resize(my_size + 1);
		reserve(my_capacity + 5);
		buffer[my_size - 1] = value;
	}
	else
	{
		buffer[my_size] = value;
	}
}

template<class T>
void Vector<T>:: pop_back()
{
	// Removes the last element of the Vector 
	--my_size;
}

template<class T>
void Vector<T>:: reserve(unsigned int capacity)
{
	// Allocates an array newbuffer to hold the Vector with the appropriate capacity 
	// Copies all elements from the original array to the array of the new capacity 
	// Deletes memory space reserved for the original array
	
	my_capacity = capacity; 
	T* newbuffer;
	newbuffer = new T[capacity];

	for(int i = 0; i < my_size; i++)
	{
		newbuffer[i] = buffer[i];
	}
	
	delete [] buffer;
	buffer = newbuffer;
}

template<class T>
void Vector<T>:: resize(unsigned int size)
{
	// Updates the size of the Vector
	// If the requested size is greater than the capacity, the value of the capacity is increased
	
	if(size > my_capacity) 
	{
		reserve(size);
	}
	
	my_size = size;

}

template<class T>
T & Vector<T> :: operator[](unsigned int index)
{
	// Allows user to access elements in the Vector by using [] notation
	return buffer[index];
}

template<class T>
Vector<T>& Vector<T> :: operator=(const Vector<T> & v)
{
	// Allows use of = notation to assign an existing Vector to this Vector
	// Copies all data members and elements of existing Vector to this vector 
	
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	buffer = new T[my_capacity];
		
	for(int i = 0; i < my_size; ++i)
	{
		buffer[i] = v.buffer[i];
	}
}

#endif