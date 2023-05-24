/// @brief
#include "../inc/Common.h"

/// @brief
#include "../inc/Singly.h"

/// @brief
#include <iostream>

/// @brief
using namespace std;

/// @brief
Singly::Singly()
{
    LOG_INFO();
    m_iData = 0;
    m_iNodeCount = 0;
    m_pFirst = nullptr;
    m_pNext = nullptr;
}

Singly::~Singly()
{
    LOG_INFO();
    delete m_pFirst;
    m_pFirst = nullptr;
}

/// Tested Scenario 1) If list is empty
/// Tested Scenario 2) If list is non empty
/// Tested Scenario 3) If iData is negative, positive, check whether its correctly feed in Linked List
bool Singly::InsertAtFirst(int iData)
{
    LOG_INFO();
    SinglyLLNode* pNewNode = new SinglyLLNode();
    pNewNode->m_iData = iData;

    if (false == IsListEmpty())
    {
        pNewNode->m_pNext = m_pFirst;
        m_pFirst = pNewNode;
    }
    else
    {
        pNewNode->m_pNext = nullptr;
        m_pFirst = pNewNode;
    }

    pNewNode = nullptr;
    return IncrementNodeCount();
}

/// Tested Scenario 1) If list is empty
/// Tested Scenario 2) If list is non empty
/// Tested Scenario 3) If iData is negative, positive, check whether its correctly feed in Linked List
bool Singly::InsertAtLast(int iData)
{
    LOG_INFO();
    SinglyLLNode* pNewNode = new SinglyLLNode();
    pNewNode->m_iData = iData;
    pNewNode->m_pNext = nullptr;

    if (false == IsListEmpty())
    {
        SinglyLLNode* pTraverse = m_pFirst;
        while (NULL != pTraverse->m_pNext)
        {
            pTraverse = pTraverse->m_pNext;
        }
        pTraverse->m_pNext = pNewNode;
        pTraverse = nullptr;
    }
    else
    {
        pNewNode->m_pNext = nullptr;
        m_pFirst = pNewNode;
    }

    pNewNode = nullptr;
    return IncrementNodeCount();
}

bool Singly::InsertAtPosition(int iData, int iPosition)
{
    LOG_INFO();
    bool bRetValue = false;

    if ((iPosition < 1) || (iPosition > CountNodes() + 1))
    {
        LOG_DEBUG("Err: Invalid Position", iPosition);
    }
    else if (1 == iPosition) // InsertAtFirst
    {
        if (true == InsertAtFirst(iData))
        {
            bRetValue = IncrementNodeCount();
        }
    }
    else if (CountNodes() + 1 == iPosition) // InsertAtLast
    {
        if (true == InsertAtLast(iData))
        {
            bRetValue = IncrementNodeCount();
        }
    }
    else // InsertAtOther
    {
        int iCount = 2; // It starts from 2 to make looping logic becomes easier
        SinglyLLNode* pTraverse = m_pFirst;
        while (NULL != pTraverse && iCount < iPosition)
        {
            pTraverse = pTraverse->m_pNext;
            iCount = iCount + 1;
        }

        if (iCount == iPosition)
        {
            SinglyLLNode* pNewNode = new SinglyLLNode();
            pNewNode->m_iData = iData;

            pNewNode->m_pNext = pTraverse->m_pNext;
            pTraverse->m_pNext = pNewNode;
            pNewNode = nullptr;

            bRetValue = IncrementNodeCount();
        }
        else
        {
            // fatal condition, ideally this shall be unreachable code
            LOG_INFO("Fatal: valid position still unable to insert, WTH?");
        }
    }

    return bRetValue;
}

bool Singly::DeleteAtFirst()
{
    LOG_INFO();
    if (NULL != m_pFirst)
    {
        SinglyLLNode* pTemp = m_pFirst;
        m_pFirst = m_pFirst->m_pNext;
        delete pTemp;
        pTemp = nullptr;
    }
    return DecrementNodeCount();
}

