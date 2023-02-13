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
                double M = Math.Truncate(N / 100);
                double n = N - M * 100;
                double d = Math.Truncate(n / 10);
                double e = n - d * 10;
                switch (e)
                {
                    case 1:
                        Console.WriteLine("В этом числе " + e + " единица");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("В этом числе " + e + " единицы");
                        break;
                    default:
                        Console.WriteLine("В этом числе " + e + " единиц");
                        break;
                }
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
            }
            else
            {
                Console.WriteLine("В этом числе нет десятков!");
            }
            Console.ReadKey();
        }
    }
}