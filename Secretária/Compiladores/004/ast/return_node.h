#pragma once

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace udf {

  class return_node: public cdk::basic_node {
    cdk::expression_node *_returnVal;

  public:
    return_node(int lineno, cdk::expression_node *returnVal = nullptr) :
        cdk::basic_node(lineno), _returnVal(returnVal) {
    }

  public:
    cdk::expression_node* returnVal() {
      return _returnVal;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // udf