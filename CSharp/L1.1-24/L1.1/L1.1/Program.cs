using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L11
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = true;
            bool B = false;
            bool C = false;
            Console.WriteLine("а) A или В равно " + (A||B));
            Console.WriteLine("б) А и В равно " + (A&&B));
            Console.WriteLine("в) В или С равно " + (B||C));
            Console.ReadKey();
        }
    }
}