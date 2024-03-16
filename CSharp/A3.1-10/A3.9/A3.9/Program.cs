using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A39
{
    class Program
    {
        static void Main(string[] args)
        {
            double n = 654;
            double N = n - Math.Truncate(n / 100) * 100; // 54
            double M = N - Math.Truncate(N / 10) * 10;   // 4
            M *= 10;                                     // 40
            M += Math.Truncate(N / 10);                  // 45
            M *= 10;                                     // 450
            M += Math.Truncate(n / 100);                 // 456
            Console.WriteLine($"Исходное число равно {M}");
            Console.ReadKey();
        }
    }
}