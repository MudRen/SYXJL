inherit SKILL;
#include <ansi.h>  

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 780,
                "score" :               20
        ]),
        ([       "quest":               "ŷ����",
                "quest_type":           "ɱ",
                "time":                 760,
                "score" :               14
        ]),
        ([       "quest":               "������",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               15
        ]),
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 750,
                "score" :               15
        ]),
        ([       "quest":               "���߹�",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               20
        ]),

          ([      "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               12
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               14
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 540,
                "score" :               11
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 850,
                "score" :               16
        ]),       
          ([      "quest":                "��Ů��",
                  "quest_type":           "ɨ",
                "time":                 550,
                "score" :               11
        ]),  
          ([      "quest":                "˼����",
                  "quest_type":           "ɨ",
                "time":                 400,
                "score" :               15
        ]),
          ([      "quest":                "���ƺ",
                  "quest_type":           "ɨ",
                "time":                 660,
                "score" :               15
        ]),
          ([      "quest":                "������",
                  "quest_type":           "ɨ",
                "time":                 600,
                "score" :               15
        ]),
          ([      "quest":                "������",
                  "quest_type":           "ɨ",
                "time":                 610,
                "score" :               15
        ]),

        ([      "quest":                HIY"����"NOR,
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               19
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               14
        ]),
        ([      "quest":                HIW"����"NOR,
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               14
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               16
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

