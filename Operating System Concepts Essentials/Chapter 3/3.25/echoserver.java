/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.21 side 138 */

import java.net.*;
import java.io.*;

public class echoserver {

    public static void main(String[] args) {
        try {
            /* Listens for connections */
            ServerSocket sock = new ServerSocket(6017); 
            
            /* Establish the connection to the socket */
            Socket client = sock.accept();              
            
            /* Output location */
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);                     
           
            /* Read the input from the socket */
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream())); 
            
            /* Runs while socket contain anything */
            do{
                /* Puts it in the socket */
                pout.println("Server echo back: " + in.readLine()); 
                break;                 
            }
            while (in.read() != -1);   
            
            /* close the socket */
            client.close();             
        } catch (IOException ioe) {
            System.err.println(ioe);    
        }
    }
}
