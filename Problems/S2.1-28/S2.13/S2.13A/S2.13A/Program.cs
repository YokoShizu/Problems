using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S213A
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первое число");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите второе число");
            int b = Convert.ToInt32(Console.ReadLine());
            double arif = (Math.Abs(a)+Math.Abs(b))/2;
            double geom = Math.Pow(Math.Abs(a) * Math.Abs(b), 1.0/2);
            Console.WriteLine("Среднее арифметическое равно " + arif);
            Console.WriteLine("Среднее геометрическое равно " + geom.ToString("#.##"));
            Console.ReadKey();
        }
    }
}