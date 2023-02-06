using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S24
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = Convert.ToDouble(Console.ReadLine());
            double b = Math.Sqrt(Math.Pow(6350 + a, 2) - Math.Pow(6350, 2));
            Console.WriteLine("Расстояние от точки В до линии горизонта равно " + b.ToString("0") + " км.");
            Console.ReadKey();
        }
    }
}