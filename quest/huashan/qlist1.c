#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":               "С��",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               8
        ]),        
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]), 
        ([      "quest":               "���",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               8
        ]),    
        ([      "quest":               "�ٱ�",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               9
        ]),          
        ([      "quest":               "��ͯ",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               6
        ]),       
         ([      "quest":               "�ο�",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
       ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               6
        ]),
       ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               5
        ]),

        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),       
          ([      "quest":                "���䳡",
                  "quest_type":           "ɨ",
                "time":                 400,
                "score" :               7
        ]),  
          ([      "quest":                "������",
                  "quest_type":           "ɨ",
                "time":                 500,
                "score" :               8
        ]),  
          ([      "quest":                "ɽ���ٲ�",
                  "quest_type":           "ɨ",
                "time":                 470,
                "score" :               9
        ]),  
          ([      "quest":                "��ȪԺ",
                  "quest_type":           "ɨ",
                "time":                 430,
                "score" :               10
        ]),  

        ([      "quest":                "���չ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               4
        ]),
          ([      "quest":                "����",
                  "quest_type":           "ɨ",
                "time":                 650,
                "score" :               9
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               8
        ]),  
        ([      "quest":                "�廨Ь",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               9
        ]),  
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               10
        ]),  
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
