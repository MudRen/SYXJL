#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÀîËÄ",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "Àî½ÌÍ·",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]), 
          ([      "quest":                "Ð¡ÆÑÍÅ",
                  "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "É®¹÷",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
          ([      "quest":                "ÑÒ¶´",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
          ([      "quest":                "Ð¡ÎÝ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
        ]), 
        ([      "quest":                "Âô»¨¹ÃÄï",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ìú¼×",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "¸ÖÕÈ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "¿¾Ñ¼",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "µ¶¿Í",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               7
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
