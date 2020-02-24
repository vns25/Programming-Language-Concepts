//Vanshika Shah 
/**
Write a C++ program that is given a file name as a command line argument.

Open the file and read it. At the end of the file, print out:

LINES: lc
WORDS: wc
CHARS: cc
DIGITS: dc

Where lc is the number of lines, wc is the number of words, cc is the number of characters, and dc is the number of digit characters, 0-9.
If no file name is provided, the program should use the standard input instead of a file.
If the file cannot be opened, print "CANNOT OPEN " followed by a space and the filename, and stop.
The program should ignore any extra command line arguments that are provided after the file name.
**/ 


#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[ ])
{
    ifstream myFile;	
	istream *in = &cin;
	

    string line;
	string word;
    
	int wordC =0;
	int lineC =0;
	int charC =0;
	int digitC =0;
    
 
	if(argc >= 2)
    {
		myFile.open(argv[1]);

		if(myFile.is_open() == true)
        {
			in = &myFile;
        }
    	else 
    	{ 
		cerr << "CANNOT OPEN " << argv[1] << endl ;
		return -1;
		}
	}	

	while ( getline(*in,line) )
    {
		lineC++;
		istringstream iss(line);
        
		while(iss >> word)
		{
			wordC++; 
		}
        
		for (int i = 0; i < line.length(); i++)
        {
			charC++;
            
			if (isdigit(line[i]))
        	{
				digitC++;
			}
        }
	}
    
charC = lineC + charC; 
    
cout << "LINES: " << lineC << endl; 
cout << "WORDS: " << wordC << endl; 
cout << "CHARS: " << charC << endl; 
cout << "DIGITS: " << digitC << endl; 
    
myFile.close();
    
return 0;

}
