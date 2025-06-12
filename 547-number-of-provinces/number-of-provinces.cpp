class DisjointSet {
public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV)
            return;
        if (rank[parentU] < rank[parentV])
            parent[parentU] = parentV;
        else if (rank[parentV] < rank[parentU])
            parent[parentV] = parentU;
        else {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }

    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV)
            return;
        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        } else if (size[parentV] < size[parentU]) {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        } else {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    dsu.unionByRank(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.parent[i] == i)
                count++;
        }
        return count;
    }
};