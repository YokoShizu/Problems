using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S223
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Монитор стоит 1000 рублей, системный блок - 7000 рублей, клавиатура - 500 рублей, а мышь 400 рублей");
            Console.WriteLine("Стоимость покупки трех компьютеров из этих элементов равна " + (3 * 1000 + 3 * 7000 + 3 * 500 + 3* 400) + " рублей");
            Console.WriteLine("Сколько компьютеров Вы хотите купить?");
            int N = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Стоимость покупки " + N + " компьютеров из этих элементов равна " + (N * 1000 + N * 7000 + N * 500 + N * 400) + " рублей");
            Console.ReadKey();
        }
    }
}