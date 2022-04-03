// Q4: Encrypt and Decrypt Strings
// first apporach: look forward
// using Trie to store the dictionary, pruning as early as possible
// TLE!!!!!!!!!!!!!!!!!!!!!!!

struct Trie {
    bool isWord = false;
    unordered_map<char, Trie*> children;
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children.count(c))
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Encrypter {
    unordered_map<char, string> enc;
    unordered_map<string, vector<char>> dec;
    Trie* root;
    int dfs(string& w, Trie* cur, int i) {
        if (i == w.length()) 
            return cur->isWord;
        int cnt = 0;
        string s = w.substr(i, 2);
        for (auto c: dec[s]) {
            if (cur->children.count(c))
                cnt += dfs(w,cur->children[c], i+2);
        }
        return cnt;
    }
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            enc[keys[i]] = values[i];
            dec[values[i]].push_back(keys[i]);
        }
        root = new Trie();
        for (string w : dictionary) {
            root->insert(w);
        }
    }

    string encrypt(string word1) {
        string res = "";
        for (char c : word1) {
            res += enc[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return dfs(word2, root, 0);
    }
};


// second apporach: look backward
// just count the num of all encrypted word from dictionary
// Time: O(n); Space: O(n);
class Encrypter {
    unordered_map<char, string> enc;
    unordered_map<string, int> lookUp;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            enc[keys[i]] = values[i];
        }
        for (string w : dictionary) {
            lookUp[encrypt(w)]++;
        }
    }

    string encrypt(string word1) {
        string res = "";
        for (char c : word1) {
            res += enc[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return lookUp[word2];
    }
};

