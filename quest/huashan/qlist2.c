inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "�佫",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               12
        ]),     
        ([      "quest":                "������ʿ",
                "quest_type":           "ɱ",
                "time":                 450,
                "score" :               13
        ]), 
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               9
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               9
        ]),    
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]), 
        ([      "quest":                "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 650,
                "score" :               10
        ]),       
         ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),       
         ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 850,
                "score" :               7
        ]),       
         ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 650,
                "score" :               10
        ]),       
         ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 790,
                "score" :               11
        ]),       
       
          ([      "quest":                "������",
                  "quest_type":           "ɨ",
                "time":                 560,
                "score" :               7
        ]),
          ([      "quest":                "��ɽС��",
                  "quest_type":           "ɨ",
                "time":                 600,
                "score" :               12
        ]),
          ([      "quest":                "ǧ�ߴ�",
                  "quest_type":           "ɨ",
                "time":                 520,
                "score" :               8
        ]),
          ([      "quest":                "��Ů��",
                  "quest_type":           "ɨ",
                "time":                 510,
                "score" :               10
        ]),
          ([      "quest":                "��Ů��",
                  "quest_type":           "ɨ",
                "time":                 520,
                "score" :               6
        ]),

        ([      "quest":                "С����",
                "quest_type":           "Ѱ",
                "time":                 980,
                "score" :               11
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

