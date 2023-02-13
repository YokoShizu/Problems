using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S45
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Со дня Х прошло 234 дня");
            int days = 234;
            double weeks = 234 / 7;
            Console.WriteLine("Значит прошло " + Math.Truncate(weeks) + " недель");
            Console.ReadKey();
        }
    }
}