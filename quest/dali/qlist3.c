#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ŷ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "˾����",
                "quest_type":           "ɨ",
                "time":                 120,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               16
        ]),
        ([      "quest":                "ҹ����",
                "quest_type":           "Ѱ",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "ƫ��",
                "quest_type":           "ɨ",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "ͥԺ",
                "quest_type":           "ɨ",
                "time":                 120,
                "score" :               18
        ]),
        ([      "quest":                "ʨ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ժ����",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "˾ͽ��",
                "quest_type":           "ɨ",
                "time":                 120,
                "score" :               10
        ]),
        ([      "quest":                "�軨԰��",
                "quest_type":           "ɨ",
                "time":                 140,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����԰",
                "quest_type":           "ɨ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "ǰ��",
                "quest_type":           "ɨ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 700,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
