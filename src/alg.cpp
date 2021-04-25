// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  char* act = new char[inf.length()];
bool  hight_pr = false;
int j = 0; std::string out;
  for (int i = 0; i < inf.length(); i++) {
    if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/') {
      j++, act[j] = inf[i];
    } else if (inf[i] == '(') {
      if (act[j] == '+' || act[j] == '-') hight_pr = true;
      j++, act[j] = inf[i];
    } else if (inf[i] == ')') {
      while (act[j] != '(') {
        out += act[j], out += ' ';
        j--;
      }
      j--;
      if (hight_pr == true) {
        if (i + 1 < inf.length() && (inf[i + 1] == '*' || inf[i + 1] == '/')) {
          out += inf[i + 2], out += ' ';
          out += inf[i + 1], out += ' ';
          i += 2;
        }
        hight_pr = false;
      }
      while (j > 0 && act[j] != '(') {
        out += act[j], out += ' ';
        j--;
      }
    } else {
      out += inf[i], out += ' ';
      if (j > 0 && act[j] != '(') {
        out += act[j], out += ' ';
        j--;
      }
    }
  }
  out.erase(out.length() - 1, 1);
  return out;
}
int eval(std::string pst) {
int* act = new int[pst.length()];
int j = -1;
for (int i = 0; i < pst.length(); i++) {
if (isdigit(pst[i])) {
     j++, act[j] = pst[i] - '0';
  } else if (pst[i] == '+') {
     act[j - 1] = (act[j] + act[j - 1]);
     j--;
    } else if (pst[i] == '-') {
      act[j - 1] = (act[j - 1] - act[j]);
      j--;
    } else if (pst[i] == '*') {
      if ( i + 1 < pst.length() && pst[i + 1] == '-' ) {
        int result = (act[j] * act[j - 1]);
        act[j - 1] = (act[j - 1] - result);
        j--;
      } else if (i + 1 < pst.length() && pst[i + 1] == '+') {
        int result = (act[j] * act[j - 1]);
        act[j - 1] = (act[j - 1] + result);
        j--;
      } else {
        act[j - 1] = (act[j] * act[j - 1]);
        j--;
      }
    } else if (pst[i] == '/') {
      if (i + 1 < pst.length() && pst[i + 1] == '-') {
        int result = (act[j - 1] / act[j]);
        act[j - 1] = (act[j - 1] - result);
        j--;
      } else if (i + 1 < pst.length() && pst[i + 1] == '+') {
        int result = (act[j - 1] / act[j]);
        act[j - 1] = (act[j - 1] + result);
        j--;
      } else {
        act[j - 1] = (act[j - 1] / act[j]);
        j--;
      }
    }
  }
  return act[j];
}
//123
