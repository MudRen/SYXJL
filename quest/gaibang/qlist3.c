inherit SKILL;
#include <ansi.h>
mapping *quest = ({
        ([      "quest":                "Œ›Ω«±ﬂ",
                "quest_type":           "…®",
                "time":                 680,
                "score" :               10
        ]),
        ([      "quest":                "Õ¡∑ÀŒ—±ﬂ",
                "quest_type":           "…®",
                "time":                 480,
                "score" :               8
        ]),
        ([      "quest":                "∆∆√Ì√‹ “",
                "quest_type":           "…®",
                "time":                 780,
                "score" :               10
        ]),
        ([      "quest":                "…·…Ì—¬œ¬",
                "quest_type":           "…®",
                "time":                 800,
                "score" :               5
        ]),
        ([      "quest":                "π»≥°ª± ˜±ﬂ",
                "quest_type":           "…®",
                "time":                 360,
                "score" :               6
        ]),
        ([      "quest":                "∞¢◊œ",
                "quest_type":           "…±",
                "time":               1000,
                "score" :             12
        ]),
        ([      "quest":                "µ∂∑Ê¿‰",
                "quest_type":           "…±",
                "time":               800,
                "score" :             12
        ]),
        ([      "quest":                "–˛ø‡",
                "quest_type":           "…±",
                "time":               1100,
                "score" :             13
        ]),
        ([      "quest":                "√∑Ω£",
                "quest_type":           "…±",
                "time":               810,
                "score" :             10
        ]),
        ([      "quest":                "ºŒƒæªÓ∑",
                "quest_type":           "…±",
                "time":               600,
                "score" :             12
        ]),
        ([      "quest":                "ªÙ∂º",
                "quest_type":           "…±",
                "time":               680,
                "score" :             9
        ]),
        ([      "quest":                "∂Œ—”«Ï",
                "quest_type":           "…±",
                "time":               450,
                "score" :             10
        ]),
  ([      "quest":                HIG"∞Ÿœ„ª®"NOR,
                "quest_type":           "—∞",
                "time":                600,
                "score" :              10
      ]),
  ([      "quest":                "‚Œ",
                "quest_type":           "—∞",
                "time":                700,
                "score" :              10
      ]),
  ([      "quest":                "∂¨≤ª¿≠",
                "quest_type":           "—∞",
                "time":                680,
                "score" :              9
      ]),
  ([      "quest":                "≥§≈€",
                "quest_type":           "—∞",
                "time":                900,
                "score" :              10
      ]),
  ([      "quest":                HIW"“¯¬÷"NOR,
                "quest_type":           "—∞",
                "time":                500,
                "score" :              9
      ]),
  ([      "quest":                HIR"…Æ√±"NOR,
                "quest_type":           "—∞",
                "time":                890,
                "score" :              8
      ]),
  ([      "quest":                "—Ú∆§ È",
                "quest_type":           "—∞",
                "time":                500,
                "score" :              11
      ]),


   });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
