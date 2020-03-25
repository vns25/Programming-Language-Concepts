//Vanshika Shah 

#include <iostream>
#include <map> 
#include "lex.h" 

using namespace std; 

	map<Token, string> tokenMap = 
	{
    	{PRINT, "PRINT"}, 
    	{PRINTLN, "PRINTLN"}, 
    	{REPEAT, "REPEAT"}, 
    	{BEGIN, "BEGIN"}, 
    	{END, "END"}, 
    	{IDENT, "IDENT"}, 
    	{ICONST, "ICONST"}, 
    	{SCONST, "SCONST"},  
    	{PLUS, "PLUS"}, 
    	{MINUS, "MINUS"}, 
   	 	{STAR, "STAR"}, 
        {SLASH, "SLASH"}, 
    	{EQ, "EQ"}, 
    	{LPAREN, "LPAREN"}, 
    	{RPAREN, "RPAREN"}, 
    	{SC, "SC"},
    	{ERR, "ERR"}, 
    	{DONE, "DONE"}
	}; 
	
	ostream& operator<<(ostream& out, const Tok& tok) 
	{
    	Token t = tok.GetToken(); 
        out << tokenMap[t]; 
        if( t == IDENT || t == ICONST || t == SCONST || t == ERR) 
        {
        	out <<  "(" << tok.GetLexeme() << ")";
        }
		return out; 
	}
