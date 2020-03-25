/**
Write a C++ program that reads from the standard input and counts the number of times each word is seen. 
A word is a number of non-whitespace characters separated by whitespace.

After all input has been processed, print each word that was seen the largest number of times on a line by itself. 
The words should be printed in alphabetical order.
**/ 

//Vanshika Shah 

#include <iostream>
#include <map> 

using namespace std;

int main(int argc, char *argv[ ])
{
    map<string, int> counter; 
    
    string word; 
    int largestFreq = 0; 
    
    while(cin >> word) 
    {
    	counter[word]++; 
        if( counter[word] > largestFreq) 
            largestFreq = counter[word]; 
    }
    
    
    for( map<string, int> :: iterator it = counter.begin(); it != counter.end(); it++) 
    {
    	if( it -> second  == largestFreq) 
        {
            cout << it -> first << endl; 
        }
    }
    
    return 0; 
    
}
