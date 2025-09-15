#pragma once

#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>

namespace udf {

    /**
     * Class for describing for-cycle nodes.
     */
    class for_node: public cdk::basic_node {
      cdk::sequence_node *_inits;
      cdk::sequence_node *_condition;
      cdk::sequence_node *_incrs;
      cdk::basic_node *_block;
  
    public:
      inline for_node(int lineno, cdk::sequence_node *inits, cdk::sequence_node *condition, cdk::sequence_node *incrs, cdk::basic_node *block) :
          basic_node(lineno), _inits(inits), _condition(condition), _incrs(incrs), _block(block) {
      }
  
      cdk::sequence_node *inits() {return _inits;}
  
      cdk::sequence_node *condition() {return _condition;}
  
      cdk::sequence_node *incrs() {return _incrs;}
  
      cdk::basic_node *block() {return _block;}
  
      void accept(basic_ast_visitor *sp, int level) {sp->do_for_node(this, level);}
  
  }; 
} // udf
  