bool Singly::DeleteAtLast()
{
    LOG_INFO();
    if (NULL != m_pFirst)
    {
        SinglyLLNode* pTraverse = m_pFirst;
        SinglyLLNode* pTemp = m_pFirst;
        while (NULL != pTraverse->m_pNext)
        {
            pTemp = pTraverse;
            pTraverse = pTraverse->m_pNext;
        }
        delete pTraverse;
        pTraverse = nullptr;
        pTemp->m_pNext = nullptr;
    }
    return DecrementNodeCount();
}

/// Test Scenario 1 - Invalid Position
///                     1.1 If iPos < 1
///                     1.2 If iPos
/// Test Scenario 2 - After calling this function DisplayListData() function shall print nothing
/// Test Scenario 3 - After calling this function CountNodes() function shall return zero
bool Singly::DeleteAtPosition(int iPos)
{
    LOG_INFO();

    if (0 > iPos || CountNodes() < iPos)
    {
        LOG_DEBUG("Err: Invalid Position", iPos);
    }
    else if (1 == iPos)
    {
        DeleteAtFirst();
    }
    else
    {
        int iCount = 1;
        SinglyLLNode* pTraverse = m_pFirst;
        while (NULL != pTraverse && iCount < iPos)
        {
            iCount = iCount + 1;
        }
    }

    return DecrementNodeCount();
}

/// Note -
/// Test Scenario 1 - After calling this function IsListEmpty() function shall return true
/// Test Scenario 2 - After calling this function DisplayListData() function shall print nothing
/// Test Scenario 3 - After calling this function CountNodes() function shall return zero
bool Singly::DeleteAll()
{
    LOG_INFO();
    SinglyLLNode* pItr = m_pFirst;
    LOG_DEBUG("m_iNodeCount", m_iNodeCount);
    LOG_DEBUG("CountNodes()", CountNodes());
    while (NULL != m_pFirst)
    {
       m_pFirst = m_pFirst->m_pNext;
       delete pItr;
       pItr = m_pFirst;
       DecrementNodeCount();
       LOG_DEBUG("m_iNodeCount", m_iNodeCount);
       LOG_DEBUG("CountNodes()", CountNodes());
    }
    return (0 == CountNodes() == m_iNodeCount);
}

/// searches iData in whole list and returns the position
/// position starts from 1
/// position zero indicates iData not found
int Singly::SearchData(int iData)
{
    LOG_INFO();
    int iPos = 0;
    int iIndex = 0;
    SinglyLLNode* pTrav = m_pFirst;

    while (nullptr != pTrav)
    {
        iIndex ++;
        if (iData == pTrav->m_iData)
        {
            iPos = iIndex;
            break;
        }
    }

    return iPos;
}

/// Test Scenario 1
/// Test Scenario 2
bool Singly::IsListEmpty()
{
    LOG_INFO();
    bool bRetValue = false;
    if (NULL == m_pFirst)
    {
        bRetValue = true;
    }
    return bRetValue;
}

/// displays list data by traversing the list
string Singly::DisplayListData()
{
    LOG_INFO();
    SinglyLLNode* pTraverse = m_pFirst;
    string sReturnData = "";

    while (NULL != pTraverse)
    {
        sReturnData = sReturnData + " " + to_string(pTraverse->m_iData);
        pTraverse = pTraverse->m_pNext;
    }

    pTraverse = nullptr;
    sReturnData.erase(0, sReturnData.find_first_not_of(' '));
    LOG_INFO(sReturnData);
    return sReturnData;
}

/// calculates node count by traversing the list
unsigned int Singly::CountNodes()
{
    LOG_INFO();
    unsigned int iCount = 0;
    SinglyLLNode* pTraverse = m_pFirst;

    while (NULL != pTraverse)
    {
        iCount = iCount + 1;
        pTraverse = pTraverse->m_pNext;
    }

    return iCount;
}

