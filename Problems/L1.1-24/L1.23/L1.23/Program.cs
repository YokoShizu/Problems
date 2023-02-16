using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L123
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int A = 0; A <= 1; A++)
            {
                for (int B = 0; B <= 1; B++)
                {
                    for (int C = 0; C <= 1; C++)
                    {
                        bool a = Convert.ToBoolean(A);
                        bool b = Convert.ToBoolean(B);
                        bool c = Convert.ToBoolean(C);
                        Console.WriteLine($"{a}, {b}, {c}");
                        Console.WriteLine("а) не (А и В) и (не А или не С) " + (!(a && b) && (!a || !c)));
                        Console.WriteLine("б) не (А и не В) или (А или не С) " + (!(a && !b) || (a || !c)));
                        Console.WriteLine("в) А и не В или не (А или не С) " + (a && !b || !(a || !c)));
                    }
                }
            }
            Console.ReadKey();
        }
    }
}