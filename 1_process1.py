# coding: utf-8
import os
#import sys

def main():
    pid = os.fork()

    if pid == 0:
        print('[Child] PID:{} PPID:{} fork ret:{}'.format(os.getpid(), os.getppid(), pid))
        #sys.stdout.flush()
        #os.execv('/bin/echo', ['/bin/echo', 'Hello Python'])
    elif pid > 0:
        os.wait()
        print('[Parent] PID:{} PPID:{} fork ret:{}'.format(os.getpid(), os.getppid(), pid))
    else:
        print('[Error] PID:{} PPID:{} fork ret:{}'.format(os.getpid(), os.getppid(), pid))

    print('PID:{} PPID:{} fork ret:{}'.format(os.getpid(), os.getppid(), pid))

if __name__ == "__main__":
    main()
