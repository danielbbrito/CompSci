#include <utility>
#include <iostream>

template<typename T>

class AVLNode {
    public:
        int key;
        T data;
        AVLNode<T>* right;
        AVLNode<T>* left;
        int bf;

    
        static AVLNode<T>* make_node(int k, T dt)
        {
            AVLNode<T>* p = new AVLNode<T>;

            if (p)
            {
                p->key = k;
                p->data = dt;
                p->bf = 0;
                p->right = nullptr;
                p->left = nullptr;
            }

            return p;
        }

        static void destroy_node(AVLNode<T>* n)
        {
            delete n;
        }

        static void set_bf(AVLNode<T>* R, int n)
        {
            R->bf = n;
        }
};

template<typename T>
class AVLTree {
    private:
        AVLNode<T>* root;
        int n;
    
    public:
        AVLTree()
        {
            root = nullptr;
            n = 0;
        }

        static AVLNode<T>* min(AVLNode<T>* R)
        {
            if (!R->left && !R->right)
                return R;
            
            return min(R->left);
        }

        static AVLNode<T>* sucessor(AVLNode<T>* R)
        {
            return min(R->right);
        }

        std::pair<T, bool> search(int k)
        {
            AVLNode<T>* c = root;

            while (c && c->key != k)
            {
                if (k < c->key)
                    c = c->left;
                
                else
                    c = c->right;
            }

            if (c)
            {
                return {c->data, true};
            }
            else
            {
                T* trash = new T;
                return {*trash, false};
            }
        }

        static void rse(AVLNode<T>** R)
        {
            // Keep subtree original root
            AVLNode<T>* a = *R;

            // Get right child to rotate
            AVLNode<T>* b = a->right;

            a->right = b->left;
            b->left = a;

            if (b->bf == 0)
            {
                a->bf = 1;
                b->bf = -1;
            }
            else
            {
                a->bf = b->bf = 0;
            }

            *R = b;
        }

        static void rsd(AVLNode<T>** R)
        {
            // Keep subtree original root
            AVLNode<T> *a = *R;

            // Get right child to rotate
            AVLNode<T> *b = a->left;

            a->left = b->right;
            b->right = a;

            if (b->bf == 0)
            {
                a->bf = -1;
                b->bf = 1;
            }
            else
            {
                a->bf = b->bf = 0;
            }

            *R = b;
        }

        static void rde(AVLNode<T>** R)
        {
            AVLNode<T>* a = *R;
            AVLNode<T>* b = a->right;
            AVLNode<T>* c = b->left;

            a->right = c->left;
            b->left = c->right;
            c->right = b;
            c->left = a;

            if (c->bf == 0)
                a->bf = b->bf = 0;

            else
            {
                if (c->bf == -1)
                {
                    a->bf = 0;
                    b->bf = 1;
                }
                else
                {
                    a->bf = -1;
                    b->bf = 0;
                }
                c->bf = 0;
            }

            *R = c;
        }

        static void rdd(AVLNode<T>** R)
        {
            AVLNode<T> *a = *R;
            AVLNode<T> *b = a->left;
            AVLNode<T> *c = b->right;

            a->left = c->right;
            b->right = c->left;
            c->left = b;
            c->right = a;

            if (c->bf == 0)
                a->bf = b->bf = 0;

            else
            {
                if (c->bf == 1)
                {
                    a->bf = 0;
                    b->bf = -1;
                }
                else
                {
                    a->bf = 1;
                    b->bf = 0;
                }
                c->bf = 0;
            }

            *R = c;
        }

