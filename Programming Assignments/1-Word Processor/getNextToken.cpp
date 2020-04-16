//Vanshika Shah 

#include "lex.h"
#include <iostream> 
#include <sstream> 
#include <map> 


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

map<string, Token> tokenMapDup = 
	{
    	{"PRINT", PRINT}, 
    	{"PRINTLN", PRINTLN,}, 
    	{"REPEAT", REPEAT}, 
    	{"BEGIN", BEGIN}, 
    	{"END", END}, 
    	{"IDENT", IDENT}, 
    	{"ICONST", ICONST }, 
    	{"SCONST", SCONST},  
    	{"PLUS", PLUS}, 
    	{"MINUS", MINUS},
   	 	{"STAR", STAR}, 
        {"SLASH", SLASH}, 
    	{"EQ", EQ}, 
    	{"LPAREN",LPAREN}, 
    	{"RPAREN",RPAREN}, 
    	{"SC", SC },
    	{"ERR", ERR}, 
    	{"DONE",DONE,}
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

Tok getNextToken(istream& in, int& linenum) 
{
    enum LexState { BEGIN, IDENT, ICONST, SCONST, COMMENT, ERR, DONE}; 
    LexState lexstate = BEGIN; 
    
    string lexeme;
    char ch; 

	while( in.get(ch) ) 
    {
        
    	switch(lexstate) 
        {
            case BEGIN: 
                
                if( ch == '\n' ) 
                	linenum++; 
                
                if( isspace(ch) ) 
                    continue; 
                
                lexeme = ch; 
                 
                
                if( isdigit(ch) )
                {
                	lexstate = ICONST; 
                }
                
                if( isalpha(ch))
                {
                	lexstate = IDENT; 
                }
                
                if( ch == '"') 
                    lexstate = SCONST; 
                
                if( ch == '/' && in.peek() == '/') 
                	lexstate = COMMENT; 
                else
                {
					switch(ch)
                    {
                        case '+': 
                            return Tok(PLUS, lexeme, linenum); 
                        
                            
                        case '-':  
                            return Tok(MINUS, lexeme, linenum); 
                            
                            
                        case '*':
                            return Tok(STAR, lexeme, linenum); 
                            lexeme.clear(); 
                            
                        case '/': 
                            return Tok(SLASH, lexeme, linenum); 
                        	lexeme.clear(); 
                            
                        case '=': 
                            return Tok(EQ, lexeme, linenum); 
                            lexeme.clear(); 
                            
                        case '(': 
                            return Tok(LPAREN, lexeme, linenum); 
                            lexeme.clear(); 
                            
                        case ')':  
                            return Tok(RPAREN, lexeme, linenum); 
                            lexeme.clear(); 
                            
                        case ';':  
                            return Tok(SC, lexeme, linenum); 
                            lexeme.clear(); 
                            
                        case '.': 
                            return Tok(Token::ERR, lexeme, linenum); 
                        
                        case '_': 
                            return Tok(Token::ERR, lexeme, linenum); 
                            
                        case '$': 
                            return Tok(Token::ERR, lexeme, linenum); 
                        
                        case '!': 
                            return Tok(Token::ERR, lexeme, linenum); 
                     
                    }
                }
                break; 
                
            case IDENT: 
               if( isdigit(ch)  || isalpha(ch) ) 
               {
                    lexeme += ch; 
               }
               else 
               {
                   in.putback(ch); 
                   string lexeme2; 
                   for( int i = 0; i< lexeme.length(); i++) 
                   {
                   		lexeme2 += toupper( lexeme[i] ); 
                   }
                      
                   if( tokenMapDup.count(lexeme2) > 0) 
                   {
                   		return Tok(tokenMapDup[lexeme2], lexeme, linenum); 
                   }
                   
                   else 
                   {
                   return Tok(Token::IDENT, lexeme, linenum); 
                   
                   } 
                   
               }
               break; 
                
            case ICONST:
               if( isdigit(ch))
                  lexeme += ch;  
           	   else
               {
                   in.putback(ch); 
                   return Tok(Token::ICONST, lexeme, linenum); 
                   
               }
               break; 
                
            case SCONST: 
					
                if(ch == '"') 
                     return Tok(Token::SCONST, lexeme, linenum) ;
                
                
                else if(ch == '\\') 
                {
                    lexeme += "\\"; 
                	if( isalpha (in.peek() ) || isspace(in.peek()) || ispunct(in.peek()))
                    {
                        if(in.peek() == 'n')
                        {
                            in.get(ch); 
                            lexeme += "\n"; 
                        }
                       
                        else 
                        {
                            in.get(ch); 
                            lexeme += ch; 
                        }
                    }
                    
                }
                else if( ch == '\n') 
                {
                    lexeme += ch; 
                	return Tok(Token::ERR, lexeme, linenum); 
                }
                
                else 
                    lexeme += ch; 
                
                break; 
                
            case COMMENT: 
                if( ch == '\n' ) 
                {
                    lexstate = BEGIN; 
                    linenum++; 
                }
                
            case ERR: 
                break; 
                
            case DONE: 
                break; 
        }
    }
    
    if(in.eof())
    {
     	return Tok(Token::DONE, lexeme, linenum);
    }
   
    
    return Tok(); 
    
}





