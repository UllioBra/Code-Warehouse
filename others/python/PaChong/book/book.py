import io
import os
import re
import sys

import requests
from bs4 import BeautifulSoup

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gbk')


def login():
    login_page = "https://www.wenku8.net/index.php"
    data = {"email": 'ullio', "password": 'luoxiangyu'}
    headers = {
        'User-agent': 'Mozilla/5.0 (Windows NT 6.3;WOW64; rv:36.0) Gecko/201    00101 Firefox/36.0'}
    res = requests.post(login_page, data=data, headers=headers)
    print(res.cookies)
    return res.cookies


def Get_Dic(page_n):
    cookie = login()
    headers = {
        'User-agent': 'Mozilla/5.0 (Windows NT 6.3;WOW64; rv:36.0) Gecko/201    00101 Firefox/36.0'}
    for i in range(page_n):
        url = "https://www.wenku8.net/modules/article/articlelist.php?page=" + \
            str(i+1)
        body = requests.get(url,cookies=cookie, headers = headers)
        body.encoding = 'gbk'
        tx = body.text
        bf = BeautifulSoup(tx, features='html.parser')
        # print(tx)


page = 1

Get_Dic(page)
