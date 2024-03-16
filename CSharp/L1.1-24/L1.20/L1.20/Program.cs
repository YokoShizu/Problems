using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L120
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
                        Console.WriteLine($"{Convert.ToBoolean(X)}, {Convert.ToBoolean(Y)}, {Convert.ToBoolean(Z)}");
                        Console.WriteLine("а) не (X или не Y и Z) " + !(Convert.ToBoolean(X) || !Convert.ToBoolean(Y) && Convert.ToBoolean(Z)));
                        Console.WriteLine("б) Y или (X и не Y или Z) " + (Convert.ToBoolean(Y) || (Convert.ToBoolean(X) && !Convert.ToBoolean(Y) || Convert.ToBoolean(Z))));
                        Console.WriteLine("в) не (не X и Y или Z) " + !(!Convert.ToBoolean(X) && Convert.ToBoolean(Y) || Convert.ToBoolean(Z)));
                    }
                }
            }
            Console.ReadKey();
        }
    }
}