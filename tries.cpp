#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root; 
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                return false; 
            }
            node = node->get(word[i]); 
        }
        if(node->isEnd()) {
            return true; 
        }
        return false; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root; 
        for(int i = 0;i<prefix.size();i++) {
            if(!node->containsKey(prefix[i])) {
                return false; 
            }
            node = node->get(prefix[i]); 
        }
        return true; 
    }
};

int main(){
    Trie t;
    t.insert("no");
    t.insert("not");
    t.insert("news");
    t.insert("apple");
    t.insert("ape");
    if(t.startsWith("no")) cout<<"There is/are words that start with no"<<endl;
    if(t.search("news")) cout<<"There is/are word news"<<endl;
    return 0;
}