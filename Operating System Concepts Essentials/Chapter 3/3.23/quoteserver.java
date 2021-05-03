/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.21 side 138 */

import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.ArrayList;

public class quoteserver {
    private static ArrayList<String> quotes = new ArrayList<>(); 
    private static Random rand = new Random(); 

    public static void main(String[] args) {
        quote(); 
        try {
            /* Listens for connections */
            ServerSocket sock = new ServerSocket(6017); 
            while (true) {                              
                
                /* Establish the connection to the socket */
                Socket client = sock.accept();          
                
                /* How to write to the socket */
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true); 
                pout.println("Quote of the day:");      
                pout.println(quotes.get(rand.nextInt(quotes.size())));
                
                /* close the socket and resume */
                client.close();                         
            }
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
    /* Add the following quotes to the arraylist */
    private static void quote() {
        quotes.add("Be yourself; everyone else is already taken.");
        quotes.add("Two things are infinite: the universe and human stupidity; and I'm not sure about the universe.");
        quotes.add("You only live once, but if you do it right, once is enough.");
        quotes.add("Be the change that you wish to see in the world.");
        quotes.add("In three words I can sum up everything I've learned about life: it goes on.");
    }
}
