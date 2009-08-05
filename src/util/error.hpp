#ifndef KOMPIS_UTIL_ERROR_HPP
#define KOMPIS_UTIL_ERROR_HPP

namespace kompis
{
  namespace util
  {
    // TODO: should probably use streams instead
    void error(const char *filename, int line_num, const char *error_type, const char *message);
  }
}

#endif
