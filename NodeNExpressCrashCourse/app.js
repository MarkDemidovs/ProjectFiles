const http = require('http') 

// first parameter is incoming request, and res is the response which is sent to the client.
const server = http.createServer((req, res)=>{
    res.write('Welcome to our home page');
})

// port
server.listen(5000)