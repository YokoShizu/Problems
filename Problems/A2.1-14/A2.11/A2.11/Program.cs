using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A211
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите четырехзначное число");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 999 && N < 10000)
            {
                double t = Math.Truncate(N / 1000);
                double s = Math.Truncate((N - t * 1000) / 100);
                double d = Math.Truncate((N - t * 1000 - s * 100) / 10);
                double e = N - t * 1000 - s * 100 - d * 10;
                Console.WriteLine("а) Число, полученное при прочтении его цифр справа налево, раввно " + (e*1000 + d*100 + s*10 + t));
                Console.WriteLine("б) Число, образованное при перестановке первой и второй, третьей и четвертой цифр заданного числа, равно " + (s*1000 + t*100 + e*10 + d));
                Console.WriteLine("в) Число, образованное при перестановке второй и третьей цифр заданного числа, равно " + (t*1000 + d*100 + s*10 + e));
                Console.WriteLine("Способ первый. г) Число, образованное при перестановке двух первых и двух последних цифр заданного числа, равно " + (d*1000 + e*100 + t*10 + s));
                double first = Math.Truncate(N / 100);
                double second = N - first * 100;
                Console.WriteLine("Способ второй. г) Число, образованное при перестановке двух первых и двух последних цифр заданного числа, равно " + (second*100 + first));
            }
            else
            {
                Console.WriteLine("Это не четырехзначное число!");
            }
            Console.ReadKey();
        }
    }
}