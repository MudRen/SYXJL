inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               2
        ]),
        ([      "quest":                "��ͨذ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               4
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                HIG"Ҷ����"NOR,
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               3
        ]),       
        ([      "quest":                HIR"��������"NOR,
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               5
        ]), 
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               5
        ]),  
 
        ([      "quest":                "̨�Ķ�ȹ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "ţƤ�ƴ�",                           "quest_type":           "Ѱ",
                "time":                 240,
                "score" :               2
        ]), 
        ([      "quest":                "̨��ͷ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "Ƥ����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 780,
                "score" :               5
        ]),
        ([      "quest":                "ָ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               4
        ]),  
        ([      "quest":                "Ͳȹ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               9
        ]),
        ([      "quest":                "���",
                  "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               4
        ]),
       ([      "quest":                "��ҩ",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               10
        ]),
       ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 240,
                "score" :               3
        ]),
        ([      "quest":                HIR"��õ��"NOR,
                "quest_type":           "Ѱ",
                "time":                 360,
                "score" :               5
        ]),

  });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
