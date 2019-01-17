inherit SKILL;
#include <ansi.h>  

mapping *quest = ({
        ([       "quest":               "Ðþ¿à",
                "quest_type":           "É±",
                "time":                 780,
                "score" :               20
        ]),
        ([       "quest":               "Å·Ñô·æ",
                "quest_type":           "É±",
                "time":                 760,
                "score" :               14
        ]),
        ([       "quest":               "¶ÎÑÓÇì",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               15
        ]),
        ([       "quest":               "Ïô·å",
                "quest_type":           "É±",
                "time":                 750,
                "score" :               15
        ]),
        ([       "quest":               "ºéÆß¹«",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               20
        ]),

          ([      "quest":               "¶·Åñ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               12
        ]),
        ([      "quest":                "¶¡´ºÇï",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               14
        ]),
        ([      "quest":                "ÀèÉú",
                "quest_type":           "É±",
                "time":                 540,
                "score" :               11
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 850,
                "score" :               16
        ]),       
          ([      "quest":                "ÓñÅ®·å",
                  "quest_type":           "É¨",
                "time":                 550,
                "score" :               11
        ]),  
          ([      "quest":                "Ë¼¹ýÑÂ",
                  "quest_type":           "É¨",
                "time":                 400,
                "score" :               15
        ]),
          ([      "quest":                "Çà¿ÂÆº",
                  "quest_type":           "É¨",
                "time":                 660,
                "score" :               15
        ]),
          ([      "quest":                "³¯Ñô·å",
                  "quest_type":           "É¨",
                "time":                 600,
                "score" :               15
        ]),
          ([      "quest":                "ÕòÔÀ¹¬",
                  "quest_type":           "É¨",
                "time":                 610,
                "score" :               15
        ]),

        ([      "quest":                HIY"½ðÂÖ"NOR,
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               19
        ]),
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               14
        ]),
        ([      "quest":                HIW"ÒøÂÖ"NOR,
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               14
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               16
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

