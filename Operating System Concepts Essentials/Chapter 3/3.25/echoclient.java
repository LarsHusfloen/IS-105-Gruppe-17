/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.22 side 139 */

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class echoclient {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 

        try {
            /* make connection to server socket */
            Socket sock = new Socket("127.0.0.1", 6017);                            
            
            /* How to write to the socket */
            PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);       
            
            /* Where to get the input stream from socket */
            InputStream in = sock.getInputStream();                                 
           
            /* Output from the server */
            BufferedReader reader = new BufferedReader(new InputStreamReader(in)); 

            System.out.println("Please insert input: "); 
            String bin = sc.nextLine(); 
            
            /* Puts bin in the socket and closes scanner*/
            pout.println(bin);          
            sc.close();   
            
            /* Runs until the end of the stream */
            do {
                System.out.println(reader.readLine()); 
            } while (reader.read() != -1);  
            
            /* close the socket connection */
            sock.close(); 
            System.exit(0);
        } catch (IOException ioe) {
            System.err.println(ioe); 
        }
    }
}
