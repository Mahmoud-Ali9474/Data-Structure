namespace AVL_Tree.Generics
{
    class TreeNode<T>
    {
        public T val;
        public int height;
        public TreeNode<T> left;
        public TreeNode<T> right;

        public TreeNode(T val)
        {
            this.val = val;
        }
    }
}
