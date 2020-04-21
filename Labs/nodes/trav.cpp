#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "trav.h"

std::map<int, Tree*> Tree::allNodes;

// trav print
// trav find X

int main(int argc, char *argv[])
{
    if( argc < 2 )
        return 0;
    
    string cmd(argv[1]);
    
    // READ IN THE INTEGERS
    vector<int> ids;
    int input;
    
    while( cin >> input ) 
    {
        ids.push_back( input );
    }
    
    // MAKE NODES FROM THE INTEGERS
    vector<Tree*> nodes;
    for( int id: ids )
    {
        nodes.push_back( new Tree(id) );
    }
    
    if( ids.size() == 0 )
        return -1;
    
    // PUT NODES INTO A TREE USING Insert
    Tree *theTree = nodes[0];
    
    if( theTree == nullptr )
        return -1;
    
    
    for( auto n : nodes ) 
    {
        theTree->Insert(n);
        
    }
    
    // PRINT TREE
    if( cmd == "print" ) 
    {
    	theTree->Print(theTree); 
    }
    
	
    if( cmd == "find") 
    {
        int numToFind = stoi(argv[2]); 
        int findInTree = theTree->Find(numToFind); 
    	cout<< "Finding " << numToFind << ": " << findInTree <<endl; 
      
    }
    
    return 0;
}
