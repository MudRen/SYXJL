#include <ansi.h>

inherit SKILL;

mapping *quest = ({
            ([      "quest":                "∂Œ—”«Ï",
		"quest_type":           "…±",
		"time":                 1200,
		"score" :               12
	]),
	([      "quest":                "œÙ∏’",
		"quest_type":           "…±",
		"time":                 1200,
		"score" :               14
	]),
	([      "quest":                "¬Ì≥¨–À",
		"quest_type":           "…±",
		"time":                 1000,
		"score" :               12
	]),
	([      "quest":                HIG" ÷ÔÌ"NOR,
		"quest_type":           "—∞",
		"time":                 1200,
		"score" :               11
	]),
	([      "quest":                "«Â–ƒ…¢",
		"quest_type":           "—∞",
		"time":                 1200,
		"score" :               15
	]),
	([      "quest":                "œÙ»Õ",
		"quest_type":           "…±",
		"time":                 1200,
		"score" :               12
	]),
	([      "quest":                "ÀŒ‘∂«≈",
		"quest_type":           "…±",
		"time":                 1200,
		"score" :               14
	]),
	([      "quest":                "‘¿≤ª»∫",
		"quest_type":           "…±",
		"time":                 700,
		"score" :               10
	]),
	([      "quest":                "¡Ó∫¸≥Â",
		"quest_type":           "…±",
		"time":                 700,
		"score" :               10
	]),
	([      "quest":                "∂Œ”˛",
		"quest_type":           "…±",
		"time":                 700,
		"score" :               10
	]),
	([      "quest":                "–˛±Ø¥Û ¶",
		"quest_type":           "…±",
		"time":                 700,
		"score" :               10
	]),
	([      "quest":                "µÿ¿Œ",
		"quest_type":           "…®",
		"time":                 300,
		"score" :               10
	]),
	([      "quest":                "≥¯∑ø",
		"quest_type":           "…®",
		"time":                 300,
		"score" :               8
	]),
	([      "quest":                "—©…Ω±‘∫",
		"quest_type":           "…®",
		"time":                 200,
		"score" :               8
	]),
});


mapping query_quest()
{
	return quest[random(sizeof(quest))];
}

