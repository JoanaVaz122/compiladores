#include <string>
#include <sstream>
#include <memory>
#include <cdk/types/types.h>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include ".auto/all_nodes.h"
#include "targets/frame_size_calculator.h"
#include "targets/symbol.h"
#include "udf_parser.tab.h"

//---------------------------------------------------------------------------

void udf::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void udf::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void udf::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  // EMPTY
    if (_inFunctionBody) {
    _pf.DOUBLE(node->value()); // load number to the stack
  } else {
    _pf.SDOUBLE(node->value());    // double is on the DATA segment
  }
}
void udf::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  // EMPTY
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl + 2);
  _pf.INT(0);
  _pf.EQ();
}
void udf::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  // EMPTY
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void udf::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  // EMPTY
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value()); // push an integer
}

void udf::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_unary_minus_node(cdk::unary_minus_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

void udf::postfix_writer::do_unary_plus_node(cdk::unary_plus_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.ADD();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->left()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DADD();
  else
    _pf.ADD();
}
void udf::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.SUB();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.I2D();
  } else if (node->type()->name() == cdk::TYPE_POINTER && node->right()->type()->name() == cdk::TYPE_INT) {
    _pf.INT(3);
    _pf.SHTL();
  }

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DSUB();
  else
    _pf.SUB();
}
void udf::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void udf::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
  /*ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->left()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE && node->right()->type()->name() == cdk::TYPE_INT) _pf.I2D();

  if (node->type()->name() == cdk::TYPE_DOUBLE)
    _pf.DMUL();
  else
    _pf.MUL();*/
}


void udf::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}


void udf::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.LT();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.LT();
}
void udf::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.LE();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.LE();
}
void udf::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.GE();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.GE();
}

void udf::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.GT();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.GT();

}
void udf::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.NE();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.NE();
}
void udf::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->left()->accept(this, lvl);
  //node->right()->accept(this, lvl);
  //_pf.EQ();
  ASSERT_SAFE_EXPRESSIONS;

  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() == cdk::TYPE_INT && node->right()->type()->name() == cdk::TYPE_DOUBLE) _pf.I2D();

  _pf.EQ();
}


//---------------------------------------------------------------------------

void udf::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  // simplified generation: all variables are global
  //_pf.ADDR(node->name());
  ASSERT_SAFE_EXPRESSIONS;

  const std::string &id = node->name();
  auto symbol = _symtab.find(id);
  if (symbol->global()) {
    _pf.ADDR(symbol->name());
  } else {
    _pf.LOCAL(symbol->offset());
    //std::cerr << "LVAL " << symbol->name() << ":" << symbol->type()->size() << ":" << symbol->offset() << std::endl;
  }
}

void udf::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  //node->lvalue()->accept(this, lvl);
  //_pf.LDINT(); // depends on type size
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  } else {
    // integers, pointers, and strings
    _pf.LDINT();
  }
}

void udf::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  /*ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP32();
  if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  } else {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(new_symbol()->name()); // name variable location
    reset_new_symbol();
    _pf.SINT(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }
  _pf.STINT(); // store the value at address*/
  ASSERT_SAFE_EXPRESSIONS;

  node->rvalue()->accept(this, lvl + 2);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    if (node->rvalue()->type()->name() == cdk::TYPE_INT) _pf.I2D();
    _pf.DUP64();
  } else {
    _pf.DUP32();
  }

  node->lvalue()->accept(this, lvl);
  if (node->type()->name() == cdk::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    _pf.STINT();
  }
}

//---------------------------------------------------------------------------
/*
void udf::postfix_writer::do_program_node(udf::program_node * const node, int lvl) {
  // Note that UDF doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(0);  // UDF doesn't implement local variables

  node->statements()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.STFVAL32();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
}
*/
//---------------------------------------------------------------------------

