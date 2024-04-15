# coding: utf-8

import datetime
import os
import threading
import time

def out_log():
    # JST = datetime.timezone(datetime.timedelta(hours=+9), 'JST')
    # now = datetime.datetime.now(JST)
    now = datetime.datetime.now()
    print('Thread Name:{} Time:{}'.format(threading.currentThread().getName(), now))

def thread_funcA():
    for i in range(2):
        time.sleep(0.1)
        out_log()

def thread_funcB():
    for i in range(2):
        time.sleep(0.15)
        out_log()

def main():
    out_log()

    # 名前指定しなければ連番でThread-1のようにが自動命名される
    threadA = threading.Thread(target=thread_funcA)
    threadB = threading.Thread(target=thread_funcB)

    threadA.start()
    threadB.start()

    threadA.join()
    threadB.join()

    os._exit

if __name__ == "__main__":
    main()
