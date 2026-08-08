class WordDictionary {
public:
    struct Trie {
        bool isEnd;
        Trie* child[26];
    };

    Trie* getNode() {
        Trie* newNode = new Trie();
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    Trie* root;
    WordDictionary() { root = getNode(); }

    void addWord(string word) {
        Trie* crawl = root;
        for (auto ch : word) {
            int idx = ch - 'a';

            if (crawl->child[idx] == NULL) {
                crawl->child[idx] = getNode();
            }
            crawl = crawl->child[idx];
        }
        crawl->isEnd = true;
    }

    bool search(string word) { return search(0, root, word); }

    bool search(int idx,  Trie* node, string word){
           if (idx == word.size()) {
            return node->isEnd;
        }
        if (word[idx] == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->child[i] != NULL) {

                    if (search(idx + 1, node->child[i], word)) {
                        return true;
                    }
                }
            }

            return false;
        }

        int x=word[idx]-'a';
        if(node->child[x]==NULL){
            return false;
        }
        return search(idx+1,node->child[x],word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */