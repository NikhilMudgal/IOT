var dev_ip = " ";
var dev_port = " ";
var dev_obj ;
var client;
function login() {
	var username = document.getElementById("user").value;
	var password = document.getElementById("pswd").value;
		
	if(username=='Nikhil' && password=='admin') {
		$.mobile.changePage("#home", "fade");
		document.getElementById("name").innerHTML = "Welcome <b>" + username + "</b>";
	} else {
		document.getElementById("myresult").innerHTML = "Retry";
		document.getElementById("user").value = "";
		document.getElementById("pswd").value = "";
	} 
}
$(document).ready(function(){
client=mqtt.connect('mqtt://test.mosca.io')
client.on('connect',function(){
  console.log('yay I am connected')
  client.subscribe('nikhile')
})
client.on('message',function(topic,payload){
console.log('New msg topic: '+topic+' msg: '+payload);
document.getElementById('nikhil').innerHTML=payload;
})

})
$(document).ready(function(){
	client=mqtt.connect('mqtt://test.mosca.io')
    client.on('connect',function(){
  console.log('yay I am connected')
  client.subscribe('nikhilldr')		
});
client.on('message',function(topic,payload){
console.log('New msg topic: '+topic+' msg: '+payload);
document.getElementById('ldr').innerHTML=payload;

})


});


/*--------------*/
$( document ).delegate( "#flip-1", "change", function() {

var new_toggle = $("#flip-1").val() ; 

if(new_toggle =="on") {

console.log('its on') ;
client.publish('nikhilm','a',1)
 //dev_obj.send('on');

  }

  if(new_toggle == "off" ){
  client.publish('nikhilm','b',1); 
  console.log('its off');

  	//dev_obj.send('off');


  }



//console.log(new_toggle) ;

})
