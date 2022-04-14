Use the text editor Notepad++ (https://notepad-plus-plus.org/) to examine the data file data/MetData-31-3.csv. 
Open the same file (data/MetData-31-3.csv) using a spreadsheet like Microsoft Excel. Compare the views shown in Excel and notepad++. 
This is the type of data that will be used for assignment 1. The notepad++ version is what your program will see. 
To see what your program will see: in notepad++, select the View Menu/Show Symbol/Show All Characters.

The first row shows the sensor codes. See the file SensorCodes.rtf for their meaning. 

The first field contains both the date and time. You will need to split the date and time values. 
The date can be stored in the Date class from a previous exercise. You need to create, and unit test a Time class to store time values.

For this question, we are interested only in the first field marked “WAST” and the field marked “S”. 
The data in the S field is the wind speed. You should assume that the speed recorded in the data file is in m/s. 
You can download your own data files to check the units. The units are shown in the raw data files you download.

For lab 5 you will use the following data structure:

	// #include anything else you need
	#include “Date.h”  // your Date class from a previous lab
	#include “Time.h”  // your Time class from this lab
	#include “Vector.h” // your Template Vector class from this lab

	typedef struct {
    	Date d;
    	Time t;
    	float speed;
	} WindLogType;

	Vector<WindLogType> windlog; // Vector<WindlogType> is a realised Vector. 
					  // This cannot be declared global	
The Date class was created, and unit tested in lab 4. The Time and Vector classes were created, and unit tested as part of this lab 5 (this lab). 
Note that as you are creating classes, the classes get reused later in other contexts, so make sure you design for reuse. Remember to keep the classes simple. 
The more you add to classes beyond the bare minimum, their reusability goes down. 
Apply the principles of low coupling and high cohesion.

Write a C++ program to read data from the file data/MetData-31-3.csv into windlog. 

Once the data is read into windlog, your program will use windlog to work out the average wind speed in km/h and the sample standard deviation (SD).  
The numbers are printed to the screen on a new line with appropriate text information to show what the numbers represent.

The program will go through windlog and when a value of speed is found that matches the average speed that was printed out, 
the date and time stored (in windlog) for this speed is printed on a new line. 

Some things to consider:  
•	Is it possible that the average speed would not be in windlog? 
•	What does it mean, when you need to “match” and the values being matched are floating point values?
•	What values could be in the data file if a sensor is offline? What would happen to your program if, say, a value of N/A (or some other) value is there for an offline sensor.
•	Should any offline sensor value take part in the average and SD calculation?

Once you have the correct results, check your program on the larger data file, data/MetData_Mar01-2014-Mar01-2015-ALL.csv. 


Some essential things to consider:
•	A number of fields that are not of interest would be read and discarded for question 5. Other fields will be used later (Ambient Air Temperature T, Solar Radiation SR). 
Future work may not have columns that are in the same order. 
The field names (column names) would be similar, but column arrangement can be in a different order. How would you future-proof your read routine?
•	How do you know that the data is being read in correctly? 
Hint: before you attempt to read the data into the data structure, you need to read, split the data, and print it out on screen or a file for debugging. 
Then manually check the output. Your program doesn’t have to do this for the entire data file - just the first few lines will be sufficient to check. 
Once this limited manual check is successful, check that you can read the whole file correctly. 
You do this check by reading MetData-31-3.csv and printing the date, time, and wind speed into an output file (testoutput.csv). 
Commas separate the date, time, and wind speed, with 3 data values per line. 

Open MetData-31-3.csv and testoutput.csv in a text editor and spreadsheet, and then manually check that the values are correct in testoutput.csv. 
Once you can visually confirm that the values are correct, you start on this question and use the windlog data structure. 

Test your program by printing out all the data from windlog into the output file called testoutput.csv.  
The three values in the output file must be separated by commas. Do a visual check to see that the data in testoutput.csv is correct. 
Once you can confirm that the output is correct, do the average speed calculation and output date/time on screen. 
Make sure that you check that the screen output is correct by viewing the input data file in a spreadsheet (application test). 
Use the spreadsheet’s average formula calculation to verify your program’s calculation. Repeat this process for the sample standard deviation.
•	Can you think of any good reason why WindLogType should be a class and not a struct? When would you use a class and when would you use a struct? 
Think very carefully about this. The assignments do require (mandatory ) you to provide rationale (reasons why) for data structure approaches you take.
