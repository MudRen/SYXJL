#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "�������䵶",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 240,
                "score" :               3
        ]),
         ([      "quest":               "�ۺ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               3
        ]),
        
        ([      "quest":               "��˹����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               3
        ]),
        
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               3
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               8
        ]),       
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),                      
        ([      "quest":                "���ָ",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                HIW"���ƺͷ�"NOR,
                "quest_type":           "Ѱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               5
        ]),
        ([      "quest":                "��ʿ",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               3
        ]),         ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "ҩ��",
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
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
