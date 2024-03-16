using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S210
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Console.WriteLine("Эта программа решает уравнение вида ax + b = 0, a - не ноль."); // эта штука тоже работает, но она не такая крутая как та, что ниже
            Console.WriteLine("Введите a");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите b");
            double b = Convert.ToDouble(Console.ReadLine());
            if (b == 0)
            {
                Console.WriteLine("Решение: x = 0");
            }
            else
            {
                Console.WriteLine("Решение: x = " + (-b)/a);
            }
            Console.ReadKey();*/
            Console.WriteLine("Эта программа решает уравнение вида ax+b=0, a - не ноль.");
            Console.WriteLine("Введите уравнение (без пробелов)");
            string eq = Console.ReadLine();
            char[] c = eq.ToCharArray();
            string a1 = "";
            int i = 0;
            while (c[i] != 'x')
            {
                a1 = a1 + Char.ToString(c[i]);
                i++;
            }
            string b1 = "";
            int j = 0;
            while (c[i+j+2] != '=')
            {
                b1 = b1 + Char.ToString(c[i+j+2]);
                j++;
            }
            int a2 = Convert.ToInt32(a1);
            int b2 = Convert.ToInt32(b1);
            if (b2 == 0)
            {
                Console.WriteLine("Решение: x = 0");
            }
            else
            {
                Console.WriteLine("Решение: x = " + (-b2) / a2);
            }
            Console.ReadKey();
        }
    }
}