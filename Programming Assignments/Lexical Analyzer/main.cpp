//Vanshika Shah 

#include <iostream>
#include <fstream>
#include <sstream> 
#include <list> 
#include "lex.h"

using namespace std;

int main(int argc, char *argv[ ])
{
    ifstream myFile;
    int fileCount = 0; 
    
    istream*in = &cin; 
        
    int lineNumber = 1; 
    
    bool isV = false; 
    bool isIconsts = false; 
    bool isSconsts = false; 
    bool isIds = false; 
 
    for(int i = 1; i < argc; i++) 
    	{ 
        	string command( argv[i] ); 
            if( command == "-v" ) 
                isV = true; 
        
        	else if( command == "-iconsts" ) 
                isIconsts = true; 
        
        	else if( command == "-sconsts" ) 
                isSconsts = true; 
        	
        	else if( command == "-ids") 
                isIds = true; 
        
        	else if( command.substr(0,1) == "-" ) 
            {
            	cerr << "UNRECOGNIZED FLAG " << command << endl; 
                return -1; 
            } 
        
        	else if(command.substr(0,1) != "-" ) 
            {
                fileCount++; 
                myFile.open(argv[i]); 
                
                if( fileCount > 1) 
                {
                	cerr<< "ONLY ONE FILE NAME ALLOWED" << endl; 
                    return -1; 
                }
            	else if( ! myFile.is_open() ) 
                {
                	cerr << "CANNOT OPEN " << command << endl; 
                    return -1; 
                }
                else 
                {
                	in = &myFile; 
                }
            }
        }
     
  
    list<string> identList; 
    list<string> iconstList; 
    list<string> sconstList; 

  	int tokenNum = 0; 
    Tok t; 
    while( (t = getNextToken(*in, lineNumber)) != DONE && t != ERR) 
    {
        tokenNum++;
        
        if(isV) 
        	cout << t << endl; 
        
        else if( t == IDENT) 
       		identList.push_back(t.GetLexeme() ); 
        
        else if( t == SCONST) 
            sconstList.push_back(t.GetLexeme()); 
        
        else if(t == ICONST)
            iconstList.push_back(t.GetLexeme()); 
     
    }
    
    if(t.GetToken() == ERR)
    {
    	cerr << "Error on line " << lineNumber << " (" << t.GetLexeme() << ")" << endl; 
        return -1; 
    }
        
        
    

    cout << "Lines: " << lineNumber-1 << endl; 
    
  	if( tokenNum > 0 ) 
    	cout << "Tokens: " << tokenNum << endl; 
  

    
    if(isIds && identList.size() >0 )
    {
        identList.sort(); 
        identList.unique(); 
        if( tokenNum > 0)
        	cout << "IDENTIFIERS: " ;
        
        for (list<string>::iterator i = identList.begin(); i != identList.end(); i++) 
        {
            
         	cout << *i ; 
            if(*i != identList.back() ) 
                cout << ", "; 
        }
        
        cout << endl; 
               
    }
            
    
    if(isIconsts && iconstList.size() > 0)
    {
    	iconstList.sort(); 
        iconstList.unique(); 
        
        if( tokenNum > 0)
        	cout << "INTEGERS: " ;
        
        for (list<string>::iterator i = iconstList.begin(); i != iconstList.end(); i++) 
        {
            
         	cout << *i ; 
            if(*i != iconstList.back() ) 
                cout << ", "; 
        }
        
        cout << endl; 
    }
    
    if(isSconsts && sconstList.size() > 0)
    {
   	    iconstList.sort(); 
        iconstList.unique(); 
        
        if( tokenNum > 0)
        	cout << "STRINGS: " ;
        
        for (list<string>::iterator i = sconstList.begin(); i != sconstList.end(); i++) 
        {
            
         	cout << *i ; 
            if(*i != sconstList.back() ) 
                cout << ", "; 
        }
        
        cout << endl; 
    }
 
   
myFile.close(); 
return 0;
}
