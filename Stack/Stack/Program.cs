using System;

namespace Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] arr = { 'a', 's', 'd', 'e', 'y' };

            Stack<char> stack = new Stack<char>(arr);
            while (!stack.Empty())
            {
                Console.WriteLine($"Stack top is {stack.Top()} Size is {stack.Size}");
                stack.Pop();
            }
            stack.Push('w');
            Console.WriteLine(stack.Top());
            stack.Pop();
            //stack.Top();

        }
    }
}
