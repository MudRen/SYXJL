inherit SKILL;

mapping *quest = ({
   ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               5
        ]),
       ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 650,
                "score" :               15   //over
        ]),
                ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               5   //over
        ]),
        ([      "quest":                "���ָ",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               5   //over
        ]),
                ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               20
        ]),
                ([      "quest":                "��ü��",
                "quest_type":          "Ѱ",
                "time":                 800,
                "score" :               5
        ]),
                ([      "quest":                "��ݺݺ",
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
          ([      "quest":            "��ѻ",
                "quest_type":           "ɱ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "���۷�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               5
        ]),
       ([      "quest":                "Ǯ�ϱ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
       ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               7
        ]),
      ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               8
        ]),
      ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "˼����",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               4
        ]),       
        ([      "quest":                "����ׯǰԺ",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               7
        ]),  
        ([      "quest":                "�ͷ�",
                "quest_type":           "ɨ",
                "time":                 800,
                "score" :               7
        ]),
      
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

