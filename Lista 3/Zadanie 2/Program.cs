//Alicja Danilczuk
//Pracownia PO, czwartek, s. 108
//L3, z2
//Program implementuj�cy s�ownik
//Program g��wny
//2018-03-15


using System;

namespace z2
{
    // Klasa zawieraj�ca program daj�cy mo�liwo�� przetestowania 
    // dzia�ania s�ownika. Program jest zabezpieczony przed 
    // podawaniem niepoprawnych danych
    class Program
    {
        static void Main()
        {
            int choice = 0;
            Slownik<int, string> slownik = new Slownik<int, string>();
            
            while (choice != 5)
            { 
                Console.WriteLine("Wybierz co chcesz zrobi�:");
                Console.WriteLine("\n Wpisz nowe has�o do s�ownika- 1");
                Console.WriteLine("\n Usu� has�o ze s�ownika- 2");
                Console.WriteLine("\n Wyszukaj has�o w s�owniku- 3");
                Console.WriteLine("\n Wy�wietl wszystkie has�a ze s�ownika- 4");
                Console.WriteLine("\n Wyjd� z programu- 5");
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
                            Console.WriteLine("\nWpisz klucz hasla");
                            int key;// = new slownik<int,string>();
                            try
                            {
                                key = Int32.Parse(Console.ReadLine());
                            }
                            catch (FormatException)
                            {
                                Console.WriteLine("\n To nie jest poprawny klucz");
                                Console.Read();
                                break;
                            }
                            try
                            {
                                Console.WriteLine("\nWpisz wartosc hasla");
                                string value;// = new slownik<int,string>();
                                value = Console.ReadLine();
                                slownik.Dodaj(key, value);
                            }
                            catch (System.ArgumentException)
                            {
                                Console.WriteLine("\nElement o tym kluczu juz istnieje");
                                Console.Read();
                                break;
                            }
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("\nWpisz klucz hasla, ktore chcesz usunac");
                            int key;
                            try
                            {
                                key = Int32.Parse(Console.ReadLine());
                                slownik.Usun(key);
                            }
                            catch (FormatException)
                            {
                                Console.WriteLine("\\n To nie jest poprawny klucz");
                                Console.Read();
                                break;
                            }

                            catch (System.ArgumentException)
                            {
                                Console.WriteLine("Element o tym kluczu nie istnieje");
                                Console.Read();
                                break;
                            }
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("\nWpisz klucz hasla, ktore chcesz wyszukac");
                            int key;
                            try
                            {
                                key = Int32.Parse(Console.ReadLine());
                                slownik.Wyszukaj(key);
                            }
                            catch (FormatException)
                            {
                                Console.WriteLine("\n To nie jest poprawny klucz");
                                Console.Read();
                                break;
                            }
                            catch (System.ArgumentException)
                            {
                                Console.WriteLine("Element o tym kluczu nie istnieje");
                                Console.Read();
                                break;
                            }
                            break;
                        }
                    case 4:
                        {
                            slownik.wyswietl();
                            Console.Read();
                            break;
                        }
                    default:
                        { 
                            Console.WriteLine("\nNie ma takiej opcji, podaj inna liczbe");
                            break;
                        }

                }
                Console.Clear();
            }
            Console.Read();
        }

    }
}
