#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶·Åñ",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               11
        ]),
        ([      "quest":                "ÇàÒÂ",
                "quest_type":           "Ñ°",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                HIY"½ðÂÖ"NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               12
        ]),
        ([      "quest":                HIW"ÒøÂÖ"NOR,
                "quest_type":           "Ñ°",
                "time":                 1100,
                "score" :               11
        ]),

        ([      "quest":                "¡ºÐÇËÞ¶¾¾­¡¼ÉÏ²á¡½¡»",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([       "quest":               "¶ÎÓþ",
                "quest_type":           "É±",
                "time":                 360,
                "score" :               6
        ]),

        ([      "quest":                "Ãæ¾ß",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ÕÅÈý",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ºÚÉ«ôÂôÄ",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶¡´ºÇï",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
           
        ([      "quest":                "çÎç¿·åÉ½½Å",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "¶Ï»êÑÂ",
                "quest_type":           "É¨",
                "time":                 400,
                "score" :               11
        ]),
        ([      "quest":                "¶À×ðÌü´óÃÅ",
                "quest_type":           "É¨",
                "time":                 550,
                "score" :               14
        ]),
        ([      "quest":                "Ïô·å",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "¶ÎÑÓÇì",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "½ðÂÖ·¨Íõ",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               11
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
