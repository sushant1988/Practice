/* create a binary tree and its function */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>

using namespace std;

struct tree {
int data;
struct tree *left;
struct tree *right;
};

typedef struct tree Tree;
vector<Tree*> element;
vector<int> level;

Tree * CreateNode(int data)
{
    Tree * new_node = new Tree;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Using while loop
void InsertLoop(Tree **root,int data)
{
    Tree * new_node;
    Tree *temp = *root;
    if(*root == NULL)
    {
        *root = CreateNode(data);
    }
    else
    {
        new_node = CreateNode(data);
        while(1)
        {
            if(data <= temp->data )
            {
                if(temp->left == NULL)
                {
                    temp->left = new_node;
                    return;
                }
            temp = temp->left;
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = new_node;
                    return;
                }
            temp = temp->right;
            }
        }
    }
}

// using recursion with return pointer
Tree * InsertRecPointer(Tree *root,int data)
{
    if (root == NULL)
        return CreateNode(data);
    else
    {
        if(data <= root->data)
            root->left = InsertRecPointer(root->left,data);
        else
            root->right = InsertRecPointer(root->right,data);
    }
return root;
}

// without return pointer
void InsertRec(Tree *&root,int data)
{
    if (root == NULL)
        root = CreateNode(data);
    else
    {
        if(data<= root->data)
                InsertRec(root->left, data);
        else
                InsertRec(root->right, data);
    }
}

