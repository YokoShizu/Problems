using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A18
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число k от 1 до 365");
            int k = Convert.ToInt32(Console.ReadLine());
            if (1<=k && k<=365)
            {
                Console.WriteLine("Введите, каким днем недели было 1-е января (1 - понедельник, ..., 6 - суббота, 0 - воскресенье)");
                int d = Convert.ToInt32(Console.ReadLine());
                if (0<=d && d <=6)
                {
                    double K = (k + d) / 7;
                    double n = Math.Abs(k + d - Math.Truncate(K) * 7);
                    switch (n)
                    {
                        case 0:
                            Console.WriteLine("k-ый день года это воскресенье");
                            break;
                        case 1:
                            Console.WriteLine("k-ый день года это понедельник");
                            break;
                        case 2:
                            Console.WriteLine("k-ый день года это вторник");
                            break;
                        case 3:
                            Console.WriteLine("k-ый день года это среда");
                            break;
                        case 4:
                            Console.WriteLine("k-ый день года это четверг");
                            break;
                        case 5:
                            Console.WriteLine("k-ый день года это пятница");
                            break;
                        case 6:
                            Console.WriteLine("k-ый день года это суббота");
                            break;
                    }
                }
                else
                {
                    Console.WriteLine("Введенное d находится вне заданных границ!");
                }
            }
            else
            {
                Console.WriteLine("Введенное k находится вне заданных границ!");
            }
            Console.ReadKey();
        }
    }
}