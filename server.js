var init = false ;
var WebSocketServer = require('ws').Server
  , wss = new WebSocketServer({port: 8008});
// var WebSocket = require('ws'), ws = new WebSocket('http://192.168.1.11:8004');
//var socket = require('socket.io-client')('http://encypher.local/abc');
//var socket = require('socket.io-client')('http://localhost:8008/cabin');

var status_id ; 

var res ;

var host = "localhost", port_robo = 30001 , port_rfid = 30002 , port_graph = 30003 , port_sys = 30017 ; // udp servers 

var dgram = require( "dgram" );

var client = dgram.createSocket( "udp4" );


function send_data_udp(msg, port){


var message = new Buffer(msg);
client.send(message, 0, message.length,port, host );


}


wss.on('connection', function(ws) {

    console.log("connected");

    ws.on('message', function(message) {

      send_data_udp(message , port_graph) ;

     console.log('received: %s', message);


    });



  client.on( "message", function( msg, rinfo ) {
   var message = msg.toString("utf-8", 0, 20);

   console.log( message );
 //  console.log( msg );
 /* In ack what is -1.Device ID  , 2.Switch , 3. Status  || In  stack -1.Device ID  , 2.Switch , 3. Status to be  changed  */

   // res = message.split(":");

   // ack.id = res[0];
   // ack.dev= res[1];
   // ack.status=res[2];

   // console
//   var data = message ;
  // send_data_udp( data, port_sys);

});

  

});