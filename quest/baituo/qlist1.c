#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "�ٱ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "����ʤ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "Сɳ��",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               3
        ]),         
        ([      "quest":                "С���",
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
        ([      "quest":                "�廨Ь",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 590,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               3
        ]),
        ([      "quest":                "�߱�",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               4
        ]),
        ([      "quest":                "�˻���",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "ũ�Ҹ�Ů",
                "quest_type":           "ɱ",
                "time":                 650,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

