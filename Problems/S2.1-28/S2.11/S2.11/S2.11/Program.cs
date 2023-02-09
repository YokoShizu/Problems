using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S211
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите значение первого катета");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите значение второго катета");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Гипотенуза треугольника равна " + Math.Sqrt(Math.Pow(a,2) + Math.Pow(b,2)));
            Console.ReadKey();
        }
    }
}