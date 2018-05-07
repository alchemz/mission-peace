/*
example tree:. 
     1
   / | \
  2  3  4. 
/|\    |.
5 8 6   7
   / \
  9   10
*/

struct Node {
Node* parent;
Node* first_sibling; // note: not prev_sibling
Node* next_sibling;
Node* first_child;
Node* last_child;
};

Node* find_prev_node(Node* input);

example tree:
     1
   / | \
  2  3  4
/|\    |
5 8 6   7
   / \
  9   10

2. int frequency

class DetectTriples {

public:
// Calls InvokeTripleAction if the last three ints accepted are equal
void AcceptNumber(int i); // <- write this

private:. from: 1point3acres.com/bbs 
void InvokeTripleAction(int i) {
   Log.output("found 5 in a row");
}
};

像这样子调用：
DetectTriples dt;
dt.AcceptNumber(5);
dt.AcceptNumber(5);
dt.AcceptNumber(5); "found". 
dt.AcceptNumber(5); "found"
dt.AcceptNumber(4); 
dt.AcceptNumber(5);
dt.AcceptNumber(5);
