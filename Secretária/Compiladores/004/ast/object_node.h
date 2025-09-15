#pragma once

#include <cdk/ast/unary_operation_node.h>

namespace udf {

  class object_node: public cdk::unary_operation_node {
  public:
    object_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_operation_node(lineno, argument) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_object_node(this, level);
    }

  };

}