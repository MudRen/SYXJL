inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8   //over
        ]),
        ([      "quest":                "�ݽǱ�",
                "quest_type":           "ɨ",
                "time":                 680,
                "score" :               10
        ]),
        ([      "quest":                "�����ѱ�",
                "quest_type":           "ɨ",
                "time":                 480,
                "score" :               8
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɨ",
                "time":                 780,
                "score" :               10
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
        ([      "quest":                "�ȳ�������",
                "quest_type":           "ɨ",
                "time":                 360,
                "score" :               6
        ]),

        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               14   //over
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               10
        ]),
            ([      "quest":                "ɮ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               9
        ]),
 ([      "quest":                    "������",
                "quest_type":           "Ѱ",
                "time":                 900,
                 "score" :               11
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               9
        ]),
       ([      "quest":                "Ǯ�ϱ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               10
        ]),
  ([      "quest":                "����ƴ�",
                "quest_type":           "Ѱ",
                "time":                100,
                "score" :              4
      ]),
        ([      "quest":                "�佫",
                "quest_type":           "ɱ",
                "time":               300,
                "score" :             11
        ]),
        ([      "quest":                "����ʤ",
                "quest_type":           "ɱ",
                "time":               600,
                "score" :             10
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":               1000,
                "score" :             10
        ]),
        ([      "quest":                "ʷ��ɽ",
                "quest_type":           "ɱ",
                "time":               1000,
                "score" :             8
        ]),
    ([      "quest":                "����������",
                "quest_type":          "ɱ",
                "time":                 800,
                "score" :               9
        ]),
    ([      "quest":                "����",
                "quest_type":          "Ѱ",
                "time":                 500,
                "score" :               5
        ]),
    ([      "quest":                "��",
                "quest_type":          "ɱ",
                "time":                 800,
                "score" :               7
        ]),
        ([      "quest":                "������",
                "quest_type":          "Ѱ",
                "time":                 800,
                "score" :               8
        ]),  
       ([      "quest":                "Ů�ܼ�",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               9
        ]),
   
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

