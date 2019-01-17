inherit SKILL;

mapping *quest = ({
   ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               5
        ]),
       ([      "quest":                "°ÍÒÀ",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               15   //over
        ]),
                ([      "quest":                "·÷³¾",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               5   //over
        ]),
        ([      "quest":                "½ð½äÖ¸",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               5   //over
        ]),
                ([      "quest":                "´ÞÔ±Íâ",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "º£¹«¹«",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               20
        ]),
                ([      "quest":                "ÆëÃ¼¹÷",
                "quest_type":          "Ñ°",
                "time":                 800,
                "score" :               5
        ]),
                ([      "quest":                "´ÞÝºÝº",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
  ([      "quest":                "½äµ¶",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               5
        ]),
       ([      "quest":                "°¢·²Ìá",
                "quest_type":           "É±",
                "time":                 620,
                "score" :               5
        ]),
          ([      "quest":            "ÎÚÑ»",
                "quest_type":           "É±",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "ÑÃÒÛ·þ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               5
        ]),
       ([      "quest":                "Ç®ÀÏ±¾",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
       ([      "quest":                "¼Ò¶¡",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               7
        ]),
      ([      "quest":                "À®Âï",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               8
        ]),
      ([      "quest":                "¸ßÑå³¬",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               8
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
      
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

