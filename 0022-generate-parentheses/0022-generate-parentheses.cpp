class Solution {
public:
    void solve(string op, int open, int close, vector<string> &result){
        // if no more open and close brackets, return
        if (open == 0 && close == 0){
            result.push_back(op);
            return;
        }
        // when open and close brackets are same, push open bracket first to the stack
        if (open == close){
            string op1 = op;
            op1.push_back('(');
            // decrease a open bracket, and keep recursively call solve function to generate all combinations
            solve(op1, open - 1, close, result);
        }
        // when no more open bracket, push close bracket to the stack
        else if (open == 0){
            string op1 = op;
            op1.push_back(')');
            // decrease close bracket, and keep recursively call solve function to generate all combinations
            solve(op1, open, close - 1, result);
        }
        // when no more close bracket, push open bracket to the stack
        else if (close == 0){
            string op1 = op;
            op1.push_back('(');
            // decrease open bracket, and keep recursively call solve function to generate all combinations
            solve(op1, open - 1, close, result);
        }
        // other conditions, keep generate a pair of parentheses and push it back to the stack
        else {
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open - 1, close, result);
            solve(op2, open, close - 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        // initialize open bracket and close bracket as input n pairs of parentheses
        int open = n;
        int close = n;

        // initialze a stack result vector to store all generated combinations of well-formed parentheses
        vector<string> result;
        
        // call solve helper function to get all combinations
        solve("", open, close, result);
        return result;
    }
};

/*
Initially, we have:
For n = 3

Dry run:
                                    op      ip
                                    ""   O-3, C-3
                            
                                    "(",O-2,C-3
                    
                "((",O-1,C-3                            "()", O-2,C-2

    "(((",0,3             "(()",1,2                       "()(",1,2

    "((()",0,2      "(()(",0,2    "(())",1,1        "()((",0,2      "()()",1,1

    "((())",0,1     "(()()",0,1   "(())(",0,1       "()(()",0,1     "()()(",0,1

    "((()))",0,0   "(()())",0,0   "(())()",0,0      "()(())",0,0    "()()()", 0,0

*/