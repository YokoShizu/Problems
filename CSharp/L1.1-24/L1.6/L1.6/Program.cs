using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L16
{
    class Program
    {
        static void Main(string[] args)
        {
            bool X = false;
            bool Y = false;
            bool Z = true;
            Console.WriteLine("a) X или Y и не Z " + (X || Y && !Z));
            Console.WriteLine("б) не X и не Y " + (!X && !Y));
            Console.WriteLine("в) не (X и Z) или Y " + (!(X && Z) || Y));
            Console.WriteLine("г) X и не Y или Z " + (X && !Y || Z));
            Console.WriteLine("д) X и (не Y или Z) " + (X && (!Y || Z)));
            Console.WriteLine("е) X или (не (Y или Z)) " + (X || !(Y || Z)));
            Console.ReadKey();
        }
    }
}