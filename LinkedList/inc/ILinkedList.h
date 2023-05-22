
/// @brief
#pragma once

/// @brief
#include <iostream>

/// @brief
#include "../inc/SinglyLLNode.h"

/// @brief
using namespace std;

/// @brief
class ILinkedList
{

public:

    /// @brief
    /// @param iPos
    /// @return
    virtual bool InsertAtFirst(int iPos) = 0;

    /// @brief
    /// @param iPos
    /// @return
    virtual bool InsertAtLast(int iPos) = 0;

    /// @brief
    /// @return
    virtual bool InsertAtPosition(int, int) = 0;

    /// @brief
    /// @return
    virtual bool DeleteAtFirst() = 0;

    /// @brief
    /// @return
    virtual bool DeleteAtLast() = 0;

    /// @brief
    /// @param iPos
    /// @return
    virtual bool DeleteAtPosition(int iPos) = 0;

    /// @brief
    /// @return
    virtual bool DeleteAll() = 0;

    /// @brief
    /// @param iData
    /// @return
    virtual int SearchData(int iData) = 0;

    /// @brief
    /// @return
    virtual bool IsListEmpty() = 0;

    /// @brief
    /// @return
    virtual string DisplayListData() = 0;

    /// @brief
    /// @return
    virtual unsigned int CountNodes() = 0;

    /// @brief
    /// @param pSecond
    /// @return
    virtual SinglyLLNode* ConcatList(SinglyLLNode* pSecond) = 0;

    /// @brief
    /// @param pSecond
    /// @param iPos
    /// @return
    virtual SinglyLLNode* ConcatAtPosition(SinglyLLNode* pSecond, int iPos) = 0;

    /** Reverse Functions **/
};
