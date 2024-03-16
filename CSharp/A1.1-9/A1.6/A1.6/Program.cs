using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A16
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите, сколько секунд прошло с начала суток");
            int n = Convert.ToInt32(Console.ReadLine());
            if (n <0)
            {
                Console.WriteLine("Число должно быть натуральным!");
            }
            else 
            {
                double h = n / 3600;
                switch (Math.Truncate(h))
                {
                    case 0:
                        Console.WriteLine("С начала суток прошло " + Math.Truncate(h) + " полных часов");
                        break;
                    case 1:
                        Console.WriteLine("С начала суток прошел " + Math.Truncate(h) + " полный час");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("С начала суток прошло " + Math.Truncate(h) + " полных часа");
                        break;
                    default:
                        Console.WriteLine("С начала суток прошло " + Math.Truncate(h) + " полных часов");
                        break;
                }

                double m = (n - Math.Truncate(h) * 3600) / 60;
                switch (Math.Truncate(m))
                {
                    case 0:
                        Console.WriteLine("С начала очередного часа прошло " + Math.Truncate(m) + " полных минут");
                        break;
                    case 1:
                        Console.WriteLine("С начала очередного часа прошла " + Math.Truncate(m) + " полная минута");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("С начала очередного часа прошли " + Math.Truncate(m) + " полные минуты");
                        break;
                    default:
                        Console.WriteLine("С начала очередного часа прошло " + Math.Truncate(m) + " полных минут");
                        break;
                }

                double s = n - 60 * Math.Truncate(m) - Math.Truncate(h) * 3600;
                switch (s)
                {
                    case 0:
                        Console.WriteLine("С начала очередной минуты прошло " + s + " секунд");
                        break;
                    case 1:
                        Console.WriteLine("С начала очередной минуты прошла " + s + " секунда");
                        break;
                    case 2:
                    case 3:
                    case 4:
                        Console.WriteLine("С начала очередной минуты прошли " + s + " секунды");
                        break;
                    default:
                        Console.WriteLine("С начала очередной минуты прошло " + s + " секунд");
                        break;
                }
            }
            Console.ReadKey();
        }
    }
}