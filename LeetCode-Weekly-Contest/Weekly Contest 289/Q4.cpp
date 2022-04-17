// Q4: Longest Path With Different Adjacent Characters
// read what it needs you to do!!
// I tried to get the longest path string at first, and got MLE;
// just create a k-nary tree, and do the dp
// use a helper function that retuan the Path start form this node to it's children.
// each time we get next possible candidates string and update the res;
// then we return the maxpath of it child + 1(itself);
// time: O(n), space: O(n);

struct Node {
    int index;
    char val;
    Node* parent;
    vector<Node*> children;
    Node(int i, char v) :index(i),val(v) {}
};
class Solution {
    int res = 0;
    unordered_map<int, Node*> mp;
    unordered_map<int, int> record;
    int helper(Node* node) {
        if (node->children.size() == 0) {
            res = max(res, 1);
            return record[node->index] = 1;
        }
        if(record.count(node->index)){
            return record[node->index];
        }
        priority_queue<int, vector<int>, less<int>> childList;
        for (auto childNode : node->children) {
            int child = helper(childNode);
            if (childNode->val != node->val) {
                childList.push(child);
            }
        }
        int left = 0, right = 0;
        if (childList.size()) {
            right = childList.top(); childList.pop();
        }
        if (childList.size()) {
            left = childList.top(); childList.pop();
        }
        int cur = left + right + 1;
        res = max(res,cur);
        return record[node->index] = right + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        Node* root;
        for (int i = 0; i < n; i++) {
            Node* node = new Node(i,s[i]);
            mp[i] = node;
        }
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = mp[i];
            }
            else {
                mp[parent[i]]->children.push_back(mp[i]);
                mp[i]->parent = mp[parent[i]];
            }
        }
        helper(root);
        return res;
    }
};

// below is how to get the result string
// basic the same idea
struct Node {
    char val;
    Node* parent;
    vector<Node*> children;
    Node() {}
    Node(char v) :val(v) {}
};
struct cmp {
    bool operator()(const string a, const string b) {
        return a.length() < b.length();
    }
};
class Solution {
    string res = "";
    void reverse(string& s) {
        if (s.length() == 0)
            return;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    unordered_map<Node*, string> record;
    string helper(Node* node) {
        if (node->children.size() == 0) {
            string s = "";
            s += node->val;
            if (s.length() > res.length()) {
                res = s;
            }
            return record[node] = s;
        }
        if (record.count(node)) {
            return record[node];
        }
        priority_queue<string, vector<string>, cmp> childList;
        for (auto childNode : node->children) {
            string child = helper(childNode);
            if (child[0] != node->val) {
                childList.push(child);
            }
        }
        string leftChild = "", rightChild = "";
        if (childList.size()) {
            rightChild = childList.top(); childList.pop();
        }
        if (childList.size()) {
            leftChild = childList.top(); childList.pop();
        }
        reverse(leftChild);
        string can = leftChild + node->val + rightChild;
        if (can.length() > res.length()) {
            res = can;
        }
        return record[node] = node->val + rightChild;
    }
public:
    string longestPath(vector<int>& parent, string s) {
        int n = s.length();
        unordered_map<int, Node*> mp;
        Node* root = new Node();
        for (int i = 0; i < n; i++) {
            Node* node = new Node(s[i]);
            mp[i] = node;
        }
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = mp[i];
            }
            else {
                mp[parent[i]]->children.push_back(mp[i]);
                mp[i]->parent = mp[parent[i]];
            }
        }
        helper(root);
        return res;
    }
};
