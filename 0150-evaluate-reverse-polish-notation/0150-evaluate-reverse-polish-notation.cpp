// clean code implementation with Stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for (auto &t: tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int num2 = S.top(); S.pop();
                int num1 = S.top(); S.pop();
                switch(t[0]){
                    case '+': S.push(num1 + num2); break;
                    case '-': S.push(num1 - num2); break;
                    case '*': S.push(num1 * num2); break;
                    case '/': S.push(num1 / num2); break;
                }
            }
            else S.push(stoi(t));
        }
        return S.top();
    }
};

// // Easy implementation with Stack
// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         // initialize a stack to store tokens
//         stack<int> S;
//         // iterate through tokens and push it into stack
//         for (int i = 0; i < tokens.size(); i++){
//             // if encountered operator, execute each operator using switch case statement
//             if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
//                 // extract 1st number and 2nd number from the top of the stack to process with operator
//                 int num1, num2;
//                 num2 = S.top(); S.pop(); // pop 2nd number first, because it's FILO
//                 num1 = S.top(); S.pop();
//                 switch(tokens[i][0]){
//                     case '+':
//                         S.push(num1 + num2);
//                         break;
//                     case '-':
//                         S.push(num1 - num2);
//                         break;
//                     case '*':
//                         S.push(num1 * num2);
//                         break;
//                     case '/':
//                         S.push(num1 / num2);
//                         break;
//                 }
//             }

//             // if encountered numbers, push it to the stack
//             else {
//                 S.push(stoi(tokens[i])); // using stoi() convert string to integer
//             }
//         }
//         return S.top(); // the top of the stack will be the summary answer
//     }
// };