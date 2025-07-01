#include<bits/stdc++.h>
using namespace std;

struct Node{

    Node* links[26];
    int endsWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    void increaseEnd(){
        endsWith++;
    }

    void decreaseEnd(){
        endsWith--;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void decreasePrefix(){
        countPrefix--;
    }

    int getEnd(){
        return endsWith;
    }

    int getPrefix(){
        return countPrefix;
    }

};

class Trie{

private: Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(!node->containsKey(s[i])){
                node->put(s[i], newNode());
            }
            node = node->get(s[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string s){
        Node* node = root;
        for(int i = 0; i<s.length(); i++){
            if(node->containsKey(s[i])){
                node = node->get(s[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
    }

};

int main(){
    
    return 0;
}