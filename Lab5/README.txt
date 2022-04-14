1. In the previous lab exercises, the Registration class had a raw array of results. This array itself was not encapsulated inside a class to provide controlled access to the array. You would have used ArrayList in Java.

An encapsulated array called Vector needs to be created.  Vector encapsulates a dynamic array (uses “new” to create memory on the heap ). 
Vector is a template class. (The closes analogy would be the Java ArrayList which is also templated.) The raw array is a private member of a template class Vector. 
You write the Vector class and provide controlled access to the dynamic raw array via the Vector’s public methods. Your Vector class is not the same as the STL vector, so please do not attempt to duplicate the STL vector. 

Do not use the STL vector class (i.e. you must not have #include <vector> in any part of your code for this lab or assignment 1). 

The template Vector class that you have to write is an example of a linear data structure. 
The entire (declaration and implementation) template Vector class is written in a file called Vector.h because it is a template class. There is no Vector.cpp for the template Vector class in this lab (and assignment). 
There is no need to complicate the issue by having a .cpp file for template classes.

Vector.h contains the following:

	#ifndef VECTOR_H
	#define VECTOR_H

	// The class interface/declaration must have doxygen comments – put these in
	// Follow the style in modelfile.h

	template <class T>
	class Vector   // This is NOT the std::vector.
	{
		public:
	// class declaration	
	// you fill in the rest and include doxygen comments
		private:
			// the encapsulated dynamic array
			// fill in ..
	};

	// class implementation follows with normal comments
	// you fill in the rest


	#endif



How big is the Vector going to be? Once you create the internal array on the heap using “new”, the size is fixed. 
What happens if there is more data to be added? The Vector would need to resize itself (grow) once full. 
The user of Vector should not be bothered with this detail as the Vector would take care of this behind the scenes. 
Naturally, you as the designer of Vector would have to write the code to do the resize. 
The amount to resize is typically 1.5 to 2 times current size.

Keep the Vector minimal but complete. Do not attempt to the mimic the STL vector. Methods or operators should not have duplicated functionality.
The required Vector class is a container class. It must not violate the Law of Demeter.

You will need to unit test this Vector before using it. Discuss your ideas with your tutor. You will need this template Vector class for the assignment.

In the previous labs, you were using an array of Result objects. Assuming you had the following in Registration.h:

	Result results[MaxResults];// you may have been using different names for array and max size of array, so amend this example accordingly.
Change the above to:

	Vector<Result> results;        // use the same name for the Vector object as your actual array name.

You will need to #inlcude “Vector.h” in Registration.h. Build your Registration program.
Provide the required operator [] methods in Vector if you have not provided them. 

2. Consider a change in requirements in the Registration lab work from previous weeks: each unit has a unit coordinator and the unit coordinator’s details include: coordinator’s name, room number, telephone number and email.

Reflect on the re-design you would need to do to cater for new requirements for the Registration codebase. 
How would you “future-proof”  your design so that any new code that you write will introduce additional functionality to cater for new requirements and not keep on modifying existing code? (Open-Closed principle) 
Note that in the past, you were given an example of what output the program should do. What if the output format was changed? Would you have to go back and change existing classes? 

Ideally, to change the output format should only require a changed “main program” (client code) and not a change to the data classes. 
What about a change in the input format? For example, how would you cater for the input format shown at the end of the document?

It is a common mistake to spend little or no time in design and spend a lot of time trying to make the code “work”. 
For example, assignment 2 makes use of earlier work. 
If the earlier work is not designed (and implemented) right, assignment 2 will require more work (and time) to complete when you have very limited time available. 

Vector must not depend on any part of the application. Vector is just an encapsulated array that can store any other data type, including Vector itself. To be able to have this flexibility, Vector must not know about the data type that it is storing.

Can your Vector class be used in exercise 7 of Lab 4 (assessed lab)? You need working exercise 7 code before you proceed. Your declaration in exercise 7 of lab 4 would have been:

	float *dataArray;

In exercise 7 of lab 4, replace the line above with the following:

	Vector<float> dataArray;  // You will need to #include  “Vector.h” at the top of the file for exercise 7 to be able to use the Vector class.

Do not change anything else in exercise 7 of lab 4. Build and run the program. Did the program build and run correctly? Were changes needed.? 
If so, redesign the Vector. Check the Vector again with Vector of Result in the Registration lab exercise. 

