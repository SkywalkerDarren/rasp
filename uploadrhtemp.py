#!/usr/bin/python
#-*-coding:UTF-8-*-

import time
import json
import requests
import os

def main():
	fileRecord = open("rhtemp.txt","w")
	fileRecord.write("connect to yeelink")
	fileRecord.close

	while True:
		#read
		os.system("./uprhtemp")
		file = open("/home/pi/rt")
		num = int(file.read())
		rh = num / 100
		temp = num % 100
		#send
		apiurl = 'http://www.lewei50.com/api/V1/gateway/UpdateSensors/01'
		apiheaders = {'userkey':'8e2df14d702c4a959444558416c9aecd'}
		payload = [{'Name': 'temp', 'Value': str(temp)},{'Name': 'rh', 'Value': str(rh)}]
		r = requests.post(apiurl, headers=apiheaders, data=json.dumps(payload))
		#payload = {'Name': 'rh', 'Value': str(rh)}
		#r = requests.post(apiurl, headers=apiheaders, data=json.dumps(payload))

		# apiurl = 'http://api.yeelink.net/v1.0/device/97909/sensor/391804/datapoints'
		#apiheaders = {'U-ApiKey': '7b3cfd60ca0ca7baec454d3567833b3e', 'content-type': 'application/json'}
		#payload = {'value': rh}

		#send temp
		#r = requests.post(apiurl, headers=apiheaders, data=json.dumps(payload))
		#log
		fileRecord = open("result.txt", "a")
		strTime = time.strftime('%Y-%m-%d:%H-%M-%S', time.localtime(time.time()))
		fileRecord.writelines(strTime + "\n")
		strRT = "temp : %d" % temp + "    RH : %d" % rh + "\n"
		fileRecord.writelines(strRT)
		fileRecord.writelines(str(r.status_code) + "\n")
		fileRecord.close()

		time.sleep(5)
#	print "start"
#	print rh
#	print temp
#	print "end"
if __name__ == '__main__':
	main()
