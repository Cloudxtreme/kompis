#ifndef KOMPIS_UTIL_ERROR_HPP
#define KOMPIS_UTIL_ERROR_HPP

namespace kompis
{
  namespace util
  {
    /*
     * errors should look like this:
     *
     * filename.java:17: type error: left operand of + not int
     * filename.java:17: type error: left operand of && not boolean
     */
    void error(const char *filename, int line_num, const char *error_type, const char *message)
    {
      fprintf(stderr, "%s:%d: %s error: %s\n", filename, line_num, error_type, message);
    }
  }
}

#endif
