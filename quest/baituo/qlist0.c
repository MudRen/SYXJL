inherit SKILL;

mapping *quest = ({
        ([       "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "�̽�",
                "quest_type":           "Ѱ",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "����",                
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               2
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 320,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               3
        ]),       
        ([      "quest":                "�ֵ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "�ֽ�",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               5
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "�Ǵ�",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "�ߵ���",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "�Ѹ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               5
        ]),        
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "��ݮ",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               6        
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

