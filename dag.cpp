#include<bits/stdc++.h>
using namespace std;

void findToposort(int node,int vis[],stack<int>&st,vector<pair<int,int>>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first])
            findToposort(it.first,vis,st,adj);
    }
    st.push(node);
}

void shortestPath(int src,int n,vector<pair<int,int>>adj[]){
    int vis[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i])
            findToposort(i,vis,st,adj);
    }
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=1e9;
    }
    dis[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dis[node]!=1e9){
            for(auto it:adj[node]){
                if(dis[node]+it.second<dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i]==1e9)
            cout<<src<<": "<<i<<" -> "<<"INF"<<"\n";
        else
            cout<<src<<": "<<i<<" -> "<<dis[i]<<"\n";
    }
}



int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int a,b,wt;
    cout<<"Enter two vertices and weight between them: ";
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
    }
    int source;
    cout<<"Enter the source: ";
    cin>>source;
    shortestPath(source,n,adj);
    return 0;
}