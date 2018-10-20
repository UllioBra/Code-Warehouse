import os
import re

import requests
from bs4 import BeautifulSoup

def get_url():
    hed = {'user-agent': 'Mozilla/5.0'}
    url = 'https://www.ssrtool.com/tool/free_ssr'
    req = requests.get(url, headers = hed).text
    body = BeautifulSoup(req, features='html.parser')
    fir = body.find('blockquote', class_='layui-elem-quote')
    return fir.find_all('input')

if __name__ == '__main__':
    list_ = get_url()
    print(list_[1]['value'])
