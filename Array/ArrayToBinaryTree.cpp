/*Let's pretend that Amazon stores its categorization structure within binary tree called Browse Nodes.  Someone decided to stream this structure to a web service as an array with the following rules:
1. The first element in the array is the value of the root node of the tree.
2. The next two values are the left and right node values of the root node's children.
3. The next four values are the next depth level of the tree.
4. So on and so forth.

A B C D E F G becomes:

         A
      B     C
    D   E F   G

Implement a method that takes in the array and returns the root of the browse node tree.

*/

/* This Whole code is bogus --- NEED To FIX*/


#include<iostream>
#include<vector>
#include<map>


struct tree* createnode(string x)
{
    struct nw = new tree;
    nw->left = NULL;
    nw->right = NULL;
    nw->data = x;
 return nw;
}

/*
class tree {
    tree *left;
    tree *right;
    string data;
    map<string , int> treemap;
    int flag = 0;

public:

    bool contains(string x)
    {
        if(flag == 0) {
            setupmap();
            flag =1;
        }
        map<string, int>:: iterator it = treemap.find(x);
        if(it != treemap.end())
            return true;
        else
            return false;
    }

    void setupmap()
    {

    }
};*/

BinTree* arr_to_tree(int *arr, int size)
{
    BinTree *newTree, *root;
    vector<BinTree*> node_list;
    int i=0;
    root = createBNode(arr[0]);
    node_list.push_back(root);
    while(!node_list.empty())
    {
        newTree = node_list.front();
        node_list.erase(node_list.begin());
        if(2*i + 1 >= size)
            break;

        newTree->left = createBNode(arr[2*i+1]);
        node_list.push_back(newTree->left);
        if(2*i+2 >= size)
            break;

        newTree->right = createBNode(arr[2*i+2]);
        node_list.push_back(newTree->right);
        i+=1;
    }
    return root;
}

struct tree *(vector<string> v)
{
    struct tree *root = NULL;
    if(!v.isempty())
    {
        struct tree *temp = NULL;
        vector<struct tree*> queue;
          root = createnode(v[0]);
          queue.push_back(root);
          temp = root;
          int currentnumber = 0;
        while(currentnumber < v.size() && currentnumber < queue.size())
        {
            temp = queue[currentnumber];
           if(temp->left == NULL)
          {
             if(currentnumber *2 +1 < v.size())
                 temp->left = createnode(v[currentnumber *2 +1]);
                 queue.push_back(temp->left);
          }
          if(temp->right == NULL)
          {
             if(currentnumber *2 +2 < v.size())
                 temp->right= createnode(v[currentnumber *2 +2]);
                 queue.push_back(temp->right);
          }

         currentnumber++;
        }
     }
    return root;
}
