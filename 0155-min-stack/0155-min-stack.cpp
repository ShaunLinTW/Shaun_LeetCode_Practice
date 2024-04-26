// Two stack solution
class MinStack {
public:
    // initialize two empty stack
    stack<int> S1; // stack 1 store all element
    stack<int> S2; // stack 2 store the min elements
    
    void push(int val) {
        // if stack 1 is empty, push val to stack 2
        if (S1.empty()) S2.push(val);
        // keep the min elements in stack 2
        else if (val <= S2.top()) S2.push(val);
        // stack 1 store all element
        S1.push(val);
    }
    
    void pop() {
        // if stack 1 are empty, return null
        if (S1.empty()) return;
        // if both top of the stack are the same, pop the stack 2
        if (S1.top() == S2.top()) S2.pop();
        // also pop the stack 1 to maintain it
        S1.pop();
    }
    
    int top() {
        // if stack 1 is empty, return -1 to indicate nothing to pop from the stack
        if (S1.empty()) return -1;
        return S1.top();
    }
    
    int getMin() {
        // if stack 1 is empty, return -1 to indicate nothing to get from the stack
        if (S1.empty()) return -1;
        return S2.top(); // min element must be the top of the stack 2
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// // Linked list solution
// class MinStack {
// public:
//     struct Node {
//         int val, mn;
//         Node* next;
//         // initialize Node as NULL
//         Node(int _val, int _mn, Node* _next = NULL) {
//             val = _val;
//             mn = _mn;
//             next = _next;
//         } 
//     }*head;

//     void push(int val) {
//         // if head does not exist, create a new node
//         if (!head) head = new Node(val, val);
//         else head = new Node(val, min(val, head->mn), head);
//     }
    
//     void pop() {
//         // if head does not exist, return null
//         if (!head) return;
//         Node* temp = head;
//         head = head->next;
//         delete(temp);
//     }
    
//     int top() {
//         // if head does not exist, return -1 to indicate stack is empty
//         if (!head) return -1;
//         return head->val;
//     }
    
//     int getMin() {
//         // if head does not exist, return -1 to indicate stack is empty
//         if (!head) return -1;
//         return head->mn;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */