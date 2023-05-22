
/// @brief
#pragma once

/// @brief
#include "../inc/ILinkedList.h"

/// @brief
#include "../inc/common.h"

/// @brief
class ListFactory
{
public:

    /// @brief
    ListFactory();

    /// @brief
    void ListBuidler(ListType);

    /// @brief
    /// @return
    ILinkedList *ListHandle();

private:

    /// @brief
    ILinkedList *m_pListHandle;
};
