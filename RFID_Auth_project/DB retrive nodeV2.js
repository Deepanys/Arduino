var mysql = require('mysql');
var http = require('http');


//var reo ='{${table}}';

http.createServer(function (req, response) {


  var con = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : '',
  database : 'savedata',
});


              con.connect(function(err) {
                
                  if (err) throw err;
              //Select all customers and return the result object:
              con.query("SELECT * FROM tcpdata ORDER BY No DESC", function (err, res, fields) {
                if (err) throw err;
               
                var table =''; //to store html table

      //create html table with data from res.
      for(var i=0; i<res.length; i++){
        table +='<tr><td>'+ res[i].No +'</td><td>'+ res[i].id +'</td><td>'+ res[i].mode +'</td></tr>';
      }
      //table ='<center><table border="1"><tr><th>Nr.</th><th>ID</th><th>MODE</th></tr>'+ table +'</table></center>';


  table ='<html><head><meta http-equiv="refresh" content="1"><style>#customers {font-family: "Trebuchet MS", Arial, Helvetica, sans-serif; border-collapse: collapse; width:50%;}#customers td, #customers th { border: 1px solid #ddd;  padding: 8px;}#customers tr:nth-child(even){ background-color: #f2f2f2;}#customers tr:hover {background-color: #ddd;}#customers th {   padding-top: 12px; padding-bottom: 12px;  text-align: center;   background-color: #4CAF50;   color: white;}#customers td{text-align:center;}</style></head><body><center><h3>RF ID</h3><table id="customers"><tr><th>No</th><th>ID</th><th>Mode</th></tr>'+ table +'</table></center></body></html>';      



              //create a server object:
            
   // reo = reo.replace('{${table}}', resql);
    //response.write(200, {'Content-Type':'text/html; charset=utf-8'});
    response.write(table, 'utf-8');
    response.end();
    console.log("\thtml ready")
//end the response


                                   con.end(function(err)     
                                    {
                                      if (err) throw err;
                                                // Function to close database connection
                                          });
  });//

});


            }).listen(8091); //the server object listens on port 8080

