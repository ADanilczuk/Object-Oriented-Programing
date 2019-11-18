// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z5
// Program g³ówny
// 2018-04-12

import java.util.Random;

public class Program 
{
	public static final int rozmiar = 40;
    public static int[] tablica = new int[rozmiar];
    public static int[] tab = new int[rozmiar];
    
    
    public static void main(String [] args) 
						throws InterruptedException 
    {
    	
    	Random rand = new Random();

    	//Tworzymy i wypisujemy tablicê
        for(int i = 0 ; i<rozmiar; i++)
            tablica[i] = rand.nextInt(1000);

        System.out.println("Tablica przed posortowaniem: ");
        for(int i = 0 ; i<rozmiar; i++)
        {
        	System.out.print(tablica[i]);
        	System.out.print(" ");
        }
           
        
        System.out.println(" ");
        
        int pocz = 0;
        int kon = rozmiar-1;
        
     // Sortujemy i wypisujemy posortowan¹ tablice
        Mergesort.mergesort(pocz, kon);

        System.out.println("\nTablica po sortowaniu: ");
        for(int i = 0 ; i<rozmiar; i++)
        {
        	System.out.print(tablica[i]);
        	System.out.print(" ");
        }
        	

    }
}
