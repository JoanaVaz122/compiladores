#pragma once

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>

namespace udf {

  /**
   * Class for describing tensor reshape operation.
   */
  class tensor_reshape_node: public cdk::expression_node {
    cdk::expression_node *_tensor;
    cdk::sequence_node *_dims;

  public:
    tensor_reshape_node(int lineno, cdk::expression_node *tensor,
                        cdk::sequence_node *dims)
        : cdk::expression_node(lineno), _tensor(tensor), _dims(dims) {}

    cdk::expression_node *tensor() {
      return _tensor;
    }

    cdk::sequence_node *dims() const {
      return _dims;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_tensor_reshape_node(this, level);
    }
  };

}
