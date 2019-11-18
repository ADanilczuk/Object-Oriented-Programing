/*
   Alicja Danilczuk
   Programowanie obiektowe
   Lista 2
   Zadanie 4
   8.03.2018
 */
 
using System;
using System.Collections.Generic;

namespace Zad
{
	class ListaLeniwa
	{
		public int length;
		public List<int> L = new List<int>();

		
	public int element(int i)
		{
			length = L.Count;
		    if (i<length) return L[i-1];
			int x = length;
			System.Random rand=new System.Random();
			while (i>x)
			{
				L.Add(rand.Next());
				x++;
			}
			return L[i-1];
		}
		
	public int size()
		{
			return L.Count;
		}
		
		static void Main()
		{
			ListaLeniwa lista = new ListaLeniwa(); 
			Console.WriteLine(lista.size());
			Console.WriteLine(lista.element(40)); 
			Console.WriteLine(lista.size());
			Console.WriteLine(lista.element(38)); 
			Console.WriteLine(lista.size());
			Console.WriteLine(lista.element(40)); 
			
			Pierwsze list = new Pierwsze(); 
		
			Console.WriteLine(list.element_p(1)); 
			
			Console.WriteLine(list.element_p(2)); 
		
			Console.WriteLine(list.element_p(3)); 
			Console.Read();
		}
	}
	
	
	class Pierwsze : ListaLeniwa
	{
		public List<int> K = new List<int>();
		
		public bool pierwsza(int x)
		{
            if (x < 2)
                return false;
            for (int i = 2; i <= Math.Sqrt(x) && i < int.MaxValue; i++) 
            {
                if (x % i == 0)
                    return false;
            }
            return true;
        }

        public int kolejna(int x) 
        {
        	x++;
        	while (!pierwsza(x)) x++;
            return x;
        }
		
		public int element_p(int i)
		{
			length = K.Count;
			int y;
		    if (i<length) return K[i-1];
			int x = length;
			while (i>x)
			{
				if (x==0) y=1;
				else y=K[x-1];
				K.Add(kolejna(y));
				x++;
			}
			return K[i-1];
		}
	}
}