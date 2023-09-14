/*
  The FUNCTIONS_H is known as an "include guard". 
  Its role is to prevent the contents of the header file from being processed more than once by the preprocessor.

  If you include a header file in multiple places within your project, and that header file doesn't have an include guard, 
  then its contents will be copied into every file that includes it. This can lead to issues like redefinition errors.

  The way the include guard works is like this:

  #ifndef FUNCTIONS_H: This is a preprocessor directive that checks if FUNCTIONS_H has not been defined yet. 
  If it hasn't, then the preprocessor continues to the next line. If it has, the preprocessor skips to the line after #endif.

  #define FUNCTIONS_H: This line defines FUNCTIONS_H. The next time the preprocessor encounters #ifndef FUNCTIONS_H, it will skip to the line after #endif.

  #endif: This marks the end of the block of code that is guarded by #ifndef FUNCTIONS_H.

  The choice of FUNCTIONS_H is arbitrary; you could use any valid identifier. However, it is common practice 
  to use a name related to the file name, all in uppercase, to make it clear and easy to avoid conflicts. 
  If you had another file called utilities.h, you might use UTILITIES_H as the include guard in that file.
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <numeric>
#include <type_traits>
#include <fstream>
#include <sstream>

using std::cout;
using std::vector;
using std::accumulate;
using std::string;
using std::ifstream;
using std::istringstream;


vector<int> twoSum(vector<int>& nums, const int target) {
    // O(N)
    // key: number, value: index
    std::unordered_map<int, int> map;

    for (auto i = 0; i < nums.size(); i++) {
        auto current_value = nums[i];
        auto target_value = target - current_value;

        if (map.find(target_value) != map.end()) {
            return {map[target_value], i};
        }
        else {
            map[current_value] = i;
        }
    }

    return {};
}

bool isPalindrome(int x) {
    const auto chars = std::to_string(x);
    auto left = chars.begin();
    auto right = chars.end() - 1;

    while (left < right) {
        if (*left != *right) {
            return false;
        }
        // for performance
        ++left;
        --right;
    }

    return true;
}

/*
  The use of static_assert along with std::is_arithmetic does not incur a runtime performance penalty. This is because these checks occur at compile-time, not at runtime.

  In C++, templates and type traits like std::is_arithmetic are evaluated by the compiler at compile time. 
  They generate specific code for each type that's used as a template argument, just as if you had written separate functions or classes for each type.

  static_assert also does its work at compile time. If its condition is false, it causes a compile error; if the condition is true, it has no effect on the generated code. 
  It does not produce any instructions that would slow down the program at runtime.

  So you can use these features to make your code more flexible and safe, without worrying about a performance cost. 
  They're part of what makes C++ a powerful language for high-performance programming.
*/

#endif // FUNCTIONS_H