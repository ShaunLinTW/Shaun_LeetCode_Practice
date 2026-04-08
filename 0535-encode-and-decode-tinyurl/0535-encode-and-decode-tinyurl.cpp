class Solution {
public:
    int counter=0;
    unordered_map<int,string> dict;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        char cmap[] = "abcdefghijklmnopqrstuvwxyz\
            ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int n = (++counter);
        string shortUrl;
        while(n){
            shortUrl.push_back(cmap[n%62]);
            n=n/62;
        }
        reverse(shortUrl.begin(), shortUrl.end());
        dict[counter] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = 0; // initialize result
        for (int i=0; i < shortUrl.length(); i++)
        {
            if ('a' <= shortUrl[i] && shortUrl[i] <= 'z')
                id = id*62 + shortUrl[i] - 'a';
            if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z')
                id = id*62 + shortUrl[i] - 'A' + 26;
            if ('0' <= shortUrl[i] && shortUrl[i] <= '9')
                id = id*62 + shortUrl[i] - '0' + 52;
        }
        return dict[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));   