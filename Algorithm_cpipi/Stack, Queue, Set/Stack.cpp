#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    void coutStack();
    MyStack() { top = NULL; }

};

int main() {
    MyStack *sq = new MyStack();
    sp->push(2);
    sp->push(3);
    sp->pop();
    sp->push(5);
    sp->pop();
    sp->coutStack(); // Check this def.
}



//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    StackNode*  const newNode(new StackNode(x));
    newNode-> next = top;
    top = newNode;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if ( !top ) return -1;
    const int x{top->data};
    const StackNode* const n{top};
    top = top->next;
    delete n;
    return x;
}

// Haven't checked yet. 
void MyStack ::coutStack()
{
    const StackNode* current{top};
    while (top){
        if (current){
            cout<< current->data;
            current= current->next;
        } else{
            return;
        }
    }
    
}