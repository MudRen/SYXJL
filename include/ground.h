// create by five 

#include <ansi.h>

#define DEBUG 0

#define REWARD 16

#define STEP_PREPARE 0
#define STEP_FIGHT   1
#define STEP_FINISH  2

#define MODE_SINGLE_SD 0
#define MODE_SINGLE_LT 1
#define MODE_TEAM_LT   2
#define MODE_TEAM_DZ   3
#define MODE_TEAM_XH   4
string *modes = ({
  "����ɢ��",
  "������̨",
  "������̨",
  "���ɶ���",
  "����ѭ����",
});
string *mode_hints = ({
  "��������������ϳ�����",
  "��������ϳ�������������Ӯ��Ϊ������",
  "ÿ���ɵ�ѡ�������ϳ����ޣ���ѡ��Ӯ��Ϊ����������",
  "ÿ���ɵ�ѡ�ְ���ǿ�ȼ����࣬�����ɼ��ͬ��ѡ�ֽ���",
  "ÿ���ɵ�ѡ������������������ѡ�ֽ���",
});

#define FAMILY_NONE     0
#define FAMILY_SHAOLIN  1
#define FAMILY_WUDANG   2
#define FAMILY_HUASHAN  3
#define FAMILY_GAIBANG  4
#define FAMILY_TAOHUA   5
#define FAMILY_XINGXIU  6
#define FAMILY_RIYUE    7
#define FAMILY_GUSHU    8
#define FAMILY_MINGJIAO 9
#define FAMILY_GUMU     10
#define FAMILY_EMEI     11
#define FAMILY_QUANZ    12

string *families = ({
  "�������",
  "������",
  "�䵱��",
  "��ɽ��",
  "ؤ��",
  "�һ���",
  "������",
  "�������",
  "����Ľ��",
  "����",
  "��Ĺ��",
  "������",
  "ȫ���",  
});


