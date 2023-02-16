using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L111
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int A = 0; A <= 1; A++)
            {
                for (int B = 0; B <= 1; B++)
                {
                        Console.WriteLine($"{Convert.ToBoolean(A)}, {Convert.ToBoolean(B)}") ;
                        Console.WriteLine("а) не (А и В) " + !(Convert.ToBoolean(A) && Convert.ToBoolean(B)));
                        Console.WriteLine("б) не А или В " + (!Convert.ToBoolean(A) || Convert.ToBoolean(B)));
                        Console.WriteLine("в) А или не В " + (Convert.ToBoolean(A) || !Convert.ToBoolean(B)));
                }
            }
            Console.ReadKey();
        }
    }
}