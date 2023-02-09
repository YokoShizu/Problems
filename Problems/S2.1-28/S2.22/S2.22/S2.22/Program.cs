using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S222
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Один килограмм конфет стоит 100 рублей, печенья - 150 рублей, а яблок - 70 рублей");
            Console.WriteLine("Введите, сколько килограмм конфет Вы купили");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Теперь введите, сколько печенья");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("И, наконец, сколько яблок");
            int c = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Стоимость вашей покупки равна " + (a * 100 + b * 150 + c * 70) + " рублей");
            Console.ReadKey();
        }
    }
}