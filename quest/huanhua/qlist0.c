inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
         ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
         ([      "quest":                "���¾����Ͼ�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
         ([      "quest":                "�����޶������ϲ᡽��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
         ([      "quest":                "�廨СЬ",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
 	
        ([      "quest":                "��å",               
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "�����徭",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),  
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "�����ɺ���",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "����",               
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "�ֵ�",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               4
        ]),
          ([      "quest":                "���춴",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
          ([      "quest":                "��ɽ",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               4
        ]),       
          ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               7
        ]),  
          ([      "quest":                "�᷿",
                "quest_type":           "ɨ",
                "time":                 800,
                "score" :               7
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),           
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];

}
