/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {
    Trie* child[26];
    bool flag;
public:

    /** Initialize your data structure here. */
    Trie() {
        flag = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur =   this;
        for(int i = 0; i < word.length(); i++)
        {
            if(!cur -> child[word[i] - 'a'])
                cur -> child[word[i] - 'a'] = new Trie;
            cur = cur -> child[word[i] - 'a'];
        }
        cur->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(int i = 0; i < word.length(); i++)
        {
            if(cur -> child[word[i] - 'a'] == NULL)
                return false;
            cur = cur -> child[word[i] - 'a'];
        }
        if(cur -> flag == true)
            return true;
        else 
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(cur -> child[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur -> child[prefix[i] - 'a'];
        }
        return true;
    }
};
