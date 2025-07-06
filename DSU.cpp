#include<bits/stdc++.h>
using namespace std;


class DisjointSet{

public:
    vector<int> parent, size, rank;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for(int i = 0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findParent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void unionByRank(int x, int y){
        int xParent = findParent(x);
        int yParent = findParent(y);
        if(xParent==yParent){
            return;
        }
        if(rank[xParent]<rank[yParent]){
            parent[xParent]=yParent;
        }
        else if(rank[yParent]<rank[xParent]){
            parent[yParent]=xParent;
        }
        else{
            parent[yParent]=xParent;
            rank[xParent]++;
        }
    }

    void unionBySize(int x, int y){
        int xParent = findParent(x);
        int yParent = findParent(y);
        if(xParent==yParent){
            return;
        }
        if(size[xParent]<size[yParent]){
            parent[xParent]=yParent;
            size[yParent]+=size[xParent];
        }
        else{
            parent[yParent]=xParent;
            size[xParent]+=size[yParent];
        }
    }

};