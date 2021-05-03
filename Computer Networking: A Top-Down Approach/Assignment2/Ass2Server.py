import random
from socket import *
import time

def main():
	#Creates a UDP socket
	serverSocket = socket(AF_INET,SOCK_DGRAM)
	#Assign IP and port to socket
	serverSocket.bind(("",12000))
	
	while True:
		#Random number from 0 to 10
		rand = random.randint(0,10)
		#Recieve clclient packet and senders address
		message,address = serverSocket.recvfrom(1024)
		message = message.decode()
		message = message.upper()
		message = message.encode()
		#if rand < 4, consider packet lost and dont respond
		if rand < 4:
			continue
		#otherwise, respond
		time.sleep(.05) #simulates longer delay, therefore more likely to timeout
		serverSocket.sendto(message,address)
	pass

if __name__ == "__main__":
	main()