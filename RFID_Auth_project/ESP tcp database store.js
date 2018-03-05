var net = require('net');

var url = require('url');
var msg;

var mysql  = require('mysql');
var dbconn = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : '',
  database : 'savedata',
});


var tcpServer = net.createServer(function(socket){
		console.log('connection established....');
		socket.write('Server Reply');
		
		
		socket.on('data', function(data){
			console.log('data received from the tcp client');
			//socket.write('Server Reply: ' + data);
			
			data =data.toString();
			console.log(data);
			var adr = data;

			var q = url.parse(adr, true);
			var qdata = q.query;
			//console.log(qdata.id);


			var record= q.query;


						dbconn.query('INSERT INTO tcpdata SET ?', record, function(err,res){
						  if(err) throw err;

						  console.log('Last record insert id:', res.insertId);
						});


		});

		socket.on('end', function(){
			console.log('server disconnected..');
			});
		
		
		
		});

tcpServer.listen(8090, function(){ 

dbconn.connect(function(err){
  if(err){
    console.log('Database connection error');
  }else{
    console.log('Database connection successful');
  }
});

	console.log('server started listening...');
});