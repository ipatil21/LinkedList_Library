#include "../inc/ListFactory.h"
#include "../inc/Singly.h"

void ListFactory::ListBuidler(ListType type)
{
    LOG_INFO();
    switch (type)
    {
        case ListType::SinglyLL:
        {
            m_pListHandle = new Singly();
            // m_pListHandle->IsListEmpty();
            break;
        }
        case ListType::DoublyLL:
        {
            break;
        }
        case ListType::SinglyCircularLL:
        {
            break;
        }
        case ListType::DoublyCircularLL:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

ILinkedList *ListFactory::ListHandle()
{
    LOG_INFO();
    return m_pListHandle;
}

ListFactory::ListFactory()
{
    LOG_INFO();
    m_pListHandle = nullptr;
}