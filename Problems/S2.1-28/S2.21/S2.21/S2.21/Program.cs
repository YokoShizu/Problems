using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S221
{
    class Program
    {
        static void Main(string[] args)
        {
            // Вводим с клавиатуры координаты точек
            Console.WriteLine("Введите координаты первой точки (без скобок, через запятую, без пробелов)");
            string coor1 = Console.ReadLine();
            char[] c1 = coor1.ToCharArray();
            string x1 = "";
            int v1 = 0;
            for (int i = 0; c1[i] != ','; i++)
            {
                x1 = x1 + Char.ToString(c1[i]);
                v1 = v1 + i;
            }
            string y1 = "";
            int l1 = coor1.Length;
            for (int j = 0; v1 + j + 2 < l1; j++)
            {
                y1 = y1 + Char.ToString(c1[v1 + j + 2]);
            }
            int xx1 = Convert.ToInt32(x1);
            int yy1 = Convert.ToInt32(y1);

            Console.WriteLine("Введите координаты второй точки (без скобок, через запятую, без пробелов)");
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

            Console.WriteLine("Введите координаты третьей точки (без скобок, через запятую, без пробелов)");
            string coor3 = Console.ReadLine();
            char[] c3 = coor3.ToCharArray();
            string x3 = "";
            int v3 = 0;
            for (int i = 0; c3[i] != ','; i++)
            {
                x3 = x3 + Char.ToString(c3[i]);
                v3 = v3 + i;
            }
            string y3 = "";
            int l3 = coor3.Length;
            for (int j = 0; v3 + j + 2 < l3; j++)
            {
                y3 = y3 + Char.ToString(c3[v3 + j + 2]);
            }
            int xx3 = Convert.ToInt32(x3);
            int yy3 = Convert.ToInt32(y3);

            Console.WriteLine("Введите координаты четвертой точки (без скобок, через запятую, без пробелов)");
            string coor4 = Console.ReadLine();
            char[] c4 = coor4.ToCharArray();
            string x4 = "";
            int v4 = 0;
            for (int i = 0; c4[i] != ','; i++)
            {
                x4 = x4 + Char.ToString(c4[i]);
                v4 = v4 + i;
            }
            string y4 = "";
            int l4 = coor4.Length;
            for (int j = 0; v4 + j + 2 < l4; j++)
            {
                y4 = y4 + Char.ToString(c4[v4 + j + 2]);
            }
            int xx4 = Convert.ToInt32(x4);
            int yy4 = Convert.ToInt32(y4);

            // Считаем стороны четырехугольника
            double diss12 = Math.Sqrt(Math.Pow((xx1 - xx2), 2) + Math.Pow((yy1 - yy2), 2));
            double diss23 = Math.Sqrt(Math.Pow((xx2 - xx3), 2) + Math.Pow((yy2 - yy3), 2));
            double diss13 = Math.Sqrt(Math.Pow((xx1 - xx3), 2) + Math.Pow((yy1 - yy3), 2));
            double diss34 = Math.Sqrt(Math.Pow((xx3 - xx4), 2) + Math.Pow((yy3 - yy4), 2));
            double diss41 = Math.Sqrt(Math.Pow((xx4 - xx1), 2) + Math.Pow((yy4 - yy1), 2));

            // Считаем площадь двух треугольников, составляющих четырехугольник, по формуле Герона
            double P1 = diss12 + diss13 + diss23;
            double p1 = P1 / 2;
            double S1 = Math.Sqrt(p1 * (p1 - diss12) * (p1 - diss13) * (p1 - diss23));
            double P2= diss41 + diss13 + diss34;
            double p2 = P2 / 2;
            double S2 = Math.Sqrt(p2 * (p2 - diss41) * (p2 - diss13) * (p1 - diss34));
            double S = S1 + S2;
            Console.WriteLine("Площадь треугольника равна " + S.ToString("#.##"));
            Console.ReadKey();
        }
    }
}