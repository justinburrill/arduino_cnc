# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM8', baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
info = [0,1,1,1]
arduino.write(bytes(str(len(info)), 'utf-8'))
for i in info:
    # time.sleep(0.05)
    value = write_read(str(i))
    print(value) # printing the value