/**
You are given a copy of lex.h from Programming Assignment 2 and a file called streams.cpp

DO NOT CHANGE streams.cpp

Write code to implement the operator<< overload for Tok

Use the given code to test your implementation.
**/ 

/*
 * lex.h 
 */

#ifndef LEX_H_
#define LEX_H_

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

enum Token {
		// keywords
	PRINT, PRINTLN, REPEAT, BEGIN, END,

		// an identifier
	IDENT,

		// an integer and string constant
	ICONST, SCONST,

		// the operators, parens, semicolon
	PLUS, MINUS, STAR, SLASH, EQ, LPAREN, RPAREN, SC,
		// any error returns this token
	ERR,

		// when completed (EOF), return this token
	DONE
};

class Tok {
	Token	token;
	string	lexeme;
	int	lnum;

public:
	Tok() {
		token = ERR;
		lnum = -1;
	}
	Tok(Token token, string lexeme, int line) {
		this->token = token;
		this->lexeme = lexeme;
		this->lnum = line;
	}

	bool operator==(const Token token) const { return this->token == token; }
	bool operator!=(const Token token) const { return this->token != token; }

	Token	GetToken() const { return token; }
	string	GetLexeme() const { return lexeme; }
	int	GetLinenum() const { return lnum; }
};

extern ostream& operator<<(ostream& out, const Tok& tok);

extern Tok getNextToken(istream& in, int& linenum);


#endif /* LEX_H_ */


/** 
operator.cpp 
**/ 
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

