class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
    }
};

/*
Intuition:
This problem is one of the classical recursion problems.
For any given n, lets say n = 2, we have to fill four places in our output ("_ _ _ _"). And each of these places can be either filled by an open braces "(" or a closed braces ")".

Approach:
                                "_  _  _  _"
                                / \     
                              '(' ')'
For every place we have two choices and 1 decision to make.
Our choices are to either use '(' or ')'.

Now lets try to visualize the recursive tree based upon the choices discussed above.

Initially, we have:
For n = 3
current ouput = ""
availableOpenBracketsCnt = 3 and availableCloseBracketsCnt = 3

The first choise is very simple. Since we can not start a balanced parenthesis sequence with ')', we have only one choice in the begining. So our output will be '(' and count of open brackets left = 2 and count of closed brackets left = 3.
                                    op      ip
                                    ""   O-3, C-3
                            
                                    "(",O-2,C-3
                    
                "((",O-1,C-3                            "()", O-2,C-2

    "(((",0,3             "(()",1,2                       "()(",1,2

    "((()",0,2      "(()(",0,2    "(())",1,1        "()((",0,2      "()()",1,1

    "((())",0,1     "(()()",0,1   "(())(",0,1       "()(()",0,1     "()()(",0,1

    "((()))",0,0   "(()())",0,0   "(())()",0,0      "()(())",0,0    "()()()", 0,0
                        
Observation from the recursive tree:
Whenever we have count of open brackets equal to the count of close brackets, we have only one choice - that is to use '('. Because, all the brackets till now have been balanced. And we can not start a new sequence with ')'.
Whenever, count of close bracket is 0, we can only use '('.
Whenever, count of open bracket is 0, we can only use ')'.
And for all the remaining cases, we have both the choices.
We get an answer, when count of open == 0 and count of close == 0.
Just convert these 5 observations into an algorithm and write the code.

*/

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// 1st approach:
// class Solution {
// public:
//     void solve(string op, int open, int close, vector<string> &ans){
//         if(open == 0 && close == 0){
//             ans.push_back(op);
//             return;
//         }
//         //when count of open and close brackets are same then 
//         //we have only one choice to put open bracket 
//         if(open == close){
//             string op1 = op;
//             op1.push_back('(');
//             solve(op1, open-1, close, ans);
//         }
//         else if(open == 0){
//             //only choice is to put close brackets 
//             string op1 = op;
//             op1.push_back(')');
//             solve(op1, open, close-1, ans);
//         }
//         else if(close == 0){
//             //only choise is to use open bracket 
//             string op1 = op;
//             op1.push_back('(');
//             solve(op1, open-1, close, ans);
//         }
//         else{
//             string op1 = op;
//             string op2 = op;
//             op1.push_back('(');
//             op2.push_back(')');
//             solve(op1, open-1, close, ans);
//             solve(op2, open, close-1, ans);
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         int open = n;
//         int close = n;
//         vector<string> ans;
//         string op = "";
//         solve(op, open, close, ans);
//         return ans;
//     }
// };

// 2nd approach:
// class Solution {
//     private:
//     void solve(int cnt1,int cnt2,int n,vector<string> &ans,string &op,int ind)
//     {
//         if(ind>=n*2)
//         {
//             ans.push_back(op);
//             return;}
//         if(cnt1<n and ind<n*2-1)
//         {
//             op+='(';
//             solve(cnt1+1,cnt2,n,ans,op,ind+1);
//             op.pop_back();
//         }
        
//         if(cnt2<cnt1 and ind>0)
//         {
//             op+=')';
 
//             solve(cnt1,cnt2+1,n,ans,op,ind+1);
//             op.pop_back();
//         }
        
//     }
// public:
//     vector<string> generateParenthesis(int n) {
//          string op="";
//         vector<string> ans;
//         solve(0,0,n,ans,op,0);
//         return ans;
//     }
// };

// int main() {
//     Solution solution;
//     int n = 3;
//     vector<string> result = solution.generateParenthesis(n);
//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << endl;
//     }
//     cout << endl;

//     int n2 = 1;
//     vector<string> result2 = solution.generateParenthesis(n2);
//     for (int i = 0; i < result2.size(); i++) {
//         cout << result2[i] << endl;
//     }
//     return 0;
// }

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]   
// example 2:
// Input: n = 1
// Output: ["()"]
// Constraints:
// 1 <= n <= 8