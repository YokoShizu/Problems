using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A12
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите массу в килограммах");
            int weight = Convert.ToInt32(Console.ReadLine());
            double M = weight / 100;
            Console.WriteLine("Число полных центнеров равно " + Math.Truncate(M));
            Console.ReadKey();
        }
    }
}