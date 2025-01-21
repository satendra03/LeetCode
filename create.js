const fs = require('fs');

const name = "Undirected Graph Cycle";
function createFolderAndFiles(name) {
    if (!name) {
        console.error("Please provide a name for the folder.");
        return;
    }
    fs.mkdirSync(name);
    fs.writeFileSync(`${name}/README.md`, "");
    fs.writeFileSync(`${name}/solutions.cpp`, "");
    console.log(`Folder "${name}" created successfully.`);
}

createFolderAndFiles(name);
