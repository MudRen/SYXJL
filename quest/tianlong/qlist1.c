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
        ([      "quest":		"Ìú¼×",               
                "quest_type":           "Ñ°",
                "time":  		300,
                "score"	:		6,
        ]),
        ([      "quest":                "¸Ö½£",
                "quest_type":           "Ñ°",
                "time":                 360,
                "score" :               6,
        ]),
        ([      "quest":                "ÄÁÑò±Þ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               5,
        ]),
        ([      "quest":                "Ë®ÃÛÌÒ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               3,
        ]),
        ([      "quest":                "»ªÉ½½£Æ×",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               5,
        ]),       
        ([      "quest":                "ÒÁÀçÂí",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               5
        ]),  
        ([      "quest":                "Ê¯°å",
                "quest_type":           "Ñ°",
                "time":                 480,
                "score" :               7,
        ]),
        ([      "quest":                "Èðº×ÃÅ",
                "quest_type":           "É¨",
                "time":                 410,
                "score" :               6,
        ]),
        ([      "quest":                "ÎÞ³£¸ó",
                "quest_type":           "É¨",
                "time":                 410,
                "score" :               6,
        ]),
        ([      "quest":                "»ÎÌìÃÅ",
                "quest_type":           "É¨",
                "time":                 410,
                "score" :               6,
        ]),


           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
