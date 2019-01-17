inherit SKILL;

mapping *quest = ({
       ([      "quest":                "½ðÉßµ¨",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5   //over
        ]),
       ([      "quest":                "ÇàÉßµ¨",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5   //over
        ]),
       ([      "quest":                "°×É«³¤ÅÛ",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5   //over
        ]),
       ([      "quest":                "´óµ¶",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5   //over
        ]),
       ([      "quest":                "³¤±Þ",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               5   //over
        ]),
	
       ([      "quest":                "·÷³¾",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               5   //over
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
        ([      "quest":                "º£¹«¹«",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               20
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
 ([      "quest":                    "ºÚÁú±Þ",
                "quest_type":           "Ñ°",
                "time":                 300,
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
        ([      "quest":                "Îä½«",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "½­°ÙÊ¤",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "Ìú±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "Ã½ÆÅ",
                "quest_type":           "É±",
                "time":               300,
                "score" :             5
        ]),
        ([      "quest":                "Ïã²è",
                "quest_type":           "Ñ°",
                "time":               300,
                "score" :             5
        ]),
    ([      "quest":                "ÉñÁú½ÌÀÏÕß",
                "quest_type":          "É±",
                "time":                 800,
                "score" :               5
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
