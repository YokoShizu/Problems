using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L14
{
    class Program
    {
        static void Main(string[] args)
        {
            bool X = true;
            bool Y = true;
            bool Z = false;
            Console.WriteLine("а) Не X и Y равно " + (!X && Y));
            Console.WriteLine("б) X или не Y равно " + (X || !Y));
            Console.WriteLine("в) X или Y и Z равно " + (X || Y && Z));
            Console.ReadKey();
        }
    }
}