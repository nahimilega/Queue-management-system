


import maincode
import sys
from PyQt5.QtWidgets import QMainWindow, QPushButton, QApplication,QLabel,QWidget,QHBoxLayout, QFrame, QSplitter, QStyleFactory
from PyQt5.QtCore import Qt
from PyQt5.QtGui import *
from PyQt5.QtGui import QIcon, QPixmap

listAlerts=["Some one cut the que","Someone not standing propery"]


class Example(QMainWindow):
    
    def __init__(self):
        super().__init__()
        
        self.initUI()
        
        
    def initUI(self):      

        btn1 = QPushButton("ON", self)
        btn1.move(200, 50)
        btn1.resize(100,40)

        btn2 = QPushButton("OFF", self)
        btn2.move(420, 50)
        btn2.resize(100,40)
        
      
        btn1.clicked.connect(self.buttonClicked)            
        btn2.clicked.connect(self.buttonClicked2)
        btn1.setStyleSheet("background-color: white;font-weight: bold;font-size: 20px")
        btn2.setStyleSheet("background-color: white;font-weight: bold;font-size: 20px")
        self.lbl = QLabel(self)
        self.lbl.move(60, 700)      
        self.lbl.setText("Alerts : ")
        
        self.checkAlerts()

        self.lbl.setStyleSheet("QLabel { background-color : black; color : white;font-size: 30px;font-weight: bold; }");
        self.lbl.adjustSize()



        self.statusBar()
        
        self.setGeometry(200, 100, 1000, 900)
        self.setWindowTitle('QWERTY - Queue Management System')
        self.setStyleSheet("background-color: black;")
        image = QLabel(self)
    
        image.setGeometry(200, 140, 640, 480)            #Graph
        pixmap = QPixmap("day_Graph.png")
        #pixmap = pixmap.scaled(320, 140, Qt.KeepAspectRatio, Qt.FastTransformation)
        #self.resize(pixmap.width(),pixmap.height())
        image.setPixmap(pixmap)
        #image.show()
        self.show()
        
        
    def buttonClicked(self):
        print("ON")
        #sender = self.sender()
        #self.statusBar().showMessage(sender.text() + ' was pressed')

    def buttonClicked2(self):
        print("OFF")
        maincode.switch_off()
        #sender = self.sender()
        #self.statusBar().showMessage(sender.text() + ' was pressed')    

    def checkAlerts(self):
        self.alertMessage=QLabel(self)
        self.alertMessage.move(60, 760)         #message
        self.alertMessage.setText(listAlerts[1])
        self.alertMessage.setStyleSheet("QLabel { background-color : black; color : white;font-size: 20px;font-weight: bold; }");
        self.alertMessage.adjustSize()    
        
        
if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())