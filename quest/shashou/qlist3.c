#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ΤһЦ",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":               "�������䵶",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
         ([      "quest":               "�ۺ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        
        ([      "quest":               "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        
        ([      "quest":                "�йٱ�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ʴ����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "�ߵ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),                  
        ([      "quest":                "�ֲ�",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "����ʩ",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�����޶������ϲ᡽��",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "��ͷ��",
               "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "˾���",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}



