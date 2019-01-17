#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "´å¹Ã",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "²¨Ë¹ÉÌÈË",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "Âô»¨¹ÃÄï",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "²¼ÒÂ",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "ºóµî",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "½ÓÒýµî",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "ÉñµÆ¸ó",
                "quest_type":           "É¨",
                "time":                 120,
                "score" :               5
        ]),
        ([      "quest":                "ºóÔ°",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               4
        ]),

        ([      "quest":                "ÎÄÊâµî",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
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
        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "»¨µñ¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "¼¦¹ÇÍ·",
                "quest_type":           "Ñ°",
                "time":                 230,
                "score" :               5
        ]),

        ([      "quest":                "Á÷Ã¥Í·",
                "quest_type":           "É±",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "ÑÃÒÛ",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               4
        ]),
        ([      "quest":                "¹Ù±ø",
                "quest_type":           "É±",
                "time":                 850,
                "score" :               7
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

