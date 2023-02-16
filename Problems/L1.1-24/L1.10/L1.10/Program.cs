using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L110
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = false;
            bool B = false;
            bool C = true;
            Console.WriteLine("а) (не А или не В) и не С " + ((!A || !B) && !C));
            Console.WriteLine("б) (не А или не В) и (А или В) " + ((!A || !B) && (A || B)));
            Console.WriteLine("в) А и В или А и С или не С " + (A && B || A && C || !C));
            Console.ReadKey();
        }
    }
}