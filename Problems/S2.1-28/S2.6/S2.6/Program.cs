using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S26
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Длина окружности равна " + 2 * a);
            double b = Math.PI * Math.Pow(a, 2);
            Console.WriteLine("Площадь круга примерно равна " + b.ToString("0"));
            Console.ReadKey();
        }
    }
}