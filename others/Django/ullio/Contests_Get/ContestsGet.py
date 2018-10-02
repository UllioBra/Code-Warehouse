import os
import re
import sys, time

import json
import requests
import urllib.request
from bs4 import BeautifulSoup

def Atcoder_Upcoming_Contests():
    '''
        Get the upcoming contests of Atcoder
    '''
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
            list_.append(['比赛:%s' %(e[1].text), '开始时间:%s' %(e[0].text), '结束时间:%s' %(e[2].text)])
    return list_

def Codeforces_Upcoming_Contests():  
    '''
        Get the upcoming contests of Codeforces
    '''
    tar = "http://codeforces.com/api/contest.list"
    req = requests.get(tar)
    false = False
    tx = eval(req.text)
    list_ = []
    if tx['status'] == 'OK':
        for i in tx['result']:
            if i['phase'] == 'BEFORE':
                tim_1 = time.asctime(time.localtime(i['startTimeSeconds']))
                tim_2 = time.asctime(time.localtime(i['startTimeSeconds'] + i['durationSeconds']))
                list_.append(['比赛%s' %(i['name']), '开始时间:%s' %(tim_1), '结束时间:%s' %(tim_2)])
    return list_

def Luogu_Upcoming_Contests():
    '''
        Get the upcoming contests of luogu
    '''
    hed = {'user-agent': 'Mozilla/5.0'}
    tar = "http://www.luogu.org/contest/lists"
    req = requests.get(tar, headers = hed)
    tx = req.text
    bf = BeautifulSoup(tx, features='html.parser')
    body = bf.find_all('div', class_ = 'am-g lg-table-bg0 lg-table-row')
    list_ = []
    for i in body:
        # print(i.strong.text)
        if i.strong.text == '未开始':
            part = i.find('div', class_ = "am-u-md-2 lg-table-small").text
            tmp = []
            tmp = re.split('[\n]', part)
            list_.append(['比赛:%s' %(i.a.text),'开始时间:%s' %(tmp[1]),'结束时间:%s' %(tmp[3])])
    return list_

def Nowcoder_Upcoming_Contests():
    '''
        Get the upcoming contests of nowcoder
    '''
    tar = "https://www.nowcoder.com/acm/contest/vip-index"
    req = requests.get(tar)
    tx = req.text
    bf = BeautifulSoup(tx, features='html.parser')
    body = bf.find('div', class_="platform-mod js-current").find_all('div', class_ = "platform-item-cont")
    list_ = []
    for i in body:
        if i.find('span', class_ = "match-status match-signup"):
            title = i.find('a', href = re.compile(r'/acm/contest/\d*')).get_text(strip=True)
            tim_1 = i.find('li', class_ = "time-icon").get_text(strip=True)
            tim_2 = i.find('li', class_ = "match-time-icon").get_text(strip=True)
            list_.append(['比赛:%s' %(title), tim_1, tim_2])
    return list_


def Get_Dict():
    list_1 = Atcoder_Upcoming_Contests()
    list_2 = Codeforces_Upcoming_Contests()
    list_3 = Luogu_Upcoming_Contests()
    list_4 = Nowcoder_Upcoming_Contests()
    dict_ = {
        'name' : ['Atcoder', 'Codeforces', 'Luogu', 'Nowcoder'],
        'contests' : [list_1, list_2, list_3, list_4],
    }
    return dict_


if __name__ == '__main__' :
    print(json.dumps(Get_Dict()))