//Vanshika Shah



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