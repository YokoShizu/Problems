using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L124
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int X = 0; X <= 1; X++)
            {
                for (int Y = 0; Y <= 1; Y++)
                {
                    for (int Z = 0; Z <= 1; Z++)
                    {
                        bool x = Convert.ToBoolean(X);
                        bool y = Convert.ToBoolean(Y);
                        bool z = Convert.ToBoolean(Z);
                        Console.WriteLine($"{x}, {y}, {z}");
                        Console.WriteLine("а) не (X или Y) и (не X или не Z) " + (!(x || y) && (!x || !z)));
                        Console.WriteLine("б) не (не X и Y) или (X и не Z) " + (!(!x && y) || (x && !z)));
                        Console.WriteLine("в) X или не Y и не (X или не Z) " + (x || !y && !(x || !z)));
                    }
                }
            }
            Console.ReadKey();
        }
    }
}