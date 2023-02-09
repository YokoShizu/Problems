using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S33
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число a");
            int a = Convert.ToInt32(Console.ReadLine());
            // а) Получим a^4 за две операции
            int a2 = a * a;
            int a4 = a2 * a2;
            Console.WriteLine("Мы получили a^4 за две операции: " + a4);
            // и) Получим a^6 за три операции
            int a6 = a4 * a2;
            Console.WriteLine("Мы получили a^6 за три операции: " + a6);
            // в) Получим a^7 за четыре операции
            int a7 = a6 * a;
            Console.WriteLine("Мы получили a^7 за четыре операции: " + a7);
            // г) Получим a^8 за три операции
            int a8 = a4 * a4;
            Console.WriteLine("Мы получили a^8 за четыре операции: " + a8);
            // д) Получим a^9 за четыре операции
            int a9 = a8 * a;
            Console.WriteLine("Мы получили a^9 за четыре операции: " + a9);
            // е) Получим a^10 за четыре операции
            int a10 = a8 * a2;
            Console.WriteLine("Мы получили a^10 за четыре операции: " + a10);
            Console.ReadKey();
        }
    }
}