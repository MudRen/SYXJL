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
        ([      "quest":                HIW"·üÄ§µ¶"NOR,
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "½ð¸ÕÕÖ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               15
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
        ([      "quest":                "Ðþ±¯´óÊ¦",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

