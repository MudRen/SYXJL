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
        ([      "quest":		"ÌúÊÖÕÆ",               
                "quest_type":           "Ñ°",
                "time":  		60,
                "score"	:		2,
                
        ]),
        ([      "quest":                "¾ÉÖñÆ¬",
                "quest_type":           "Ñ°",
                "time":                 360,
                "score" :               4
        ]),
        ([      "quest":                "³çÊ¥±¦µî",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               4,
        ]),
        ([      "quest":                "·¨»ª¾­",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               4
        ]),
        ([      "quest":                "½ð¸Õ¾­",
                "quest_type":           "Ñ°",
                "time":                 150,
                "score" :               5
        ]),  
        ([      "quest":                "Ïèº×ÃÅ",
                "quest_type":           "É¨",
                "time":                 150,
                "score" :               5,
        ]),
        ([      "quest":                "±¡¾î",
                "quest_type":           "Ñ°",
                "time":                 210,
                "score" :               6
        ]),
        ([      "quest":                "Èðº×ÃÅ",
                "quest_type":           "É¨",
                "time":                 210,
                "score" :               6,
        ]),
           

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
