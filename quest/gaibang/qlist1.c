inherit SKILL;

mapping *quest = ({
       ([      "quest":                "���⴮",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               5   //over
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 680,
                "score" :               7
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "�����ѱ�",
                "quest_type":           "ɨ",
                "time":                 960,
                "score" :               7
        ]),
        ([      "quest":                "�ȳ�������",
                "quest_type":           "ɨ",
                "time":                 360,
                "score" :               6
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 460,
                "score" :               5
        ]),

        ([      "quest":                "���ָ",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               5   //over
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
             ([      "quest":                "�䵶",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               5
        ]),
       ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 620,
                "score" :               5
        ]),
             ([      "quest":                "��Ѽ",
                "quest_type":           "Ѱ",
                "time":                 300,
                 "score" :               5
        ]),
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               5
        ]),
          ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                100,
                "score" :              5
      ]),
       ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :              15
        ]),
        ([      "quest":                "Ѿ��",
                "quest_type":           "ɱ",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "��С��",
                "quest_type":           "ɱ",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":               300,
                "score" :             5
        ]),
    ([      "quest":                "����",
                "quest_type":          "Ѱ",
                "time":                 200,
                "score" :               5
        ]),
    ([      "quest":                "��",
                "quest_type":          "ɱ",
                "time":                 800,
                "score" :               5
        ]),
    ([      "quest":                "������",
                "quest_type":          "Ѱ",
                "time":                 800,
                "score" :               5
        ]),  
   ([      "quest":                "Ů�ܼ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
    
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


