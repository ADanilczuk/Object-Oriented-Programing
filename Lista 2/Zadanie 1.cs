/*
   Alicja Danilczuk
   Programowanie obiektowe
   Lista 2
   Zadanie 1
   9.03.2018
 */


namespace Zadanie
{
	class IntStream
	{
		
		int n=0;
		bool test=true;
		
		virtual public int next()
		{
			if (n<=int.MaxValue) 
			{
				return n++;
			}
			else
			{
				test=false;
				return -1;
			}
		}
		
		public bool eos()
		{
			return test;
		}
		
		public void reset()
		{
			n=0;
		}	
	}
	
	
	
	class Primestream : IntStream
	{
		int n=1;
	
	override public int next()
		{
			if (n<=int.MaxValue) 
			{
				n++;
				while (!pierwsza(n))
				{
					n++;
				}
				return n;
			}
			else
			{
				return -1;
			}
			
		}
	
	public bool pierwsza(int x)
		{
            if (x < 2)
                return false;
            for (int i = 2; i <= System.Math.Sqrt(x) && i < int.MaxValue; i++) 
            {
                if (x % i == 0)
                    return false;
            }
            return true;
        }   
	}
	
	
	class RandomStream : Primestream
	{
		System.Random rand = new System.Random();
		
		override public int next()
		{
			return rand.Next();
		}
		
	}
	
	class RandomWordStream
	{
		Primestream pierw= new Primestream();
		
		public string next()
        {
			
            string s = null;
     		int l = pierw.next();
     		
            RandomStream rand_2 = new RandomStream();
            int r = rand_2.next();
            
            for (int i = 0; i < l; i++)
            {
                s += r % 10;
                if (r > 10) r /= 10;
                else r = rand_2.next();
            }
            return s;
        }
		
		
	}
	
class main
{
	static void Main()
		{
			IntStream a= new IntStream();
			System.Console.WriteLine(a.next());
			System.Console.WriteLine(a.next());
			System.Console.WriteLine();
			
			a.reset();
			System.Console.WriteLine(a.next());
			System.Console.WriteLine(a.next());
			System.Console.WriteLine();
			
			Primestream p= new Primestream();
			System.Console.WriteLine(p.next());
			System.Console.WriteLine(p.next());
			System.Console.WriteLine(p.next());
			System.Console.WriteLine(p.next());
			System.Console.WriteLine();
			
			RandomStream r= new RandomStream();
			System.Console.WriteLine(r.next());
			System.Console.WriteLine(r.next());
			System.Console.WriteLine(r.next());
			System.Console.WriteLine();
			
			RandomWordStream rs= new RandomWordStream();
			System.Console.WriteLine(rs.next());
			System.Console.WriteLine(rs.next());
			System.Console.WriteLine(rs.next());
			System.Console.Read();
		}
	}
}