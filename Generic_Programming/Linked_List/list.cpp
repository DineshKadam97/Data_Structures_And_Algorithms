#include "list.hpp"

int main()
{
    list<int>* p_list = new list<int>();

    p_list->insert_end(11);
    p_list->insert_end(21);
    p_list->insert_end(31);

    std::cout << "----------------------------------------------------------------------" << std::endl;
    for(list<int>::iterator iter = p_list->begin(); iter != p_list->end(); ++iter)
    {
        std::cout << "[" << *iter << "]" << "<=>";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    p_list->insert_start(55);
    p_list->insert_start(66);
    p_list->insert_end(77);
    p_list->insert_end(88);

    std::cout << "----------------------------------------------------------------------" << std::endl;
    for(list<int>::iterator iter = p_list->begin(); iter != p_list->end(); ++iter)
    {
        std::cout << "[" << *iter << "]" << "<=>";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;


    std::cout << "----------------------------------------------------------------------" << std::endl;
    int data = 0;
    try
    {
        p_list->pop_start(&data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Popped start element : " << data << std::endl;
    std::cout << "Now, Linked List is : " << std::endl;

    for(list<int>::iterator iter = p_list->begin(); iter != p_list->end(); ++iter)
    {
        std::cout << "[" << *iter << "]" << "<=>";
    }
    std::cout << std::endl;

    try
    {
        p_list->pop_end(&data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Popped end element" << data << std::endl;
    std::cout << "Now, Linked List is : " << std::endl;

    for(list<int>::iterator iter = p_list->begin(); iter != p_list->end(); ++iter)
    {
        std::cout << "[" << *iter << "]" << "<=>";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;

    return 0;
}
