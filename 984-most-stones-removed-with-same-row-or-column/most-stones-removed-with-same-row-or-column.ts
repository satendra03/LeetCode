class DisjointSet {
    parent: Map<string, string> = new Map();
    size: Map<string, number> = new Map();

    find(x: string): string {
        if (this.parent.get(x) !== x) {
            this.parent.set(x, this.find(this.parent.get(x)!));
        }
        return this.parent.get(x)!;
    }

    union(a: string, b: string): void {
        let pa = this.find(a);
        let pb = this.find(b);
        if (pa === pb) return;

        if (this.size.get(pa)! < this.size.get(pb)!) {
            this.parent.set(pa, pb);
            this.size.set(pb, this.size.get(pb)! + this.size.get(pa)!);
        } else {
            this.parent.set(pb, pa);
            this.size.set(pa, this.size.get(pa)! + this.size.get(pb)!);
        }
    }

    add(x: string): void {
        if (!this.parent.has(x)) {
            this.parent.set(x, x);
            this.size.set(x, 1);
        }
    }

    getUniqueRoots(): Set<string> {
        const roots = new Set<string>();
        for (const node of this.parent.keys()) {
            roots.add(this.find(node));
        }
        return roots;
    }
};
function removeStones(stones: number[][]): number {
    const dsu = new DisjointSet();

    for (const [x, y] of stones) {
        const row = `r-${x}`;
        const col = `c-${y}`;
        dsu.add(row);
        dsu.add(col);
        dsu.union(row, col);
    }

    const components = dsu.getUniqueRoots().size;
    const maxRemovable = stones.length - components;
    return maxRemovable;
};