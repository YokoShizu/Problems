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
                double n = Math.Truncate(N / 1000);
                double s = Math.Truncate((N - n * 1000) / 100);
                double d = Math.Truncate((N - n * 1000 - s * 100)/10);
                switch (d)
                {
                    case 1:
                        Console.WriteLine("В этом числе " + d + " десяток");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("В этом числе " + d + " десятка");
                        break;
                    default:
                        Console.WriteLine("В этом числе " + d + " десятков");
                        break;
                }
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
            }
            else
            {
                Console.WriteLine("В этом числе нет десятков!");
            }
            Console.ReadKey();
        }
    }
}