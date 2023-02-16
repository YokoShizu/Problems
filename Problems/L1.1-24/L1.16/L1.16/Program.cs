using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L116
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int X = 0; X <= 1; X++)
            {
                for (int Y = 0; Y <= 1; Y++)
                {
                    Console.WriteLine($"{Convert.ToBoolean(X)}, {Convert.ToBoolean(Y)}");
                    Console.WriteLine("а) не (X и не Y) или Х " + (!(Convert.ToBoolean(X) && !Convert.ToBoolean(Y)) || Convert.ToBoolean(X)));
                    Console.WriteLine("б) Y и не Х или не Y " + (Convert.ToBoolean(Y) && !Convert.ToBoolean(X) || !Convert.ToBoolean(Y)));
                    Console.WriteLine("в) не Y и не X или Y " + (!Convert.ToBoolean(Y) && !Convert.ToBoolean(X) || Convert.ToBoolean(Y)));
                }
            }
            Console.ReadKey();
        }
    }
}