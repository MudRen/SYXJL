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
        ([      "quest":                "����",
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
        ([       "quest":               "������",
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

        ([       "quest":               "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               9
        ]),
        ([       "quest":               "��",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               8
        ]),
        ([       "quest":               "����ƴ�",
                "quest_type":           "Ѱ",
                "time":                 560,
                "score" :               6
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɱ",
                "time":                 880,
                "score" :               9
        ]),
        ([       "quest":               "��ҩ��",
                "quest_type":           "ɱ",
                "time":                 480,
                "score" :               10
        ]),
        ([       "quest":               "���",
                "quest_type":           "ɱ",
                "time":                 880,
                "score" :               5
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

