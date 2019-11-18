// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L4, z2
// Program wypisuj¹cy liczby pierwsze
// Program g³ówny
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
                    Console.WriteLine("Wybierz, co chcesz zrobiæ:");
                    Console.WriteLine("\n Wypisz liczby pierwsze do podanej liczby: 1");
                    Console.WriteLine("\n Wypisz liczby pierwsze z ca³ego zakresu int: 2");
                    Console.WriteLine("\n Zakoñcz program: 3\n");

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
                                Console.WriteLine("\n Wpisz maksymaln¹ liczbê");
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
                                Console.WriteLine("\nNie ma takiej opcji, zmieñ swój wybór");
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
