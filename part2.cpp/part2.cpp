//Vanshika Shah
//31447294

#include <iostream>
#include <fstream>
#include <sstream> 


using namespace std;

int main(int argc, char *argv[ ])
{
    ifstream myFile;
    istream*in = &cin; 
    int fileCount = 0; 
    
    int lineLength = 40;  
    int indentLength = 8; 
        
    
    	for(int i = 1; i < argc; i++) 
    	{ 
        	string command( argv[i] ); 
            if( command.substr(0,1) != "-" ) 
            {
            	fileCount++; 
                myFile.open( argv[i] ); 
                if( ! myFile.is_open() ) 
                {
                	cerr << "UNABLE TO OPEN FILE " << command << endl; 
                    return -1; 
                }
                else 
                {
                	 in = &myFile; 
                }
            }
            
            else if( command.substr(0,3) != "-LL" 	&& command.substr(0,3) != "-IN") 
            {
                cerr << "UNRECOGNIZED FLAG " << command << endl; 
                return -1; 
            } 
            
            else if( command.substr(3,1) != "=")
            {
                cerr << "MISSING = SIGN " << command <<endl; 
                return -1; 
            }
            
            else if( command.substr(0,4) == "-LL=" || command.substr(0,4) == "-IN=") 
            {
            	string strNum = command.substr(4);
                
                bool isNumeric = true; 
                for(int i = 0; i< strNum.length(); i++) 
                {
                	if( isdigit( strNum[i] ) == false) 
                       isNumeric = false; 
                    
                    if( isNumeric == false)
                	{
                	cerr << "VALUE NOT INTEGER > 0 " << command << endl; 
                    return -1;
                	}
                    
                    else if ( isdigit( strNum[i]) && command.substr(0,4) == "-LL=" ) 
                    {
                    	lineLength = stoi(strNum); 
                        
                    }
                    
                    else if( isdigit( strNum[i]) && command.substr(0,4) == "-IN=" )
                    {
                    	indentLength = stoi(strNum); 
                    }
                }
            }
    	}
        
        if( fileCount > 1) 
        {
        	cerr << "TOO MANY FILENAMES" << endl; 
            return -1; 
        }


    string line;
	bool inPara = true;
    int charPrinted = 0; 
    
    bool emptyFile = true; 
    while( getline( *in, line) ) 
    {
        bool isBlank = true; 
        
        for( int i =0; i< line.length(); i++) 
         {
            if( ! isspace(line[i]) ) 
                isBlank = false; 
         }
        for(int i = 0; i< line.length(); i++) 
        {
        	if( ! isspace(line[i]) ) 
               	emptyFile = false; 
        }
        
        if(inPara)
        {
           if( (line.empty() || isBlank) && !emptyFile ) 
            {
                cout << "\n"; 
            	inPara = false; 
                cout << "\n"; 
                continue; 
            }
            
        	istringstream iss(line); 
    		string word;
        	while( iss >> word) 
        	{
            	if(charPrinted == 0) 
            	{
                	for(int i = 0; i< indentLength; i++) 
       				{
           			cout << " "; 
       				}
             		cout << word; 
                	charPrinted += word.length() + indentLength;      
            	}
            	else if( charPrinted + word.length() + 1 <= lineLength) 
            	{
                	cout << " " << word; 
                    charPrinted += word.length() + 1; 
            	}
            	else if( charPrinted + word.length() + 1 > lineLength) 
            	{
            		cout << "\n"; 
                	cout << word; 
                	charPrinted = word.length(); 
            	}
        	}
        }
        
        else
        {	
            if ( ! line.empty() ) 
        	{
            	inPara = true; 
                charPrinted = 0; 
        	}
            
         	istringstream iss(line); 
            string word;
        	while( iss >> word) 
        	{	
            	if(charPrinted == 0) 
            	{	
                	for(int i = 0; i< indentLength; i++) 
       				{
           			cout << " "; 
       				}
             		cout << word; 
                	charPrinted += word.length() + indentLength; 
                
            	}
           	    else if( charPrinted + word.length() + 1 <= lineLength) 
            	{
                	cout << " " << word; 
                    charPrinted += word.length() + 1; 
            	}
            	else if( charPrinted + word.length() + 1 > lineLength) 
            	{
            		cout << "\n"; 
                	cout << word; 
                	charPrinted = word.length(); 
            	}
        	}
        }
    }
    if( emptyFile) 
      cout << "\n"; 
     else 
   		cout << "\n"; 
    
myFile.close(); 
return 0;
}
