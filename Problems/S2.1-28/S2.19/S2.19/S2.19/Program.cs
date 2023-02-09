using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S218
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите меньше основание трапеции");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Теперь большее");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("А еще введите угол при большем основании! (В градусах)");
            int angle = Convert.ToInt32(Console.ReadLine());
            double rangle = angle * Math.PI / 180;
            Console.WriteLine("Площадь трапеции равна " + (b + a) * Math.Tan(rangle) * (b - a) / 4);
            Console.ReadKey();
        }
    }
}