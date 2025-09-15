#pragma once

#include <cdk/ast/expression_node.h>

namespace udf {

  /**
   * Class for describing tensor dims access.
   */
  class tensor_node: public cdk::expression_node {
    cdk::expression_node *_args;
    cdk::sequence_node *_dims;

  public:
    tensor_node(int lineno, cdk::expression_node *args, cdk::sequence_node *dims)
        : cdk::expression_node(lineno), _args(args), _dims(dims) {}

    cdk::expression_node *args() {
      return _args;
    }

    cdk::sequence_node *dims() {
      return _dims;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_tensor_node(this, level);
    }
  };

}
