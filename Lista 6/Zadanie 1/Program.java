// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z1
// Program g³ówny
// 2018-04-12

import java.io.*;

public class Program
{
    @SuppressWarnings("unchecked")
	public static void main(String[]args) 
    						throws IOException, ClassNotFoundException 
    {
    	
    	// Lista liczb
    	Lista<Integer> l = new Lista<Integer>();
    	 for(int i=0;i<=5; i++)
             l.DodajNaPoczatek(i);
    	 
    	 
    	// Serializacja
         try
         {
           FileOutputStream fos= new FileOutputStream("mylist");
           ObjectOutputStream oos= new ObjectOutputStream(fos);
           oos.writeObject(l);
           oos.close();
           fos.close();
         }
         catch(IOException ioe)
         {
              ioe.printStackTrace();
         }
         
         // Deserializacja
         Lista<Integer> list= new Lista<Integer>();
         try
         {
             FileInputStream fis = new FileInputStream("mylist");
             ObjectInputStream ois = new ObjectInputStream(fis);
             list = (Lista<Integer>) ois.readObject();
             ois.close();
             fis.close();
          }
         catch(IOException ioe)
         {
              ioe.printStackTrace();
              return;
          }
         catch(ClassNotFoundException c)
         {
              System.out.println("Class not found");
              c.printStackTrace();
              return;
         }
         // Wyœwietlanie zdeserializowanej listy liczb
         System.out.println("Zdeserializowana lista liczb:");
         list.wypisz();
         System.out.println();
         
         
         
         // Lista znaków
         Lista<String> l2 = new Lista<String>();
    	 String a = "k";
    	 for (int i=0; i<=5; i++)
    		l2.DodajNaKoniec(a + Integer.toString(i));
    	 
         try
         {
           FileOutputStream fop= new FileOutputStream("mylist2");
           ObjectOutputStream oop= new ObjectOutputStream(fop);
           oop.writeObject(l2);
           oop.close();
           fop.close();
         }
         catch(IOException ioe)
         {
              ioe.printStackTrace();
         }
         
         // Deserializacja
         Lista<String> list2= new Lista<String>();
         try
         {
             FileInputStream fip = new FileInputStream("mylist2");
             ObjectInputStream oip = new ObjectInputStream(fip);
             list2 = (Lista<String>) oip.readObject();
             oip.close();
             fip.close();
          }
         catch(IOException ioe)
         {
              ioe.printStackTrace();
              return;
          }
         catch(ClassNotFoundException c)
         {
              System.out.println("Class not found");
              c.printStackTrace();
              return;
         }
      // Wyœwietlanie zdeserializowanej listy napisów
         System.out.println("Zdeserializowana lista napisów:");
         list2.wypisz();
         System.out.println();
         
    }
}