#include <ansi.h>
inherit SKILL;

mapping *quest = ({
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
        ([      "quest":                "°¢×Ï",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "ÐÇËÞÅÉîàÊÖ",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "²¼ÒÂ",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "Ç°µî",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "µÚÒ»Â¥",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
        ]),         ([      "quest":                "Î¤´º·¼",
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
        ([      "quest":                "Á÷Ã¥Í·",
                "quest_type":           "É±",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

