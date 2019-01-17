inherit SKILL;

mapping *quest = ({
       ([      "quest":                "ÑòÈâ´®",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               5   //over
        ]),
        ([      "quest":                "´óÌüÏÂ",
                "quest_type":           "É¨",
                "time":                 680,
                "score" :               7
        ]),
        ([      "quest":                "ÉáÉíÑÂÏÂ",
                "quest_type":           "É¨",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "ÍÁ·ËÎÑ±ß",
                "quest_type":           "É¨",
                "time":                 960,
                "score" :               7
        ]),
        ([      "quest":                "¹È³¡»±Ê÷±ß",
                "quest_type":           "É¨",
                "time":                 360,
                "score" :               6
        ]),
        ([      "quest":                "ÆÆÃíÃÜÊÒ",
                "quest_type":           "É¨",
                "time":                 460,
                "score" :               5
        ]),

        ([      "quest":                "½ð½äÖ¸",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               5   //over
        ]),
        ([      "quest":                "´ÞÔ±Íâ",
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
             ([      "quest":                "¿¾Ñ¼",
                "quest_type":           "Ñ°",
                "time":                 300,
                 "score" :               5
        ]),
        ([      "quest":                "ÑÃÒÛ·þ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               5
        ]),
          ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                100,
                "score" :              5
      ]),
       ([      "quest":                "¼Ò¶¡",
                "quest_type":           "É±",
                "time":                 300,
                "score" :              15
        ]),
        ([      "quest":                "Ñ¾»·",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "»ï¼Æ",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "µêÐ¡¶þ",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "Ìú±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":               300,
                "score" :             5
        ]),
    ([      "quest":                "ôÕ×Ó",
                "quest_type":          "Ñ°",
                "time":                 200,
                "score" :               5
        ]),
    ([      "quest":                "½ð»¨",
                "quest_type":          "É±",
                "time":                 800,
                "score" :               5
        ]),
    ([      "quest":                "Ìú»¤Ñü",
                "quest_type":          "Ñ°",
                "time":                 800,
                "score" :               5
        ]),  
   ([      "quest":                "Å®¹Ü¼Ò",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
    
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


