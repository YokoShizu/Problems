using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A33
{
    class Program
    {
        static void Main(string[] args)
        {
            double n = 564;
            double N = Math.Truncate(n / 10);
            N += (n - N * 10) * 100;
            Console.WriteLine($"Исходное число равно {N}");
            Console.ReadKey();
        }
    }
}