const fs = require('fs');

const name = ""; // name of the directory to be created
const raedmeTemplate = 
`# ${name}

## Description

## Approach

## How to Use

1. **Compile**: \`g++ -o solution solution.cpp\`
2. **Run**: \`./solution\`

## Contact

If you have any questions, suggestions, or feedback, feel free to reach out to me:

- GitHub: [satendra03](https://github.com/satendra03)
- Email: [satendrakumarparteti.work@gmail.com](mailto:satendrakumarparteti.work@gmail.com)

Happy coding! 😊
`
function createFolderAndFiles(name) {
    if (!name) {
        console.error("Please provide a name for the folder.");
        return;
    }
    fs.mkdirSync(name);
    fs.writeFileSync(`${name}/README.md`, raedmeTemplate);
    fs.writeFileSync(`${name}/solutions.cpp`, "");
    console.log(`Folder "${name}" created successfully.`);
}

createFolderAndFiles(name);
