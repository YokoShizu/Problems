using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A13
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число килограммов");
            int weight = Convert.ToInt32(Console.ReadLine());
            double m = weight / 1000;
            Console.WriteLine("Число полных тонн равно " + Math.Truncate(m));
            Console.ReadKey();
        }
    }
}