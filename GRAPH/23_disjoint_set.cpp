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
    parent[i] = 1;
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