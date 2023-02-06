using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S28
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите объем тела");
            double V = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите массу тела");
            double M = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Плотность материала тела равна " + M/V);
            Console.ReadKey();
        }
    }
}