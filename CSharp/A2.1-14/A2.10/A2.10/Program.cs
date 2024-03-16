using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A210
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
                double s = Math.Truncate((N - t*1000) / 100);
                double d = Math.Truncate((N - t*1000 - s * 100) / 10);
                double e = N - t*1000 - s * 100 - d * 10;
                Console.WriteLine("Сумма цифр числа равна " + (t+s+d+e));
                Console.WriteLine("Произведение цифр числа равно " + (t * s * d * e));
            }
            else
            {
                Console.WriteLine("Это не четырехзначное число!");
            }
            Console.ReadKey();
        }
    }
}