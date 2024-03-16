using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A212
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 9)
            {
                double n = Math.Truncate(N / 10000);
                double t = Math.Truncate((N - n * 10000) / 1000);
                double s = Math.Truncate((N - n * 10000 - t * 1000) / 100);
                switch (s)
                {
                    case 1:
                        Console.WriteLine("В этом числе " + s + " сотня");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("В этом числе " + s + " сотни");
                        break;
                    default:
                        Console.WriteLine("В этом числе " + s + " сотен");
                        break;
                }
                switch (t)
                {
                    case 1:
                        Console.WriteLine("В этом числе " + t + " тысяча");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("В этом числе " + t + " тысячи");
                        break;
                    default:
                        Console.WriteLine("В этом числе " + t + " тысяч");
                        break;
                }
            }
            else
            {
                Console.WriteLine("В этом числе нет десятков!");
            }
            Console.ReadKey();
        }
    }
}