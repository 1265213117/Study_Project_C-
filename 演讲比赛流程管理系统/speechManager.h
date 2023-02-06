#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include "speaker.h"

class SpeechManager {
 public:
  vector<int> v1;
  vector<int> v2;
  vector<int> victory;
  map<int, Speaker> m_Speaker;
  int m_Index;

  SpeechManager();

  void createSpeaker();

  void InitSpeech();
  // 菜单显示
  void show_Menu();

  // 退出系统
  void exitSystem();

  ~SpeechManager();
};
