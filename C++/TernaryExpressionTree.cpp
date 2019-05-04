
/*
 * For the context of this question, all of the operands in the expression are either
a variable name or another ternary expression. The variable names are single character
lowercase english letters.

For example, a valid expression would be ”a ? b : c”. This expression can be represented in a tree form, for example:
    a
   /  \
 b     c

 Also, you are given a Node class that holds a node in the above-showed tree representation of an expression:
struct Node {
	String variableName;
	Node left, right;
}

Expression class holds a reference to the root of the parsed expression tree:
struct Expression {
	Node root;
}

a?b?c:d:e

                        a
                      /   \
                    b       e
                   /  \
                c       d


 */
#include <iostream>
#include<vector>

using namespace std;

struct Node{
    char var;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;
vector<struct Node*> stack;
vector<char> expression;

struct Node* create_node(char x)
{
    struct Node *temp = new struct Node;
    temp->left = NULL;
    temp->right = NULL;
    temp->var = x;

    return temp;
}

void expresssion(string x, int pos)
{
    if(pos == x.length())
    {
        return;
    }

    if (x[pos] != '?' && x[pos] != ':')
    {
        struct Node * temp = create_node(x[pos]);
        if (root == NULL)
        {
            root = temp;
        }

        if(stack.size() > 0)
        {
            struct Node* stackelement = stack[stack.size()-1];

            if(stackelement->var == '?' || stackelement->var == ':')
            {
                stack.pop_back();
                struct Node *temp2 = stack[stack.size()-1];
                if(temp2->left == NULL)
                {
                    temp2->left = temp;
                     stack.push_back(temp);
                }
                else
                    temp2->right = temp;
            }
        }
        else
        {
            stack.push_back(temp);
        }
        expresssion(x, pos+1);
    }
    else
    {
        if (x[pos] == '?')
        {
             struct Node * temp = create_node(x[pos]);
             stack.push_back(temp);

             expresssion(x, pos+1);
        }
        else if (x[pos] == ':')
        {
            struct Node * temp = create_node(x[pos]);
            stack.pop_back();
            stack.push_back(temp);
            expresssion(x, pos+1);
        }
    }
}

void print(struct Node *head)
{
    if(head == NULL)
        return;
    cout<<head->var<<endl;
    print(head->left);
    print(head->right);
}

int main()
{
    string x = "a?b?c:d:e";
    expresssion(x, 0);
    print(root);
    cout << "Hello world!" << endl;

    return 0;
}
