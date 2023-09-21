/*
  #include <filename> is typically used for system header files. 
  The preprocessor searches for the file in the standard system directories.

  #include "filename" is typically used for user-defined header files. 
  The preprocessor first searches for the file in the same directory as the file that contains the #include directive. 
  If it doesn't find the file there, it then searches the standard system directories.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>

#include "functions.h"

using std::cout;
using std::string;
using std::vector;

// g++ -std=c++17 leetcode.cpp -o leetcode
/*
  When you compile a project with g++, g++ actually performs several distinct tasks:

  The preprocessor runs and executes any statement beginning with a hash symbol: #, such as #include statements. This ensures all code is in the correct location and ready to compile.
  Each file in the source code is compiled into an "object file" (a .o file). Object files are platform-specific machine code that will be used to create an executable.
  The object files are "linked" together to make a single executable. In the examples you have seen so far, this executable is a.out, but you can specify whatever name you want.

  CMakeLists.txt files can be used to specify the locations of necessary packages, set build flags and environment variables, specify build target names and locations, and other actions.
  In general, CMake only needs to be run once for a project, unless you are changing build options (e.g. using different build flags or changing where you store your files).
  Make will be able to keep track of which files have changed and compile only those that need to be compiled before building.
  Note: If you do re-run CMake, or if you are having problems with your build, it can be helpful to delete your build directory and start from scratch. Otherwise, some environment variables may not be reset correctly.

  mkdir build
  cd build
  cmake ..
  make
*/
int main() {
    // nums = [2,7,11,15], target = 9
    // [0,1]
    vector<int> nums = {2, 7, 11, 15};
    auto target = 9;
    const auto indices = twoSum(nums, target);
    cout << "Two Sum:\n";
    cout << indices[0] << ", " << indices[1] << "\n";

    cout << "Is Palindrome:\n";
    cout << isPalindrome(121) << "\n"; // true
    cout << isPalindrome(1217) << "\n"; // false
    cout << isPalindrome(1111) << "\n"; // true
    cout << isPalindrome(766) << "\n"; // false

    cout << "Remove Duplicates:\n";
    vector<int> duplicates_a = {1, 2, 3, 3, 3, 3, 8};
    cout << removeDuplicates(duplicates_a) << "\n";

    cout << "Remove Element:\n";
    vector<int> values_a = {3,2,2,3};
    vector<int> values_b = {0,1,2,2,3,0,4,2};
    vector<int> values_c = {2,3,2,2,3};
    cout << removeElement(values_a, 3) << "\n"; // 2
    cout << removeElement(values_b, 2) << "\n"; // 5
    cout << removeElement(values_c, 2) << "\n"; // 2

    cout << "Longest Common Prefix:\n";
    vector<string> strs_a = {"flower", "flow", "flight"};
    vector<string> strs_b = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs_a) << "\n"; // "fl"
    cout << longestCommonPrefix(strs_b) << "\n"; // ""

    cout << "Valid Parentheses:\n";
    cout << std::boolalpha << isValid("()") << std::endl; // true
    cout << std::boolalpha << isValid("()[]{}") << std::endl; // true
    cout << std::boolalpha << isValid("(]") << std::endl; // false
    cout << std::boolalpha << isValid("(([{}]{})){}") << std::endl; // true
    cout << std::boolalpha << isValid("(){}}{") << std::endl; // false
}
