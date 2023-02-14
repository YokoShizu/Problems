using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A37
{
    class Program
    {
        static void Main(string[] args)
        {
            double n = 456;
            double N = n - Math.Truncate(n / 10) * 10;                  // 6
            double M = Math.Truncate(n/100)*100;                        // 400
            M += N * 10;                                                // 460
            M += Math.Truncate(n/10) - Math.Truncate(n / 100) * 10; // 465
            Console.WriteLine($"Исходное число равно {M}");
            Console.ReadKey();
        }
    }
}