/// Scenario 1 = list first is empty and list second is empty
/// Scenario 2 = list first is empty and list second is non-empty
/// Scenario 3 = list first is non-Empty and list second is empty
/// Scenario 4 = list first is non-Empty and list second is non-empty
SinglyLLNode* Singly::ConcatList(SinglyLLNode* m_pSecond)
{
    LOG_INFO();

    // Scenario = 1 and 3
    if (nullptr == m_pSecond)
    {
        return m_pFirst;
    }

    // Scenario = 2
    if (nullptr == m_pFirst)
    {
        return m_pSecond;
    }

    // Scenario 4
    if (nullptr != m_pSecond && nullptr != m_pFirst)
    {
        SinglyLLNode* pTrav = m_pFirst;
        while (nullptr != pTrav->m_pNext)
        {
            pTrav = pTrav->m_pNext;
        }
        pTrav->m_pNext = m_pSecond;
        pTrav = nullptr;
        m_iNodeCount = CountNodes();
    }

    return m_pFirst;
}

/// Scenario 0 = invalid position
/// Scenario 1 = list first is empty and list second is empty
/// Scenario 2.1 = list first is empty and list second is non-empty (with iPos == 1)
/// Scenario 2.2 = list first is empty and list second is non-empty (with iPos != 1)
/// Scenario 3 = list first is non-Empty and list second is empty
/// Scenario 4 = list first is non-Empty and list second is non-empty
/// Note - Don't change the sequence of if statement, as it does matters
SinglyLLNode* Singly::ConcatAtPosition(SinglyLLNode* m_pSecond, int iPos)
{
    LOG_INFO();

    // Scenario 0 = invalid position
    if (0 > iPos || CountNodes() < iPos)
    {
        LOG_DEBUG("Err: Invalid Position", iPos);
        return nullptr;
    }

    // Scenario = 1 and 3
    if (nullptr == m_pSecond)
    {
        return m_pFirst;
    }

    // Scenario 2.1
    if (nullptr == m_pFirst && 1 == iPos)
    {
        return m_pSecond;
    }

    // Scenario 2.2
    if (nullptr == m_pFirst && 1 < iPos)
    {
        return nullptr;
    }

    // Scenario 4
    if (nullptr != m_pSecond && nullptr != m_pFirst)
    {
        int iTrav = 2;
        SinglyLLNode* pTrav = m_pFirst;
        while (iTrav != iPos)
        {
            pTrav = pTrav->m_pNext;
            iTrav++;
        }

        SinglyLLNode* pTemp = pTrav->m_pNext;
        pTrav->m_pNext = m_pSecond;
        while (nullptr != m_pSecond->m_pNext)
        {
            m_pSecond = m_pSecond->m_pNext;
        }
        m_pSecond->m_pNext = pTemp;
        m_iNodeCount = CountNodes();
    }

    return m_pFirst;
}

/// private function which increases Node Count by 1 as per CountNodes() function
bool Singly::IncrementNodeCount()
{
    LOG_INFO();
    bool bRetValue = false;
    if ((m_iNodeCount + 1) == CountNodes())
    {
        bRetValue = true;
        m_iNodeCount = m_iNodeCount + 1;
    }
    return bRetValue;
}

/// private function which reduces Node Count by 1 as per CountNodes() function
bool Singly::DecrementNodeCount()
{
    LOG_INFO();
    bool bRetValue = false;
    if ((m_iNodeCount - 1) == CountNodes())
    {
        bRetValue = true;
        m_iNodeCount = m_iNodeCount - 1;
    }
    return bRetValue;
}

/// displays data by physically reversing it
/// after displaying data again doing physically reverse
void Singly::ReverseDisplay()
{
    ReversePhysical();
    LOG_DEBUG("", DisplayListData());
    ReversePhysical();
}

SinglyLLNode* Singly::ReversePhysical()
{
    SinglyLLNode* pCurr = m_pFirst;
    SinglyLLNode* pPrev = m_pFirst;
    SinglyLLNode* pNext = m_pFirst;

    while (nullptr != pCurr)
    {
        pNext = pCurr->m_pNext;
        pCurr->m_pNext = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }

    m_pFirst->m_pNext = nullptr;
    m_pFirst = pPrev;
}