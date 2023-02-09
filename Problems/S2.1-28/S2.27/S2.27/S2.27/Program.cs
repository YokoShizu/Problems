using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S227
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите температуру по шкале Цельсия");
            int C = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("По шкале Фаренгейта это соответствует " + (C*1.8 + 32) + " градусам");
            Console.WriteLine("По шкале Кельвина это соответствует " + (C + 273.15) + " градусам");
            Console.ReadKey();
        }
    }
}