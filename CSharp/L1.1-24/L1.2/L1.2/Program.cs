using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L12
{
    class Program
    {
        static void Main(string[] args)
        {
            bool X = false;
            bool Y = true;
            bool Z = false;
            Console.WriteLine("а) X или Z равно " + (X || Z));
            Console.WriteLine("б) X и Y равно " + (X && Y));
            Console.WriteLine("в) X и Z равно " + (X && Z));
            Console.ReadKey();
        }
    }
}