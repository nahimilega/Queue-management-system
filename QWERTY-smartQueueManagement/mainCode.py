import serial
import datetime

guiIndex = 0

class person:
    def __init__(self):
        self.duration = 0
        self.score = 0

one = person()
two = person()
three = person()

def f():
    arduino.write('1'.encode())
def switchOff():
    arduino.write('0'.encode())

gameIndex = 0

try:
    arduino = serial.Serial("/dev/ttyACM0", baudrate = 2000000, timeout = 0)
    arduino1 = serial.Serial("/dev/ttyACM1", baudrate = 2000000, timeout = 0)
    # arduino2 = serial.Serial("/dev/ttyACM2", baudrate = 2000000, timeout = 0)


except:

    print("check port connections")


def driverFunction(a):
    global gameIndex

    
    if gameIndex == 0 and a.find("main mat on") != -1:
        gameIndex = 1
        
        

    if gameIndex == 1 and a.find("mat 1 on") != -1:
        gameIndex = 2
    
    if gameIndex == 2 and a.find("mat 2 on") != -1:
        gameIndex == 3

    if gameIndex != 0 and a.find("***main") != -1:
       
        if gameIndex == 2:
            number = int(a[int(a.find('p')) + 1])
            if number == 1:
                one.duration += int(a[int(a.find('d')) + 1 :int(a.find('mat1')) - 1])
                two.duration += int(a[int(a.rfind('d')) + 1 :int(a.rfind('s')) - 1])

            elif number == 2:
                two.duration += int(a[int(a.rfind('d')) + 1 :int(a.rfind('s')) - 1])
            
            gameIndex = 0

            

        if gameIndex == 3:
            number = int(a[int(a.find('p')) + 1])
            if number == 1:
                one.duration += int(a[int(a.find('d')) + 1 :int(a.find('mat1')) - 1])
                two.duration += int(a[int(a.find('d')) + 1 :int(a.rfind('s')) - 1])
                three.duration += int(a[int(a.rfind('d')) + 1 :int(a.rfind('s')) - 1])

            elif number == 2:
                two.duration += int(a[int(a.rfind('d')) + 1 :int(a.rfind('s')) - 1])
            
            gameIndex = 0
    
    if gameIndex == 3 and a.find(" mat3 p") != -1:
        gameIndex = 2
        three.duration += int(a[int(a.rfind('d')) + 1 :int(a.rfind('s')) - 1])


    if gameIndex >= 2 and a.find("***mat1") != -1:
        gameIndex = 1




while True:
    

    if gameIndex == 0:
        arduino.write('1'.encode())
    if(gameIndex == 0 or gameIndex == 1):
        while arduino.inWaiting() != 0:
            
            a = str(arduino.readlines()) 
            print(a)
            driverFunction(a)

    elif gameIndex == 2:

        arduino1.write('1'.encode())
        
        while arduino1.inWaiting() != 0:
            
            b = str(arduino1.readlines())
            print(b)
            driverFunction(b)

