// Time : O(n * n)
// Space : O(n)

class Solution {
private:
    vector<int> parent;
    int component;
    int find(int p) {
        if (parent[p] == p) return p;
        return parent[p] = find(parent[p]);
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    void merge(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        component--;
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        parent = vector<int>(n);
        component = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] && !connected(i, j)) {
                    merge(i, j);
                }
            }
        }
        
        return component;
    }
};