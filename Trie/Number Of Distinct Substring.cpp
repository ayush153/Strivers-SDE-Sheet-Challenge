#include <bits/stdc++.h> 
struct Node{
    Node* child[26];
    bool containsKey(char ch){
        return (child[ch - 'a'] != NULL);
    }
    Node* get(char ch){
        return (child[ch - 'a']);
    }
    void set(Node* node , char ch){
        child[ch - 'a'] = node;
    }
};

class Trie{
    Node *root ;
    public:
    Trie()
    {
        root = new Node();
    }
    
    public:
    void insert(string word,int &ans){
        Node* node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node -> set(new Node(), word[i]);
                ans++;
            }
            node = node -> get(word[i]);
        }
    }
};

int distinctSubstring(string &word) {
    //  Write your code here.
    int ans = 0;
    Trie trie;
    
    for(int i = 0; i < word.length(); i++)
    {
        string st = "";
        for(int j = i; j < word.length(); j++)
        {
            st += word[j];
            trie.insert(st,ans);
        }
    }
    return ans;
}

