1.	You will need to follow this approach for all classes that you create/modify from now onwards – all classes must have a full complement of set and get methods; are fully unit tested before being used in an application.

2.	Move the body of methods into the corresponding implementation files (.cpp). Only class declarations and method declarations are in .h files. 
	This is the approach that you will use for all future work except when you are working with template classes (template classes will be covered later). Run the unit tests to make sure all changes are working.

3.	Modify exercise 2 (above) so that instead of using C style strings, the string class from #include <string> is used (std::string). You are changing over from the C string to the Object Oriented string std::string.
	You may want to restructure the data file to reflect this but this might create a problem if you try to read in a std::string using the “>>” operator as only one word is read in each time. 
	One way around this is to have the unit name on a line by itself in the data file and use the getline(…) to read the entire line, composed of a number of words into one std::string object.
	Alternatively, you may want to read the unit name in with the “_” between words and replace the “_” with a space character when storing the values in your data structure.  
	A better way is to have the data related to one record on one line separated by a delimiter (usually a comma) and use the getline(…) with the delimiter parameter to read the data in.


4.	Result will now contain a date. The output  operator for Result should output the unit information, the marks and the date these marks were obtained. 
	The output for registration in the output data file will contain the Student ID, Semester, unit information, date and marks for each unit. 
	The output should be in a similar format as the output in the previous exercise except it will have the date information as well and there will be no “_” in the unit name. 
	A sample run is shown at the end.

5.	*Once the above exercises are completed (includes testing everything), convert all I/O operators (operator<< and operator>>) so that they are no longer friends and they are not methods of the class. 
	You will need to make use of the set and get methods from exercise 1 above. Run the unit tests to make sure all changes are working. 
	This modification should not affect the main program (client program that makes use of the classes), other than the change to how a unit object is constructed at the end of main(). 
	A sample run is shown at the end.

Sample Run:


Student ID: 12345678
Semester:  1
	Unit ID: ICT283
	Unit Name: Data Structures and Abstractions
	Credits: 3
	Marks: 90
	Date: 30 June 2016

	Unit ID: ICT289
	Unit Name: Computer Graphics
	Credits: 3
	Marks: 97
	Date: 30 December 2016

Number of Units = 2
Total Credits = 6
