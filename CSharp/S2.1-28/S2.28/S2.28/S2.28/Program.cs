using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S228
{
    class Program
    {
        static void Main(string[] args)
        {
            double C = (450 - 32) / 1.8;
            Console.WriteLine("Указанные 450 градусов по Фаренгейту соответствуют " + C.ToString("#.##") + " градусам");
            Console.ReadKey();
        }
    }
}