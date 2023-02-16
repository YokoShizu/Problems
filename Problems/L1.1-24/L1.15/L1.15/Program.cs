using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L115
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int A = 0; A <= 1; A++)
            {
                for (int B = 0; B <= 1; B++)
                {
                    Console.WriteLine($"{Convert.ToBoolean(A)}, {Convert.ToBoolean(B)}");
                    Console.WriteLine("а) не A и не B или А " + (!Convert.ToBoolean(A) && !Convert.ToBoolean(B) || Convert.ToBoolean(A)));
                    Console.WriteLine("б) B или не А и не В " + (Convert.ToBoolean(B) || !(Convert.ToBoolean(A) && !Convert.ToBoolean(B))));
                    Console.WriteLine("в) B и не (А и не В) " + (Convert.ToBoolean(B) && !(Convert.ToBoolean(A) && !Convert.ToBoolean(B))));
                }
            }
            Console.ReadKey();
        }
    }
}