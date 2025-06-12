class DisjointSet {
    rank: number[];
    size: number[];
    parent: number[];

    constructor(n: number) {
        this.rank = new Array(n + 1).fill(0);
        this.size = new Array(n + 1).fill(1);
        this.parent = new Array(n + 1);
        for (let i = 0; i <= n; i++) {
            this.parent[i] = i;
        }
    }

    findParent(node: number): number {
        if (this.parent[node] === node) return node;
        return (this.parent[node] = this.findParent(this.parent[node]));
    }

    unionBySize(u: number, v: number): boolean {
        const parentU = this.findParent(u);
        const parentV = this.findParent(v);

        if (parentU === parentV) return true;

        if (this.size[parentU] < this.size[parentV]) {
            this.parent[parentU] = parentV;
            this.size[parentV] += this.size[parentU];
        } else {
            this.parent[parentV] = parentU;
            this.size[parentU] += this.size[parentV];
        }
        return false;
    }
}

function makeConnected(n: number, connections: number[][]): number {
    if (connections.length < n-1) return -1;

    let dsu = new DisjointSet(n);
    for (let [a, b] of connections) dsu.unionBySize(a, b);

    let count = 0;
    for(let i=0; i<n; i++){
        if(dsu.parent[i] == i) count++;
    }
    return count-1;

};