#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "���",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "��Ƹ�",
                "quest_type":           "ɨ",
                "time":                 120,
                "score" :               5
        ]),
        ([      "quest":                "��԰",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               4
        ]),

        ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               3
        ]),        
             ([      "quest":                "Τ����",
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
        ([      "quest":                "����ƴ�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "����ͷ",
                "quest_type":           "Ѱ",
                "time":                 230,
                "score" :               5
        ]),

        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 650,
                "score" :               4
        ]),
        ([      "quest":                "�ٱ�",
                "quest_type":           "ɱ",
                "time":                 850,
                "score" :               7
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

