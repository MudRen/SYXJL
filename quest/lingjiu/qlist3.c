#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               11
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                HIY"����"NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               12
        ]),
        ([      "quest":                HIW"����"NOR,
                "quest_type":           "Ѱ",
                "time":                 1100,
                "score" :               11
        ]),

        ([      "quest":                "�����޶������ϲ᡽��",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 360,
                "score" :               6
        ]),

        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
           
        ([      "quest":                "��翷�ɽ��",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "�ϻ���",
                "quest_type":           "ɨ",
                "time":                 400,
                "score" :               11
        ]),
        ([      "quest":                "����������",
                "quest_type":           "ɨ",
                "time":                 550,
                "score" :               14
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "���ַ���",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               11
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
