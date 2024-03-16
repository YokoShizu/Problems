using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A19
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число n - количество прошедших месяцев");
            int n = Convert.ToInt32(Console.ReadLine());
            double Y = n / 12;
            double N = n - Math.Truncate(Y) * 12;
            double x;
            if (N >= 1 && N <= 11)
            {
                x = N + 1;
            }
            else
            {
                x = 1;
            }
            Console.WriteLine("Сейчас по счету " + x + " месяц");
            Console.ReadKey();
        }
    }
}