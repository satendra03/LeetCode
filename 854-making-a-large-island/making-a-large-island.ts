const getKey = (x: number, y: number): string => `r${x},c${y}`;
const add = (coords: string, parent: Map<string, string>, size: Map<string, number>): void => {
    if (!parent.has(coords)) {
        parent.set(coords, coords);
        size.set(coords, 1);
    }
}
const find = (coord: string, parent: Map<string, string>, size: Map<string, number>): string => {
    if (parent.get(coord)! !== coord) parent.set(coord, find(parent.get(coord)!, parent, size));
    return parent.get(coord)!;
}
const union = (a: string, b: string, parent: Map<string, string>, size: Map<string, number>): void => {
    let pa = find(a, parent, size)!;
    let pb = find(b, parent, size)!;
    if (pa == pb) return;

    if (size.get(pa) < size.get(pb)) {
        parent.set(pa, pb);
        size.set(pb, size.get(pa)! + size.get(pb)!);
    } else {
        parent.set(pb, pa);
        size.set(pa, size.get(pb)! + size.get(pa)!);
    }
}
const getMaxSize = (size: Map<string, number>): number => {
    let maxSize = 0;
    for (let key of size.keys()) {
        maxSize = Math.max(size.get(key)!, maxSize);
    }
    return maxSize;
}
class DisjointSet {
    parent: Map<string, string> = new Map();
    size: Map<string, number> = new Map();

    add(coords: string): void {
        if (!this.parent.has(coords)) {
            this.parent.set(coords, coords);
            this.size.set(coords, 1);
        }
    }

    find(coord: string): string {
        if (this.parent.get(coord)! !== coord) this.parent.set(coord, this.find(this.parent.get(coord)!));
        return this.parent.get(coord)!;
    }

    union(a: string, b: string): void {
        let pa = this.find(a)!;
        let pb = this.find(b)!;
        if (pa == pb) return;

        if (this.size.get(pa) < this.size.get(pb)) {
            this.parent.set(pa, pb);
            this.size.set(pb, this.size.get(pa)! + this.size.get(pb)!);
        } else {
            this.parent.set(pb, pa);
            this.size.set(pa, this.size.get(pb)! + this.size.get(pa)!);
        }
    }

    getMaxSize(): number {
        let maxSize = 0;
        for (let key of this.size.keys()) {
            maxSize = Math.max(this.size.get(key)!, maxSize);
        }
        return maxSize;
    }
};
function largestIsland(grid: number[][]): number {
    let n = grid.length;
    let px = [1, 0, -1, 0];
    let py = [0, 1, 0, -1];
    let dsu = new DisjointSet();

    let zeros: [number, number][] = [];

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let key = getKey(i, j);
            if (grid[i][j]) {
                dsu.add(key);
                for (let ptr = 0; ptr < 4; ptr++) {
                    let newX = i + px[ptr];
                    let newY = j + py[ptr];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY]) {
                        let newKey = getKey(newX, newY);
                        dsu.add(newKey);
                        dsu.union(key, newKey);
                    }
                }
            } else zeros.push([i, j]);
        }
    }

    let ans = 0;
    ans = Math.max(ans, dsu.getMaxSize());

    // for (let [x, y] of zeros) {
    //     const key = getKey(x,y);
    //     grid[x][y] = 1;
    //     let sizeCopy = new Map(dsu.size);
    //     let parentCopy = new Map(dsu.parent);
    //     add(key, parentCopy, sizeCopy);
    //     for (let ptr = 0; ptr < 4; ptr++) {
    //         let newX = x + px[ptr];
    //         let newY = y + py[ptr];
    //         if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY]) {
    //             let newKey = getKey(newX, newY);
    //             add(newKey, parentCopy, sizeCopy);
    //             union(key, newKey, parentCopy, sizeCopy);
    //         }
    //     }
    //     ans = Math.max(ans, getMaxSize(sizeCopy));
    //     grid[x][y] = 0;
    // }


    for (let [x, y] of zeros) {
        const key = getKey(x, y);
        const seen = new Set<string>();
        let combinedSize = 1;

        for (let dir = 0; dir < 4; dir++) {
            let newX = x + px[dir], newY = y + py[dir];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY]) {
                let neighborKey = getKey(newX, newY);
                let root = dsu.find(neighborKey);
                if (!seen.has(root)) {
                    seen.add(root);
                    combinedSize += dsu.size.get(root)!;
                }
            }
        }

        ans = Math.max(ans, combinedSize);
    }

    return ans;

};