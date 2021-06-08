using System;
namespace Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            
            int[] arr = { 1, 2, 3, 4, 5 };
            Queue<int> queue = new Queue<int>(arr);
            queue.Push(6);
            queue.Push(7);
            
            while (!queue.Empty())
            {
                
                Console.WriteLine($"value : {queue.Front()} Queue size is {queue.Size}");
                queue.Pop();
            }
            queue.Push(10);
            queue.Push(6);
            queue.Push(7);

            while (!queue.Empty())
            {

                Console.WriteLine($"value : {queue.Front()} Queue size is {queue.Size}");
                queue.Pop();
            }
            //Console.WriteLine(queue.Front());
            Console.WriteLine("=======================");

            double[] ar = { 1.3, 2.9, 3, 4, 5 };
            Queue<double> qu = new Queue<double>(ar);
            qu.Push(6.5);
            qu.Push(7.1);
            while (!qu.Empty())
            {
                Console.WriteLine($"value : {qu.Front():n2} Queue size is {qu.Size}");
                qu.Pop();
            }
        }
    }
}
