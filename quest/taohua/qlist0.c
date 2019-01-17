inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Á÷Ã¥",               
                "quest_type":           "É±",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "¶¾Éß",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "ËÄÊéÎå¾­",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               10
        ]),

        ([      "quest":                "¸¹Éß",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),  
        ([      "quest":                "ÍÁ·Ë",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "ÐÇËÞÅÉºÅÊÖ",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "°ÍÒÀ",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "°ü×Ó",               
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               2
        ]),
        ([      "quest":                "¸Öµ¶",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               4
        ]),
        ([      "quest":                "Ë¼¹ýÊÒ",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                "Ð¡ÎÝ",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               4
        ]),       
        ([      "quest":                "¹éÔÆ×¯Ç°Ôº",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               7
        ]),  
        ([      "quest":                "¿Í·¿",
                "quest_type":           "É¨",
                "time":                 800,
                "score" :               7
        ]),
        ([      "quest":                "´ÞÔ±Íâ",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),           
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];

}
