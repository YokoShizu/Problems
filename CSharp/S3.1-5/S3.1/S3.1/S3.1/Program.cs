using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S31
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первое число: a =");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите второе число: b =");
            int b = Convert.ToInt32(Console.ReadLine());
            int c = b;
            b = a;
            a = c;
            Console.WriteLine("А теперь поменяем их местами!");
            Console.WriteLine("a = " + a);
            Console.WriteLine("b = " + b);
            Console.ReadKey();
        }
    }
}