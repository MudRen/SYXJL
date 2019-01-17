#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "Ë¾¿ÕÌÃ",
                "quest_type":           "É¨",
                "time":                 120,
                "score" :               20
        ]),
        ([      "quest":                "¶ÎÑÓÇì",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               16
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "Æ«µî",
                "quest_type":           "É¨",
                "time":                 700,
                "score" :               15
        ]),
        ([      "quest":                "Í¥Ôº",
                "quest_type":           "É¨",
                "time":                 120,
                "score" :               18
        ]),
        ([      "quest":                "Ê¨ºð×Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ÕªÐÇ×Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "³ö³¾×Ó",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "°¢×Ï",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Ë¾Í½ÌÃ",
                "quest_type":           "É¨",
                "time":                 120,
                "score" :               10
        ]),
        ([      "quest":                "²è»¨Ô°ÃÅ",
                "quest_type":           "É¨",
                "time":                 140,
                "score" :               10
        ]),
        ([      "quest":                "³¤ÀÈ",
                "quest_type":           "É¨",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Óù»¨Ô°",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "Ç°µî",
                "quest_type":           "É¨",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Õýµî",
                "quest_type":           "É¨",
                "time":                 700,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
