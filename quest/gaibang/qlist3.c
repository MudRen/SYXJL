inherit SKILL;
#include <ansi.h>
mapping *quest = ({
        ([      "quest":                "�ݽǱ�",
                "quest_type":           "ɨ",
                "time":                 680,
                "score" :               10
        ]),
        ([      "quest":                "�����ѱ�",
                "quest_type":           "ɨ",
                "time":                 480,
                "score" :               8
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 780,
                "score" :               10
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "�ȳ�������",
                "quest_type":           "ɨ",
                "time":                 360,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":               1000,
                "score" :             12
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":               800,
                "score" :             12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":               1100,
                "score" :             13
        ]),
        ([      "quest":                "÷��",
                "quest_type":           "ɱ",
                "time":               810,
                "score" :             10
        ]),
        ([      "quest":                "��ľ���",
                "quest_type":           "ɱ",
                "time":               600,
                "score" :             12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":               680,
                "score" :             9
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":               450,
                "score" :             10
        ]),
  ([      "quest":                HIG"���㻨"NOR,
                "quest_type":           "Ѱ",
                "time":                600,
                "score" :              10
      ]),
  ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                700,
                "score" :              10
      ]),
  ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                680,
                "score" :              9
      ]),
  ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                900,
                "score" :              10
      ]),
  ([      "quest":                HIW"����"NOR,
                "quest_type":           "Ѱ",
                "time":                500,
                "score" :              9
      ]),
  ([      "quest":                HIR"ɮñ"NOR,
                "quest_type":           "Ѱ",
                "time":                890,
                "score" :              8
      ]),
  ([      "quest":                "��Ƥ��",
                "quest_type":           "Ѱ",
                "time":                500,
                "score" :              11
      ]),


   });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
