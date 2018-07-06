import paho.mqtt.client as mqtt
import serial
import time
ser=serial.Serial('COM3')
ser.isOpen()# open COM
ser.baudrate=9600#set baudrate to 9600
ser.bytesize=8
ser.parity='N'
ser.stopbits=1
dataA='1'
dataB='2'
dataC='3'
dataD='4'



def on_connect(client,userdata,flags,rc):
    print "I am connected to broker\n"
    client.publish('nikhilch','Already connected',1)
    client.subscribe('nikhilch',1)
def on_message(client,userdata,msg):
    
    mess=str(msg.payload)
    print mess
    if mess=='1':
        ser.write(dataA)
    elif mess=='2':
        ser.write(dataB)
    elif mess=='3':
        ser.write(dataC)
    elif mess=='4':
        ser.write(dataD)
        
        



client=mqtt.Client()
client.on_connect=on_connect
client.on_message=on_message
#client.on_disconnect=on_disconnect



client.connect('test.mosca.io',1883,120)

client.loop_start()
raw_input()
