#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "�Ҷ���",
                "quest_type":           "ɨ",
                "time":                 400,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               9
        ]),
        ([      "quest":                "��԰",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               9
        ]),

([      "quest":                "��ˮ��",
                "quest_type":           "Ѱ",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "�߸���",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                "��ˮ��",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               8
        ]),

        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "���������Ͼ�",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "̫��ʮ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               9        
        ]),
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
        ([       "quest":               "ʩ����",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "�Է�",                            "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([       "quest":               "���촨",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([       "quest":               "�������",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

