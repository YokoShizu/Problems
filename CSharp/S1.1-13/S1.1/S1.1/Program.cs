using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S11
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rn = new Random();
            double x = rn.NextDouble();
            Console.WriteLine(x.ToString("0.00"));
            Console.ReadKey();
        }
    }
}