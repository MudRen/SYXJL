#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "��Զ��",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "����ɺ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               13
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "�����ʦ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "��Ц��ңɢ",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Կ��",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               12
        ]),
        ([      "quest":                "��ɽѩ��",
                "quest_type":           "Ѱ",
                "time":                 1300,
                "score" :               11
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                HIR"ɮñ"NOR,
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               10
        ]),
        ([      "quest":                "���¶�",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "���޺� ",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "��ң��",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "ɽ��",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 1200,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

