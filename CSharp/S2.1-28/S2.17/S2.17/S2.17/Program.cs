using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S217
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Console.WriteLine("Введите координату x первой точки");
            double x1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите координату y первой точки");
            double y1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите координату x второй точки");
            double x2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите координату y второй точки");
            double y2 = Convert.ToInt32(Console.ReadLine());
            double dis = Math.Sqrt(Math.Pow((y2- y1),2) + Math.Pow((x2-x1),2));
            Console.WriteLine("Расстояние между точками равно " + dis);*/

            Console.WriteLine("Введите координаты первой точки (без скобок, через запятую, без пробелов)");
            string coor1 = Console.ReadLine();
            char[] c1 = coor1.ToCharArray();
            string x1 = "";
            int v1 = 0;
            for (int i = 0;  c1[i] != ','; i++)
            {
                x1 = x1 + Char.ToString(c1[i]);
                v1 = v1 + i;
            }
            string y1 = "";
            int l1 = coor1.Length;
            for (int j = 0; v1+j+2 < l1; j++)
            {
                y1 = y1 + Char.ToString(c1[v1+j+2]);
            }
            int xx1 = Convert.ToInt32(x1);
            int yy1 = Convert.ToInt32(y1);
            
            Console.WriteLine("Введите координаты второй точки (в круглых скобках, через запятую, без пробелов)");
            string coor2 = Console.ReadLine();
            char[] c2 = coor2.ToCharArray();
            string x2 = "";
            int v2 = 0;
            for (int i = 0; c2[i] != ','; i++)
            {
                x2 = x2 + Char.ToString(c2[i]);
                v2 = v2 + i;
            }
            string y2 = "";
            int l2 = coor2.Length;
            for (int j = 0; v2 + j + 2 < l2; j++)
            {
                y2 = y2 + Char.ToString(c2[v2 + j + 2]);
            }
            int xx2 = Convert.ToInt32(x2);
            int yy2 = Convert.ToInt32(y2);
            double diss = Math.Sqrt(Math.Pow((xx1-xx2),2) + Math.Pow((yy1-yy2),2));
            Console.WriteLine("Расстояние между точками равно " + diss);
            Console.ReadKey();
        }
    }
}