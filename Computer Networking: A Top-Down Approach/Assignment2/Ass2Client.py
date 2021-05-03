from socket import *
from datetime import datetime	#Needed for timeout system

def main():
	serverName = "localhost"	#Destination serverName
	serverPort = 12000			#Destination port
	counter = 0;				#Number of pings start at 0
	
	message = input("Input Lowercase Message: ")	#Ask user for message
	message = message.encode()						#Konverterer fra string til bytes
	
	while counter < 10:							#While counter less than 0
		counter = counter + 1					#Add 1 to counter
		mainSocket = socket(AF_INET,SOCK_DGRAM)	#Create socket
		
		try:
			mainSocket.settimeout(1.0)	#Timeout after 1 second
			startTime = datetime.now()	#start time is current time
			
			mainSocket.sendto(message,(serverName, serverPort)) 		#Send the message
			modifiedMessage, serverAddress = mainSocket.recvfrom(1024)	#Modified message is the message it gets back
			modifiedMessage = modifiedMessage.decode()					#Decodes modified message
			endTime = datetime.now()									#End time is current time at declaration
		
		except timeout:																	#If timeout
			print("PING " +str(counter)+" "+ str(startTime)+ ": Request timed out!")	#Print timeout message
			mainSocket.close()   														#Close socket
		else:																			#Else print PING num Start Time Returned Message and RTT
			print("PING " +str(counter)+" "+ str(startTime)+": Returned: " + modifiedMessage + " after "+ str(endTime-startTime))

	mainSocket.close()	#Close socket
	pass

if __name__ == "__main__":
    main()