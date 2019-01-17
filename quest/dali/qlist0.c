inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "Æû¹ø¼¦",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               2
        ]),
        ([      "quest":                "ÆÕÍ¨Ø°Ê×",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               4
        ]),
        ([      "quest":                "Á÷Ã¥Í·",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                HIG"Ò¶¶ùôÎ"NOR,
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               3
        ]),       
        ([      "quest":                HIR"ÐûÍþ»ðÍÈ"NOR,
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               5
        ]), 
        ([      "quest":                "ÑþÇÙ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               5
        ]),  
 
        ([      "quest":                "Ì¨ÒÄ¶ÌÈ¹",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "ÄÚÌÃ",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "Å£Æ¤¾Æ´ü",                           "quest_type":           "Ñ°",
                "time":                 240,
                "score" :               2
        ]), 
        ([      "quest":                "Ì¨ÒÄÍ·½í",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "»¨Ìü",
                "quest_type":           "É¨",
                "time":                 780,
                "score" :               5
        ]),
        ([      "quest":                "Ö¸Ì×",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               4
        ]),  
        ([      "quest":                "Í²È¹",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               9
        ]),
        ([      "quest":                "²èºø",
                  "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               4
        ]),
       ([      "quest":                "½ð´´Ò©",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               10
        ]),
       ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 240,
                "score" :               3
        ]),
        ([      "quest":                HIR"ºìÃµ¹å"NOR,
                "quest_type":           "Ñ°",
                "time":                 360,
                "score" :               5
        ]),

  });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
