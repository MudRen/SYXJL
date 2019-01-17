inherit SKILL;

mapping *quest = ({
        ([      "quest":                "·÷³¾",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8   //over
        ]),
        ([      "quest":                "ÎÝ½Ç±ß",
                "quest_type":           "É¨",
                "time":                 680,
                "score" :               10
        ]),
        ([      "quest":                "ÍÁ·ËÎÑ±ß",
                "quest_type":           "É¨",
                "time":                 480,
                "score" :               8
        ]),
        ([      "quest":                "ÆÆÃíÃÜÊÒ",
                "quest_type":           "É¨",
                "time":                 780,
                "score" :               10
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
        ([      "quest":                "¹È³¡»±Ê÷±ß",
                "quest_type":           "É¨",
                "time":                 360,
                "score" :               6
        ]),

        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               14   //over
        ]),
        ([      "quest":                "º£¹«¹«",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               10
        ]),
            ([      "quest":                "É®¹÷",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               9
        ]),
 ([      "quest":                    "ºÚÁú±Þ",
                "quest_type":           "Ñ°",
                "time":                 900,
                 "score" :               11
        ]),
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 900,
                "score" :               9
        ]),
       ([      "quest":                "Ç®ÀÏ±¾",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               10
        ]),
  ([      "quest":                "»¨µñ¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                100,
                "score" :              4
      ]),
        ([      "quest":                "Îä½«",
                "quest_type":           "É±",
                "time":               300,
                "score" :             11
        ]),
        ([      "quest":                "½­°ÙÊ¤",
                "quest_type":           "É±",
                "time":               600,
                "score" :             10
        ]),
        ([      "quest":                "Ìú±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":               1000,
                "score" :             10
        ]),
        ([      "quest":                "Ê·ÇàÉ½",
                "quest_type":           "É±",
                "time":               1000,
                "score" :             8
        ]),
    ([      "quest":                "ÉñÁú½ÌÀÏÕß",
                "quest_type":          "É±",
                "time":                 800,
                "score" :               9
        ]),
    ([      "quest":                "ôÕ×Ó",
                "quest_type":          "Ñ°",
                "time":                 500,
                "score" :               5
        ]),
    ([      "quest":                "½ð»¨",
                "quest_type":          "É±",
                "time":                 800,
                "score" :               7
        ]),
        ([      "quest":                "Ìú»¤Ñü",
                "quest_type":          "Ñ°",
                "time":                 800,
                "score" :               8
        ]),  
       ([      "quest":                "Å®¹Ü¼Ò",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               9
        ]),
   
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

