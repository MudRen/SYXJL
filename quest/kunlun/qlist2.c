#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "������ʿ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "����ͷ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "��ʮ���¾���",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "Ѳɽ����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "佻�����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "������ʿ",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "���",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "����ɽ��ʥ��",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               5
        ]),
        ([       "quest":               "ǰ��",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
        ([       "quest":               "����",
                "quest_type":           "ɨ",
                "time":                 160,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

