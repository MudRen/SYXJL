inherit SKILL;

mapping *quest = ({
        ([       "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 60,
                "score" :               2
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               4
        ]),
        ([       "quest":               "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               5
        ]),
        ([       "quest":               "ͭ��",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               3
        ]),

        ([      "quest":                "�̽�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               2
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               6
        ]),    
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               5
        ]),
          ([      "quest":                "Сë¿",
                  "quest_type":           "Ѱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "�ֵ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "��С��",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               8
        ]),
          ([      "quest":                "���䳡",
                  "quest_type":           "ɨ",
                "time":                 600,
                "score" :               10
        ]),
          ([      "quest":                "��ɽ����",
                  "quest_type":           "ɨ",
                "time":                 400,
                "score" :               5
        ]),
          ([      "quest":                "ɯ��ƺ",
                  "quest_type":           "ɨ",
                "time":                 550,
                "score" :               6
        ]),
          ([      "quest":                "�ٳ�Ͽ",
                  "quest_type":           "ɨ",
                "time":                 700,
                "score" :               7
        ]),
          ([      "quest":                "�Ͼ���",
                  "quest_type":           "ɨ",
                "time":                 760,
                "score" :               5
        ]),
          ([      "quest":                "�����",
                  "quest_type":           "ɨ",
                "time":                 780,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}




