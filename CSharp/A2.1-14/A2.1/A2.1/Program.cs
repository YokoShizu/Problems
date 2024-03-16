using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A21
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите двузначное число");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 9 && N < 100)
            {
                double d = Math.Truncate(N / 10);
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
                double e = N - d * 10;
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
                Console.WriteLine("Сумма его цифр равна " + (d+e));
                Console.WriteLine("Произведение его цифр равно " + (d*e));
            }
            else 
            {
                Console.WriteLine("Это не двузначное число!");    
            }
            Console.ReadKey();
        }
    }
}