#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "��ͷ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "��ƽ֮",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               3
        ]),         ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "���չ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


