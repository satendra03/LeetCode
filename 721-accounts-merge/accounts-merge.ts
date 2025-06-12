class DisjointSet {
    parent: Map<string, string> = new Map();
    rank: Map<string, number> = new Map();
    name: Map<string, string> = new Map();

    add(name: string, mail: string): void {
        if(!this.parent.has(mail)) {
            this.parent.set(mail, mail);
            this.rank.set(mail, 1);
            this.name.set(mail, name);
        }
    }

    find(mail: string): string{
        if(this.parent.get(mail)! === mail) return mail;
        let par = this.find( this.parent.get(mail)! );
        this.parent.set(mail, par); 
        return par;
    }

    union(mail1: string, mail2: string) {
        let p1 = this.find(mail1);
        let p2 = this.find(mail2);
        if(p1 == p2) return;

        if(this.rank.get(p1)! < this.rank.get(p2)!) {
            this.parent.set(p1, p2);
            this.rank.set(p2, this.rank.get(p1)! + this.rank.get(p2)!);
        } else {
            this.parent.set(p2, p1);
            this.rank.set(p1, this.rank.get(p1)! + this.rank.get(p2)!);
        }
    }
};
function accountsMerge(accounts: string[][]): string[][] {
    let dsu = new DisjointSet();
    for(let data of accounts) {
        let name = data[0];
        for(let i=1; i<data.length; i++) dsu.add(name, data[i]);
        for (let i = 2; i < data.length; i++) dsu.union(data[1], data[i]);
    }

    const merged = new Map<string, string[]>();
    for (const mail of dsu.parent.keys()) {
        const root = dsu.find(mail);
        if (!merged.has(root)) merged.set(root, []);
        merged.get(root)!.push(mail);
    }

    let ans: string[][]=[];
    for (const [root, emails] of merged) {
        emails.sort();
        const name = dsu.name.get(root)!;
        ans.push([name, ...emails]);
    }
    return ans;
};