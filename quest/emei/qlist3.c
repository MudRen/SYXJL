#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "�����Ϲ�",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               16
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               18
        ]),  
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([       "quest":               "��¬��",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               10
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               11
        ]),
        ([       "quest":               "��ˮ��",
                "quest_type":           "ɨ",
                "time":                 400,
                "score" :               13
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               9
        ]),
        ([       "quest":               "���Ƹ�",
                "quest_type":           "ɨ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "������;�",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               13
        ]),
        ([      "quest":                "��ˮ��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               15
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               18
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               16
        ]),
        ([      "quest":                "�Ħ��",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               16
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
