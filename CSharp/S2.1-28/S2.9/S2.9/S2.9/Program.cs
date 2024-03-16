using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S29
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите количество жителей страны");
            double C = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите площадь территории");
            double S = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Плотность населения равна " + C / S);
            Console.ReadKey();
        }
    }
}