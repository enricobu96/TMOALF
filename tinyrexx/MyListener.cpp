// Generated from tinyrexx.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"

using namespace std;

MyListener::MyListener(const std::set<std::string> &ids) {
  vars = ids;
}


void MyListener::enterProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
    // Dichiara le variabili
    for (auto name : vars) {
        cout << string(indent, ' ') << "int " << name << " = 0;" << endl;
    }

}

void MyListener::exitProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::enterAssign(tinyrexxParser::AssignContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << name << " = " ;
}

void MyListener::exitAssign(tinyrexxParser::AssignContext * ctx) {
    cout << ";" << endl;
}

void MyListener::enterPrint(tinyrexxParser::PrintContext * ctx) {
    cout << string(indent, ' ') << "cout << " ;
}

void MyListener::exitPrint(tinyrexxParser::PrintContext * ctx) {
    cout << " << endl;" << endl;
}


void MyListener::exitInput(tinyrexxParser::InputContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << "cin >> " << name << ";" << endl;
}

void MyListener::enterW_loop(tinyrexxParser::W_loopContext * ctx){
    cout << string(indent, ' ') << "while";
    indent += 4;
}


void MyListener::exitW_loop(tinyrexxParser::W_loopContext * ctx){
    indent -= 4;
    cout << string(indent, ' ') << "}" << endl;
}


void MyListener::enterTest(tinyrexxParser::TestContext * ctx){
    cout << "(";
}

void MyListener::exitTest(tinyrexxParser::TestContext * ctx){
    cout << ") {" << endl;
}


void MyListener::enterI_t_e(tinyrexxParser::I_t_eContext * ctx){
    //entrata in if_block
}

void MyListener::exitI_t_e(tinyrexxParser::I_t_eContext * ctx){
    //esce dall if_condition e l'ultima parentesi viene messa dal do_block
}


void MyListener::enterIf_cond(tinyrexxParser::If_condContext * ctx){
  cout << string(indent, ' ') << "if ";
}

void MyListener::exitIf_cond(tinyrexxParser::If_condContext * ctx){

}


void enterDo_block(tinyrexxParser::Do_blockContext* ctx){
  cout << "{" << endl;
  indent += 4;
}

void exitDo_block(tinyrexxParser::Do_blockContext* ctx){
  indent -= 4;
  cout << "}" << endl;
}


void MyListener::exitElse_cond(tinyrexxParser::Else_condContext * ctx){
  cout << string(indent, ' ') << " else " << endl;
}


void MyListener::enterA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
        cout << ctx->ID()->getText();
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
        cout << ctx->NUMBER()->getText();
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
        cout << "-" ;
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da enterA_op
    } else {
        // caso parentesi
        cout << "(" ;
    }
}

void MyListener::exitA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da exitA_op
    } else {
        // caso parentesi
        cout << ")" ;
    }
}

void MyListener::enterB_expr(tinyrexxParser::B_exprContext* ctx){
  // controllo in quale caso sono
  if(ctx->T() != NULL) {
      // caso valore true
      cout << ctx->T()->getText();
  } else if(ctx->F() != NULL) {
      // caso valore false
      cout << ctx->F()->getText();
  } else if(ctx->NOT() !=  NULL) {
      // caso operatore NOT unario
      cout << "!" ;
  } else if(ctx->b_op() != NULL) {
      // caso operatore binario: gestito da enterB_op
  } else if(ctx->test() != NULL) {
      // caso operatore binario: gestito da enterTest
  } else {
      // caso parentesi
      cout << "(" ;
  }
}

void MyListener::exitB_expr(tinyrexxParser::B_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->T() != NULL) {
        // caso true
    } else if(ctx->F() != NULL) {
        // caso false
    } else if(ctx->NOT() !=  NULL) {
        // caso operatore NOT unario
    } else if(ctx->B_op() != NULL) {
        // caso operatore binario: gestito da exitB_op
    } else if(ctx->test() != NULL) {
        // caso operatore binario: gestito da exitTest
    } else {
        // caso parentesi
        cout << ")" ;
    }
}

void MyListener::exitA_op(tinyrexxParser::A_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->PLUS() != NULL) {
        cout << " + ";
    } else if(ctx->MINUS() != NULL) {
        cout << " - ";
    } else if(ctx->MUL() != NULL) {
        cout << " * ";
    } else if(ctx->DIV() != NULL) {
        cout << " / ";
    }
}

void MyListener::exitR_op(tinyrexxParser::R_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->EQUAL() != NULL) {
        cout << " == ";
    } else if(ctx->LT() != NULL) {
        cout << " < ";
    } else if(ctx->LEQ() != NULL) {
        cout << " <= ";
    } else if(ctx->GT() != NULL) {
        cout << " > ";
    } else if(ctx->GEQ() != NULL) {
        cout << " >= ";
    }
    else if(ctx->DISEQUAL() != NULL) {
      cout << "!= ";
    }
}

void MyListener::exitB_op(tinyrexxParser::B_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->AND() != NULL) {
        cout << " && ";
    } else if(ctx->MINUS() != NULL) {
        cout << " || ";
    }
}

//implementazione enterTerminate
void MyListener::enterTerminate(tinyrexxParser::TerminateContext * ctx) {
  cout << string(indent, ' ') << "return ";
}

//implementazione exitTerminate
void MyListener::exitTerminate(tinyrexxParser::TerminateContext * ctx) {
  cout << " ;" << endl;
}
