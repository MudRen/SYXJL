#include <ansi.h>

inherit SKILL;

mapping *quest = ({
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
        ([      "quest":		"������",               
                "quest_type":           "Ѱ",
                "time":  		60,
                "score"	:		2,
                
        ]),
        ([      "quest":                "����Ƭ",
                "quest_type":           "Ѱ",
                "time":                 360,
                "score" :               4
        ]),
        ([      "quest":                "��ʥ����",
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               4,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               4
        ]),
        ([      "quest":                "��վ�",
                "quest_type":           "Ѱ",
                "time":                 150,
                "score" :               5
        ]),  
        ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 150,
                "score" :               5,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 210,
                "score" :               6
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 210,
                "score" :               6,
        ]),
           

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