void udf::postfix_writer::do_evaluation_node(udf::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->is_typed(cdk::TYPE_STRING)) {
    _pf.TRASH(4); // delete the evaluated value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void udf::postfix_writer::do_print_node(udf::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to print
  for(size_t i = 0; i < node->argument()->size(); i++) {
    cdk::expression_node *expression = dynamic_cast<cdk::expression_node *>(node->argument()->node(i));
    cdk::variable_node *variable = dynamic_cast<cdk::variable_node *>(expression);
    if (expression != nullptr) {
      if (expression->is_typed(cdk::TYPE_INT)) {
        _pf.CALL("printi");
        _pf.TRASH(4); // delete the evaluated value
      } else if (expression->is_typed(cdk::TYPE_STRING)) {
        _pf.CALL("prints");
        _pf.TRASH(4); // delete the evaluated value
      } else if (expression->is_typed(cdk::TYPE_DOUBLE)) {
        _pf.CALL("printd");
        _pf.TRASH(4); // delete the evaluated value
      } else {
        std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
        exit(1);
      }
    } else if (variable != nullptr) {
      if(variable->type()->name() == cdk::TYPE_INT) {
        _pf.CALL("printi");
        _pf.TRASH(4); // delete the evaluated value
      } else if (variable->type()->name() == cdk::TYPE_STRING) {
        _pf.CALL("prints");
        _pf.TRASH(4); // delete the evaluated value
      } else if (variable->type()->name() == cdk::TYPE_DOUBLE) {
        _pf.CALL("printd");
        _pf.TRASH(4); // delete the evaluated value
      } 
    }else{
      std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
      exit(1);
    }
  }    
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_input_node(udf::input_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if(node->is_typed(cdk::TYPE_INT)) {
    _pf.CALL("readi"); // read an integer
    _pf.LDFVAL32(); // store it in the variable
  } else if(node->is_typed(cdk::TYPE_STRING)) {
    _pf.CALL("reads"); // read a string
    _pf.STFVAL32(); // store it in the variable
  } else if(node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.CALL("readd"); // read a double
    _pf.STFVAL64(); // store it in the variable
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_if_node(udf::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl_end;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl_end = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl_end));
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_if_else_node(udf::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl_else, lbl_end;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl_else = lbl_end = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  if (node->elseblock()) {
    _pf.JMP(mklbl(lbl_end = ++_lbl));
    _pf.LABEL(mklbl(lbl_else));
    node->elseblock()->accept(this, lvl + 2);
  }
  _pf.LABEL(mklbl(lbl_end));
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_for_node(udf::for_node *const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;

  _forIni.push(++_lbl); // after init, before body
  _forStep.push(++_lbl); // after intruction
  _forEnd.push(++_lbl); // after for

  os() << "        ;; FOR initialize" << std::endl;
  // initialize: be careful with variable declarations:
  // they are done here, but the space is occupied in the function
  _symtab.push();
  _inForInit = true;  // remember this for local declarations

  // initialize
  node->inits()->accept(this, lvl + 2);

  os() << "        ;; FOR test" << std::endl;
  // prepare to test
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forIni.top()));
  node->condition()->accept(this, lvl + 2);
  _pf.JZ(mklbl(_forEnd.top()));

  os() << "        ;; FOR instruction" << std::endl;
  // execute instruction
  node->condition()->accept(this, lvl + 2);

  os() << "        ;; FOR increment" << std::endl;
  // prepare to increment
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forStep.top()));
  node->incrs()->accept(this, lvl + 2);
  //DAVID FIXME trash
  os() << "        ;; FOR jump to test" << std::endl;
  _pf.JMP(mklbl(_forIni.top()));

  os() << "        ;; FOR end" << std::endl;
  _pf.ALIGN();
  _pf.LABEL(mklbl(_forEnd.top()));

  _inForInit = false;  // remember this for local declarations
  _symtab.pop();

  _forIni.pop();
  _forStep.pop();
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_return_node(udf::return_node *const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;

  // should not reach here without returning a value (if not void)
  if (_function->type()->name() != cdk::TYPE_VOID) {
    node->returnVal()->accept(this, lvl + 2);

    if (_function->type()->name() == cdk::TYPE_INT || _function->type()->name() == cdk::TYPE_STRING
        || _function->type()->name() == cdk::TYPE_POINTER) {
      _pf.STFVAL32();
    } else if (_function->type()->name() == cdk::TYPE_DOUBLE) {
      if (node->returnVal()->type()->name() == cdk::TYPE_INT) _pf.I2D();
      _pf.STFVAL64();
    } else if (_function->type()->name() == cdk::TYPE_STRUCT) {
      // "return" tuple: actually, must allocate space for it on the stack
      // TODO
    } else {
      std::cerr << node->lineno() << ": should not happen: unknown return type" << std::endl;
    }
  }

  _pf.JMP(_currentBodyRetLabel);
  _returnSeen = true;
}

