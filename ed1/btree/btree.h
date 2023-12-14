#include <iostream>
#include <utility>

template <typename T>
class TreeNode
{
private:
    TreeNode<T> *left, *right, *parent;
    T key, data;

public:
    static TreeNode<T> make_node(T k, T d)
    {
        TreeNode<T> *p = new TreeNode<T>;

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
};

// Binary tree
template <typename T>
class BTree
{
private:
    TreeNode<T> *root;
    int n;

public:
    static void inorder_walk(TreeNode<T> *node)
    {
        if (node->left)
            inorder_walk(node->left);

        cout << node->key << " ";

        if (node->right)
            inorder_walk(node->right);
    }

    static void preorder_walk(TreeNode<T> *node)
    {
        cout << node->key << " ";

        if (node->left)
            preorder_walk(node->left);

        if (node->right)
            preorder_walk(node->right);
    }

    static void postorder_walk(TreeNode<T> *node)
    {
        if (node->left)
            postorder_walk(node->left);

        if (node->right)
            postorder_walk(node->right);

        cout << node->key << " ";
    }

    pair<bool, TreeNode<T> *> search(TreeNode<T> *r, T k)
    {
        if (!r)
        {
            TreeNode<T> *junk;
            return {false, junk};
        }

        if (r->key == k)
            return {true, r};

        if (r->key > k)
            return search(r->left, k);

        return search(r->right, k);
    }

    pair<bool, TreeNode<T> *> iterative_search(TreeNode<T> *r, T k)
    {
        while (r)
        {
            if (r->key == k)
                return {true, r};

            else if (r->key > k)
                r = r->left;

            else
                r = r->right;
        }

        TreeNode<T> *junk;
        return {false, junk};
    }

    TreeNode<T> iterative_tree_min(TreeNode<T> *r)
    {
        while (r->left)
            r = r->left;

        return r->key;
    }

    TreeNode<T> tree_min(TreeNode<T> *r)
    {
        if (!r->left)
            return r;

        return tree_min(r->left);
    }

    TreeNode<T> iterative_tree_max(TreeNode<T> *r)
    {
        while (r->right)
            r = r->right;

        return r;
    }

    TreeNode<T> tree_max(TreeNode<T> *r)
    {
        if (!r->right)
            return r;

        return tree_max(r->right);
    }

    TreeNode<T> successor(TreeNode<T> *r)
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

    T predecessor(TreeNode<T> *r)
    {
        if (r->left)
            return tree_max(r->left);

        TreeNode<T> *parent = r->parent;

        while (parent && r == parent->left)
        {
            r = parent;
            parent = parent->parent;
        }

        return parent;
    }

    static bool insert(BTree<T> *t, T k, T dt)
    {
        TreeNode<T> *p = TreeNode<T>::make_node(k, dt);

        if (!p)
            return false;

        TreeNode<T> *r = t->root;
        TreeNode<T> *in = nullptr;
        while (r)
        {
            in = r;

            if (r->key >= p->key)
                r = r->left;
            else
                r = r->right;
        }

        p->parent = in;

        if (!in)
            t->root = p;
        else if (p->key <= in->key)
            in->left = p;
        else
            in->right = p;
    }

    void clear_subtree(TreeNode<T> *r)
    {
        if (r->left)
            clear_subtree(r->left);

        else if (r->right)
            clear_subtree(r->right);
        else
            delete r;
    }

    void transplant(TreeNode<T> *u, TreeNode<T> *v)
    {
        if (!u->parent)
            root = v;

        else if (u == u->parent->left)
            u->parent->left = v;

        else if (u == u->parent->right)
            u->parent->right = v;

        if (v)
            v->parent = u->parent;
    }

    void remover(TreeNode<T> *z)
    {
        if (!z->left)
        {
            transplant(z, z->right);
            delete z;
        }

        else if (!z->right)
        {
            transplant(z, z->left);
            delete z;
        }

        else
        {
            TreeNode<T> y = successor(z);

            if (y != z->right)
            {
                transplant(y, y->right);
                y->right = z->right;
            }

            swap(z->key, y->key);
            swap(z->data, y->data);
            remover(z);
        }
    }

    bool remove(T dt)
    {
        pair<bool, TreeNode<T> *> found = search(root, dt);

        if (found)
        {
            remover(found.second);
            return true;
        }

        return false;
    }
};