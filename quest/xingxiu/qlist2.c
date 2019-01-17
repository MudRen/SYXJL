#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "ÀèÉú",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "¸ß¸ùÃ÷",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "Ê·ÇàÉ½",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "Ïô·å",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([       "quest":               "Ì«¼«Ê®ÈýÊÆ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               9        ]),
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
        ([       "quest":               "Âí³¬ÐË",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "Öª¿ÍµÀ³¤",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "¹ÈÐéµÀ³¤",
                "quest_type":           "É±",
                "time":                 180,
                "score" :               5
        ]),

        ([       "quest":               "Î¬Îá¶û×å³¤ÅÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "¾ü·þ",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               9
        ]),
        ([       "quest":               "âÎ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               8
        ]),
        ([       "quest":               "»¨µñ¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 560,
                "score" :               6
        ]),
        ([       "quest":               "³àÁ·Éß",
                "quest_type":           "É±",
                "time":                 880,
                "score" :               9
        ]),
        ([       "quest":               "²ÉÒ©ÈË",
                "quest_type":           "É±",
                "time":                 480,
                "score" :               10
        ]),
        ([       "quest":               "òÚò¼",
                "quest_type":           "É±",
                "time":                 880,
                "score" :               5
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

