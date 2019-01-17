#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ÑîåÐ",               
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "¶¡´ºÇï",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "Î¤Ò»Ð¦",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":               "°¢À­²®Íäµ¶",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ÌÒÄ¾½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
         ([      "quest":               "·Ûºì³ñÉÀ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "½ðÏîÁ´",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        
        ([      "quest":               "Î¬Îá¶û×å³¤ÅÛ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "¹âÃ÷µ¶",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        
        ([      "quest":                "ÅÐ¹Ù±Ê",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "Ê´»êÐÇ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "ÓñµÑ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "Éßµ¨¸à",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),                  
        ([      "quest":                "¼Ö²¼",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "¼ÆÎÞÊ©",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¡ºÐÇËÞ¶¾¾­¡¼ÉÏ²á¡½¡»",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ÀÏÍ·×Ó",
               "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Ë¾Âí´ó",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}



