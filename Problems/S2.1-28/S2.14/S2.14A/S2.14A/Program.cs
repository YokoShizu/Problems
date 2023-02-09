using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S214A
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите длину прямоугольника");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("А теперь ширину");
            int b = Convert.ToInt32(Console.ReadLine());
            double d = Math.Sqrt(Math.Pow(a, 2) + Math.Pow(b, 2));
            double P = 2*a + 2*b;
            Console.WriteLine("Периметр прямоугольника равна " + P.ToString("#.##"));
            Console.WriteLine("Диагональ прямоугольника равна " + d.ToString("#.##"));
            Console.ReadKey();
        }
    }
}