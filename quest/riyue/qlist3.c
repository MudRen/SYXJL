#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "¬Ì≥¨–À",
                "quest_type":           "…±",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "ÀŒ‘∂«≈",
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "œÙ∑Â",
                "quest_type":           "…±",
                "time":                 700,
                "score" :               16
        ]),
        ([      "quest":                "∂Œ”˛",
                "quest_type":           "…±",
                "time":                 700,
                "score" :               16
        ]),
         ([       "quest":               "≤®Àπ≥§≈€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "∂∑≈Ò",
                "quest_type":           "—∞",
                "time":                 800,
                "score" :               8
        ]),
        ([       "quest":               "‚Œ",
                "quest_type":           "—∞",
                "time":                 900,
                "score" :               13
        ]),           
        ([       "quest":               "∞¢¿≠≤ÆÕ‰µ∂",
                "quest_type":           "—∞",
                "time":                 900,
                "score" :               14
        ]),
        ([      "quest":                "√∑Ω£",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "≈Ì”®”Ò",               
                "quest_type":           "…±",
                "time":                 1200,
                "score" :               14
        ]),
          ([      "quest":              "“π√˜÷È",
                "quest_type":           "—∞",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "‘ø≥◊",
                "quest_type":           "—∞",
                "time":                 800,
                "score" :               12
        ]),
        ([      "quest":                "≥§¿»",
                "quest_type":           "…®",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "–›œ¢ “",
                "quest_type":           "…®",
                "time":                 1200,
                "score" :               19
        ]),
        ([      "quest":                "“©∑ø",
                "quest_type":           "…®",
                "time":                 1200,
                "score" :               10
        ]),
        ([      "quest":                "÷Ï»∏Ã√",
                "quest_type":           "…®",
                "time":                 1200,
                "score" :               12
        ]),
           
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

