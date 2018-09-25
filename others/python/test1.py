<<<<<<< HEAD
import os
import sys
from random import randint

from PyQt5.QtCore import QCoreApplication
from PyQt5.QtGui import QFont, QIcon
from PyQt5.QtWidgets import (QApplication, QLineEdit, QMessageBox, QPushButton,
                             QToolTip, QWidget)
=======
from flask import Flask
app = Flask(__name__)
>>>>>>> 3bd4892c97b8dd51503eb33a3d7168749bd234b9


@app.route('/')
def hello_world():
        return 'Hello World!'

<<<<<<< HEAD
        self.initUI()
        self.num =  19260817

    def initUI (self):
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('exciting')
        self.setWindowIcon(QIcon('test.jpeg'))

        self.bt1 = QPushButton('猜', self)
        self.bt1.setGeometry(100, 100, 100, 100)
        self.bt1.setToolTip("<b>666</b>")
        self.bt1.clicked.connect(self.showmessage)

        self.text = QLineEdit("输入数字", self)
        self.text.selectAll()
        self.text.setFocus()
        self.text.setGeometry(70, 70, 110, 30)

        self.show()     

    def showmessage(self):
        gs = int(self.text.text())
        print(self.num)
        if gs > self.num or gs < self.num:
            QMessageBox.about(self, 'Too young', "不要总想着搞出个大新闻")
            self.text.setFocus()
            # print("WA")
        else :
            QMessageBox.about(self, "Exciting", "天若有情天亦老，我为长者续一秒")
            self.text.setFocus()
            # print("AC")
            self.num = 19260817
            self.text.clear()
            self.text.setFocus()

    def closeEvent(self, event):
        rep = QMessageBox.warning(self, 'OK', "OK!", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if rep == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore() 


app = QApplication(sys.argv)

ex = test();

sys.exit(app.exec_())
=======

if __name__ == '__main__':
        app.run()
>>>>>>> 3bd4892c97b8dd51503eb33a3d7168749bd234b9
