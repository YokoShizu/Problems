using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L114
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
                    Console.WriteLine("а) не X и не Y " + (!Convert.ToBoolean(X) && !Convert.ToBoolean(Y)));
                    Console.WriteLine("б) X или (не Х и Y) " + (Convert.ToBoolean(X) || (!Convert.ToBoolean(X) && Convert.ToBoolean(Y))));
                    Console.WriteLine("в) (не X и Y) или Y " + ((!Convert.ToBoolean(X) && Convert.ToBoolean(Y)) || Convert.ToBoolean(Y)));
                }
            }
            Console.ReadKey();
        }
    }
}