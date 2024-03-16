using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L17
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = true;
            bool B = false;
            bool C = false;
            Console.WriteLine("а) А или не (А и В) или С " + (A || !(A && B) ||C));
            Console.WriteLine("б) не А или А и (В или С) " + (!A || A && (B || C)));
            Console.WriteLine("в) (А или В и не С) и С " + ((A || B && !C) && C));
            Console.ReadKey();
        }
    }
}