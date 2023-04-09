## Cloud shell.


To upload a file: 
```bash
curl -F "filee=@<filename>" "https://<appname>.onrender.com"
```

To download your file:  
```bash
curl "https://<appname>.onrender.com/files/<filename>" -O
```

To get the list of stored files: 
```bash
curl "https://<appname>.onrender.com/list"
```
