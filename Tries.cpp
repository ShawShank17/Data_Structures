#include<bits/stdc++.h>
using namespace std;

struct Node{

    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    bool setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag==true ;
    }

};

class Trie{
    
private: Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(!node->containsKey(s[i])){
                return false;
            }
            node=node->get(s[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(!node->containsKey(s[i])){
                return false;
            }
            node=node->get(s[i]);
        }
        return true;
    }



};
