#pragma once

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>

namespace udf {

  /**
   * Class for describing tensor dims access.
   */
  class tensor_dims_node: public cdk::sequence_node {
    cdk::expression_node *_tensor;

  public:
    tensor_dims_node(int lineno, cdk::expression_node *tensor)
        : cdk::sequence_node(lineno), _tensor(tensor) {}

    cdk::expression_node *tensor() {
      return _tensor;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_tensor_dims_node(this, level);
    }
  };

}

