import socket
import sys
from thread import *
HOST = ''
PORT = 8081
s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
#print 'Socket created'
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
	#conn.send('Welcome to the server. Type something and hit enter\n')
	while 1:
		data = conn.recv(4)
		if not data:
			break
		data.strip('\x00')
		if data=='\x00':
			continue
			# num*=10
			# print(type(numb))
			# numb = data.split()
			# num = num+ int(numb[0])
			# continue


		print('data received')
		#print(type(data))
		print(data)
		temp2=data.split('\x00')
		if temp2[0]== "\\":
			conn.sendall(str(output))
			print("sending data back")
			break	
		print(temp2)
		temp.append(temp2[i])
		print(temp)
		print(type(temp))
		#temp2=temp.split()
		output = sorted(temp,key=int)
		out = str(output)
		print(type(out))
		print(out)
	
	conn.close()
	temp = []
while 1:
	conn, addr = s.accept()
	start_new_thread(sort,(conn,))
conn.close()
