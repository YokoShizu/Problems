using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A23
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите трехзначное число");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 99 && N < 1000)
            {
                double s = Math.Truncate(N / 100);
                double d = Math.Truncate((N - s*100) / 10);
                switch (d)
                {
                    case 1:
                        Console.WriteLine("У числа " + N + " " + d + " десяток");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("У числа " + N + " " + d + " десятка");
                        break;
                    default:
                        Console.WriteLine("У числа " + N + " " + d + " десятков");
                        break;
                }
                double e = N - s*100 - d * 10;
                switch (e)
                {
                    case 1:
                        Console.WriteLine("И " + e + " единица");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("И " + e + " единицы");
                        break;
                    default:
                        Console.WriteLine("И " + e + " единиц");
                        break;
                }
                Console.WriteLine("Сумма его цифр равна " + (d + e + s));
                Console.WriteLine("Произведение его цифр равно " + (d * e * s));
            }
            else
            {
                Console.WriteLine("Это не трехзначное число!");
            }
            Console.ReadKey();
        }
    }
}