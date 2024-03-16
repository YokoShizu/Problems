using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A36
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите трехзначное число");
            double n = Convert.ToDouble(Console.ReadLine());
            if (n > 99 && n < 1000)
            {
                double N = n - Math.Truncate(n / 100) * 100;
                double M = N - Math.Truncate(N / 10) * 10; 
                N -= M;                                    
                M += Math.Truncate(n / 100) * 10;          
                M += N * 10;                               
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