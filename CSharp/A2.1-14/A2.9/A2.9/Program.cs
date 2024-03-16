using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A29
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите трехзначное число, все цифры которого различны");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 99 && N < 1000)
            {
                double s = Math.Truncate(N / 100);
                double d = Math.Truncate((N - s * 100) / 10);
                double e = N - s * 100 - d * 10;
                if ((e == s) || (d == s) || (d == e))
                {
                    Console.WriteLine("Число не удовлетворяет условию различности цифр!");
                }
                else
                {
                    Console.WriteLine("Шесть чисел, полученных при перестановке цифр заданного числа: 1)" + (s * 100 + d * 10 + e) + ", 2)" + (d*100 + e*10 + s) + ", 3)" + (e*100 + s*10 + d) + ", 4)" + (s*100 + e*10 + d) + ", 5)" + (e*100 + d*10+ s) + ", 6)" + (d*100 + s*10 + e));
                }
            }
            else
            {
                Console.WriteLine("Это не трехзначное число!");
            }
            Console.ReadKey();
        }
    }
}