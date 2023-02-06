#include <iostream>
using namespace std;

#include "speechManager.h"

int main() {
  SpeechManager sm;
  int select;
  while (true) {
    sm.show_Menu();
    cout << "请输入您的选择" << endl;
    cin >> select;
    switch (select) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 0:
        sm.exitSystem();
        break;
      default:
        system("clear");
        break;
    }
  }

  return 0;
}
