using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace A22
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите двузначное число");
            double N = Convert.ToInt32(Console.ReadLine());
            if (N > 9 && N < 100)
            {
                double d = Math.Truncate(N / 10);
                double e = N - d * 10;
                Console.WriteLine("Число, получаемое при перестановке цифр: " + (e*10 + d));
            }
            else
            {
                Console.WriteLine("Это не двузначное число!");
            }
            Console.ReadKey();
        }
    }
}