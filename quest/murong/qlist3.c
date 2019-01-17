#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "∞¢¿≠≤ÆÕ‰µ∂",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "Ã“ƒæΩ£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
         ([      "quest":               "∑€∫Ï≥Ò…¿",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ΩœÓ¡¥",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
 	
        ([      "quest":               "Œ¨Œ·∂˚◊Â≥§≈€",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "π‚√˜µ∂",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
 	
        ([      "quest":                "≈–πŸ± ",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                " ¥ªÍ–«",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "”Òµ—",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "…ﬂµ®∏‡",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),                      	
   ([      "quest":                "“¡¿Á¬Ì",
                "quest_type":           "—∞",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "”Ò÷Ò’»",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),       
       ([      "quest":                "–€ª∆",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),  
      ([      "quest":                "”Œ¡˙Ω£",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "∆Â∆◊",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               " Ø∞Â",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "ª’€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "“©≥˙",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
       ([       "quest":               "∑˜≥æ",
               "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

