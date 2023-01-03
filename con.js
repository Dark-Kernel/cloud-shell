const NetcatClient = require('netcat/client')
const nc2 = new NetcatClient()

process.stdin.pipe( nc2.addr('https://cloud-shell.onrender.com').port(2389).connect().pipe(process.stdout).stream() )
