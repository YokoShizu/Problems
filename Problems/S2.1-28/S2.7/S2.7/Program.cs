using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S27
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первое число.");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите ыторое число.");
            double b = Convert.ToDouble(Console.ReadLine());
            string c = Convert.ToString(a)+Convert.ToString(b);
            int d = c.Length;
            double geom = Math.Pow(a*b, 1.0/d);
            Console.WriteLine("Среднее арифметическое двух чисел равно " + (a + b) / d);
            Console.WriteLine("Среднее геометрическое двух чисел равно " + geom.ToString("0.000"));
            Console.ReadKey();
        }
    }
}