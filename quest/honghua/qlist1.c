#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "ºì»¨»á×Ü¶æ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               7
        ]),
        ([       "quest":               "ºì»¨»á×Ü¶æ´óÃÅ",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               6
        ]),
        ([       "quest":               "×ßÀÈ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               8
        ]),
        ([      "quest":               "ÊéÉú",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "Âô»¨¹ÃÄï",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "ÕÅÂè",
                "quest_type":           "É±",
                "time":                 920,
                "score" :               6
        ]),
        ([      "quest":                "²¼ÒÂ",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "½øÏã¿Í",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "Ð¡··",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "Ìô·ò",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               6
        ]),
        ([      "quest":                "½£¿Í",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               7
        ]),

        ([      "quest":                "µÀÍ¯",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               7
        ]),      
             ([      "quest":                "Î¤´º·¼",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ìú¼×",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "¸ÖÕÈ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]), 
        ([      "quest":                "ÑÃÒÛ·þ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               6
        ]),  
        ([      "quest":                "ËÉÊó÷¬Óã",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "¿¾Ñ¼",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               8
        ]),  
 
        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "ÑÃÒÛ",
                "quest_type":           "É±",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


