using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L119
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
                        Console.WriteLine($"{Convert.ToBoolean(A)}, {Convert.ToBoolean(B)}, {Convert.ToBoolean(C)}");
                        Console.WriteLine("а) не (А или не В и С) или С " + (!(Convert.ToBoolean(A) || !Convert.ToBoolean(B) && Convert.ToBoolean(C)) || Convert.ToBoolean(C)));
                        Console.WriteLine("б) не (А и не В или С) и В " + (!(Convert.ToBoolean(A) && !Convert.ToBoolean(B) || Convert.ToBoolean(C)) && Convert.ToBoolean(B)));
                        Console.WriteLine("в) не (не А или В и С) или А " + (!(!Convert.ToBoolean(A) || Convert.ToBoolean(B) && Convert.ToBoolean(C)) || Convert.ToBoolean(A)));
                    }
                }
            }
            Console.ReadKey();
        }
    }
}