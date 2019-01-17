#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "∞¢¿≠≤ÆÕ‰µ∂",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "—Ú±ﬁ",
                "quest_type":           "—∞",
                "time":                 240,
                "score" :               3
        ]),
         ([      "quest":               "∑€∫Ï≥Ò…¿",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ΩœÓ¡¥",
                "quest_type":           "—∞",
                "time":                 300,
                "score" :               3
        ]),
        
        ([      "quest":               "≤®Àπ≥§≈€",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "≤®Àπ…Ã»À",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               3
        ]),
        
        ([      "quest":                "ƒ¡—Ú»À",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "Œ¨Œ·∂˚◊Â≥§≈€",
                "quest_type":           "—∞",
                "time":                 300,
                "score" :               3
        ]),
        ([      "quest":                "√≈Œ¿",
                "quest_type":           "…±",
                "time":                 700,
                "score" :               8
        ]),       
        ([      "quest":                "¥Ûµ∂",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),                      
        ([      "quest":                "ΩΩ‰÷∏",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                HIW"∞◊‘∆∫Õ∑˛"NOR,
                "quest_type":           "—∞",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "÷ÒΩ£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               5
        ]),
        ([      "quest":                "Œ¿ ø",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "Õı∏Æ¥Û√≈",
                "quest_type":           "…®",
                "time":                 300,
                "score" :               3
        ]),         ([      "quest":                "¡˜√•",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "“©∑€",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "Ã˙¥∏",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "∫Ï…’π∑»‚",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "¡˜√•Õ∑",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
