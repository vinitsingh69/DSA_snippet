
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
