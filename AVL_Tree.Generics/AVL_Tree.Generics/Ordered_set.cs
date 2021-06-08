using System;
using System.Collections;
using System.Collections.Generic;


namespace AVL_Tree.Generics
{
    class Ordered_set<T>: IEnumerable<T>
        where T:IComparable<T>
    {
        TreeNode<T> Root;
        public TreeNode<T> Head { get { return Root; } }
        public int Size { get; private set; }
        public int ht { get { return updateHigh(Root); } }

        public bool this[T val]
        {
            get
            {
                return Contains(val);
            }
        }
        public bool Remove(T val)
        {
            bool removed = false;
            Root = RemoveNode(Root, val,ref removed);
            if (removed)
                Size--;
            return removed;
        }

        private TreeNode<T> RemoveNode(TreeNode<T> root,T val,ref bool removed)
        {
            Stack<TreeNode<T>> s = new Stack<TreeNode<T>>();

            if (root == null)
                return null;
            if(root.val.CompareTo(val) < 0)
            {
                root.right = RemoveNode(root.right,val, ref removed);
            }else if (root.val.CompareTo(val) > 0)
            {
                root.left = RemoveNode(root.left, val, ref removed);
            }
            else
            {
                removed = true;
                if (root.right == null)
                    return root.left;
                LowestCommonAncestor(root,s);
                while (s.Count > 1)
                {
                    var curr = s.Pop();
                    if (curr != null)
                    {
                        var temp = ChickAndUpdate(curr);
                        if (temp != null&&s.Count>=1)
                        {
                            var node = s.Peek();

                            if (node.val.CompareTo(temp.val) > 0)
                                node.left = temp;
                            else
                                node.right = temp;
                        }else if(temp!=null)
                            return temp;

                    }
                }
            }

            var tem = ChickAndUpdate(root);
            if (tem != null)
                return tem;
            return root;

        }

        private int updateHigh(TreeNode<T> curr)
        {
            if (curr == null)
                return -1;
            return Math.Max(curr.left == null ? -1 : curr.left.height, curr.right == null ? -1 : curr.right.height)+1;
        }

        private void LowestCommonAncestor(TreeNode<T> root, Stack<TreeNode<T>> s)
        {
            

            var curr = root.right;
            s.Push(curr);
            while (curr.left != null)
            {

                curr = curr.left;
                s.Push(curr);
            }
            root.val = curr.val;
            if (curr == root.right)
            {
                s.Pop();
                root.right = curr.right;
            }
            else if (curr.right == null)
            {
                s.Pop();
                s.Peek().left = null;
            }
            else if (curr.right != null)
            {
                LowestCommonAncestor(curr, s);
            }


        }

        public void insert(T val)
        {
            var curr = Root;
            bool update = true;
            Root = helper(val, curr,ref update);

        }
        public bool Contains(T val)
        {
            var curr = Root;
            while (curr != null)
            {
                if (curr.val.CompareTo(val) == 0)
                    return true;
                else if (curr.val.CompareTo(val) > 0)
                    curr = curr.left;
                else
                    curr = curr.right;
            }
            return false;
        }

        private TreeNode<T> helper(T val, TreeNode<T> curr,ref bool update)
        {
            
            if (curr == null)
            {
                Size++;
                return new TreeNode<T>(val);
            }
            else if (curr.val.CompareTo(val) > 0)
                curr.left = helper(val, curr.left,ref update);
            else if (curr.val.CompareTo(val) < 0)
                curr.right = helper(val, curr.right,ref update);
            else 
            {
                update = false;
                return curr;
            }
            TreeNode<T> node=default;
            if (update)
                node=ChickAndUpdate(curr);
            if (node != null)
                return node;


            return curr;

        }

        private TreeNode<T> ChickAndUpdate(TreeNode<T> curr)
        {
            int HeightLeft = updateHigh(curr.left);
            int HeightRight = updateHigh(curr.right);
            curr.height = updateHigh(curr);
            if (HeightLeft - HeightRight > 1)
            {
                if (updateHigh( curr.left.left) > updateHigh(curr.left.right))
                {
                    return RightRotate(curr);
                }
                else
                {
                    curr.left = LeftRotate(curr.left);
                    return RightRotate(curr);
                }

            }
            else if (HeightLeft - HeightRight < -1)
            {
                if (updateHigh(curr.right.right) > updateHigh(curr.right.left))
                {
                    return LeftRotate(curr);
                }
                else
                {
                    curr.right = RightRotate(curr.right);
                    return LeftRotate(curr);
                }

            }
            return null;

        }

        private TreeNode<T>LeftRotate(TreeNode<T> curr)
        {
            var newcurr = curr.right;
            var newcurrleft = newcurr.left;
            curr.right = newcurrleft;
            newcurr.left = curr;
            //Update height after rotation
            curr.height = Math.Max(Height(curr.left), Height(curr.right))+1;
            newcurr.height = Math.Max(Height(newcurr.left), Height(newcurr.right))+1;


            return newcurr;
        }
        public void inOrderTraversal()
        {
            Traverse(Root);
        }

        public IEnumerator<T> Traverse(TreeNode<T> root)
        {
            if (root == null)
                yield break;
                   
            Traverse(root.left);
            yield return root.val;//Console.WriteLine(root.val);
            Traverse(root.right);
        }
        private IEnumerator<T> Traverse2(TreeNode<T> root)
        {
            if (root == null)
                yield break;
            var s = new Stack<TreeNode<T>>();
            TreeNode<T> node = root;
            while (s.Count > 0||node!=null)
            {
                
                while (node!= null)
                {
                    s.Push(node);
                    node = node.left;
                }


                node = s.Pop();
                yield return node.val;
              

                node = node.right;
                
            }
            
        }

        public void Clear()
        {
            Root = null;
        } 

        private TreeNode<T> RightRotate(TreeNode<T> curr)
        {
            var newcurr = curr.left;
            var newcurrright = newcurr.right;
            curr.left = newcurrright;
            newcurr.right = curr;

            //Update height after rotation
            curr.height = Math.Max(Height(curr.left), Height(curr.right))+1;
            newcurr.height = Math.Max(Height(newcurr.left), Height(newcurr.right))+1;

            return newcurr;
        }

        private int Height(TreeNode<T> node)
        {
            if (node == null)
                return -1;
            return Math.Max(Height(node.left), Height(node.right))+1;
        }

        public IEnumerator<T> GetEnumerator()
        {
            return Traverse2(Head);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return Traverse2(Head);
        }
    }
}
