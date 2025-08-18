class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCnt;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCnt = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); 
    }

    void insertUtil(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != NULL) {
            child = node->children[index];
        } else {
            child = new TrieNode(word[0]);
            node->childCnt++;
            node->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (root->childCnt == 1 && root->isTerminal == false) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();

        for (int i = 0; i < strs.size(); i++) {
            t->insert(strs[i]);
        }

        string ans = "";
        string first = strs[0];
        t->lcp(first, ans);
        return ans;
    }
};
// using trie
// Time: O(N⋅L)  N no of word and L is length of each word
// Space : O(N⋅L)
