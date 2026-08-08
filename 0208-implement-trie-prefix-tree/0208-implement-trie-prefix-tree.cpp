class Trie {
public:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26]; // arr {1,b,....z}
    };
    TrieNode* root;
    Trie() { root = getNode(); }
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(string word) {
        TrieNode* crawl = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEnd = true;
    }

    bool search(string word) {
        TrieNode* crawl = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                return false;
            }
            crawl = crawl->children[idx];
        }
        if (crawl->isEnd)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* crawl = root;
        for (auto ch : prefix) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                return false;
            }
            crawl = crawl->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */