/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.22 side 139 */

import java.net.*;
import java.io.*;

public class quoteclient {
    public static void main(String[] args) {
        try {
            /* make connection to server socket */
            Socket sock = new Socket("127.0.0.1", 6017); 
            
            /* Where to get the input stream from socket */
            InputStream in = sock.getInputStream(); 
           
            /* Read the quote from the socket */
            BufferedReader bin = new BufferedReader(new InputStreamReader(in)); 
            
            String line;
            /* True if socket contain anything */
            while ((line = bin.readLine()) != null) 
                System.out.println(line); 
            
            /* close the socket connection */
            sock.close(); 
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
