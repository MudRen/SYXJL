#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "ʷ��ɽ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                HIW"��ħ��"NOR,
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
          ([      "quest":               "���",
                  "quest_type":           "ɨ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               9        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "֪�͵���",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "�������",
                "quest_type":           "ɱ",
                "time":                 180,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
