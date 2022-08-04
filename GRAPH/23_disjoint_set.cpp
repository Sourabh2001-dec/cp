// Rough code of Disjoint Set Union


#include <bits/stdc++.h>
using namespace std;

int n = 10000;
int parent[10000];
int rank[10000];

void makeSet()
{
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
}

int findPar(int node){
  if(node == parent[node]) return node;

  // path compression
  return parent[node] = findPar(parent[node]);
}

void union(int u, int v){
  int parU =  findPar(u);
  int parV = findPar(v);

  if(rank[parU] < rank[parV]){
    parent[parU] = parV;
  }
  else if(rank[parU] > rank[parv]){
    parent[parV] = parU;
  }
  else{
    rank[parU]++;
    parent[parV] = parU;
  }
}

int main(){
  int i,j;
  if(findPar(i) == findPar(j)){
    cout << "Present in same component";
  }
  else{
    cout << "Not in same compoent";
  }
  return 0;
}


// sample code

struct DSU{
    vi dsu, szx;
 
    DSU() = default;
    DSU(int n) : dsu(n), szx(n, 1) { 
        for(int i=0; i<n; i++) dsu[i] = i;
    }
    
    int parent(int i){
        if(dsu[i]==i) return i;
        else return dsu[i] = parent(dsu[i]);
    }
 
    int size(int i) { return szx[parent(i)]; }
    int operator[](int i){ return parent(i); }
    int num_comps(){
        int ct = 0;
        for(int i=0; i<sz(dsu); i++) if(dsu[i] == i) ct++;
        return ct;
    }
 
    void unify(int a, int b){
        a = parent(a);
        b = parent(b);
        if(szx[a] < szx[b]) swap(a, b);
        if(a!=b) dsu[b] = a, szx[a] += szx[b];
    }
};