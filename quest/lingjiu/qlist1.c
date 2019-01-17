#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "—√“€",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "≥§Ω£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "’≈¬Ë",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               5
        ]), 
        ([      "quest":                " ÿÀ¬…Æ±¯",
                "quest_type":           "…±",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "…Æπ˜",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "±’πÿ “",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "≈∫œ„Èø",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "–«Àﬁ≈…Ó‡ ÷",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               10
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
        ([      "quest":                "ª®‘∞",
                "quest_type":           "…®",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "«ﬂ∑º–˘",
                "quest_type":           "…®",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                "œ∑∑Ô∏Û",
                "quest_type":           "…®",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "¥Ûµ∂",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "‚Œ",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "Œ¨Œ·∂˚◊Â≥§≈€",
                "quest_type":           "—∞",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "∞¢∑≤Ã·",
                "quest_type":           "…±",
                "time":                 650,
                "score" :               9
        ]),
        ([      "quest":                "≤…ª®◊”",
                "quest_type":           "…±",
                "time":                 550,
                "score" :               9
        ]),
        ([      "quest":                "πŸ±¯",
                "quest_type":           "…±",
                "time":                 550,
                "score" :               9
        ]),


});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

