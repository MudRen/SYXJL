#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "�Ʋ�",               
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               12
        ]), 
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 850,
                "score" :               10
        ]),       
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 550,
                "score" :               11
        ]),       
        ([      "quest":                HIW"ѩ��"NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               12
        ]),       
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 550,
                "score" :               10
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
        ([      "quest":                "������ʦ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               7
        ]),
        ([       "quest":               "�컨���ܶ����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               12
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               10
        ]),
        ([       "quest":               "Ͽ��",
                "quest_type":           "ɨ",
                "time":                 120,
                "score" :               11
        ]),
        ([       "quest":               "����Ͽ",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               9
        ]),
        ([       "quest":               "��Ϣ��",
                "quest_type":           "ɨ",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               15
        ]),  
        ([      "quest":                "��Ө��",
                "quest_type":           "ɱ",
                "time":                 1500,
                "score" :               15
        ]),  
        ([      "quest":                "���߹�",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),  

           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
