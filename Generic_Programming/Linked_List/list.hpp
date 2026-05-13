/*
    templatized list.
    Type Generic list
*/

#include <iostream>
#include <stdexcept>

/* forward declaration of the class template list. So, we can make it a friend to class template node */
template<typename T>
class list;

template<typename T>
class node
{
    friend class list<T>;
    private:
        T data;
        node* next;
        node* prev;

    public:
        node(T _data):data(_data), next(0), prev(0)
        {

        }
};

template<typename T>
class list
{
    private:
        node<T>* head_node;

    public:
        list():head_node(new node(-1))
        {
            head_node->next = head_node;
            head_node->prev = head_node;
        }

        static void generic_insert(node<T>* p_begin, node<T>* p_mid, node<T>* p_end)
        {
            p_begin->next = p_mid;
            p_mid->prev = p_begin;

            p_end->prev = p_mid;
            p_mid->next = p_end;
        }

        static void generic_delete(node<T>*p_delete_node)
        {
            p_delete_node->next->prev = p_delete_node->prev;
            p_delete_node->prev->next = p_delete_node->next;

            delete p_delete_node;
            p_delete_node = nullptr;
        }

        void insert_start(T new_data)
        {
            generic_insert(head_node, new node(new_data), head_node->next);
        }

        void insert_end(T new_data)
        {
            generic_insert(head_node->prev, new node(new_data), head_node);
        }

        void insert_before(T existing_data, T new_data)
        {
            node<T>* p_node = search_node(existing_data);
            if(p_node == NULL)
            {
                throw std::runtime_error("Exception in insert_before(). Invalid existing data");
            }

            generic_insert(p_node->prev, new node(new_data), p_node);
        }

        void insert_after(T existing_data, T new_data)
        {
            node<T>* p_node = search_node(existing_data);
            if(p_node == nullptr)
            {
                throw std::runtime_error("Exception in insert_after. Invalid Existing data");
            }

            generic_insert(p_node, new node(new_data), p_node->next);
        }

        node<T>* search_node(T data)
        {
            node<T>* p_run = nullptr;
            p_run = head_node->next;
            while(p_run != head_node)
            {
                if(data == p_run->data)
                {
                    return p_run;
                }
            }

            return nullptr;
        }

        void pop_start(T* data)
        {
            if(head_node->next == head_node && head_node->prev == head_node)
            {
                throw std::runtime_error("Exception in pop_start(). Linked List is empty.");
            }
            *data = head_node->next->data;
            generic_delete(head_node->next);
        }

        void pop_end(T* data)
        {
            if(head_node->next == head_node && head_node->prev == head_node)
            {
                throw std::runtime_error("Exception in pop_end(). Linked List is empty.");
            }
            *data = head_node->prev->data;
            generic_delete(head_node->prev);
        }

        void remove_start()
        {
            if(head_node->next == head_node && head_node->prev == head_node)
            {
                throw std::runtime_error("Exception in remove_start. Linked List Empty.");
            }
            generic_delete(head_node->next);
        }

        void remove_end()
        {
            if(head_node->next == head_node && head_node->prev == head_node)
            {
                throw std::runtime_error("Exception in remove_end. Linked List empty.");
            }

            generic_delete(head_node->prev);
        }

        void remove_data(T r_data)
        {
            node<T>* p_node = search_node(r_data);

            if(p_node == nullptr)
            {
                throw std::runtime_error("Exception in remove_data(). Invalid data.");
            }

            generic_delete(p_node);
        }

        ~list()
        {
            node<T>* p_run = head_node->next;
            node<T>* p_run_next = nullptr;

            while(p_run != head_node)
            {
                p_run_next = p_run->next;
                delete p_run;
                p_run = p_run_next;
            }

            delete head_node;
        }

        class iterator
        {
            private:
                node<T>* current_node;

            public:
                iterator(node<T>* ptr):current_node(ptr)
                {

                }

                bool operator!=(const iterator& other)
                {
                    return current_node != other.current_node;
                }

                iterator& operator++()
                {
                    this->current_node = this->current_node->next;
                    return *this;
                }

                T& operator*()
                {
                    return current_node->data;
                }
        };

        iterator begin()
        {
            return iterator(head_node->next);
        }

        iterator end()
        {
            return iterator(head_node);
        }
};
