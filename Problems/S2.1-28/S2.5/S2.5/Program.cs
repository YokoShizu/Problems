using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S25
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Объем куба равен " + Math.Pow(a,3));
            Console.WriteLine("Площадь боковой поверхности куба равна " + 6*Math.Pow(a,2));
            Console.ReadKey();
        }
    }
}