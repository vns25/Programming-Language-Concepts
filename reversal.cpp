//Vanshika Shah 


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