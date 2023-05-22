/// @brief
#include <iostream>

/// @brief
#include "../inc/ILinkedList.h"

/// @brief
#include "../inc/ListFactory.h"

/// @brief
using namespace std;

/// @brief
/// @param pListHandle
void InsertAtFirst_TC(ILinkedList* pListHandle)
{
    {
        /// InsertAtFirst() : Tested Scenario 1) If list is empty
        pListHandle->DeleteAll();
        pListHandle->InsertAtFirst(10);
        pListHandle->DisplayListData();
    }

    {
        /// InsertAtFirst() : Tested Scenario 2) If list is non empty
        pListHandle->InsertAtFirst(20);
        pListHandle->InsertAtFirst(30);
        pListHandle->InsertAtFirst(10);
        pListHandle->DisplayListData();
    }

    {
        /// Tested Scenario 3) If iData is negative, positive, check whether its correctly feed in Linked List
        pListHandle->InsertAtFirst(-300);
        pListHandle->InsertAtFirst(+300);
        pListHandle->DisplayListData();
    }
}

/// @brief
/// @param pListHandle
void InsertAtLast_TC(ILinkedList* pListHandle)
{
    {
        pListHandle->DeleteAll();
        pListHandle->DisplayListData();

        pListHandle->InsertAtFirst(10);
        pListHandle->InsertAtFirst(20);
        pListHandle->InsertAtFirst(30);

        pListHandle->InsertAtLast(40);
        pListHandle->DisplayListData();
    }
}

/// @brief
/// @param pListHandle
void InsertAtPosition_TC(ILinkedList* pListHandle)
{
    {
        pListHandle->DeleteAll();
        pListHandle->DisplayListData();

        pListHandle->InsertAtFirst(20);
        pListHandle->InsertAtFirst(30);
        pListHandle->InsertAtLast(40);

        pListHandle->InsertAtPosition(111, 0);
        pListHandle->InsertAtPosition(111, 1);
        pListHandle->InsertAtPosition(111, -1);
        pListHandle->InsertAtPosition(222, 2);
        pListHandle->InsertAtPosition(333, 3);
        pListHandle->InsertAtPosition(888, 8);
        pListHandle->InsertAtPosition(777, 7);
        pListHandle->DisplayListData();
    }
}

/// @brief
/// @param pListHandle
void DeleteAll_TC(ILinkedList* pListHandle)
{
    pListHandle->DeleteAll();
    pListHandle->InsertAtFirst(20);
    pListHandle->InsertAtFirst(30);
    pListHandle->InsertAtLast(40);

    LOG_DEBUG("Debug: CountNodes() before DeleteAll()", pListHandle->CountNodes());
    LOG_DEBUG("Debug: IsListEmpty() before DeleteAll()", pListHandle->IsListEmpty());
    LOG_DEBUG("Debug: IsListEmpty() before DisplayListData()", pListHandle->DisplayListData());
    pListHandle->DeleteAll();
    LOG_DEBUG("Debug: CountNodes() after DeleteAll()", pListHandle->CountNodes());
    LOG_DEBUG("Debug: IsListEmpty() after DeleteAll()", pListHandle->IsListEmpty());
    LOG_DEBUG("Debug: IsListEmpty() before DisplayListData()", pListHandle->DisplayListData());
}

/// @brief
/// @return
int main()
{
    LOG_INFO();
    ListFactory* pListFactory = new ListFactory();
    pListFactory->ListBuidler(ListType::SinglyLL);
    ILinkedList* pListHandle = pListFactory->ListHandle();

    if (NULL != pListFactory->ListHandle())
    {
        // InsertAtFirst_TC(pListHandle);
        // InsertAtLast_TC(pListHandle);
        // InsertAtPosition_TC(pListHandle);
        DeleteAll_TC(pListHandle);
    }

    return 0;
}

/**
Folder Hierarchy
 DS
    1. SLL
        Version_0 ....Version_4
        Version_0 : Write separate file
        Version_1 : Write Defination
        Version_2 : Menu Driven Program
                    * All fourteen function in menu driven
                    * Display jhalach paije
                    * Case 1 - 14
                    * Case 15 - exit
                    * Insert Pos , first take position validation
        Version 3   * 1. Insert 2. Del 3. Search 4. Count 5. Reverse 6. Concat 7. Exit
    2. DLL
    3. SLL Circular
    4. DLL Circular
**/

/**
 * Version 2 of SLL
 * Version 3 of SLL
 * Version 0 physical reverse of double
 * Version 3 of doubly
 * Version 3 of singly circular
 * Version 3 of double circular
 */

// Version 0
// Separate

// Version 1
// Version 2