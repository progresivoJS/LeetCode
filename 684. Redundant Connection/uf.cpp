// Time : O(n), more concisely O(n * log*(n))
// Space : O(n)

class Solution {
private:
    vector<int> parent;
    int find(int p) {
        if (p == parent[p]) {
            return p;
        }
        return parent[p] = find(parent[p]);
    }
    
    void merge(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n + 1);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int w = edges[i][1];
            if (connected(v, w)) return edges[i];
            merge(v, w);
        }
        return vector<int>();
    }
};