using System;


namespace Queue
{
    class qNode<T>
    {
        public T val;
        public qNode<T> next;

        public qNode(T val) 
        {
            this.val = val;
            next = default;
        }
    }
    class Queue<T>
    {
        qNode<T> Head;
        qNode<T> Tail;

        public int Size { get; private set; }

        public Queue()
        {
        }
        public Queue(T[] arr)
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
            qNode<T> node = new qNode<T>(val);
            if (Head == null)
            {
                Head = node;
                Tail = node;
            }
            else
            {
                Tail.next = node;
                Tail = Tail.next;
            }

            
            Size++;
        }
        public void Pop()
        {
            if (Head == null)
                return;
            Head = Head.next;
            Size--;

        }
        public T Front()
        {
            if (Head == null)
                throw new NullReferenceException("Queue is Empty");
            
            return Head.val;
        }
    }
}
