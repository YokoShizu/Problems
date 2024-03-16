using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A17
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Дан прямоугольник размерами 543 х 130 мм.");
            double n = 543 / 130;
            Console.WriteLine("От него можно отрезать " + Math.Truncate(n) + " квадрата со стороной 130 мм");
            Console.ReadKey();
        }
    }
}