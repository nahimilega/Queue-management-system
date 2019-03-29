import serial
ser = serial.Serial('COM5',9600)  # open serial port
print(ser.name)         # check which port was really used
ser.write(b'5')     # write a string
ser.close()             # close port