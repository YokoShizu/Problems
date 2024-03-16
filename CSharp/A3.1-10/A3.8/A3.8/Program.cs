using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A38
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите трехзначное число");
            double n = Convert.ToDouble(Console.ReadLine());
            if (n > 99 && n < 1000)
            {
                double N = n - Math.Truncate(n / 10) * 10;               
                double M = Math.Truncate(n / 100) * 100;                     
                M += N * 10;                                               
                M += Math.Truncate(n / 10) - Math.Truncate(n / 100) * 10;
                Console.WriteLine($"Исходное число равно {M}");
            }
            else
            {
                Console.WriteLine("Вы ввели не трехзначное число!");
            }
            Console.ReadKey();
        }
    }
}