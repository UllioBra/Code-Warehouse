import os
import socket

import requests
import socks
from bs4 import BeautifulSoup

def Cookie_Dict(cookies):
    cookies_di = {}
    for i in cookies.split(';'):
        name, val = i.strip().split('=', 1)
        cookies_di[name] = val
    return cookies_di

def proxy():
    pro = {
        'http': "http://127.0.0.1:12333",
        'https': 'http://127.0.0.1:12333',
    }
    return pro

def test():
    # data = {
    #     'username': '3411683350@qq.com',
    #     'password': 'luoxiangyu'
    # }
    # user_he = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.81 Safari/537.36'
    # session = requests.Session()
    # tx = session.post(url, data = data)
    cookie = 'first_visit_datetime_pc=2018-09-27+11%3A00%3A12; p_ab_id=3; p_ab_id_2=0; p_ab_d_id=575327832; _ga=GA1.2.47226259.1538013647; _gid=GA1.2.593333630.1538013647; login_bc=1; PHPSESSID=28935344_4161e5f8e62e4a69803fd8e737a77a54; device_token=040f45a519e17ac9b01b6783698a8d5a; privacy_policy_agreement=1; c_type=28; a_type=0; b_type=1; module_orders_mypage=%5B%7B%22name%22%3A%22sketch_live%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22tag_follow%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22recommended_illusts%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22showcase%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22everyone_new_illusts%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22following_new_illusts%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22mypixiv_new_illusts%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22fanbox%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22featured_tags%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22contests%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22user_events%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22sensei_courses%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22spotlight%22%2C%22visible%22%3Atrue%7D%2C%7B%22name%22%3A%22booth_follow_items%22%2C%22visible%22%3Atrue%7D%5D; is_sensei_service_user=1; yuid_b=MYOQSDE; login_ever=yes; limited_ads=%7B%22header%22%3A%22%22%7D'
    url = "https://www.pixiv.net/discovery?mode=safe"
    refer = 'https://www.pixiv.net/discovery?mode=safe'
    
    req = requests.get(url, proxies = proxy(), cookies = Cookie_Dict(cookie))
    # bf = BeautifulSoup(req, features = 'html.parser')
    # body = bf.find_all('ul', class_ = "_image-items gtm-illust-recommend-zone")
    print()

test()
