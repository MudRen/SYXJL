inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([       "quest":               "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "Å·Ñô·æ",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               20
        ]),
        ([      "quest":                "ÀèÉú",
                "quest_type":           "É±",
                "time":                 550,
                "score" :               11
        ]),
        ([      "quest":                "»ô¶¼",
                "quest_type":           "É±",
                "time":                 550,
                "score" :               11
        ]),
        ([      "quest":                HIG "ÊÖïí" NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               18
        ]),
        ([      "quest":                RED"Ô²ÕæµÄÈËÍ·"NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               18
        ]),
        ([      "quest":                "Êé·¿",
                  "quest_type":           "É¨",
                "time":                 300,
                "score" :               11
        ]),
        ([      "quest":                "¾²ÊÒ",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "´óÌü",
                "quest_type":           "É¨",
                "time":                 260,
                "score" :               12
        ]),
        ([      "quest":                "»¤·¨ôÂôÄ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               9
        ]),
        ([      "quest":                "ÇåÐÄÉ¢",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "¶ÎÓþ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               12
        ]),
        ([      "quest":                "¹ÈÐéµÀ³¤",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
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
        ([      "quest":                "ÉñÕÕÉÏÈË",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "¸ß¸ùÃ÷",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "ÕªÐÇ×Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               17
        ]),
        ([      "quest":                "Ê¨ºð×Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "Ïô·å",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "²¼ÕóÏä",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                HIW"±ùÆÇÉñÕë"NOR,
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "±ÌÁ×ÐÇ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "¹ËÑ×Îä",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "ÎâÁùÆæ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "Á·Îä³¡",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "±±Ôº",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "³ø·¿",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "Ïá·¿",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "ÄÏÔº",
                "quest_type":           "É¨",
                "time":                 340,
                "score" :               11
        ]),
        ([      "quest":                "ºÚ¹Ú¾Þòþ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "ÎèÉßÈË",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "Â³ÓÐ½Å",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
