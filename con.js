const NetcatClient = require('netcat/client')
const nc2 = new NetcatClient()

process.stdin.pipe( nc2.addr('127.0.0.1').port(2389).connect().pipe(process.stdout).stream() )
