class Solution {
    unordered_map<string, string> tmp;
    int last = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s ="http://tinyurl.com/" + to_string(last++);
        tmp[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tmp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// Another Solution(Just for fun XD)
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));