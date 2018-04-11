import socket
import sys
from thread import *
HOST = ''
PORT = 8081
s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

try:
	s.bind((HOST,PORT))
except socket.error as msg:
	print'Bind failure. Error code : ' + str(msg[0])  + ' message ' +  msg[1] 	
	sys.exit()
print 'Socket bind complete'
s.listen(10)
print 'Socket now listening'
def sort(conn):
	i=0
	num=0
	temp = []
	while 1:
		data = conn.recv(4)
		if not data:
			break
		data.strip('\x00')
		if data=='\x00':
			continue
		temp2=data.split('\x00')
		if temp2[0]== "\\":
			conn.sendall(str(output))
			print("sending data back")
			break	
		temp.append(temp2[i])
		output = sorted(temp,key=int)
		out = str(output)
	
	conn.close()
	temp = []
while 1:
	conn, addr = s.accept()
	start_new_thread(sort,(conn,))
conn.close()