        static bool insert_internal(AVLNode<T>** R, T dt, int k)
        {
            if (!*R)
            {
                AVLNode<T>* p = AVLNode<T>::make_node(k, dt);
                p->bf = 0;
                *R = p;
                
                return true;
            }

            if (k < (*R)->key)
            {
                if (insert_internal(&(*R)->left, dt, k))
                {
                    if ((*R)->bf == 1)
                    {
                        (*R)->bf = 0;
                        return false;
                    }

                    if ((*R)->bf == 0)
                    {
                        (*R)->bf = -1;

                        return true;
                    }

                    else
                    {
                        if ((*R)->left->bf == -1)
                        {
                            AVLTree<T>::rsd(R);
                            return false;
                        }

                        AVLTree<T>::rdd(R);
                        return false; 
                    }
                    return false;
                }
            }

            if (k > (*R)->key)
            {
                if (insert_internal(&(*R)->right, dt, k))
                {
                    if ((*R)->bf == -1)
                    {
                        (*R)->bf = 0;

                        return false;
                    }

                    if ((*R)->bf == 0)
                    {
                        (*R)->bf = 1;
                        return true;
                    }

                    if ((*R)->right->bf == 1)
                    {
                        AVLTree<T>::rse(R);
                        return false;
                    }

                    AVLTree<T>::rde(R);
                    return false;


                }
                return false;
            }

            return true;
        }

        static bool erase(AVLNode<T>** R, int k)
        {
            if (!(*R))
                return false;
            // Check left
            if (k < (*R)->key)
            {
                if (AVLTree::erase(&(*R)->left, k))
                {
                    if ((*R)->bf == -1)
                    {
                        (*R)->bf = 0;
                        return true;
                    }

                    if ((*R)->bf == 0)
                    {
                        (*R)->bf = 1;
                        return false;
                    }

                    // Rotate based on illegal height changes
                    if ((*R)->right->bf == 1)
                    {
                        AVLTree<T>::rse(R);
                        return true;
                    }

                    if ((*R)->right->bf == 0)
                    {
                        AVLTree<T>::rse(R);
                        return false;
                    }

                    AVLTree<T>::rde(R);
                    return false;
                }

                return false;
            }

            if (k > (*R)->key)
            {
                if (AVLTree::erase(&(*R)->right, k))
                {
                    if ((*R)->bf == 1)
                    {
                        (*R)->bf = 0;
                        return true;
                    }

                    if ((*R)->bf == 0)
                    {
                        (*R)->bf = -1;
                        return false;
                    }

                    if ((*R)->left->bf == -1)
                    {
                        AVLTree<T>::rsd(R);
                        return true;
                    }

                    if ((*R)->left->bf == 0)
                    {
                        AVLTree<T>::rsd(R);
                        return false;
                    }

                    AVLTree<T>::rdd(R);
                    return true;
                }

                return false;
            }

            // Found node to delete
            if (!(*R)->left)
            {
                AVLNode<T>* p = *R;
                *R = p->right;
                AVLNode<T>::destroy_node(p);
                return true;
            }

            if (!(*R)->right)
            {
                AVLNode<T>* p = *R;
                *R = p->left;
                AVLNode<T>::destroy_node(p);
                return true;
            }

            AVLNode<T>* p = sucessor(*R);

            std::swap(p->key, (*R)->key);
            std::swap(p->data, (*R)->data);
            
            if (AVLTree::erase(&(*R)->right, k))
            {
                if ((*R)->bf == 1)
                {
                    (*R)->bf = 0;
                    return true;
                }

                if ((*R)->bf == 0)
                {
                    (*R)->bf == -1;
                    return false;
                }

                if ((*R)->left->bf == -1)
                {
                    AVLTree<T>::rsd(R);
                    return true;
                }

                if ((*R)->left->bf == 0)
                {
                    AVLTree<T>::rsd(R);
                    return false;
                }

                AVLTree<T>::rdd(R);
                return true;
            }
            return false;
        }

        void insert(int k, T dt)
        {
            insert_internal(&(this->root), dt, k);
            n++;
        }

        void remove(int k)
        {
            erase(&(this->root), k);
            n--;
                
        }

        int size() { return n; }

        void inorder_walk(AVLNode<T> *node)
        {
            if (node->left)
                inorder_walk(node->left);

            std::cout << "Node: " << node->key << ' ' << "BF: " << node->bf << std::endl;

            if (node->right)
                inorder_walk(node->right);
        }

        void walk()
        {
            inorder_walk(this->root);
        }
};