/// @brief
#pragma once

/// @brief
#include "ILinkedList.h"

/// @brief
class Doubly : public ILinkedList
{
public:

    /// @brief
    Doubly();

    /// @brief
    ~Doubly();

    /** Insert Operations **/
    bool InsertAtFirst();
    bool InsertAtLast();
    bool InsertAtPosition();

    /** Delete Operations **/
    bool DeleteAtFirst();
    bool DeleteAtLast();
    bool DeleteAtPosition();
    bool DeleteAll();

    /** Other Operations **/
    bool SearchData(); // FirstOCc, LastOcc. searchALL;
    bool IsListEmpty();
    bool DisplayList();
    unsigned int CountNodes();

    /** Concat Operations **/
    bool ConcatList();
    bool ConcatAtPosition();

    // physicalReverse
    // reverseDis[play
};