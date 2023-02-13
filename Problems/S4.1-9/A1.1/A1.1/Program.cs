using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A11
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число сантиметров");
            int cm = Convert.ToInt32(Console.ReadLine());
            double m = cm / 100;
            Console.WriteLine("Число полных метров равно " + Math.Truncate(m));
            Console.ReadKey();
        }
    }
}