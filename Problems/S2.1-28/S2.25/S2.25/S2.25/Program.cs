using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S225
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите скорость v1 первого автомобиля");
            int v1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите скорость v2 второго автомобиля");
            int v2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите расстояние S между автомобилями");
            int S = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Автомобили встретятся черед " + S/(v1+v2) + " часов");
            Console.ReadKey();
        }
    }
}