void udf::postfix_writer::do_continue_node(udf::continue_node *const node, int lvl) {
  //TODO
  if (_forIni.size() != 0) {
    _pf.JMP(mklbl(_forStep.top())); // jump to next cycle
  } else
    std::cerr << "Line " << node->lineno() << ": 'restart' outside 'for'" << std::endl;
    exit(1);
}

void udf::postfix_writer::do_break_node(udf::break_node *const node, int lvl) {
  // TODO
  if (_forIni.size() != 0) {
    _pf.JMP(mklbl(_forEnd.top())); // jump to for end
  } else {
    std::cerr << "Line " << node->lineno() << ": 'break' outside 'for'" << std::endl;
    exit(1);
  }
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_block_node(udf::block_node *const node, int lvl) {
  // TODO
    _symtab.push(); // for block-local vars
  if (node->declarations()) node->declarations()->accept(this, lvl + 2);
  if (node->instructions()) node->instructions()->accept(this, lvl + 2);
  _symtab.pop();
}

void udf::postfix_writer::do_function_call_node(udf::function_call_node *const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;

  auto symbol = _symtab.find(node->identifier());

  size_t argsSize = 0;
  if (node->arguments()->size() > 0) {
    for (int ax = node->arguments()->size() - 1; ax >= 0; ax--) {
      cdk::expression_node *arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(ax));
      arg->accept(this, lvl + 2);
      if (symbol->argument_is_typed(ax, cdk::TYPE_DOUBLE) && arg->is_typed(cdk::TYPE_INT)) {
        _pf.I2D();
      }
      argsSize += symbol->argument_size(ax);
    }
  }
  _pf.CALL(node->identifier());
  if (argsSize != 0) {
    _pf.TRASH(argsSize);
  }

  if (symbol->is_typed(cdk::TYPE_INT) || symbol->is_typed(cdk::TYPE_POINTER) || symbol->is_typed(cdk::TYPE_STRING)) {
    _pf.LDFVAL32();
  } else if (symbol->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.LDFVAL64();
  } else {
    // cannot happer!
  }
}


void udf::postfix_writer::do_function_declaration_node(udf::function_declaration_node *const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;

  if (_inFunctionBody || _inFunctionArgs) {
    std::cerr << "Line " << node->lineno() << ": cannot declare function in body or in args" << std::endl;
    exit(1);
    return;
  }


  if (!new_symbol()) return;

  auto function = new_symbol();
  _functions_to_declare.insert(function->name());
  reset_new_symbol();
}

void udf::postfix_writer::do_function_definition_node(udf::function_definition_node *const node, int lvl) {
  //TODO
  ASSERT_SAFE_EXPRESSIONS;
  if (_inFunctionBody || _inFunctionArgs) {
    std::cerr << "Line " << node->lineno() << ": cannot define function in body or in arguments" << std::endl;
    exit(1);
    return;
  }

  // remember symbol so that args and body know
  _function = new_symbol();
  _functions_to_declare.erase(_function->name());  // just in case
  reset_new_symbol();

  _currentBodyRetLabel = mklbl(++_lbl);

  _offset = 8; // prepare for arguments (4: remember to account for return address)
  _symtab.push(); // scope of args

  if (node->arguments()->size() > 0) {
    _inFunctionArgs = true; //FIXME really needed?
    for (size_t ix = 0; ix < node->arguments()->size(); ix++) {
      cdk::basic_node *arg = node->arguments()->node(ix);
      if (arg == nullptr) break; // this means an empty sequence of arguments
      arg->accept(this, 0); // the function symbol is at the top of the stack
    }
    _inFunctionArgs = false; //FIXME really needed?
  }

  _pf.TEXT();
  _pf.ALIGN();
  if (node->qualifier() == tPUBLIC) _pf.GLOBAL(_function->name(), _pf.FUNC());
  _pf.LABEL(_function->name());

  // compute stack size to be reserved for local variables
  frame_size_calculator lsc(_compiler, _symtab, _function);
  node->accept(&lsc, lvl);
  _pf.ENTER(lsc.localsize()); // total stack size reserved for local variables

  _offset = 0; // prepare for local variable

  // the following flag is a slight hack: it won't work with nested functions
  _inFunctionBody = true;
  os() << "        ;; before body " << std::endl;
  node->block()->accept(this, lvl + 4); // block has its own scope
  os() << "        ;; after body " << std::endl;
  _inFunctionBody = false;
  _returnSeen = false;

  _pf.LABEL(_currentBodyRetLabel);
  _pf.LEAVE();
  _pf.RET();

  _symtab.pop(); // scope of arguments

  if (node->identifier() == "og") {
    // declare external functions
    for (std::string s : _functions_to_declare)
      _pf.EXTERN(s);
  }

}

