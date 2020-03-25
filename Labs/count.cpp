//Vanshika Shah

/**
Direction: 
Write a C++ program that reads in lines of text from the standard input.
Keep a count of the number of lines that you read.
Keep track of the length of the longest line.
Keep count of the number of integers in the input. Remember to check for errors before counting something as an integer. For example, 17 is an integer but 17.4 is not.
When there is no more input, print out three lines of output, as follows:

NUMBER OF LINES: n1

LENGTH OF LONGEST LINE: n2

NUMBER OF INTEGERS: n3
**/ 

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    
string input;
    
int numLines=0;
int longestLine =0;
int numInt = 0; 


while( getline(cin, input) )
{
    
    numLines++;
    if( input.length() > longestLine )
    {
    	longestLine= input.length();
    }
     istringstream iss(input);
     string number; 
  		
    while(iss >> number)
    { 
        bool isInt = true; 
        for(int i =0; i< number.length(); i++) 
        {
            if( !isdigit(number[i]) ) 
            {
               isInt = false; 
            }
        }
       
        if(isInt == true)
        {
            numInt++; 
        }
        
       
        
	}
}
cout<<"NUMBER OF LINES: "<< numLines <<endl;
cout<<"LENGTH OF LONGEST LINE: "<< longestLine <<endl;
cout<<"NUMBER OF INTEGERS: "<< numInt <<endl;

return 0;
}
