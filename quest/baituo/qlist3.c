#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "�Ʋ�",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "��Զ��",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "����Ⱥ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),

        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               9
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               9
        ]),
        ([      "quest":                "������ʦ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "���߹�",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               12
        ]),
        ([      "quest":                "��ľ���",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               14
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 870,
                "score" :               15
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               11
        ]),
        ([       "quest":               "��˹����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               8
        ]),
        ([       "quest":               HIR"��ɫ����"NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               13
        ]),           
        ([       "quest":               MAG "��ɫ����" NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               14
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
