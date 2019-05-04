// Evaluating boolean expressions
// Design a data structure that can model boolean expressions.
// We need to support nodes that are one of three kinds:
// 1. Literal nodes (true, false)
// 2. Variable nodes ("A", "B", "hello", "justastring")
// 3. Operators: And, Or, Not
//
//            !(A&B)               !         A|t
//                                &
//                               A B
//
// Implement instance method `bool evaluate(map<string, bool> varAssignments);`

#include <iostream>
#include <unordered_map>
using namespace std;


enum Type {
  OPERATOR=1, LITERAL=2, VARIABLE=3
};

typedef struct TreeNode {
  string val;
  Type ty;
  struct TreeNode *left;
  struct TreeNode *right;

} Node;

class ExpressionTree {
  Node *Root;

  Node *createNode(string val, Type ty) {
    Node *nw = new Node;
    nw->val = val;
    nw->ty = ty;
    nw->left = NULL;
    nw->right = NULL;

    return nw;
  }

  public:
    ExpressionTree() {
      Root=NULL;
    }

    void AddNode(Node *&temp, string val, Type ty) {
        if(Root) {
          temp = createNode(val, ty);
        } else {
          Root =  createNode(val, ty);
          temp = Root;
        }
    }

    bool evaluate(unordered_map<string, bool> &varAssigns) {
      return evaluate_tree(Root, varAssigns);
    }

    bool evaluate_tree(Node *root, unordered_map<string, bool> &varAssigns) {
      if(root->ty == VARIABLE) {
        if(varAssigns.find(root->val) != varAssigns.end()) {
          //  cout<<root->val<<endl;
            return varAssigns.find(root->val)->second;
        } else throw "not found value";
      }
      if(root->ty == LITERAL) {
        return (root->val == "TRUE");
      }
      if(root->ty == OPERATOR) {
        if(root->val == "!")  return (!(evaluate_tree(root->left, varAssigns)));
        else if(root->val == "&")  return (evaluate_tree(root->left, varAssigns) &&
                             evaluate_tree(root->right, varAssigns));
        else if(root->val == "|") return (evaluate_tree(root->left, varAssigns) ||
                             evaluate_tree(root->right, varAssigns));
        else  throw "Not Supported Operators";
      }
      throw "Not Supported TYPE";
    }
};


// To execute C++, please define "int main()"
int main() {

  // Instantiate example !(A&B)
  ExpressionTree ET;
  Node *root = NULL;
  ET.AddNode(root,"!", OPERATOR);
  ET.AddNode(root->left, "&", OPERATOR);
  ET.AddNode(root->left->left, "A", VARIABLE);
  ET.AddNode(root->left->right, "B", VARIABLE);

  unordered_map<string, bool> testAssignments;
  testAssignments["A"] = true;
  testAssignments["B"] = true;

  if(ET.evaluate(testAssignments)) {
    cout<<"Value is True"<<endl;
  } else  cout<<"Value is False"<<endl;

  return 0;
}
