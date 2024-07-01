// GLOBALS - NO WINDOW!

// __dirname  - path to current directory
// __filename - file name + directory
// require    - function to use modules (CommonJS)
// module     - info about current module (file)
// process    - info about env where the program is being executed


setInterval(()=>{
    console.log(__filename);
}, 1000)