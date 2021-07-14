from pynput.keyboard import Key, Controller
import serial
import time

firstContact = False
keyboard = Controller()

ser = serial.Serial('COM4', 9600)
ser.close()
ser.open()
while True:
    data = ser.readline().decode().strip('\r\n')
    if data:
        print(data)
        if data == "map_end":
            keyboard.press(Key.space)
            keyboard.release(Key.space)
        
        if firstContact==False:
            if data == "A":
                firstContact=True
                ser.write(b"A")
                print("contact")