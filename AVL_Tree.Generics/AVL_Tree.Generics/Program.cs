using System;
using System.Collections.Generic;

namespace AVL_Tree.Generics
{
    class Program
    {
        static void Main(string[] args)
        {

            Ordered_set<Char> set = new Ordered_set<char>();
            
            for (int i = 65; i <=75 ; i++) 
                set.insert((char)i);
           // Console.WriteLine(set.Remove(4));
            //Console.WriteLine(set.Remove(1));
            //s(set);
            foreach(var i in set)
            {
                Console.WriteLine(i);
            }
            //set.inOrderTraversal();


            Console.WriteLine(set.Contains('a'));
            Console.WriteLine(set.Contains('A'));
            Console.WriteLine(set['Z']);
            Console.WriteLine(set.Size);
            Console.WriteLine("set height = " + set.ht);

        }

        private static void s(Ordered_set<int> set)
        {
            Console.WriteLine(set.Remove(2));
            //set.inOrderTraversal();
            Console.WriteLine(set.Remove(3));
            //set.inOrderTraversal();
            Console.WriteLine(set.Remove(6));
            //set.inOrderTraversal();
            Console.WriteLine(set.Remove(5));
            //set.inOrderTraversal();
            Console.WriteLine(set.Remove(9));
            //set.inOrderTraversal();
            Console.WriteLine(set.Remove(11));

        }
    }
}
