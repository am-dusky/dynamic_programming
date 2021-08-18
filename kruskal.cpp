#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a,node b){
    return a.wt<b.wt;
}

int findpar(int u,vector<int>&parent){
    if(u==parent[u])
        return u;
    return findpar(parent[u],parent);
}

void union1(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int main(){

    int n,m;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>m;

    vector<node>edges;

    for(int i=0;i<m;i++){
        cout<<"\nEnter the nodes and wt between them : ";
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }

    sort(edges.begin(),edges.end(),comp);

    vector<int>parent(n);

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    vector<int>rank(n,0);

    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges){
        if(findpar(it.u,parent)!=findpar(it.v,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            union1(it.u,it.v,parent,rank);
        }
    }

    cout<<"\nThe mst of the graph is: "<<cost<<endl;
    cout<<"The corresponding edges are between :\n";
    for(auto it:mst){
        cout<<it.first<<"-"<<it.second<<endl;
    }
    return 0;
}