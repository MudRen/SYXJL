#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               6
        ]),
        ([      "quest":                "ɳ��",
                "quest_type":           "ɱ",
                "time":                 660,
                "score" :               6
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "ɱ",
                "time":                 560,
                "score" :               8
        ]),
        ([      "quest":                "���ͷ",
                "quest_type":           "ɱ",
                "time":                 860,
                "score" :               9
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "���ǽ���<�¾�>",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "��Ц��ңɢ",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "�����ɹ���",
                "quest_type":           "ɱ",
                "time":                 620,
                "score" :               10
        ]),
        ([      "quest":                "�����ɺ���",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               10
        ]),
        ([      "quest":                "׺����",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "ޤ����",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               8
        ]),
        ([      "quest":                "�ɳ���",
                "quest_type":           "ɨ",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "��ɫ����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               8
        ]),
        ([       "quest":               "�廨Ь",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               11
        ]),
        ([       "quest":               "���⴮",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

