#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Ïô¸Õ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "Âí³¬ÐË",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "ÏôÈÍ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "ËÎÔ¶ÇÅ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ÔÀÁéÉº",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               13
        ]),
        ([      "quest":                "¶ÎÓþ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "Ðþ¿à´óÊ¦",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "ÈýÐ¦åÐÒ£É¢",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Ô¿³×",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               12
        ]),
        ([      "quest":                "ÌìÉ½Ñ©Á«",
                "quest_type":           "Ñ°",
                "time":                 1300,
                "score" :               11
        ]),
        ([      "quest":                "·¨ÂÖ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                HIR"É®Ã±"NOR,
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               10
        ]),
        ([      "quest":                "ÈÕÔÂ¶´",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "ÐÇËÞº£ ",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "åÐÒ£¶´",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "É½¶´",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "ºóÃÅ",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

