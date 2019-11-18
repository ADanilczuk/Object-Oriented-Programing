// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z5
// Klasa
// 2018-04-12


// Klasa zawieraj¹ca algorytm sortowania przez scalanie, implementuj¹ca 
// interfejs Runnable, czyli interfejs do obs³ugi w¹tków

public class Mergesort extends Program
						implements Runnable
{
	int start;
	int meta;
	
	// Konstruktor pól przypisuj¹cy im przekazane wartoœci
	public Mergesort(int pocz, int kon)
	{
		start = pocz;
		meta = kon;
	}
	
	// Nadpisanie metody run() z interfejsu Runnable, w której
	// uruchamiamy metodê mergesort
	@Override
	public void run()
	{
		try 
		{
			mergesort(start, meta);
		}
		catch (InterruptedException er)
		{
			er.printStackTrace();
		}
	}
	
	
	// Metoda scalaj¹ca posortowane tablice
	public static void merge(int pocz, int sr, int kon)
    {
		int i, j, k;
		
		// przepisanie tablicy do tablicy pomocniczej
		for (i=pocz; i<=kon; i++)
			tab[i] = tablica[i];
		
		i = pocz;
		j = sr+1;
		k = pocz;
		
		while (i<= sr && j<=kon)
		{
			if (tab[i]<tab[j])
				tablica[k++] = tab[i++];
			else
				tablica[k++] = tab[j++];
		}
		while (i<=sr) tablica[k++] = tab[i++];
    }

	// Metoda dziel¹ca tablice na dwie mniejsze, uruchamiaj¹ca w¹tki
	public static void mergesort(int pocz, int kon) 
							throws InterruptedException 
	{
		int sr;
		if (pocz < kon)
		{
			sr= (pocz + kon) / 2;
			 
			// tworzymy w¹tki dla prawej i lewej czêœci tablicy
			Mergesort czesc1 = new Mergesort(pocz,sr);
			Mergesort czesc2 = new Mergesort(sr+1, kon);
			
			Thread watek1 = new Thread(czesc1);
			Thread watek2 = new Thread(czesc2);
			
			// Wywo³ujemy w¹tki
			watek1.start();
			watek2.start();
			
			// Czekamy do zakoñczenia pracy w¹tków
			watek1.join();
			watek2.join();
			
			// Scalamy powsta³e tablice
			merge(pocz, sr, kon);
			
		}
	}

}
