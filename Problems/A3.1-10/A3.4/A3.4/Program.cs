using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A34
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите трехзначное число");
            double n = Convert.ToDouble(Console.ReadLine());
            if (n > 99 && n < 1000)
            {
                double N = Math.Truncate(n / 10);
                N += (n-N*10)*100;
                Console.WriteLine($"Исходное число равно {N}");
            }
            else
            {
                Console.WriteLine("Вы ввели не трехзначное число!");
            }
            Console.ReadKey();
        }
    }
}