using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L13
{
    class Program
    {
        static void Main(string[] args)
        {
            bool A = true;
            bool B = false;
            bool C = false;
            Console.WriteLine("а) Не A и В равно " + (!A && B));
            Console.WriteLine("б) А или не В равно " + (A || !B));
            Console.WriteLine("в) A и В или С равно " + (A && B || C));
            Console.ReadKey();
        }
    }
}