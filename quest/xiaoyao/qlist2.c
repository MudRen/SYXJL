#include <ansi.h>
inherit SKILL;

mapping *quest = ({
          ([       "quest":               "ÕÅÈý",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "Ìú»¤Ñü",
                "quest_type":           "Ñ°",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "³ö³¾×Ó",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "ÍÁ·ËÍ·",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                "Ñ²É½µÜ×Ó",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "ä½»¨½£Æ×",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "ÈýÐ¦åÐÒ£É¢",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "Ò©³ú",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
          ([       "quest":               "ÑÒ·ì",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               5
        ]),
          ([       "quest":               "¹Èµ×",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               6
        ]),
          ([       "quest":               "ºþ±ß",
                "quest_type":           "É¨",
                "time":                 360,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
