class Solution {
public:
    string reverseWords(string s) {
        // using stack 
        // empty case
        if (s.size() == 0) return s;
        // initialize stack to store temp result
        stack<string> st;
        // initialize string result
        string result;

        // iterate through string s, starting from beginning
        for (int i = 0; i < s.size(); i++){
            // initialize current string word
            string word;
            if (s[i] == ' ') continue; // skip spaces if there current index exist more than one space, or starting with space case
            
            // encountered word (before space), store it to current string word
            while (i < s.size() && s[i] != ' '){
                // word += s[i++];
                word += s[i];
                i++;
            }
            // once found a word, push it to stack
            st.push(word);
        }
        // after traverse overed string s, pop out the stack to the result string
        while (!st.empty()){
            result += st.top();
            st.pop();
            if (!st.empty()) result += ' '; // add space after each word
        }
        return result;
    }
};