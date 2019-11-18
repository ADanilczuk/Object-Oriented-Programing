//Alicja Danilczuk
//Pracownia PO, czwartek, s. 108
//L3, z1
//Program tworz¹cy moj¹ w³asn¹ listê
//Program g³ówny
//2018-03-15


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace zadanie1
{
    public class Program
    {
        static void Main()
        {
            Lista<int> Lista = new Lista<int>();
            int choice = 0;

            while (choice != 5)
            {
                Console.WriteLine("Wybierz co chcesz zrobiæ:");
                Console.WriteLine("\n Dopisz element na pocz¹tku listy- 1");
                Console.WriteLine("\n Dopisz element na koñcu listy- 2");
                Console.WriteLine("\n Usuñ element z koñca listy- 3");
                Console.WriteLine("\n Wyœwietl listê- 4");
                Console.WriteLine("\n WyjdŸ z programu- 5");
                choice = Int32.Parse(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        {
                            Console.WriteLine("\n Wpisz wartoœæ dla nowego elementu");
                            int element = Int32.Parse(Console.ReadLine());
                            Lista.Add_begin(element);
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("\n Wpisz wartoœæ dla nowego elementu");
                            int element = Int32.Parse(Console.ReadLine());
                            Lista.Add_end(element);
                            break;
                        }
                    case 3:
                        {
                            Lista.Test_if_empty();
                            break;
                        }
                    case 4:
                        {
                            Lista.Show();
                            break;
                        }
                    case 5:
                        break;
                    default:
                        {
                            Console.WriteLine("\nNie ma takiej opcji, podaj inna liczbê");
                            break;
                        }

                }
                Console.Clear();
            }
            Console.Read();
        }
    }
}
