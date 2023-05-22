/// @brief
#pragma once

/// @brief
#include <iostream>

/// @brief
#define TEMPLATE_TYPE template<typename T>

/// @brief
enum ListType
{
    SinglyLL, DoublyLL, SinglyCircularLL, DoublyCircularLL
};

/// @brief
#define BOOL_LOG_DEBUG true

/// @brief
#define BOOL_LOG_INFO false

/// @brief
#define BOOL_LOG true

/// @brief
#define LOG(void) if(BOOL_LOG) cout << "[" << __PRETTY_FUNCTION__ << ": " << __LINE__ << "]"

/// @brief
#define LOG_INFO(void) if(BOOL_LOG_INFO) LOG(void) << endl;

/// @brief
#define LOG_DEBUG(str, arg) if(BOOL_LOG_DEBUG) LOG(void) << " -> " << str << " [" << arg << "]" << endl;
