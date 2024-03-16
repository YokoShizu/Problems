using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S32
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число a");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите число b");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите число c");
            int c = Convert.ToInt32(Console.ReadLine());
            // а) Схема b -> c, a -> b, c -> a
            /*int d = b;
            b = c;
            c = a;
            a = d;
            Console.WriteLine("А теперь меняем все местами!");
            Console.WriteLine("Теперь a = " + a);
            Console.WriteLine("Теперь b = " + b);
            Console.WriteLine("Теперь c = " + c);*/
            // а) Схема b -> a, c -> b, a -> c
            int d = a;
            a = c;
            c = b;
            b = d;
            Console.WriteLine("А теперь меняем все местами!");
            Console.WriteLine("Теперь a = " + a);
            Console.WriteLine("Теперь b = " + b);
            Console.WriteLine("Теперь c = " + c);
            Console.ReadKey();
        }
    }
}