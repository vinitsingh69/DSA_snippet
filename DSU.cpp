
class DisjointSet
{
    vector<int> rank,parent,size;
    public:
    
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }
    void UnionBySize(int u, int v){
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];   
        }
        
    } 
};



class Solution
{
	public:
	
	
	 int spanningTree(int V, vector<vector<int>> adj[])
    {
      // int ans = 0;
      // vector<pair<int,pair<int,int>>> edges;
      // for(int i=0; i<V; i++){
      //     for(auto it : adj[i]){
      //         int u = i;
      //         int v = it[0];
      //         int wt = it[1]; 
      //         edges.push_back({wt,{u,v}});
      //     }
      // }
      
      // sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        //  for(auto i:edges){
        //     int u=i.second.first;
        //     int v=i.second.second;
        //     int wt=i.first;
        //     if(ds.findparent(u)!=ds.findparent(v)){
        //         ds.UnionBySize(u,v);
        //         ans+=wt;
        //     }
        // }
        // return ans;
    }
