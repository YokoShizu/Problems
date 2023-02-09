using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S214
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите меньшее основание трапеции");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите большее основание");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите высоту");
            int h = Convert.ToInt32(Console.ReadLine());
            double c = Math.Sqrt(Math.Pow(h,2) + Math.Pow((b-a)/2,2));
            double P = a+b+2*c;
            Console.WriteLine("Периметр трапеции равен " + P.ToString("#.##"));
            Console.ReadKey();
        }
    }
}