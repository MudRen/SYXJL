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
        ([      "quest":                HIW"��ħ��"NOR,
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "�����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               15
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
        ([      "quest":                "������ʦ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

