// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z5
// Klasa
// 2018-04-12


// Klasa zawieraj�ca algorytm sortowania przez scalanie, implementuj�ca 
// interfejs Runnable, czyli interfejs do obs�ugi w�tk�w

public class Mergesort extends Program
						implements Runnable
{
	int start;
	int meta;
	
	// Konstruktor p�l przypisuj�cy im przekazane warto�ci
	public Mergesort(int pocz, int kon)
	{
		start = pocz;
		meta = kon;
	}
	
	// Nadpisanie metody run() z interfejsu Runnable, w kt�rej
	// uruchamiamy metod� mergesort
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
	
	
	// Metoda scalaj�ca posortowane tablice
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

	// Metoda dziel�ca tablice na dwie mniejsze, uruchamiaj�ca w�tki
	public static void mergesort(int pocz, int kon) 
							throws InterruptedException 
	{
		int sr;
		if (pocz < kon)
		{
			sr= (pocz + kon) / 2;
			 
			// tworzymy w�tki dla prawej i lewej cz�ci tablicy
			Mergesort czesc1 = new Mergesort(pocz,sr);
			Mergesort czesc2 = new Mergesort(sr+1, kon);
			
			Thread watek1 = new Thread(czesc1);
			Thread watek2 = new Thread(czesc2);
			
			// Wywo�ujemy w�tki
			watek1.start();
			watek2.start();
			
			// Czekamy do zako�czenia pracy w�tk�w
			watek1.join();
			watek2.join();
			
			// Scalamy powsta�e tablice
			merge(pocz, sr, kon);
			
		}
	}

}
