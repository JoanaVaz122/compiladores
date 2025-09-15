#pragma once

#include <cdk/ast/basic_node.h>

namespace udf {

  /**
   * Class for describing continue instruction nodes.
   */

  class continue_node: public cdk::basic_node {

  public:
    inline continue_node(int lineno) :
        cdk::basic_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_continue_node(this, level);
    }

  };

} 
