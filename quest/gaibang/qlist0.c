inherit SKILL;

mapping *quest = ({
        ([      "quest":                "��å",               
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "�к�",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               5
        ]),
        ([      "quest":                "�����ڲ�",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               3
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 900,
                "score" :               4
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 660,
                "score" :               2
        ]),
        ([      "quest":                "��ǹ����",
                "quest_type":           "ɨ",
                "time":                  340,
                "score" :               5
        ]),

        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               12
        ]),       
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),  
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "����",
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
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                "���ǹ�",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),           
        ([      "quest":                "�ۺ����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               6
        ]),           
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               4
        ]),           
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];

}


