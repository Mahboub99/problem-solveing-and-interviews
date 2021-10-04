#include <bits/stdc++.h> 

using namespace std ; 

class TrieNode {
public:
    TrieNode *children[26]{};
    bool isWord;

    TrieNode() {
        isWord = false;
        for (auto &child : children) {
            child = nullptr;
        }
    }
};

class Trie {

private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    Trie(vector<string> words) {
        root = new TrieNode();
        for (auto &word : words) {
            insert(word);
        }
    }

    void insert(const string &word) {
        TrieNode *pCrawl = root;
        for (char c : word) {
            int idx = c - 'a';
            if (pCrawl->children[idx] == nullptr) {
                pCrawl->children[idx] = new TrieNode();
            }
            pCrawl = pCrawl->children[idx];
        }
        pCrawl->isWord = true;
    }

    bool search(const string &word) {
        TrieNode *pCrawl = root;
        for (char c : word) {
            int idx = c - 'a';
            if (pCrawl->children[idx] == nullptr) {
                return false;
            }
            pCrawl = pCrawl->children[idx];
        }
        return (pCrawl->isWord);
    }

};

int main(){
   
    vector<string> vec = {"the", "a", "there",
                          "answer", "any", "by",
                          "bye", "their"};

    Trie t(vec);
    t.search("the") ? cout << "Yes\n" :
    cout << "No\n";
    t.search("these") ? cout << "Yes\n" :
    cout << "No\n";

  return 0;
}
