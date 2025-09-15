#pragma once

#include <cdk/ast/basic_node.h>

namespace udf {

  /**
   * Class for describing break nodes.
   */
  class break_node : public cdk::basic_node {
  public:
    inline break_node(int lineno) :
        cdk::basic_node(lineno) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_break_node(this, level);
    }
  };
} // udf


