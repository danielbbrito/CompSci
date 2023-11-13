#include <iostream>
#include <utility>

template<typename T>

// TreeNode class
class TreeNode {
    private:
        TreeNode<T>* left, right, parent;
        T key, data;

    public:
        static TreeNode<T> make_node(T k, T d)
        {
            TreeNode<T>* p = new TreeNode<T>;

            if (p)
            {
                p->data = d;
                p->key = k;
                p->left = nullptr;
                p->right = nullptr;
                p->parent = nullptr;
            }
            
            return p;
        }

        static void destroy_node(TreeNode<T> p)
        {
            delete p;
        }

        static void set_left(TreeNode<T>* p, TreeNode<T>* l)
        {
            p->left = l;
        }

        static void set_right(TreeNode<T>* p, TreeNode<T>* r)
        {
            p->right = r;
        }
};

template<typename T>

// Tree class
class BTree {
    private:
        TreeNode<T>* root;
        int n;

    public:
        static void inorder_walk(TreeNode<T>* node)
        {
            if (node->left)
                inorder_walk(node->left);
            
            cout << node->key << " ";

            if (node->right)
                inorder_walk(node->right);
        }

        static void preorder_walk(TreeNode<T>* node)
        {
            cout << node->key << " ";

            if (node->left)
                preorder_walk(node->left);

            if (node->right)
                preorder_walk(node->right);
        }

        static void postorder_walk(TreeNode<T>* node)
        {
            if (node->left)
                postorder_walk(node->left);

            if (node->right)
                postorder_walk(node->right);

            cout << node->key << " ";
        }

        static pair<bool, T> search(TreeNode<T>* r, T k)
        {
            if (!r)
            {
                T junk;
                return {false, junk};
            }

            if (r->key == k)
                return {true, r->data};

            if (r->key > k)
                return search(r->left, k);
            
            return search(r->right, k);
        }

        static pair<bool, T> iterative_search(TreeNode<T>* r, T k)
        {
            while (r)
            {
                if (r->key == k)
                    return {true, r->data};

                else if (r->key > k)
                    r = r->left;
                
                else r = r->right;
            }

            T junk;
            return {false, junk};
        }

        T iterative_tree_min(TreeNode<T>* r)
        {
            while (r->left)
                r = r->left;
            
            return r->key;
        }

        T tree_min(TeeNode<T>* r)
        {
            if (!r->left)
                return r->key;

            return tree_min(r->left);
        }

        T iterative_tree_max(TreeNode<T>* r)
        {
            while (r->right)
                r = r->right;
            
            return r->key;
        }

        T tree_max(TreeNode<T>* r)
        {
            if (!r->right)
                return r->key;

            return tree_max(r->right);
        }

        T successor(TreeNode<T>* r)
        {
            if (r->right)
                return tree_min(r->right);

            TreeNode<T> parent = r->parent;

            while (parent && r == parent->right)
            {
                r = parent;
                parent = parent->parent;
            }

            return parent;
        }

        T predecessor(TreeNode<T>* r)
        {
            if (r->left)
                return tree_max(r->left);
            
            TreeNode<T>* parent = r->parent;

            while (parent && r == parent->left)
            {
                r = parent;
                parent = parent->parent;
            }

            return parent;
        }

        static bool insert(BTree<T>* t, T k, T dt)
        {
            TreeNode<T>* p = TreeNode::make_node(k, dt);

            if (!p) return false;

            TreeNode<T>* r = t->root;
            TreeNode<T>* in = nullptr;
            while (r)
            {
                in = r;

                if (r->key >= p->key)
                    r = r->left
                else
                    r = r->right;
            }

            p->parent = y;

            if (!y)
                t->root = p;
            else if (p->key <= in->key)
                in->left = p;
            else in->right = p;
        }
};