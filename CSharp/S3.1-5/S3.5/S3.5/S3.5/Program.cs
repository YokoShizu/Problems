using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S34
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число a");
            int a = Convert.ToInt32(Console.ReadLine());
            double two = a * a;
            double three = two * a;
            double six = three * three;
            double nine = six * three;
            double ten = nine * a;
            double a10 = Math.Pow(a, 10);
            Console.WriteLine("a^3 = " + three);
            Console.WriteLine("a^10 = " + ten);
            Console.WriteLine("a^10 = " + a10);
        }
    }
}