using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A35
{
    class Program
    {
        static void Main(string[] args)
        {
            double n = 546;
            double N = n - Math.Truncate(n / 100)*100; // 46
            double M = N - Math.Truncate(N / 10) * 10; // 6
            N -= M;                                    // 40
            M += Math.Truncate(n / 100) * 10;          // 56
            M += N * 10;                               // 456
            Console.WriteLine($"Исходное число равно {M}");
            Console.ReadKey();
        }
    }
}