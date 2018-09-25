import os
import re
import time

import requests
from bs4 import BeautifulSoup

def func():
    hed = {'user-agent': 'Mozilla/5.0'}
    url = 'https://www.luogu.org/discuss/show/48491'
    tar = requests.get(url, headers = hed)
    tx = tar.text
    bf = BeautifulSoup(tx, features='html.parser')
    body = bf.find('div', class_='am-comment-bd')
    part = body.find_all('p')
    list_ = []
    for i in part:
        if i.strong:
            if i.a:
                list_.append([True, i.strong, i.a.text])
            else:
                list_.append([False, i.strong])
    # print(list_)
    return list_

if __name__ == '__main__':
    func()
