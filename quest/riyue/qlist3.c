#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "��Զ��",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               16
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               16
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
        ([       "quest":               "��",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               13
        ]),           
        ([       "quest":               "�������䵶",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               14
        ]),
        ([      "quest":                "÷��",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "��Ө��",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
          ([      "quest":              "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Կ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               12
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "��Ϣ��",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               19
        ]),
        ([      "quest":                "ҩ��",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               10
        ]),
        ([      "quest":                "��ȸ��",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               12
        ]),
           
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

