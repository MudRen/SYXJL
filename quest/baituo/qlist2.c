#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "Ïô·å",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "ÑÒ¶´ÄÚ",
                "quest_type":           "É¨",
                "time":                 400,
                "score" :               8
        ]),
        ([      "quest":                "ºóÃÅ",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               9
        ]),
        ([      "quest":                "ÖñÔ°",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               9
        ]),

([      "quest":                "±ÌË®½£",
                "quest_type":           "Ñ°",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "¸ß¸ùÃ÷",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "Âí³¬ÐË",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                "±ÌË®½£",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "Î÷»ª×Ó",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "òþÉß",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               8
        ]),

        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "ÔÆÁú¾­¡¸ÉÏ¾í¡¹",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "Ì«¼«Ê®ÈýÊÆ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               9        
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
        ([       "quest":               "Ê©´÷×Ó",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "éÔ·ò",                            "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([       "quest":               "ÐìÌì´¨",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([       "quest":               "¹ÈÐéµÀ³¤",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

