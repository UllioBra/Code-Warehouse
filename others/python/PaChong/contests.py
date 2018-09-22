import os
import re
import sys

import requests
from bs4 import BeautifulSoup

def Atcoder_Upcoming_Contests():
    tar = 'https://atcoder.jp/contest/'
    req = requests.get(url = tar)
    tx = req.text
    bf = BeautifulSoup(tx, features = "html.parser")
    body = bf.find_all('div', class_ = 'table-responsive')[1]
    part = body.find_all('tr')
    list_ = []
    for i in part:
        if i.find_all('tr'):
            e = i.find_all('td', limit = 3)
            list_.append([e[1].text, e[0].text, e[2].text])
    return list_


def Codeforces_Upcoming_Contests():  
    tar = "http://codeforces.com/contests"
    req = requests.get(tar)
    tx = req.text
    bf = BeautifulSoup(tx, features = 'html.parser')
    body = bf.find_all(lambda tag: tag.name == 'tr' and len(tag.attrs) == 1)
    list_ = []
    for i in body:
        li = i.td.find_all(True)
        if not li:
            tim = i.find('span', class_="format-time").get_text(strip=True)
            le_li = i.find_all(lambda tag: tag.name == 'td' and len(tag.attrs) == 0)
            list_.append([i.td.get_text(strip=True), tim,
                          le_li[2].get_text(strip=True)])
    return list_

if __name__ == '__main__':
    li1 = Atcoder_Upcoming_Contests()
    li2 = Codeforces_Upcoming_Contests()
    
    print("Atcoder Contests")
    for i in li1:
        print(i)

    print("\nCodeforce Contests")
    for i in li2:
        print(i)
