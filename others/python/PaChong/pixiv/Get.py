import os
import socket

import requests
import socks
from bs4 import BeautifulSoup

def test():
    url = "https://www.pixiv.net"
    req = requests.get(url)
    tx = req.text
    print(tx)

test()
