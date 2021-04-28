from socket import *
serverPort=12000
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind(("",serverPort))
serverSocket.listen(1)

while 1:
	connectionSocket, addr = serverSocket.accept()
	Info = connectionSocket.recv(1024)
	print('The server said:', Info, '\n')
serverSocket.close()
