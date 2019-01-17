inherit SKILL;

mapping *quest = ({
        ([       "quest":               "¿¾¼¦ÍÈ",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([       "quest":               "²¼ÒÂ",
                "quest_type":           "Ñ°",
                "time":                 100,
                "score" :               4
        ]),
        ([       "quest":               "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               5
        ]),
        ([       "quest":               "Í­°å",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               3
        ]),

        ([      "quest":                "¶Ì½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               2
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "Âô»¨¹ÃÄï",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               6
        ]),    
        ([      "quest":                "Ð¡º¢",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               5
        ]),
          ([      "quest":                "Ð¡Ã«Â¿",
                  "quest_type":           "Ñ°",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "¸Öµ¶",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "ÍõÐ¡¶þ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),
          ([      "quest":                "Á·Îä³¡",
                  "quest_type":           "É¨",
                "time":                 600,
                "score" :               10
        ]),
          ([      "quest":                "»ªÉ½½ÅÏÂ",
                  "quest_type":           "É¨",
                "time":                 400,
                "score" :               5
        ]),
          ([      "quest":                "É¯ÂÜÆº",
                  "quest_type":           "É¨",
                "time":                 550,
                "score" :               6
        ]),
          ([      "quest":                "°Ù³ßÏ¿",
                  "quest_type":           "É¨",
                "time":                 700,
                "score" :               7
        ]),
          ([      "quest":                "ÀÏ¾ý¹µ",
                  "quest_type":           "É¨",
                "time":                 760,
                "score" :               5
        ]),
          ([      "quest":                "â©áø³î",
                  "quest_type":           "É¨",
                "time":                 780,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}




