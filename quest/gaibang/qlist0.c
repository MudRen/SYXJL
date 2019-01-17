inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Á÷Ã¥",               
                "quest_type":           "É±",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "ÄÐº¢",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               5
        ]),
        ([      "quest":                "´¢²ØÊÒ",
                "quest_type":           "É¨",
                "time":                 600,
                "score" :               4
        ]),
        ([      "quest":                "ÃÜÊÒ",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               5
        ]),
        ([      "quest":                "Ê÷¶´ÄÚ²¿",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               3
        ]),
        ([      "quest":                "Ê÷¶´ÏÂ",
                "quest_type":           "É¨",
                "time":                 900,
                "score" :               4
        ]),
        ([      "quest":                "´óÌüÅÔ",
                "quest_type":           "É¨",
                "time":                 660,
                "score" :               2
        ]),
        ([      "quest":                "ÌúÇ¹ÃíÏÂ",
                "quest_type":           "É¨",
                "time":                  340,
                "score" :               5
        ]),

        ([      "quest":                "Âô»¨¹ÃÄï",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               12
        ]),       
        ([      "quest":                "µÀÍ¯",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),  
        ([      "quest":                "Ð¡··",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "Ìô·ò",
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
        ([      "quest":                "ÍÁµØÃí",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                "´óÀÇ¹·",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),           
        ([      "quest":                "·Ûºì³ñÉÀ",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               6
        ]),           
        ([      "quest":                "Ðå»¨Õë",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               4
        ]),           
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];

}


