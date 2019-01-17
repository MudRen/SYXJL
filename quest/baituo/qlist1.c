#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "–°∑∑",
                "quest_type":           "…±",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "÷ÒΩ£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "πŸ±¯",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "Ω≠∞Ÿ §",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               5
        ]),
        ([      "quest":                "≤º“¬",
                "quest_type":           "—∞",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "–°…≥√÷",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "µ¿ÕØ",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               3
        ]),         
        ([      "quest":                "–°ƒ·π√",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ã˙º◊",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "¬€”Ô",
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
        ([      "quest":                "–Âª®–¨",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               4
        ]),
        ([      "quest":                "…ﬂ»‚",
                "quest_type":           "—∞",
                "time":                 590,
                "score" :               5
        ]),
        ([      "quest":                "Õ√»‚",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               3
        ]),
        ([      "quest":                "…ﬂ±ﬁ",
                "quest_type":           "—∞",
                "time":                 900,
                "score" :               4
        ]),
        ([      "quest":                "≤Àª®…ﬂ",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "¥Âπ√",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "’≈¬Ë",
                "quest_type":           "…±",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "≈©º“∏æ≈Æ",
                "quest_type":           "…±",
                "time":                 650,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

