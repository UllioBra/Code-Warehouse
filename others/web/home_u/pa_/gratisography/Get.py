import os
import re
import sys
import time

import requests
import urllib.request
from bs4 import BeautifulSoup

def Get_Pic_url(url):
    req = requests.get(url)
    bf = BeautifulSoup(req.text, "html.parser")
    body = bf.find_all('a', rel = 'bookmark')
    list_ = []
    for i in body:
        list_.append(i.attrs['href'])
    return list_

def Get_Status(url):
    req = requests.get(url, 'html.parser')
    return req.status_code == 200

def Get_Pic(num):
    path = 'https://gratisography.com/page/'
    i = 1
    now = 0
    imglist_ = []
    while Get_Status(path + str(i)) :
        list_ = Get_Pic_url(path + str(i))
        i = i + 1
        for j in list_:
            if now >= num :
                return imglist_
            now = now + 1
            req = requests.get(j)
            bf = BeautifulSoup(req.text, 'html.parser')
            body = bf.find('a', title='Download the free photo')
            imglist_.append(body.attrs['href'])
        time.sleep(1)
    return imglist_

def Pic_Download(num):
    # print('Download start')
    imglist_ = Get_Pic(num)
    for i, j in enumerate(imglist_):
        with open('/home/gsx/pa/gratisography/{0}.jpg'.format(i), 'wb') as file:
            file.write(requests.get(j).content)
            print("Already download %d pictures" % (i))
    # print("Download finished")

if __name__ == '__main__':
    print(Get_Pic(1))
