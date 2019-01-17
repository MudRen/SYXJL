inherit SKILL;

mapping *quest = ({
        ([       "quest":               "»ô¶¼",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "ÕªÐÇ×Ó",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Îä½«",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               12
        ]),     
        ([      "quest":                "ÇàÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 450,
                "score" :               13
        ]), 
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               9
        ]),
        ([      "quest":                "Âí³¬ÐË",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               9
        ]),    
        ([      "quest":                "ÀîÁ¦ÊÀ",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "ôÃÍò¼Ò",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]), 
        ([      "quest":                "Ò©³ú",
                "quest_type":           "Ñ°",
                "time":                 650,
                "score" :               10
        ]),       
         ([      "quest":                "ÑòÈâ´®",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),       
         ([      "quest":                "ÌúÊÖÕÆ",
                "quest_type":           "Ñ°",
                "time":                 850,
                "score" :               7
        ]),       
         ([      "quest":                "Öñ½£",
                "quest_type":           "Ñ°",
                "time":                 650,
                "score" :               10
        ]),       
         ([      "quest":                "·÷³¾",
                "quest_type":           "Ñ°",
                "time":                 790,
                "score" :               11
        ]),       
       
          ([      "quest":                "ÉáÉíÑÂ",
                  "quest_type":           "É¨",
                "time":                 560,
                "score" :               7
        ]),
          ([      "quest":                "»ªÉ½Ð¡Öþ",
                  "quest_type":           "É¨",
                "time":                 600,
                "score" :               12
        ]),
          ([      "quest":                "Ç§³ß´±",
                  "quest_type":           "É¨",
                "time":                 520,
                "score" :               8
        ]),
          ([      "quest":                "ÓñÅ®ìô",
                  "quest_type":           "É¨",
                "time":                 510,
                "score" :               10
        ]),
          ([      "quest":                "ÓñÅ®·å",
                  "quest_type":           "É¨",
                "time":                 520,
                "score" :               6
        ]),

        ([      "quest":                "Ð¡»¹µ¤",
                "quest_type":           "Ñ°",
                "time":                 980,
                "score" :               11
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

