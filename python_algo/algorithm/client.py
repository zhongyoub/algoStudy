#!/usr/bin/python 
#coding:utf-8

import requests

import random
from multiprocessing import Process as process
import multiprocessing


def send_request():
    url1=r'http://192.168.10.10:8000'
    url2=r'http://192.168.10.10:9000'
    url_list=[url1, url2]
    session=requests.Session()
    headers1 = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.108 Safari/537.36',
    }
    for url in url_list:
        client_port=random.choice(list(range(2000,65535)))
        #session.mount('http://', source.SourceAddressAdapter(("192.168.10.11", client_port))
        r=session.get(url=url,headers=headers1)
        #print(r.text)


def process_function(): 
    process_list=[]
    process_num=multiprocessing.cpu_count() 
    for i in range(process_num):
        p=process(target=send_request)
        process_list.append(p)
    for i in process_list:
        p.start()
    for p in process_list:
        p.terminate()
    print("-----end-----")

if __name__== "__main__":
    process_function()