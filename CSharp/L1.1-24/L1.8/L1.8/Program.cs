using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L18
{
    class Program
    {
        static void Main(string[] args)
        {
            bool X = false;
            bool Y = true;
            bool Z = false;
            Console.WriteLine("а) X и не (Z или Y) или не Z " + (X && !(Z || Y) || !Z));
            Console.WriteLine("б) не X или X и (Y или Z) " + (!X || X && (Y || Z)));
            Console.WriteLine("в) (X или Y и не Z) и Z " + ((X || Y && !Z) && Z));
            Console.ReadKey();
        }
    }
}