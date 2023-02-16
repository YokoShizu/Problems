using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L122
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
                        Console.WriteLine("а) не (Y или не X и Z) или Z " + (!(y || !x && z)|| z));
                        Console.WriteLine("б) X и не (не Y или Z) или Y " + (x && !(!y || z) || y));
                        Console.WriteLine("в) не (X или Y и Z) или не X " + (!(x || y && z) || !x));
                    }
                }
            }
            Console.ReadKey();
        }
    }
}