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
        ([       "quest":               "º£¹«¹«",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "ÒÁÀçÂí",
                "quest_type":           "Ñ°",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "°¢Öì",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
         ([      "quest":                "ÀîÁ¦ÊÀ",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),       
       ([      "quest":                "ÐÛ»Æ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "Öª¿ÍµÀ³¤",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "ÆåÆ×",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "Ì«¼«Ê®ÈýÊÆ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               15
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
        ([       "quest":               "×æÇ§Çï",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "Ð£³¡",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "µÚÒ»Â¥",
                "quest_type":           "É¨",
                "time":                 180,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