/*
The node does not exist in the tree - In this case you have nothing to delete.
The node to be deleted has no children - The memory occupied by this node must be freed and
    either the left link or the right link of the parent of this node must be set to NULL.
The node to be deleted has exactly one child - We have to adjust the pointer of the parent
    of the node to be deleted such that after deletion it points to the child of the node
    being deleted.
The node to be deleted has two children - We need to find the inorder successor of
    the node to be deleted. The data of the inorder successor must be copied into the
    node to be deleted and a pointer should be setup to the inorder successor.
    This inorder successor would have one or zero children. This node should be deleted
    using the same procedure as for deleting a one child or a zero child node. Thus the whole
    logic of deleting a node with two children is to locate the inorder successor, copy
    its data and reduce the problem to a simple deletion of a node with one or zero children/
*/

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Tree * minValueNode(Tree* node)
{
    Tree* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

Tree* DeleteNodeBST(Tree *root, int key) {
    //base case
    if (root == NULL) return NULL;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = DeleteNodeBST(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = DeleteNodeBST(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {

        // node with only one child or no child
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Tree* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = DeleteNodeBST(root->right, temp->data);
    }
    return root;
}

// Count number of leaves in a tree
int count_leaf(Tree *root)
{
    if(root->left == NULL && root->right == NULL) // This is a leaf!
        return 1;
    else {
        return count_leaf(root->left) + count_leaf(root->right);
    }
}

// Print Tree PreOrder
void PrintTree(Tree *root)
{
    if( root == NULL)
        return;
    else
    {
        cout<<root->data<<endl;
        PrintTree(root->left);
        PrintTree(root->right);
    }
}

// Running time is O(n)
// To find Max Depth of tree
int MaxDepth(Tree *root)
{
    if(root == NULL)
        return 0;
    else {
        int l = MaxDepth(root->left);
        int r = MaxDepth(root->right);

        if(l>r)
            return l+1;
        else
            return r+1;
    }
}

// Find the Max Depth of Tree without Recursion
vector<Tree *> node;
vector<int> depth;
int MaxDepthI(Tree *root)
{
    node.push_back(root);
    depth.push_back(0);
    int Max_heigth = 0;

    while(!node.empty())
    {
        Tree *temp = node.back();
        node.pop_back();
        int level = depth.back();
        depth.pop_back();

        if(temp->right)
        {
            node.push_back(temp->right);
            depth.push_back(level+1);
        }

        if(temp->left)
        {
            node.push_back(temp->left);
            depth.push_back(level+1);
        }

        if(Max_heigth < level +1)
            Max_heigth = level + 1;
    }

    return Max_heigth;
}

// Creating mirror image of tree
void Mirror(Tree *root)
{
    if (root == NULL)
        return ;
    else
    {
        Tree *temp = root->left;
        root->left = root->right;
        root->right = temp;
        Mirror(root->left);
        Mirror(root->right);
    }
}

// If tree is same or not
bool SameTree(Tree* T1, Tree *T2)
{
    if(T1 == NULL && T2 == NULL)
        return true;
    else if ((T1 == NULL && T2 !=NULL) || (T1 != NULL && T2 == NULL))
        return false;
    else
        return ((T1->data == T2->data) && SameTree(T1->left,T2->left) && SameTree(T1->right,T2->right));
return false;
}

// If tree is Binary Search or not
int IsBST(Tree *root)
{
    if(root == NULL)
        return true;
    else if(root->left != NULL && root ->left->data > root->data)
        return false;
    else if(root->right != NULL && root->data > root->right->data)
        return false;
    else
        return (IsBST(root->left) && IsBST(root->right));
return true;
}

// Print level With Traversal
void PrintLevelWise(Tree *root)
{
    queue<Tree*> nodeQ;
	Tree* temp = NULL;
	nodeQ.push(root);{}
	while(!nodeQ.empty()) {
        temp = nodeQ.front();
		nodeQ.pop();
		cout<<temp->data<<" ";

		if(temp->left)
			nodeQ.push(temp->left);
		if(temp->right)
			nodeQ.push(temp->right);
    }
    cout<<endl;
}

//Print Level wise traversal with next level in next line
void PrintLevel1(Tree* root)
{
	queue<Tree*> nodeQ;
	Tree* temp = NULL;
	nodeQ.push(root);
	while(!nodeQ.empty())
	{
		int levelCount = nodeQ.size();
		for(int i=0;i<levelCount;i++)
		{
			temp = nodeQ.front();
			nodeQ.pop();
			cout<<temp->data<<" ";

			if(temp->left)
				nodeQ.push(temp->left);
			if(temp->right)
				nodeQ.push(temp->right);
		}
		cout<<endl;
	}
}

// Print the tree level wise with next level in next line
void PrintLevel(Tree *root)
{
    int levelcount = 0;
    int i = 0;
    element.push_back(root);
    level.push_back(0);

    while(i < element.size())
    {
        levelcount = level[i];
        Tree * temp = element[i];

        if(temp->left != NULL)
        {
            element.push_back(temp->left);
            level.push_back(levelcount+1);
        }
        if(temp->right != NULL)
        {
            element.push_back(temp->right);
            level.push_back(levelcount+1);
        }
    i++;
    }
    cout<<element[0]->data;
    for(int i=1; i<element.size();i++)
    {
            if(level[i] != level[i-1])
                    cout<<endl;
            cout<<element[i]->data<<" ";
    }
cout<<endl;
}

//Prints the paranthesized form of a tree.
void infix_exp(Tree * p)
{
    if(p)
    {
        cout<<"("<<" ";
        infix_exp(p->left);
        cout<<p->data<<" ";
        infix_exp(p->right);
        cout<<")"<<" ";
    }
}

// Finding Binay search with recursion
// O(log n)
Tree *BinarySearchR(Tree *root, int data)
{
    if(root == NULL)
        return NULL;
    else
    {
        if(root->data == data)
            return root;
        else if(root->data < data)
            return BinarySearchR(root->right, data);
        else
            return BinarySearchR(root->left, data);
    }
return NULL;
}

//// Finding Binary search without recursion
Tree *BinarySearchI(Tree *root, int data)
{
    while(root)
    {
        if(root->data == data)
            return root;
        else if(root->data < data)
            root = root->right;
        else
            root = root->left;
    }
return NULL;
}

// Preorder Traversal without recursion happend with stack
void Preorder(Tree *root)
{
    stack<Tree*> vtree;
    vtree.push(root);

    while(!vtree.empty())
    {
        Tree *temp = vtree.top();
        vtree.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            vtree.push(temp->right);
        if(temp->left)
            vtree.push(temp->left);
    }
return;
}

// Inorder Traversal without recursion without any map
//) Create an empty stack S.
/*2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = current->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.*/
void InOrderTrav(Tree *root)
{
	Tree *current = root;
	stack<Tree*> vtree;
	while(1) {
	    if(current != NULL) {
            vtree.push(current);
            current = current->left;
        } else {
            if(!vtree.empty()) {
                Tree* temp = vtree.top();
                cout<<temp->data<<endl;
                vtree.pop();

                current = temp->right;
            } else {
                return;
            }
        }
	}
}

// Inorder Traversal without recursion
// Running time is O(n)
void InorderI(Tree *root)
{
    stack<Tree*> vtree;
    unordered_map<Tree*, int> mtree;
    vtree.push(root);

    while(!vtree.empty()) {
        Tree *temp = vtree.top();
        vtree.pop();
        if(mtree.find(temp) != mtree.end()) {
            cout<<temp->data<<endl;
        } else {
        	mtree[temp] = 1;
            // push right
            if(temp->right)
                vtree.push(temp->right);
            // push root
            vtree.push(temp);
            // push left
            if(temp->left)
        	      vtree.push(temp->left);
        }
    }
}

// Get the pointer to the nth inorder node in "nthnode"  -- TOUGH
void nthinorder(Tree *root, int n, Tree **nthnode)
{
    static int whichnode;
    static bool found;
    if(!found)
    {
        if(root)
        {
            nthinorder(root->left, n , nthnode);
            if(++whichnode == n)
            {
                printf("\nFound %dth node\n", n);
                found = 1;
                *nthnode = root; // Store the pointer to the nth node.
            }
            nthinorder(root->right, n , nthnode);
        }
    }
}

// Assuming both value exist in the list, with Binary search tree
Tree * FindLCA(Tree *root, int value1, int value2)
{
    while(root != NULL)
    {
        int value = root->data;
        if(value < value1 && value < value2)
            root = root->right;
        else if(value > value1 && value > value2)
            root = root->left;
        else
            return root;
    }
return NULL;
}

// Print all the path from root to leaf one per line
void PrintPath(Tree *root, vector<int> a)
{
    //reached at leaf node
    if(root->left == NULL && root->right == NULL)
    {
        for(int i=0; i< a.size(); i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return;
    }

    a.push_back(root->data);

    PrintPath(root->left, a);
    PrintPath(root->right, a);
}

// To find the closest Ancestor in BST
Tree * ClosestAncestorBST(Tree *root, int p, int q)
{
    if(root) {
        if (root->data < p && root->data < q)
            return ClosestAncestorBST(root->right, p , q);
        else if (root->data > p && root->data > q)
            ClosestAncestorBST(root->left, p , q);
        else
            return root;
    }
    return NULL;
}

// To find the Closest Ancestor in Binary Tree
Tree* ClosestAncestorTree(Tree* root, int p, int q)
{
    Tree * l;
    Tree * r;

    if(root == NULL)
        return NULL;
    if(root->left != NULL)
    {
        if(root->left->data == p || root->left->data == q)
                return root;
    }
    if(root->right != NULL)
    {
        if(root->right->data == p || root->right->data == q)
            return root;
    }

//	This condition if P and q are given as pointer to Node rather than, Interger
//	if(root->left->data == p || root->right->data == p || root->left->data == q || root->right->data == q)
//		return root;

    l = ClosestAncestorTree(root->left, p, q);
    r = ClosestAncestorTree(root->right, p, q);

    if(l != NULL && r != NULL)
        return root;
    else
    {
        if(l != NULL)
            return l;
        else
            return r;
    }
}

/* To find the Closest Ancestor in Binary Tree including the node it self
where we allow a node to be a descendant of itself */
Tree* ClosestAncestorTree1(Tree* root, int p, int q)
{
    Tree * l;
    Tree * r;
    if(root == NULL)
        return NULL;
    else if ((root->data == p) || (root->data == q))
        return root;

    l = ClosestAncestorTree1(root->left, p, q);
    r = ClosestAncestorTree1(root->right, p, q);

    if(l != NULL && r != NULL)
        return root;

    return (l ? l : r);
}

// To find Tree is balanced or not
int IsBalanced(Tree *root)
{
    if (root == NULL)
        return 0;

    int left = IsBalanced(root->left);
    if(left == -1)
        return -1;

    int right = IsBalanced(root->right);
    if(right == -1)
        return -1;

    if(((left - right) < -1) || ((left - right) > 1))
        return -1;
    else
        return ((left >= right)? left+1:right+1);
}

// View Top View of Tree mean
void topView(Tree * root) {
    int dimension = 0;
    map<int, Tree*> Map;
    queue<Tree*> queNode;
    queue<int> queDimension;
    queNode.push(root);
    queDimension.push(0);
    while(!queNode.empty()) {
        if(Map.find(queDimension.front()) == Map.end()) {
            Map[queDimension.front()] = queNode.front();
        }
        Tree *temp = queNode.front();
        queNode.pop();
        dimension = queDimension.front();
        queDimension.pop();

        if(temp->left) {
            queNode.push(temp->left);
            queDimension.push(dimension - 1);
        }
        if(temp->right) {
            queNode.push(temp->right);
            queDimension.push(dimension + 1);
        }
    }

    map<int, Tree*>::iterator it;
    for(it = Map.begin(); it != Map.end(); it++) {
        cout<<it->second->data<<" ";
    }
    cout<<endl;
}

//To find the successor of a node in Inorder traversal of BST
Tree *Successor(Tree *root, int data)
{
    if(root->data == data)
    {
        if(root->right != NULL)
        {
            Tree *temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
        return temp;
        }
    }

    Tree * succ = NULL;
    while(root != NULL)
    {
        if(root->data > data)
        {
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}

// To find the Inorder successor in binary tree
Tree *FindRightSuccessor(Tree *root)
{
    while (root->left)
        root = root->left;
    return root;
}

Tree *InorderSuccessor(Tree *root, int key, Tree *parent)
{
    if (root==NULL)
        return NULL;
    if (root->data == key)
    {
        if (root->right)
            return FindRightSuccessor(root->right);
        else
            return parent;
    }
    Tree *left = InorderSuccessor(root->left,key,root);
    if (left)
        return left;
    return InorderSuccessor(root->right,key,parent);
}

// Inorder Traversal without recursion
// Running time is O(n)
void InorderSuccessor1(Tree *root, int key)
{
    vector<Tree*> vtree;
    map<Tree*, int> mtree;
    vtree.push_back(root);
    bool found = false;
    while(!vtree.empty())
    {
        Tree *temp = vtree.back();
        vtree.pop_back();
        map<Tree*,int>::iterator it = mtree.find(temp);
        if(it != mtree.end() || (it->second == 1))
        {
        	if(temp->data == key)
        	{
        		found = true;
        	}
        	else if (found)
        	{
        		cout<<"successor"<<temp->data;
        		found = false;
        		break;
        	}
        }
        else
        {
        	mtree[temp] = 1;
        	 if(temp->right)
        	      vtree.push_back(temp->right);
        	 vtree.push_back(temp);

        	 if(temp->left)
        	      vtree.push_back(temp->left);
        }
    }
}

/*
Input: root node, key
output: predecessor node, successor node

1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
*/

// Inorder Traversal with recursion
// Running time is O(n)
void InorderSuccessor2(Tree *root, int key, bool &found)
{
	if (root == NULL)
	{
		return;
	}
	InorderSuccessor2(root->left, key, found);

	if (found == true)
	{
		cout<<"Successor"<<root->data<<endl;
		found = false;
		return;
	}
	if(root->data == key)
	{
		found = true;
	}
	InorderSuccessor2(root->right, key, found);
}

// TODO --- Not Sure working
int PrintNodesKDistanceFromLeaf(Tree* root, int K)
{
	if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	int disleft = 0;
	int disright = 0;
	int dis = 0;
	if (root->left)
		disleft = PrintNodesKDistanceFromLeaf(root->left, K) + 1;
	if(disleft == K)
				{cout<<root->data<<endl; dis = disright;}
	if (root->right)
		disright = PrintNodesKDistanceFromLeaf(root->right, K) + 1;
	if(disright == K)
				{cout<<root->data<<endl;dis = disleft;}
	return dis;
}

/* This function prints all nodes that are distance k from a leaf node
   path[] --> Store ancestors of a node
   visited[] --> Stores true if a node is printed as output. A node may be k
                 distance away from many leaves, we want to print it once
*/
void kDistantFromLeafUtil(Tree* node, vector<int> path, map<int, int> &visited, int k)
{
    // Base case
    if (node==NULL) return;

    /* append this Node to the path array */
    path.push_back(node->data);
    visited[node->data] = 1;

    /* it's a leaf, so print the ancestor at distance k only
       if the ancestor is not already printed  */
    map<int,int>::iterator it = visited.find(path[path.size()-k-1]);
    if (node->left == NULL && node->right == NULL &&
        path.size()-k-1 >= 0 && it == visited.end())
    {
        cout << path[path.size()-k-1] << " ";
        visited[path.size()-k-1] = 1;
        return;
    }

    /* If not leaf node, recur for left and right subtrees */
    kDistantFromLeafUtil(node->left, path, visited, k);
    kDistantFromLeafUtil(node->right, path, visited, k);
}

/* Given a binary tree and a number k, print all nodes that are k
   distant from a leaf*/
void printKDistantfromLeaf(Tree* node, int k)
{
    vector<int> path;
    map<int,int> visited;
    kDistantFromLeafUtil(node, path, visited, k);
}

// Utility function to store vertical order in map 'm'
// 'hd' is horigontal distance of current node from root.
// 'hd' is initally passed as 0
void getVerticalOrder(Tree* root, int hd, map< int, vector<int> > &m)
{
    // Base case
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[hd].push_back(root->data);

    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1, m);

    // Store nodes in right subtree
    getVerticalOrder(root->right, hd+1, m);
}

// The main function to print vertical oder of a binary tree
// with given root
void printVerticalOrder(Tree* root)
{
    // Create a map and store vertical oder in map using
    // function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd,m);

    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

/*
// This function stores the given N-ary tree in a file pointed by fp
void serialize(Tree *root, FILE *fp)
{
    // Base case
    if (root == NULL) return;

    // Else, store current node and recur for its children
    fprintf(fp, "%c ", root->data);
    for (int i = 0; i < N && root->child[i]; i++)
         serialize(root->child[i],  fp);

    // Store marker at the end of children
    fprintf(fp, "%c ", MARKER);
}

// This function constructs N-ary tree from a file pointed by 'fp'.
// This functionr returns 0 to indicate that the next item is a valid
// tree key. Else returns 0
int deSerialize(Node *&root, FILE *fp)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return 1 to indicate same
    char val;
    if ( !fscanf(fp, "%c ", &val) || val == MARKER )
       return 1;

    // Else create node with this item and recur for children
    root = newNode(val);
    for (int i = 0; i < N; i++)
      if (deSerialize(root->child[i], fp))
         break;

    // Finally return 0 for successful finish
    return 0;
}*/

// This function stores a tree in a file pointed by fp
// Preorder Traversal
void serialize(Tree *root, string &fp)
{
    // If current node is NULL, store marker
    if (root == NULL)
    {
        fp += ')';
        return;
    }

    // Else, store current node and recur for its children
//    fprintf(fp, "%d ", root->data);
    fp += to_string(root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);

}

// This function constructs a tree from a file pointed by 'fp'
void deSerialize(Tree *&root, string &fp)
{
    static int strIndex = -1;
    // Read next item from file. If theere are no more items or next
    // item is marker, then return
    if ((fp[++strIndex] == '\0') || (fp[strIndex] == ')')) return;

    int val = (fp[strIndex] - '0');
    // Else create node with this item and recur for children
    root = CreateNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

/* How to Find the max weight of tree considering all weight is represented by
node data*/


int maxW(int left, int right)
{
    if(left + right > max(left, right)) return left+right;
    else return max(left, right);
}

int MaxWeight(Tree *root, int &maxWeight)
{
    if(root) {
        int leftW = MaxWeight(root->left, maxWeight);
        int rightW = MaxWeight(root->right, maxWeight);

        int maxValue = maxW(leftW, rightW);
        if(maxWeight < maxValue + root->data)
            maxWeight = maxValue + root->data;

        return maxValue + root->data;
    }
    return 0;
}

/* Create a Tree from a Array of return root of tree*/
Tree *CreateTree(int arr[], int len, int pos)
{
   if((pos < len) && (arr[pos] != 0)) {
        Tree *node = CreateNode(arr[pos]);
        node->left = CreateTree(arr, len, 2*pos+1);
        node->right = CreateTree(arr, len, 2*pos + 2);

        return node;
   }
   return NULL;
}

/* BST Iterator with hasnext and next function */
/*
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {

    }

    // @return whether we have a next smallest number
    bool hasNext() {

    }

    //@return the next smallest number
    int next() {

    }
};*/

// Implement BFS and DFS Tree



int main()
{
    Tree *root = NULL;
    InsertRec(root, 5);
    InsertRec(root, 2);
    InsertRec(root, 7);
    InsertRec(root, 3);
    InsertRec(root, 6);
    InsertRec(root, 1);
    InsertRec(root, 4);
    //print(root);l
    Tree *root1 = NULL;
    InsertRec(root1, 5);
    InsertRec(root1, 2);
    InsertRec(root1, 7);
    InsertRec(root1, 3);
    InsertRec(root1, 6);
    InsertRec(root1, 1);
	InsertRec(root1, 4);
    InsertRec(root1, 9);
    InsertRec(root1, 10);
    InsertRec(root1, 8);

//    InOrderTrav(root);
//    vector<int> v;
//	PrintPath(root1, v);
    //insert2(root1, 4);
//	PrintTree(root1);
//    cout<<"Max Depth With Recusion "<<MaxDepth(root)<<endl;
//    cout<<"Max Depth With Iterative "<<MaxDepthI(root)<<endl;
//    cout<<endl;
 //   InorderI(root1);
//    cout<<"HI"<<endl;
//    bool found = false;
//    InorderSuccessor2(root, 1, found);
//    PrintNodesKDistanceFromLeaf(root, 2);
    //Mirror(root);
    //PrintTree(root);
    //if(int x = sametree(root,root1))
    //	cout<<"same tree"<<endl;
//	if (BinarySearchI(root1, 10))
//		cout<<"Find"<<endl;
//	else
//		cout<<"Not Found"<<endl;
//	if(int x = IsBST(root1))
    //	cout<<"same tree"<<endl;
//    PrintLevel1(root);
//    cout<<endl;
//    PrintLevel(root);
//	Preorder(root1);
//    cout<<endl;
//	Tree *temp = ClosestAncestorTree1(root1, 6, 10);
//	cout<<temp->data<<endl;
//	cout<<IsBalanced(root1)<<endl;
//    cout<<endl;
//    bool found = false;
//    cout<<"Successor ";
//    Successor(root, 4, found);
//    cout<<endl;
//    Tree *temp = NULL;
//    temp = InorderSuccessor(root, 4, NULL);
//    if(temp!= NULL)
//            cout<<"Succsor "<<temp->data<<endl;
//    else
//            cout<<"Nothin"<<endl;
//    printVerticalOrder(root);
//    printKDistantfromLeaf(root, 1);
//      Tree *temp = NULL;
//      nthinorder(root, 8, &temp);
//      if (temp)
//        cout<<"nth order "<<temp->data<<endl;
 /*   string fp;
    serialize(root, fp);
    cout<<"serialize fp "<<fp<<endl;
    Tree * root2 = NULL;
    deSerialize(root2, fp);
    PrintLevel1(root2);*/
 //   topView(root);
 int treeArr[] = {1, 2, 3, 4, 0, 6, 7, 8, 0};
    Tree * root3 = CreateTree(treeArr, 9, 0);
    PrintLevel1(root3);

return 0;
}
