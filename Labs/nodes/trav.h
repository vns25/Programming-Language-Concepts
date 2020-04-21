//Vanshika Shah 

#include <map>
#include <iostream>

class Tree {
    Tree	*left;
    Tree	*right;
    int		node;
    
    static std::map<int, Tree*> allNodes;
    
public:
    Tree(int n, Tree *l=0, Tree *r=0) : left(l), right(r), node(n) 
    {
        allNodes[n] = this;
    }
    
    int GetNode() { return node; }
    
    void Insert(Tree *newnode) 
    {
        if( newnode->node < this->node ) 
        {
            if(left != nullptr)
            {
                left->Insert(newnode);
            }
            else 
            {
                this->left = newnode; 
            }
        }

        else if( newnode->node > this->node ) 
        {
            if(right != nullptr)
            {
                right->Insert(newnode);
            }
            else 
            {
                this->right = newnode; 
            }
        }
    }
    
    int Find(int node) 
    {
        if(this->node == node) 
        {
            return node;
        }
        
        else if(this->node > node) 
        {
            if(left != NULL) 
            	return left->Find(node);
            else 
                return -1; 
        }
        
        else 
        {
            if(right != NULL) 
            	return right->Find(node);
            else 
                return -1; 
        }  
    }
    
  
    void Print(Tree *root)  
    {
        if( root == nullptr) 
        {
            return;
        }
        
        Print(root->left); 
        cout<< root->node << endl; 
        Print(root->right); 
    }
     
};
