using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S44
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число метров");
            int length = Convert.ToInt32(Console.ReadLine());
            double km = length / 1000;
            Console.WriteLine("Число полных километров равно " + Math.Truncate(km));
            Console.ReadKey();
        }
    }
}