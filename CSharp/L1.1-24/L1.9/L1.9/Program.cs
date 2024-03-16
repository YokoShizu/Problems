using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace L19
{
    class Program
    {
        static void Main(string[] args)
        {
            bool X = true;
            bool Y = false;
            bool Z = false;
            Console.WriteLine("а) не X или не Y или не Z " + (!X || !Y || !Z));
            Console.WriteLine("б) (не X или не Y) и (X или Y) " + ((!X || !Y) && (X || Y)));
            Console.WriteLine("в) X и Y или X и Z или не Z " + (X && Y || X && Z || !Z));
            Console.ReadKey();
        }
    }
}