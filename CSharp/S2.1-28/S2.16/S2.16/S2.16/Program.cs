using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S216
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите длину параллелепипеда");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите ширину параллелепипеда");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите высоту параллелепипеда");
            int h = Convert.ToInt32(Console.ReadLine());
            double V = a * b * h;
            Console.WriteLine("Объем параллелепипеда равен " + V);
            double S = 2 * a * b + 2 * b * h + 2 * a * h;
            Console.WriteLine("Площадь поверхности параллелепипеда равна " + S);
            Console.ReadKey();
        }
    }
}