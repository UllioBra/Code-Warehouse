import os
import sys

from PyQt5.QtWidgets import QApplication, QWidget, QToolTip, QPushButton
from PyQt5.QtGui import QIcon, QFont

class test (QWidget):
    
    def __init__ (self):
        super().__init__()

        self.initUI()

    def initUI (self):
        
        QToolTip.setFont(QFont('SansSerif', 10))
        self.setToolTip('Button')
        butt = QPushButton('Button1', self)
        butt.setToolTip('Button2')
        butt.resize(butt.sizeHint())
        butt.move(50, 50)

        self.setGeometry(300, 300, 300, 220)
        self.setWindowTitle('exciting')
        self.setWindowIcon(QIcon('test.jpeg'))

        self.show()

app = QApplication(sys.argv)

ex = test();

sys.exit(app.exec_())
