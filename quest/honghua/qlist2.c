#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               8
        ]),
        ([       "quest":               "����Ͽ",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               10
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               9
        ]),
          ([      "quest":                "��ͷ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]), 
         ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
         ([       "quest":               "ɨ��ɮ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               9
        ]),
         ([       "quest":               "ŷ����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               11
        ]),
         ([       "quest":               "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               12
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
        ([      "quest":                "��ˮ��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               10
        ]),
        ([       "quest":               "���⴮",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               12
        ]),
        ([       "quest":               "��˹����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               10
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
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               8
        ]),
        ([       "quest":               "�佫",
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

