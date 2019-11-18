// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L4, z2
// Program wypisuj�cy liczby pierwsze
// Program g��wny
// 2018-03-22



using System;

namespace zadanie2
{
    class Program
        {
            static void Main()
            {
                int choice = 0;

                while (choice != 3)
                {
                    Console.Clear();
                    Console.WriteLine("Wybierz, co chcesz zrobi�:");
                    Console.WriteLine("\n Wypisz liczby pierwsze do podanej liczby: 1");
                    Console.WriteLine("\n Wypisz liczby pierwsze z ca�ego zakresu int: 2");
                    Console.WriteLine("\n Zako�cz program: 3\n");

                    try
                    {
                        choice = Int32.Parse(Console.ReadLine());
                    }
                    catch (FormatException)
                    {
                        continue;
                    }
                    switch (choice)
                    {
                        case 1:
                            {
                                int max;
                                Console.WriteLine("\n Wpisz maksymaln� liczb�");
                                try
                                {
                                    max = Int32.Parse(Console.ReadLine());
                                }
                                catch (OverflowException)
                                {
                                    Console.WriteLine("Ta liczba przekracza zakres");
                                    Console.Read();
                                    break;
                                }
                                catch (FormatException)
                                {
                                    break;
                                }
                                PrimeCollection pc = new PrimeCollection(max);
                                Console.WriteLine();
                                foreach (int p in pc)
                                    Console.WriteLine(p);
                                Console.Read();
                                break;
                            }
                        case 2:
                            {
                                PrimeCollection pc = new PrimeCollection(int.MaxValue);
                                foreach (int p in pc)
                                    Console.WriteLine(p);
                                break;
                            }

                        case 3:
                            break;
                        default:
                            {
                                Console.WriteLine("\nNie ma takiej opcji, zmie� sw�j wyb�r");
                                Console.Read();
                                break;
                            }

                    }
                    Console.Clear();
                }
                Console.Read();
            }

        }
    
}
