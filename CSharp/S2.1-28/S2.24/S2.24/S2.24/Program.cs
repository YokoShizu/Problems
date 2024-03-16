using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S224
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Сколько лет Тане?");
            double X = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Сколько лет Мите?");
            double Y = Convert.ToInt32(Console.ReadLine());
            switch ((X + Y) / 2)
            {
                case > 4:
                    Console.WriteLine("Их средний возраст " + ((X + Y) / 2) + " лет");
                    break;
                default:
                    Console.WriteLine("Их средний возраст " + ((X + Y) / 2) + " года");
                    break;
            }
            switch ((X - Y) / 2)
            {
                case > 4:
                    Console.WriteLine("Таня старше их среднего возраста на " + Math.Abs((X - Y) / 2) + " лет");
                    break;
                case (> 0 and < 4):
                    Console.WriteLine("Таня старше их среднего возраста на " + Math.Abs((X - Y) / 2) + " года");
                    break;
                case (< 0 and > -4):
                    Console.WriteLine("Таня младше их среднего возраста на " + Math.Abs((X - Y) / 2) + " года");
                    break;
                case < -4:
                    Console.WriteLine("Таня младше их среднего возраста на " + Math.Abs((X - Y) / 2) + " лет");
                    break;
                default:
                    Console.WriteLine("Тане ровно " + (X + Y) / 2 + " лет");
                    break;
            }
            switch ((X - Y) / 2)
            {
                case > 4:
                    Console.WriteLine("Митя старше их среднего возраста на " + Math.Abs((X - Y) / 2) + " лет");
                    break;
                case (> 0 and < 4):
                    Console.WriteLine("Митя старше их среднего возраста на " + Math.Abs((X - Y) / 2) + " года");
                    break;
                case (< 0 and > -4):
                    Console.WriteLine("Митя младше их среднего возраста на " + Math.Abs((X - Y) / 2) + " года");
                    break;
                case < -4:
                    Console.WriteLine("Митя младше их среднего возраста на " + Math.Abs((X - Y) / 2) + " лет");
                    break;
                default:
                    Console.WriteLine("Мите ровно " + (X + Y) / 2 + " лет");
                    break;
            }
            Console.ReadKey();
        }
    }
}