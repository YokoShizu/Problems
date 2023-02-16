using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L15
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = true;
            bool B = false;
            bool C = false;
            Console.WriteLine("а) A или В и не С " + (A || B && !C));
            Console.WriteLine("б) не А и не В " + (!A && !B));
            Console.WriteLine("в) не (А и С) или В " + (! (A && C) || B ));
            Console.WriteLine("г) А и не В или С " + (A && !B || C));
            Console.WriteLine("д) А и (не В или С) " + (A && (!B || C)));
            Console.WriteLine("е) А или (не (В и С)) " + (A || (!(B && C))));
            Console.ReadKey();
        }
    }
}