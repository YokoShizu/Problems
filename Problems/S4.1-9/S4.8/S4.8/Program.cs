using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S48
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число k от 1 до 365");
            int k = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите, каким по счету днем недели было 1-е января");
            int d = Convert.ToInt32(Console.ReadLine());
            double K = (k+d) / 7;
            double n = Math.Abs(k+d - Math.Truncate(K) * 7);
            Console.WriteLine(n);

            Console.ReadKey();
        }
    }
}