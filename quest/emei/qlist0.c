inherit SKILL;

mapping *quest = ({
        ([       "quest":               "¿¾¼¦ÍÈ",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "¶Ì½£",
                "quest_type":           "Ñ°",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "½ÓÒýµî",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "ÉñµÆ¸ó",                
                            "quest_type":           "É¨",
                "time":                 100,
                "score" :               2
        ]),
        ([      "quest":                "±±ÀÈ",                
                            "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "Î÷ÀÈ",                
                            "quest_type":           "É¨",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "Ç§·ðâÖ´óµî",                
                            "quest_type":           "É¨",
                "time":                 120,
                "score" :               3
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "Ð¡º¢",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               3
        ]),       
        ([      "quest":                "¸Öµ¶",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "Å®º¢",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "¸Ö½£",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5
        ]),
        ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "°ü×Ó",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "¶Ç´ø",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "²ÝÐ¬",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "ÄÐº¢",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               5
        ]),        
              ([      "quest":                "½ð´´Ò©",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "Ñø¾«µ¤",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "Í­°å",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ÍÃÈâ",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               6        ]),
        ([      "quest":                "ÉÅ·¿ ",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

