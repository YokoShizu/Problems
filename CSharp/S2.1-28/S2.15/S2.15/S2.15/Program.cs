using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S215
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первое число");
            double a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите второе число");
            double b = Convert.ToInt32(Console.ReadLine());
            double Sum = a + b;
            double Dif = a - b;
            double Mult = a * b;
            double Div = a / b;
            Console.WriteLine("Сумма чисел равна " + Sum);
            Console.WriteLine("Разность чисел равна " + Dif);
            Console.WriteLine("Произведение чисел равно " + Mult);
            Console.WriteLine("Частное от деления первого числа на второе равно " + Div.ToString("#.##"));
            Console.ReadKey();
        }
    }
}