//Vanshika Shah 

/** 
For this assignment, we define three types of "reversal"
A "line" reversal reverses the entire line. In a line reversal, "Hello world!" becomes "!dlrow olleH"
A "word" reversal reverses each word. In a word reversal, "Hello world!" becomes "olleH !dlrow"
A "lineword" reversal performs a line reversal and a word reversal. In a lineword reversal, "Hello world!" becomes "world! Hello".
No matter how many spaces between words in the input, the output should have only one space after each word. So a line reversal of "Hello    world!" becomes "!dlrow olleH"
Write a C++ program that does line, word and lineword reversals. The program is told which type of reversal to perform by providing a single command line argument, "line", "word", or "lineword".
If no command line arguments are provided, the program should print "MISSING FLAG" and stop.
If an unrecognized command line argument is provided, the program should print "UNKNOWN FLAG" followed by the unrecognized argument, and stop.
If more than one command line argument is provided, the program should print "TOO MANY FLAGS" and stop.
**/ 


#include <iostream>
#include <algorithm>


using namespace std;

void reverseLine(string str) 
{
    
	reverse(str.begin(), str.end()); 
    cout << str << endl; 
}


void reverseWord(string str)
{
    
    string reversed = "";  
    
  	for(int i = 0; i<= str.length() -1; i++)
    {
       
    	if(!(isspace(str[i]) ) ) 
        { 
           
        	reversed += str[i];  
            
            
            if( i == str.length()-1){
                reverse( reversed.begin(), reversed.end()); 
                cout << reversed << endl; 
                reversed.clear(); 
            
            }
        }
       
        
           
        else 
        {
           
            reverse( reversed.begin(), reversed.end()); 
            cout << reversed<<str[i] ; 
            reversed.clear(); 
            
        }
    	
	}
}

void reverseWordLine(string str)
{
	 
    string reversed = "";  
    
  	for(int i = str.length()-1; i>= 0; i--)
    {
       
    	if(!(isspace(str[i]) ) ) 
        { 
           
        	reversed += str[i];  
            
            
            if( i == 0){
                reverse( reversed.begin(), reversed.end()); 
                cout << reversed << endl; 
                reversed.clear(); 
            
            }
        }
       
        
           
        else 
        {
           
            reverse( reversed.begin(), reversed.end()); 
            cout << reversed<<str[i] ; 
            reversed.clear(); 
            
        }
    	
	}
}

int main(int argc, char *argv[ ])
{
    string input; 
    string command(argv[1]); 
    
    
    if(argc < 2)
    {
		cout << "MISSING FLAG"<< endl;  
    }
    
    if(argc > 2) 
    {
    	cout << "TOO MANY FLAGS"<< endl ; 
    }
    
    else if( argc == 2) 
    {
    
    
 	while(getline(cin, input)) 
    {
    	if(command == "line")
        {
        	reverseLine(input); 
        }
        
        else if(command == "word")
        {
        	reverseWord(input); 
        }
        
        else if(command == "lineword")
        {
        	reverseWordLine(input); 
        }
         else
    	{
    	cout << "UNKNOWN FLAG " <<  command << endl; 
    	}
        
    }
        
    }
   
        
    return 0; 
   
    
    
}