//--------------------------------------------------------------------------

void udf::postfix_writer::do_nullptr_node(udf::nullptr_node * const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS; // a pointer is a 32-bit integer
  if (_inFunctionBody) {
    _pf.INT(0);
  } else {
    _pf.SINT(0);
  }
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_sizeof_node(udf::sizeof_node * const node, int lvl) {
  //TODO
  ASSERT_SAFE_EXPRESSIONS;
  _pf.INT(node->expression()->type()->size());
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_address_of_node(udf::address_of_node * const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;
  // since the argument is an lvalue, it is already an address
  node->lvalue()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_object_node(udf::object_node * const node, int lvl) {
  // TODO
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ALLOC(); // allocate
  _pf.SP(); // put base pointer in stack
}

//---------------------------------------------------------------------------
void udf::postfix_writer::do_tensor_node(udf::tensor_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  // 1. Calculate total size needed for the tensor
  if (node->dims()) {
    // Push each dimension and multiply them to get total elements
    for (size_t i = 0; i < node->dims()->size(); i++) {
      auto dim = dynamic_cast<cdk::expression_node*>(node->dims()->node(i));
      dim->accept(this, lvl); // Push dimension value
      _pf.LDINT(); // Load the integer value
      if (i > 0) {
        _pf.MUL(); // Multiply with previous dimensions
      }
    }
    // Now the total element count is on top of stack
  } else {
    // No dimensions specified - use default size? Or error?
    _pf.INT(1); // Default to single element
  }

  // Multiply by element size (assuming 4 bytes per element)
  _pf.INT(4);
  _pf.MUL();

  // Allocate memory
  _pf.ALLOC(); // Allocate the calculated size
  _pf.SP();    // Leave address on stack

  // 2. Handle initialization if present
  if (node->args()) {
    // Store tensor address in a temporary
    int temp_offset = -_offset;
    _offset += 4;
    _pf.LOCAL(temp_offset);
    _pf.STINT();

    // Initialize tensor elements
    node->args()->accept(this, lvl + 2);

    // Restore tensor address
    _pf.LOCAL(temp_offset);
    _pf.LDINT();
    _offset -= 4;
  }

  // Tensor address is now on top of stack
}


void udf::postfix_writer::do_tensor_index_node(udf::tensor_index_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  // Get tensor base address
  node->tensor()->accept(this, lvl);
  
  if (!node->indices() || node->indices()->size() == 0) {
    std::cerr << "ERROR " << node->lineno() << ": tensor index requires indices\n";
    exit(1);
  }

  // Calculate offset
  for (size_t i = 0; i < node->indices()->size(); i++) {
    // Push each index expression
    auto index = dynamic_cast<cdk::expression_node*>(node->indices()->node(i));
    index->accept(this, lvl);
    
    // Multiply by appropriate stride (assuming row-major order)
    // For simplicity, we'll assume all dimensions have equal size
    // In a complete implementation, you'd need to track tensor dimensions
    _pf.INT(node->type()->size());  // size of element type
    _pf.MUL();
  }

  // Add base address and offset
  _pf.ADD();

  // Load the value based on type
  switch (node->type()->name()) {
    case cdk::TYPE_INT:    _pf.LDINT(); break;
    case cdk::TYPE_DOUBLE: _pf.LDDOUBLE(); break;
    case cdk::TYPE_STRING: _pf.LDINT(); break;  // strings are pointers (int)
    case cdk::TYPE_POINTER:_pf.LDINT(); break;
    default:
      std::cerr << "ERROR " << node->lineno() << ": cannot index tensor of type " 
                << cdk::to_string(node->type()) << "\n";
      exit(1);
  }
}

void udf::postfix_writer::do_tensor_dim_node(udf::tensor_dim_node *const node, int lvl) {
  //TODO
}

void udf::postfix_writer::do_tensor_dims_node(udf::tensor_dims_node *const node, int lvl) {
  //TODO
}

void udf::postfix_writer::do_tensor_rank_node(udf::tensor_rank_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  
  // Get the tensor address (though we won't actually use it for rank)
  node->tensor()->accept(this, lvl);
  
  // Load the rank value from the tensor metadata
  _pf.INT(-4);         // Offset to where rank is stored
  _pf.ADD();           // Add to base pointer to get rank address
  _pf.LDINT();         // Load the rank value
  
  // The rank (integer) is now on top of the stack
}

void udf::postfix_writer::do_tensor_reshape_node(udf::tensor_reshape_node *const node, int lvl) {
  //TODO
}

void udf::postfix_writer::do_tensor_capacity_node(udf::tensor_capacity_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  // Declare labels
  int lbl_done, lbl_loop;

  // Get the tensor address
  node->tensor()->accept(this, lvl);

  // 1. Get the rank (number of dimensions)
  _pf.INT(-4);         // Offset to rank
  _pf.ADD();           // Add to base pointer
  _pf.LDINT();         // Load the rank value
  _pf.DUP32();         // Save a copy for later

  // 2. Initialize product to 1
  _pf.INT(1);

  // 3. If rank is 0 (scalar), we're done
  lbl_done = ++_lbl;
  _pf.JZ(mklbl(lbl_done));

  // 4. Loop through each dimension and multiply sizes
  _pf.INT(0);          // Initialize counter
  lbl_loop = ++_lbl;
  _pf.LABEL(mklbl(lbl_loop));

  // Check if we've processed all dimensions
  _pf.DUP32();         // Duplicate counter
  _pf.DUP32();         // Duplicate rank (now at offset 2)
  _pf.LT();            // Compare counter < rank
  _pf.JZ(mklbl(lbl_done));

  // Calculate address of current dimension size:
  // base_ptr + (-8 - 4*counter)
  node->tensor()->accept(this, lvl); // Get base pointer again
  
  // Need to get the counter value - since we can't directly access stack positions,
  // we'll use a local variable
  int counter_offset = -_offset;
  _offset += 4;
  _pf.LOCAL(counter_offset);
  _pf.STINT();         // Store counter
  
  _pf.INT(-8);         // Base offset for dimension sizes
  _pf.LOCAL(counter_offset);
  _pf.LDINT();         // Load counter
  _pf.INT(4);
  _pf.MUL();
  _pf.SUB();           // Calculate offset: -8 - 4*counter
  _pf.ADD();           // Add to base pointer
  _pf.LDINT();         // Load dimension size

  // Multiply with running product
  _pf.MUL();

  // Increment counter
  _pf.LOCAL(counter_offset);
  _pf.LDINT();
  _pf.INT(1);
  _pf.ADD();
  _pf.LOCAL(counter_offset);
  _pf.STINT();
  _pf.LOCAL(counter_offset);
  _pf.LDINT();
  
  _offset -= 4; // Clean up local variable

  _pf.JMP(mklbl(lbl_loop));

  _pf.LABEL(mklbl(lbl_done));

  // Clean up stack (remove saved rank and counter)
  _pf.TRASH(4);        // Remove counter
  _pf.TRASH(4);        // Remove rank
}

void udf::postfix_writer::do_tensor_contraction_node(udf::tensor_contraction_node *const node, int lvl) {
  //TODO
}

//---------------------------------------------------------------------------

void udf::postfix_writer::do_left_index_node(udf::left_index_node * const node, int lvl) {
 //TODO
 
  ASSERT_SAFE_EXPRESSIONS;
  if (node->base()) {
    node->base()->accept(this, lvl);
  } else {
    if (_function) {
      _pf.LOCV(-_function->type()->size());
    } else {
      std::cerr << "FATAL: " << node->lineno() << ": trying to use return value outside function" << std::endl;
    }
  }
  node->index()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ADD(); // add pointer and index*/
}

void udf::postfix_writer::do_variable_declaration_node(udf::variable_declaration_node *const node, int lvl) {
  //TODO
  ASSERT_SAFE_EXPRESSIONS;

  auto id = node->identifier();

  std::cout << "INITIAL OFFSET: " << _offset << std::endl;

  // type size?
  int offset = 0, typesize = node->type()->size(); // in bytes
  std::cout << "ARG: " << id << ", " << typesize << std::endl;
  if (_inFunctionBody) {
    std::cout << "IN BODY" << std::endl;
    _offset -= typesize;
    offset = _offset;
  } else if (_inFunctionArgs) {
    std::cout << "IN ARGS" << std::endl;
    offset = _offset;
    _offset += typesize;
  } else {
    std::cout << "GLOBAL!" << std::endl;
    offset = 0; // global variable
  }
  std::cout << "OFFSET: " << id << ", " << offset << std::endl;

  auto symbol = new_symbol();
  if (symbol) {
    symbol->set_offset(offset);
    reset_new_symbol();
  }

  if (_inFunctionBody) {
    // if we are dealing with local variables, then no action is needed
    // unless an initializer exists
    if (node->initializer()) {
      node->initializer()->accept(this, lvl);
      if (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_STRING) || node->is_typed(cdk::TYPE_POINTER)) {
        _pf.LOCAL(symbol->offset());
        _pf.STINT();
      } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
        if (node->initializer()->is_typed(cdk::TYPE_INT))
          _pf.I2D();
        _pf.LOCAL(symbol->offset());
        _pf.STDOUBLE();
      } else if (node->is_typed(cdk::TYPE_STRUCT)) {
        // single var initialized with tuple
        // TODO
      } else {
        std::cerr << "cannot initialize" << std::endl;
      }
    }
  } else {
    if (!_function) {
      if (node->initializer() == nullptr) {
        _pf.BSS();
        _pf.ALIGN();
        _pf.LABEL(id);
        _pf.SALLOC(typesize);
      } else {

        if (node->is_typed(cdk::TYPE_INT) || node->is_typed(cdk::TYPE_DOUBLE) || node->is_typed(cdk::TYPE_POINTER)) {
          if (node->constant()) {
            _pf.RODATA();
          } else {
            _pf.DATA();
          }
          _pf.ALIGN();
          _pf.LABEL(id);

          if (node->is_typed(cdk::TYPE_INT)) {
            node->initializer()->accept(this, lvl);
          } else if (node->is_typed(cdk::TYPE_POINTER)) {
            node->initializer()->accept(this, lvl);
          } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
            if (node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
              node->initializer()->accept(this, lvl);
            } else if (node->initializer()->is_typed(cdk::TYPE_INT)) {
              cdk::integer_node *dclini = dynamic_cast<cdk::integer_node*>(node->initializer());
              cdk::double_node ddi(dclini->lineno(), dclini->value());
              ddi.accept(this, lvl);
            } else {
              std::cerr << node->lineno() << ": '" << id << "' has bad initializer for real value\n";
              _errors = true;
            }
          }
        } else if (node->is_typed(cdk::TYPE_STRING)) {
          if (node->constant()) {
            int litlbl;
            // HACK!!! string literal initializers must be emitted before the string identifier
            _pf.RODATA();
            _pf.ALIGN();
            _pf.LABEL(mklbl(litlbl = ++_lbl));
            _pf.SSTRING(dynamic_cast<cdk::string_node*>(node->initializer())->value());
            _pf.ALIGN();
            _pf.LABEL(id);
            _pf.SADDR(mklbl(litlbl));
          } else {
            _pf.DATA();
            _pf.ALIGN();
            _pf.LABEL(id);
            node->initializer()->accept(this, lvl);
          }
        } else {
          std::cerr << node->lineno() << ": '" << id << "' has unexpected initializer\n";
          _errors = true;
        }

      }

    }
  }

}