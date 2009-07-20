#include "ast/program_declaration.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void ProgramDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
