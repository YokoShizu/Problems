using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S226
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите скорость v1 первого автомобиля (она должна быть больше, чем скорость второго)");
            int v1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите скорость v2 второго автомобиля");
            int v2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите расстояние S между автомобилями");
            int S = Convert.ToInt32(Console.ReadLine());
            double s = S + (v1 - v2) * 0.5;
            Console.WriteLine("Через 30 минут после того, как первый автомобиль обогнал второй на " + S + " километров, между автомобилями будет " + s + " километров");
            Console.ReadKey();
        }
    }
}