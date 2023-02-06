using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S11
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int a = rnd.Next();
            int b = rnd.Next();
            int c = rnd.Next();
            Console.WriteLine(a + "  " + b + "  " + c);
            Console.ReadKey();
        }
    }
}