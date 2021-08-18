#include<bits/stdc++.h>
using namespace std;

void toposort(int n,vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i])
            indegree[it]++;
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
   for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    toposort(n,adj);
    return 0;
}