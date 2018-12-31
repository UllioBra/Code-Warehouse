import io
import os
import re
import sys
import time
import urllib.request

import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities

# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gbk')

def headers():
    dic = {'Referer': 'https://www.manhuagui.com/comic/17023/176171.html', 'DNT': '1',
           'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'}
    return dic

def MKdir(path):
    if not os.path.isdir(path):
        os.mkdir(path)

def Get_Time():
    localtime = time.asctime(time.localtime(time.time()))
    return localtime

def Download_File(list_, path, switch, cnt):
    MKdir(path)
    f = open(path + 'Download_Logs.txt', 'a+')
    f.writelines('\n'+Get_Time())
    f.writelines("Download start ---- ")
    for i in list_:
        fe = re.sub(r'\S\w+\S\w+\S\w+\S\w+$', '', os.path.basename(i))
        fe = re.search(r'\.(\w+)$', fe).group()
        res = requests.get(i, headers=headers())
        f.writelines(" HTTP Status Code : " + str(res.status_code))
        with open('%s%d%s' % (path, cnt, fe), 'wb') as file:
            file.write(res.content)
            time.sleep(1)
    f.writelines(" Download finished ----")
    f.close()


def driver_open():
    options = webdriver.ChromeOptions()
    options.set_headless()
    options.add_argument('lang=zh_CN.UTF-8')
    options.add_argument(
        "user-agent='Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'")
    driver = webdriver.Chrome(chrome_options=options)
    return driver


def Get_Img_Url(url):
    browser = driver_open()
    browser.get(url)
    tx = browser.page_source
    body = BeautifulSoup(str(tx).encode('utf8'), "html.parser").find(
        'img', class_='mangaFile')
    img_url = body['src']
    browser.close()
    return img_url

def Get_Img(url,pa_1):
    req = requests.get(url,headers=headers())
    bf = BeautifulSoup(req.text, 'html.parser')
    title = bf.find('h2').text
    body = bf.find('span',id='page').parent
    num = re.search(r'\d+', body.text).group()

    pa_2 = pa_1 + title + '/'
    MKdir(pa_2)

    if not os.path.isfile(pa_2 + 'Download_Tag.txt'):
        logs = open(pa_2 + 'Download_Tag.txt', 'w')
        logs.writelines('0')
        logs.close()
    
    logs = open(pa_2 + 'Download_Tag.txt', 'r')
    cnt = logs.readline()
    if cnt == 'Down':
        return
    logs.close()

    cnt = int(cnt)

    for i in range(int(num)):
        if i+1 > int(cnt):
            cnt = cnt + 1
            u = []
            u.append(Get_Img_Url(url + '#p=%d' %(i+1)))
            Download_File(u,pa_2,1,cnt)
            logs = open(pa_2 + 'Download_Tag.txt', 'w')
            logs.writelines(str(cnt))
            logs.close()
    if num == cnt:
        logs.writelines('Down')
    logs.close()

def Get_Comic(url):
    bf = BeautifulSoup(requests.get(url).text, 'html.parser')
    title = bf.find('h1').text
    cls_t = bf.find_all('h4') 
    body = bf.find_all('div', class_='chapter-list cf mt10')

    path = bs_p + title + '/'
    MKdir(path)
    cnt = 0
    for i in body:
        key = cls_t[cnt].text
        pa_1 = path + key + '/'
        MKdir(pa_1)
        cnt = cnt + 1
        for j in i.find_all('ul'):
            for k in j.find_all('li'):
                u = 'https://www.manhuagui.com/'+k.a['href'] 
                Get_Img(u,pa_1)

bs_p = 'C:/test/'       
url = 'https://www.manhuagui.com/comic/17023/'
    

if __name__ == "__main__":
    Get_Comic(url)
    pass
