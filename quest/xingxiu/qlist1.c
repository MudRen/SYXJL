#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               " È…˙",
                "quest_type":           "…±",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "—Ú±ﬁ",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               3
        ]),
        ([      "quest":                "≥§±ﬁ",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               3
        ]),
        ([      "quest":                "≤®Àπ≥§≈€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               3
        ]),

        ([      "quest":                "Ô⁄Õ∑",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "¡÷∆Ω÷Æ",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               5
        ]),
        ([      "quest":                "≤º“¬",
                "quest_type":           "—∞",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "Ω¯œ„øÕ",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "µ¿ÕØ",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               3
        ]),         
              ([      "quest":                "Œ§¥∫∑º",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ã˙º◊",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "∏÷’»",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "∫Ï…’π∑»‚",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "—√“€",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "¬Ú¬ÙÃ·",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),

        ([      "quest":                "∞¢∑≤Ã·",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "πŸ±¯",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),

        ([      "quest":                "∞¢¿≠≤ÆÕ‰µ∂",
                "quest_type":           "—∞",
                "time":                 580,
                "score" :               6
        ]),
        ([      "quest":                "—Ú»‚¥Æ",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               5
        ]),
        ([      "quest":                "π˛√‹πœ",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               5
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

