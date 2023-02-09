using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S212
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите внешний радиус кольца");
            int R = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите внутренний радиус кольца");
            int r = Convert.ToInt32(Console.ReadLine());
            double S = Math.PI * Math.Pow(R, 2) - Math.PI * Math.Pow(r, 2);
            Console.WriteLine("Площадь кольца равна " + S.ToString("0.00"));
            Console.ReadKey();
        }
    }
}