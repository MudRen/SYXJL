#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "�컨���ܶ�",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               7
        ]),
        ([       "quest":               "�컨���ܶ����",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               6
        ]),
        ([       "quest":               "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               8
        ]),
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
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 920,
                "score" :               6
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
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               7
        ]),

        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               7
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
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               6
        ]),  
        ([      "quest":                "��������",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "��Ѽ",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               8
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


