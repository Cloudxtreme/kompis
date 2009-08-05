#include "util/error.hpp"
#include <iostream>

namespace kompis
{
  namespace util
  {
    void error(const char *filename, int line_num, const char *error_type, const char *message)
    {
      fprintf(stderr, "%s:%d: %s error: %s\n", filename, line_num, error_type, message);
    }
  }
}
