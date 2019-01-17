#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Ïô·å",               
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ÐÇËÞÀÏ¹Ö",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "Ðì´ï",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               16
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "Âí³¬ÐË",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               18
        ]),  
        ([      "quest":                "¶ÎÓþ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶ÎÑÓÇì",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([       "quest":               "ÅþÂ¬µî",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               10
        ]),
        ([       "quest":               "ÇåÒô¸ó",
                "quest_type":           "É¨",
                "time":                 1200,
                "score" :               11
        ]),
        ([       "quest":               "ÉñË®¸ó",
                "quest_type":           "É¨",
                "time":                 400,
                "score" :               13
        ]),
        ([       "quest":               "ÍòÄêâÖ",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               9
        ]),
        ([       "quest":               "¹éÔÆ¸ó",
                "quest_type":           "É¨",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶·Åñ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "´ó³ËÄùÅÍ¾­",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               13
        ]),
        ([      "quest":                "±ÌË®½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               15
        ]),
        ([      "quest":                "ÐéÖñ",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               18
        ]),
        ([      "quest":                "°¢×Ï",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               16
        ]),
        ([      "quest":                "ð¯Ä¦ÖÇ",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               16
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
