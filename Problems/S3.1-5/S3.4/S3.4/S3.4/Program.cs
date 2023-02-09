using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S34
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число a");
            int a = Convert.ToInt32(Console.ReadLine());
            // а) Получим a^3 и a^10 за четыре операции
            /*double two = a * a;
            double three = two * a;
            double six = three * three;
            double nine = six * three;
            double ten = nine * a;
            Console.WriteLine("a^3 = " + three);
            Console.WriteLine("a^10 = " + ten);*/

            // б) Получим a^4 и a^20 за пять операций
            /*double four = a * a;
            double eight = four * four;
            double sixteen = eight * eight;
            double twenty = sixteen * four;
            Console.WriteLine("a^4 = " + four);
            Console.WriteLine("a^20 = " + sixteen);*/

            // в) Получим a^5 и a^13 за пять операций
            /*double two = a * a;
            double four = two * two;
            double five = four * a;
            double ten = five * five;
            double twelve = ten * two;
            double thirteen = twelve * a;
            Console.WriteLine("a^5 = " + five);
            Console.WriteLine("a^13 = " + thirteen);*/

            // г) Получим a^5 и a^19 за пять операций
            /*double two = a * a;
            double four = two * two;
            double five = four * a;
            double ten = five * five;
            double fifteen = ten * five;
            double nineteen = fifteen * four;
            Console.WriteLine("a^5 = " + five);
            Console.WriteLine("a^19 = " + nineteen);*/

            // д) Получим a^2, a^5 и a^17 за шесть операций
            /*double two = a * a;
            double four = two * two;
            double five = four * a;
            double ten = five * five;
            double fifteen = ten * five;
            double seventeen = fifteen * two;
            Console.WriteLine("a^2 = " + two);
            Console.WriteLine("a^5 = " + five);
            Console.WriteLine("a^17 = " + seventeen);*/

            // е) Получим a^4, a^12 и a^28 за пять операций
            double two = a * a;
            double four = two * two;
            double eight = four * four;
            double twelve = eight * four;
            double twentyfour = twelve * twelve;
            double twentyeight = twentyfour * four;
            Console.WriteLine("a^4 = " + four);
            Console.WriteLine("a^12 = " + twelve);
            Console.WriteLine("a^28 = " + twentyeight);
            
            Console.ReadKey();
        }
    }
}