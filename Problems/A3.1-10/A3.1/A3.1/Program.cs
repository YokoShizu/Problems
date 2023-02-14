using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A31
{
    class Program
    {
        static void Main(string[] args)
        {
            double basic = 237;
            double first = basic - Math.Truncate(basic/100)*100;
            first *= 10;
            first += Math.Truncate(basic / 100);
            Console.WriteLine($"Исходное число равно {first}");
            Console.ReadKey();
        }
    }
}