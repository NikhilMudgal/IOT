import paho.mqtt.client as mqtt
import serial
import time
ser=serial.Serial('COM3')
ser.isOpen()# open COM
ser.baudrate=9600#set baudrate to 9600
ser.bytesize=8
ser.parity='N'
ser.stopbits=1
def on_connect(client,userdata,flags,rc):
    print "I am connected to broker\n"
    client.subscribe('ledint',2)
def on_message(client,userdata,msg):
    mess=str(msg.payload)
    ser.write(mess)
    print mess

client=mqtt.Client()
client.on_connect=on_connect
client.on_message=on_message
#client.on_disconnect=on_disconnect
client.connect('ledint',1883,120)
client.loop_start()
raw_input()
