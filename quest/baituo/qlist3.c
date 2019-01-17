#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ÑÆ²®",               
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),
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
        ([      "quest":                "ÔÀ²»Èº",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Áîºü³å",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶ÎÓþ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),

        ([      "quest":                "ÎäÆ÷¿â",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               9
        ]),
        ([      "quest":                "ÃÅÀÈ",
                "quest_type":           "É¨",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":                "Á·¹¦³¡",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               9
        ]),
        ([      "quest":                "Ðþ±¯´óÊ¦",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ºéÆß¹«",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               12
        ]),
        ([      "quest":                "¼ÎÄ¾»î·ð",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               14
        ]),
        ([      "quest":                "´ï¶û°Í",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               11
        ]),
        ([      "quest":                "ÕÅÈý·á",
                "quest_type":           "É±",
                "time":                 870,
                "score" :               15
        ]),
        ([       "quest":               "¶ÎÑÓÇì",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               11
        ]),
        ([       "quest":               "²¨Ë¹³¤ÅÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "¶·Åñ",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               8
        ]),
        ([       "quest":               HIR"ºìÉ«ôÂôÄ"NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               13
        ]),           
        ([       "quest":               MAG "×ÏÉ«ôÂôÄ" NOR,
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               14
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
