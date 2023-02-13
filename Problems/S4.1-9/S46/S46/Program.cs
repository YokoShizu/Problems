using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S46
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("С начала суток прошло n секунд");
            int n = Convert.ToInt32(Console.ReadLine());
            double h = n / 3600;
            Console.WriteLine("С начала суток прошло " + Math.Truncate(h) + " полных суток");
            double m = (n - Math.Truncate(h)*3600)/60;
            Console.WriteLine("С начала очередного часа прошло " + Math.Truncate(m) + " полных минут");
            double s = n - 60*Math.Truncate(m) - Math.Truncate(h)*3600;
            Console.WriteLine("С начала очередной минуты прошло " + Math.Truncate(s) + " секунд");
            Console.ReadKey();
        }
    }
}