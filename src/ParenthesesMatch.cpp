#include "ParenthesesMatch.h"
#include <cstring>

bool parenthesesMatch(const char* str)
{
   if (str == nullptr) return true;

   Stack<char> s;
   for (int i = 0; str[i] != '\0'; i++)
   {
      if (str[i] == '(')
      {
         s.push('(');
      }
      else if (str[i] == ')')
      {
         if (s.empty())
         {
            return false;
         }
         s.pop();
      }
   }

   return s.empty();
}