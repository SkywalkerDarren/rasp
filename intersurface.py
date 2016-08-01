#!/usr/bin/python
# -*-coding:UTF-8-*-

import requests
import json
#import commands
import time


def main():
    #log
    fileRecord = open("result.txt", "w")
    fileRecord.write("connect to yeelink\n")
    fileRecord.close()
    while True:
        #read
        file = open("/sys/class/thermal/thermal_zone0/temp")
        temp = float(file.read()) / 1000
        file.close
        #send

        apiurl = 'http://api.yeelink.net/v1.0/device/97909/sensor/391376/datapoints'
        apiheaders = {'U-ApiKey': '7b3cfd60ca0ca7baec454d3567833b3e', 'content-type': 'application/json'}
        payload = {'value': temp}
        r = requests.post(apiurl, headers=apiheaders, data=json.dumps(payload))

        #log
        fileRecord = open("result.txt", "a")
        strTime = time.strftime('%Y-%m-%d:%H-%M-%S', time.localtime(time.time()))
        fileRecord.writelines(strTime + "\n")
        strTemp = "temp : %.1f" % temp + "\n"
        fileRecord.writelines(strTemp)
        fileRecord.writelines(str(r.status_code) + "\n")
        fileRecord.close()

        time.sleep(5)


if __name__ == '__main__':
    main()
