#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "ªÙ∂º",
                "quest_type":           "…±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "’™–«◊”",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "Ù√ÕÚº“",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "¬Ú¬ÙÃ·",
                "quest_type":           "…±",
                "time":                 560,
                "score" :               6
        ]),
        ([      "quest":                "…≥≥Ê",
                "quest_type":           "…±",
                "time":                 660,
                "score" :               6
        ]),
        ([      "quest":                "≤®Àπ…Ã»À",
                "quest_type":           "…±",
                "time":                 560,
                "score" :               8
        ]),
        ([      "quest":                "¿ÓΩÃÕ∑",
                "quest_type":           "…±",
                "time":                 860,
                "score" :               9
        ]),
        ([      "quest":                "”Œ¡˙Ω£",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "¡Ω“«Ω£∆◊<œ¬æÌ>",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "»˝–¶Â–“£…¢",
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
        ([      "quest":                "–«Àﬁ≈…πƒ ÷",
                "quest_type":           "…±",
                "time":                 620,
                "score" :               10
        ]),
        ([      "quest":                "–«Àﬁ≈…∫≈ ÷",
                "quest_type":           "…±",
                "time":                 520,
                "score" :               10
        ]),
        ([      "quest":                "◊∫Ωı∏Û",
                "quest_type":           "…®",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "ﬁ§∑Á–˘",
                "quest_type":           "…®",
                "time":                 600,
                "score" :               8
        ]),
        ([      "quest":                "œ…≥Ó√≈",
                "quest_type":           "…®",
                "time":                 500,
                "score" :               7
        ]),
        ([       "quest":               "∞◊…´≥§≈€",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               8
        ]),
        ([       "quest":               "–Âª®–¨",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               11
        ]),
        ([       "quest":               "—Ú»‚¥Æ",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

