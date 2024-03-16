using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S213
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первый катет");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите второй катет");
            int b = Convert.ToInt32(Console.ReadLine());
            double c = Math.Sqrt(Math.Pow(a,2)+Math.Pow(b,2));
            double P = a + b + c;
            Console.WriteLine("Периметр треугольника равен " + P.ToString("#.##"));
            Console.ReadKey();
        }
    }
}