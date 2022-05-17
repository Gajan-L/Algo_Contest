// Q1: Find Resultant Array After Removing Anagrams
// calculate the freq distribution of every string
// then use two pointers to skip the anagram strings
// time: O(nm); n = words.size(), m = words[i].size()
// space: O(1) if we do not count the ans

class Solution {
    string getFreq(string& s) {
        vector<int> freq(26, 0);
        for (auto& c: s){
            freq[c - 'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                res += 'a' + i;
                res += to_string(freq[i]);
            }
        }
        return res;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0, j = 0; j < n;) {
            string si = getFreq(words[i]);
            while (j < n && getFreq(words[j]) == si) j++;
            ans.push_back(words[i]);
            i = j;
        }
        
        return ans;
    }
};
