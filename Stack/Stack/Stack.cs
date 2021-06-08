using System;

namespace Stack
{
    class sNode<T>
    {
        public T val;
        public sNode<T> next;

        public sNode(T val)
        {
            this.val = val;
            next = default;
        }
    }
    class Stack<T>
    {
        sNode<T> Head;

        public int Size { get; private set; }

        public Stack()
        {
        }
        public Stack(T[] arr)
        {
            if (arr == null) return;
            for (int i = 0; i < arr.Length; i++)
                Push(arr[i]);
            Size = arr.Length;
        }
        public bool Empty()
        {
            return Size == 0 ? true : false;
        }
        public void Push(T val)
        {
            sNode<T> node = new sNode<T>(val);
            node.next = Head;
            Head = node;
            Size++;
        }
        public void Pop()
        {
            if (Head == null)
                return;
            Head = Head.next;
            Size--;

        }
        public T Top()
        {
            if (Head == null)
                throw new NullReferenceException("Stack is Empty");

            return Head.val;
        }
    }
}
