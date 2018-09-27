import os
import re
import sys
import time
import urllib.request

import requests
from bs4 import BeautifulSoup


def Download_File(list_, path, switch):
    '''
        list_ : List of file addresses
        path : Download path
        switch : Download information
    '''
    if switch:
        print("Download start ------")
    for i, j in enumerate(list_):
        with open('%s/%s.jpg' % (path, i), 'wb') as file:
            file.write(requests.get(j).content)
            if switch:
                print("Already download %d file(s)" % (i))
            time.sleep(1)
    if switch:
        print("Download finished ------")


def Proxy_Http(Ip_, Port):
    '''
        Ip_ : example '127.0.0.1'
        Port : example '1080'
    '''
    proxy = {
        'http' : '%s:%s' %(Ip_, Port) ,
        'https': '%s:%s' % (Ip_, Port) ,
    }
    return proxy