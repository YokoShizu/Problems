using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L118
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
                    Console.WriteLine("а) не (не Х или Y) или не Х " + (!(!Convert.ToBoolean(X) || Convert.ToBoolean(Y)) || !Convert.ToBoolean(X)));
                    Console.WriteLine("б) не (не Х и не Y) и Х " + (!(!Convert.ToBoolean(X) && !Convert.ToBoolean(Y)) && Convert.ToBoolean(X)));
                    Console.WriteLine("в) не (Х или не Y) или не Y " + (!(Convert.ToBoolean(X) || !Convert.ToBoolean(Y)) || !Convert.ToBoolean(Y)));
                }
            }
            Console.ReadKey();
        }
    }
}